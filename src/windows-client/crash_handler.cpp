#include "crash_handler.hpp"
#include <DbgHelp.h>
#include <stdio.h>

bool CreateMiniDump(EXCEPTION_POINTERS* pep)
{
    HANDLE hFile = CreateFileA(
        "crash.dmp",
        GENERIC_WRITE,
        FILE_SHARE_WRITE,
        NULL,
        CREATE_ALWAYS,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );

    if (hFile == INVALID_HANDLE_VALUE)
        return false;

    MINIDUMP_EXCEPTION_INFORMATION mdei;
    mdei.ThreadId = GetCurrentThreadId();
    mdei.ExceptionPointers = pep;
    mdei.ClientPointers = FALSE;

    BOOL success = MiniDumpWriteDump(
        GetCurrentProcess(),
        GetCurrentProcessId(),
        hFile,
        MiniDumpNormal,
        pep ? &mdei : NULL,
        NULL,
        NULL
    );

    CloseHandle(hFile);
    return success == TRUE;
}

static LONG WINAPI UnhandledExceptionFilterFunc(EXCEPTION_POINTERS* pep)
{
    CreateMiniDump(pep);
    return EXCEPTION_EXECUTE_HANDLER; // Let Windows know we handled it
}

void InstallCrashHandler()
{
    SetUnhandledExceptionFilter(UnhandledExceptionFilterFunc);
}
