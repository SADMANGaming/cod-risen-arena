#include <windows.h>
#include "hooks.hpp"
#include "mss32.hpp"
#include "crash_handler.hpp"
#include "file_system.hpp"
#include "codra_client.hpp"
#include "functions.hpp"

extern "C" bool bClosing = false;
static void(*Com_Quit_f)() = (void(*)())0x435D80;
static int(__stdcall *mainx)(HINSTANCE, HINSTANCE, LPSTR, int) = (int(__stdcall*)(HINSTANCE, HINSTANCE, LPSTR, int))0x4640B0;
HINSTANCE hInst;
extern cvar_t* g_vanilla;

void Sys_Unload() {
	bClosing = true;
	static bool unloaded = false;
    
    std::filesystem::remove("__CoDMP");

	if (unloaded)
		return;
	unloaded = true;
}


void sub_40E2B0()
{
	void(*o)();
	*(UINT32*)&o = 0x40E2B0;
	o();


	void Sys_Unload();
	Sys_Unload();
}
LONG WINAPI CrashHandler(EXCEPTION_POINTERS* ExceptionInfo)
{
    FILE* log = fopen("codso-cl_log.txt", "w");
    if (log)
    {
        fprintf(log, "CODRA-Client\n");
        fprintf(log, "Crash caught!\n");
        fprintf(log, "Exception code: 0x%08X\n", ExceptionInfo->ExceptionRecord->ExceptionCode);
        fprintf(log, "Exception address: %p\n", ExceptionInfo->ExceptionRecord->ExceptionAddress);
        fclose(log);
    }
    // Optionally, you could dump more info or trigger a debugger here.

    // Exit process or pass control to the next handler
    return EXCEPTION_EXECUTE_HANDLER;
}

void apply_hooks()
{
	if(g_vanilla->integer == 1)
		Com_Printf("Vanilla mode enabled, skipping hooks.\n");
		return;

	memset((void*)0x5083b1, 0x00, 1);

    __call(0x46319B, (int)sub_40E2B0); //cleanup exit
	__call(0x528948, (int)WinMain);
	// masterlist override
	//memcpy((void*)0x00566120, "", strlen("")+1);
    memcpy((void*)0x00566C18, "1.00.0", strlen("1.00.0")+1);
    memcpy((void*)0x0055dd78, "CoDRAHost", strlen("CoDRAHost")+1);
	
    __call(0x0042ce3c, (int)_FS_Init);

	void _Com_Init();
    __call(0x004641dc, (int)_Com_Init);

	
    void _Com_Init();
    __call(0x004641dc, (int)_Com_Init);

	void _CL_Init();
	__call(0x437B4B, (int)_CL_Init);
	__call(0x438178, (int)_CL_Init);

	void _SV_Init();
    __call(0x00437b34, (int)_SV_Init);
  
	
	constexpr uintptr_t addr = 0x00410490;
    constexpr uint8_t patch[] = { 0x6A, 0x06 }; // PUSH 0x6

    DWORD oldProtect;
    if (VirtualProtect((void*)addr, sizeof(patch), PAGE_EXECUTE_READWRITE, &oldProtect)) {
        memcpy((void*)addr, patch, sizeof(patch));
        VirtualProtect((void*)addr, sizeof(patch), oldProtect, &oldProtect);
    }

    constexpr uintptr_t addr2 = 0x0453429;
    constexpr uint8_t patch2[] = { 0x6A, 0x06 }; // PUSH 0x6

//    DWORD oldProtect;
    if (VirtualProtect((void*)addr2, sizeof(patch2), PAGE_EXECUTE_READWRITE, &oldProtect)) {
        memcpy((void*)addr2, patch2, sizeof(patch2));
        VirtualProtect((void*)addr2, sizeof(patch2), oldProtect, &oldProtect);
    }

    constexpr uintptr_t addr3 = 0x00453404;
    uint8_t patch3 = 0x06; // Change immediate from 0x01 to 0x06

    if (VirtualProtect((void*)addr3 + 2, 1, PAGE_EXECUTE_READWRITE, &oldProtect)) {
        *(uint8_t*)(addr3 + 2) = patch3;
        VirtualProtect((void*)addr3 + 2, 1, oldProtect, &oldProtect);
    }

	void _Check_FS_Bg();
    _Check_FS_Bg();
}

void Main_UnprotectModule(HMODULE hModule)
{
	PIMAGE_DOS_HEADER header = (PIMAGE_DOS_HEADER)hModule;
	PIMAGE_NT_HEADERS ntHeader = (PIMAGE_NT_HEADERS)((DWORD)hModule + header->e_lfanew);

	SIZE_T size = ntHeader->OptionalHeader.SizeOfImage;
	DWORD oldProtect;
	VirtualProtect((LPVOID)hModule, size, PAGE_EXECUTE_READWRITE, &oldProtect);
}
BOOL APIENTRY DllMain(HMODULE hMod, DWORD ul_reason_for_call, LPVOID lpReserved)
{
#if 0
    if (strstr(szModuleName, "rundll32") != NULL) {
        return TRUE;
    }
#endif

    switch (ul_reason_for_call) {
        case DLL_PROCESS_ATTACH: {
            HMODULE hModule = GetModuleHandle(NULL); // codmp.exe
            if (hModule)
                Main_UnprotectModule(hModule);

            // install crash handler (you may prefer to do this in the init thread)
            InstallCrashHandler();
			SetUnhandledExceptionFilter(CrashHandler);

            loadRealMSS32();

            extern bool miles32_loaded;
            if (!miles32_loaded)
                return FALSE;

            apply_hooks();
            break;
        }

        case DLL_PROCESS_DETACH: {
            break;
        }
    }
    return TRUE;
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	hInst = hInstance;


	void loadRealMSS32();
	loadRealMSS32();

	extern bool miles32_loaded;
	if (!miles32_loaded)
		return 0;

	return mainx(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
}