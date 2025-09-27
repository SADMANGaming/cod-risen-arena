#include "crash_handler.hpp"

#include <windows.h>
#include <stdio.h>
#include <dbghelp.h>
#include "functions.hpp"

#pragma comment(lib, "dbghelp.lib")

volatile int exception_processCrashed = false;

const char* exception_getText(DWORD exceptionCode) {
    switch (exceptionCode) {
        case EXCEPTION_ACCESS_VIOLATION:     return "ACCESS_VIOLATION";
        case EXCEPTION_STACK_OVERFLOW:       return "STACK_OVERFLOW";
        case EXCEPTION_FLT_DIVIDE_BY_ZERO:   return "FLT_DIVIDE_BY_ZERO";
        case EXCEPTION_INT_DIVIDE_BY_ZERO:   return "INT_DIVIDE_BY_ZERO";
        case EXCEPTION_ILLEGAL_INSTRUCTION: return "ILLEGAL_INSTRUCTION";
        case EXCEPTION_PRIV_INSTRUCTION:    return "PRIV_INSTRUCTION";
        default:                              return "Unknown Exception";
    }
}

bool exception_createMiniDump(EXCEPTION_POINTERS* pExceptionInfo) {
    HANDLE hFile = CreateFile("CoDMP_ra.crash.dmp", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE) {
        MessageBox(NULL, "Failed to create crash dump file.", "Application error", MB_OK | MB_ICONERROR | MB_TOPMOST);
        return false;
    }

    MINIDUMP_EXCEPTION_INFORMATION mdei;
    mdei.ThreadId = GetCurrentThreadId();
    mdei.ExceptionPointers = pExceptionInfo;
    mdei.ClientPointers = FALSE;

    BOOL bSuccess = MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(),
                                       hFile, MiniDumpWithFullMemory,
                                       (pExceptionInfo ? &mdei : NULL), NULL, NULL);

    CloseHandle(hFile);

    if (!bSuccess) {
        MessageBox(NULL, "Failed to create crash dump file.", "Application error", MB_OK | MB_ICONERROR | MB_TOPMOST);
        return false;
    }

    return true;
}

LONG WINAPI exception_handler(EXCEPTION_POINTERS* pExceptionInfo) {
    if (exception_processCrashed == 2) {
        MessageBoxA(NULL, "Application is already crashed. Cannot handle the exception again.", "Application error", MB_OK | MB_ICONERROR | MB_TOPMOST);
        return EXCEPTION_CONTINUE_SEARCH;
    }

    bool ignoreErrorDetails = false;
    if (exception_processCrashed == 1) {
        ignoreErrorDetails = true;
    }

    exception_processCrashed++;


    char moduleName[MAX_PATH] = {0};
    unsigned int moduleBase = 0;
    unsigned int fileOffset = 0;
    const size_t stackDumpSize = 64;
    const size_t perLineSize = 128;
    char stackDump[stackDumpSize * perLineSize];
    strcpy(stackDump, "Error reading stack");

    unsigned int exceptionCode = pExceptionInfo->ExceptionRecord->ExceptionCode;
    unsigned int exceptionAddress = (unsigned int)pExceptionInfo->ExceptionRecord->ExceptionAddress;

    if (!ignoreErrorDetails) {
        MEMORY_BASIC_INFORMATION mbi;
        if (VirtualQuery(pExceptionInfo->ExceptionRecord->ExceptionAddress, &mbi, sizeof(mbi)) != 0) {
            GetModuleFileNameA((HMODULE)mbi.AllocationBase, moduleName, sizeof(moduleName));
            char* p = strrchr(moduleName, '\\');
            if (p) strcpy(moduleName, p + 1);

            moduleBase = (unsigned int)mbi.AllocationBase;
            fileOffset = exceptionAddress - moduleBase;
        }

        uintptr_t espValue = 0;
        if (pExceptionInfo && pExceptionInfo->ContextRecord) {
            espValue = pExceptionInfo->ContextRecord->Esp;
        }

        size_t written = 0;
        stackDump[0] = '\0';

        written += snprintf(stackDump + written, sizeof(stackDump) - written, "0x%08X 0x%08X %s\n", moduleBase, fileOffset, moduleName);

        if (espValue) {
            DWORD* stack = (DWORD*)espValue;

            for (size_t i = 0; i < stackDumpSize && written < sizeof(stackDump) - perLineSize; ++i) {
                if (IsBadReadPtr(&stack[i], sizeof(DWORD))) break;

                unsigned int stackValue = (unsigned int)(stack[i]);

                if (IsBadReadPtr((void*)stackValue, sizeof(DWORD) * stackDumpSize)) continue;

                MEMORY_BASIC_INFORMATION mbi2;
                if (VirtualQuery((void*)stackValue, &mbi2, sizeof(mbi2)) == 0) continue;

                if (!(mbi2.Protect & PAGE_EXECUTE) &&
                    !(mbi2.Protect & PAGE_EXECUTE_READ) &&
                    !(mbi2.Protect & PAGE_EXECUTE_READWRITE) &&
                    !(mbi2.Protect & PAGE_EXECUTE_WRITECOPY)) continue;

                char moduleName2[MAX_PATH] = {0};
                GetModuleFileNameA((HMODULE)mbi2.AllocationBase, moduleName2, sizeof(moduleName2));
                char* p2 = strrchr(moduleName2, '\\');
                if (p2) strcpy(moduleName2, p2 + 1);

                if (moduleName2[0] == '\0') continue;

                if (exceptionAddress == 0 && strncmp(moduleName2, moduleName, MAX_PATH) == 0) {
                    exceptionAddress = stackValue;
                    fileOffset = stackValue - (unsigned int)mbi2.AllocationBase;
                }

                written += snprintf(stackDump + written, sizeof(stackDump) - written, "0x%08X 0x%08X %s\n", stackValue, stackValue - (unsigned int)mbi2.AllocationBase, moduleName2);
            }
        } else {
            strcpy(stackDump, "Stack unavailable");
        }
    }

    //error_sendCrashData((unsigned int)exceptionCode, exceptionAddress, moduleName, fileOffset, stackDump);

    char tempBuffer[1024];
    sprintf(tempBuffer, 
        "CoD: Risen Arena has crashed.\n\n"
        "Code:\t\t0x%08x  (%s)\n"
        "Address:\t0x%08x  (%s)\n"
        "File Address:\t0x%08x\n"
        "MSS32 version:\t%s\n\n"
        "Stack:\n%s\n\n"
        "Would you like to create a crash dump file before exiting?",
        exceptionCode, exception_getText(exceptionCode),
        exceptionAddress, (moduleName[0] ? moduleName : "unknown module"),
        fileOffset,
        __RAVERSION__,
        stackDump);

    int result = MessageBox(NULL, tempBuffer, "Application crash", MB_YESNO | MB_ICONERROR | MB_TOPMOST);

    if (result == IDYES) {
        bool dumpOk = exception_createMiniDump(pExceptionInfo);
        if (dumpOk) {
            MessageBox(NULL, 
                "Diagnostic file 'CoD1_s.crash.dmp' saved.\nPlease send this file to developers.\nWebsite: https://devcod.pages.dev",
                "Crash Dump Created", MB_OK | MB_ICONINFORMATION | MB_TOPMOST);
        } else {
            MessageBox(NULL, "Failed to create crash dump file.", "Crash Dump Error", MB_OK | MB_ICONINFORMATION | MB_TOPMOST);
        }
    }

    return EXCEPTION_EXECUTE_HANDLER;
}

void exception_init() {
    SetUnhandledExceptionFilter(exception_handler);
}
