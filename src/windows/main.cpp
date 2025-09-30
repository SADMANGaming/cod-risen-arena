#include <windows.h>
#include "hooks.hpp"
#include "mss32.hpp"
#include "crash_handler.hpp"
#include "file_system.hpp"
#include "codra_client.hpp"
#include "codra_server.hpp"
#include "functions.hpp"
#include "auto_updater.hpp"
#include "gsc.hpp"
#include <shlwapi.h>
#include <string>
extern "C" bool bClosing = false;
static int(__stdcall *WinMain_original)(HINSTANCE, HINSTANCE, LPSTR, int) = (int(__stdcall*)(HINSTANCE, HINSTANCE, LPSTR, int))0x4640B0;
#pragma comment(lib, "Shlwapi.lib")
#include <tchar.h>

HINSTANCE hInst;

void Sys_Unload() {
	bClosing = true;
	static bool unloaded = false;
    
//    std::filesystem::remove("__CoDMP");

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

void Cmd_Ban() {
    // Get the HWID from the command arguments
    const char* hwid = Cmd_Argv(1);
    if (hwid && hwid[0] != '\0') {
        banHWID(hwid);
        Com_Printf("HWID %s has been banned.\n", hwid);
    } else {
        Com_Printf("Usage: ban <hwid>\n");
    }
}

cHook *hook_sv_addoperatorcommands;
void custom_SV_AddOperatorCommands()
{
    hook_sv_addoperatorcommands->unhook();
    void (*SV_AddOperatorCommands)();
    *(int *)&SV_AddOperatorCommands = hook_sv_addoperatorcommands->from;
    SV_AddOperatorCommands();

    Cmd_AddCommand("ban", Cmd_Ban);
//    Cmd_AddCommand("unban", unban);

    hook_sv_addoperatorcommands->hook();
}


void apply_hooks()
{
	memset((void*)0x5083b1, 0x00, 1); // Alt + Tab fix


    __call(0x46319B, (int)sub_40E2B0); //cleanup exit
	__call(0x528948, (int)WinMain);

	// masterlist override
	//memcpy((void*)0x00566120, "", strlen("")+1);
    memcpy((void*)0x00566C18, "1.00.0", strlen("1.00.0")+1);
    memcpy((void*)0x0055dd78, "CoDRAHost", strlen("CoDRAHost")+1);
    memcpy((void*)0x0055bd4c, "Call of Duty - Risen Arena", strlen("Call of Duty - Risen Arena")+1);
	
    memcpy((void*)0x0563f88, "ra_config_mp.cfg", strlen("ra_config_mp.cfg") + 1);
    memcpy((void*)0x00562784, "exec ra_config_mp.cfg\n", strlen("exec ra_config_mp.cfg\n") + 1);

    // GSC
    DWORD old;
    VirtualProtect((void*)0x469BEE, 6, PAGE_EXECUTE_READWRITE, &old);
    *(BYTE*)0x469BEE = 0xe8;
    __call(0x469BEE, (int)Scr_GetCustomFunction);
    *(BYTE*)(0x469BEE + 5) = 0x90;
    VirtualProtect((void*)0x469BEE, 6, old, &old);


    VirtualProtect((void*)0x469E8E, 6, PAGE_EXECUTE_READWRITE, &old);
    *(BYTE*)0x469E8E = 0xe8;
    __call(0x469E8E, (int)Scr_GetCustomMethod);
    *(BYTE*)(0x469E8E + 5) = 0x90;
    VirtualProtect((void*)0x469E8E, 6, old, &old);


    __call(0x0042d21a, (int)_FS_Startup);
    __call(0x0042d2d1, (int)_FS_Startup);
    __call(0x0043bb0b, (int)_FS_Startup);

    //__call(0x0042ce3c, (int)_FS_Init);

    __call(0x0045A9BB, (int)_SVC_DirectConnect);

    // SV_ADdOPFunc 452C50
    hook_sv_addoperatorcommands = new cHook(0x452C50, (int)custom_SV_AddOperatorCommands);
    hook_sv_addoperatorcommands->hook();


	void _Com_Init(char *commandLine);
    __call(0x004641dc, (int)_Com_Init);

	void _CL_Init();
	__call(0x437B4B, (int)_CL_Init);
	__call(0x438178, (int)_CL_Init);

    void _CL_Frame(int msec);
	__call(0x43822C, (int)_CL_Frame);

//    void _Com_Frame();
//    __call(0x046426F, (int)_Com_Frame);

	void _SV_Init();
    __call(0x00437b34, (int)_SV_Init);
  
	
	constexpr uintptr_t addr = 0x00410490;
    constexpr uint8_t patch[] = { 0x6A, 0x07 }; // PUSH 0x7

    DWORD oldProtect;
    if (VirtualProtect((void*)addr, sizeof(patch), PAGE_EXECUTE_READWRITE, &oldProtect)) {
        memcpy((void*)addr, patch, sizeof(patch));
        VirtualProtect((void*)addr, sizeof(patch), oldProtect, &oldProtect);
    }

    constexpr uintptr_t addr2 = 0x0453429;
    constexpr uint8_t patch2[] = { 0x6A, 0x07 }; // PUSH 0x7

//    DWORD oldProtect;
    if (VirtualProtect((void*)addr2, sizeof(patch2), PAGE_EXECUTE_READWRITE, &oldProtect)) {
        memcpy((void*)addr2, patch2, sizeof(patch2));
        VirtualProtect((void*)addr2, sizeof(patch2), oldProtect, &oldProtect);
    }

    constexpr uintptr_t addr3 = 0x00453404;
    uint8_t patch3 = 0x07; // Change immediate from 0x01 to 0x07

    if (VirtualProtect((void*)addr3 + 2, 1, PAGE_EXECUTE_READWRITE, &oldProtect)) {
        *(uint8_t*)(addr3 + 2) = patch3;
        VirtualProtect((void*)addr3 + 2, 1, oldProtect, &oldProtect);
    }
    
	void _Check_FS_Bg();
    _Check_FS_Bg();
}

std::string GetExePath()
{
	char buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, MAX_PATH);
	std::string f = std::string(buffer);
	return f.substr(0, f.find_last_of("\\/"));
}

void RegistryAddURLProtocol() {
	HKEY hkey;
	char gamePath[MAX_PATH], szExe[MAX_PATH * 2];
	GetModuleFileName(NULL, gamePath, MAX_PATH);
	LPCTSTR defaultIcon = TEXT("CoDMP.exe,0");

	if (RegCreateKeyA(HKEY_CURRENT_USER, "Software\\Classes\\codra", &hkey) == ERROR_SUCCESS) {
		RegSetValueExA(hkey, "URL Protocol", 0, REG_SZ, (PBYTE)"", 1);
		RegSetValueExA(hkey, "DefaultIcon", 0, REG_SZ, (LPBYTE)defaultIcon, _tcslen(defaultIcon) * sizeof(TCHAR));
		RegCloseKey(hkey);
	}

	if (RegCreateKeyA(HKEY_CURRENT_USER, "Software\\Classes\\codra\\shell\\open\\command", &hkey) == ERROR_SUCCESS) {
		Com_sprintf(szExe, sizeof(szExe), "%s %%1", gamePath);
		RegSetValueA(hkey, NULL, REG_SZ, szExe, strlen(szExe));
		RegCloseKey(hkey);
	}
}



void Main_UnprotectModule(HMODULE hModule)
{
	PIMAGE_DOS_HEADER header = (PIMAGE_DOS_HEADER)hModule;
	PIMAGE_NT_HEADERS ntHeader = (PIMAGE_NT_HEADERS)((DWORD)hModule + header->e_lfanew);

	SIZE_T size = ntHeader->OptionalHeader.SizeOfImage;
	DWORD oldProtect;
	VirtualProtect((LPVOID)hModule, size, PAGE_EXECUTE_READWRITE, &oldProtect);
}
// --- DllMain hook ---
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

            exception_init();

            loadRealMSS32();
			SetCurrentDirectoryA(GetExePath().c_str());

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

// --- WinMain Hook ---
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    hInst = hInstance;

    // Custom URL protocol: cod1x://1.2.3.4 to connect to a server.
	std::string strCmdLine = std::string(lpCmdLine);
	if (strCmdLine.rfind("codra://", 0) == 0) {
		// Remove cod1x:// and ending slash from string.
		strCmdLine.erase(0, 8);
		if (strCmdLine.back() == '/')
			strCmdLine.pop_back();

		// Check is IP valid.
		netadr_t ip;
		if (NET_StringToAdr(strCmdLine.c_str(), &ip)) {
			// Set "connect ip" command to the command line.
			strCmdLine = "connect " + strCmdLine;
			lpCmdLine = const_cast<char*>(strCmdLine.c_str());
		}
	}
	else { // Add the registry keys for the protocol.
		RegistryAddURLProtocol();
    }

    void loadRealMSS32();
    loadRealMSS32();

    extern bool miles32_loaded;
    if (!miles32_loaded)
        return 0;

    return WinMain_original(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
}