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
#include "cgame.hpp"
#include "discord.hpp"
#include <string>
#include <thread>
#include <atomic>
#include <chrono>
#include <algorithm>

#include "ui.hpp"
#include "game.hpp"

#include "sniper_scopes.hpp"

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
    CL_DiscordShutdown();
}









typedef HMODULE(WINAPI* LoadLibraryA_t)(LPCSTR lpLibFileName);
LoadLibraryA_t orig_LoadLibraryA = NULL;


HMODULE WINAPI hLoadLibraryA(LPCSTR lpLibFileName) {
    HMODULE hModule = orig_LoadLibraryA(lpLibFileName);

    if (!hModule) return NULL;

    DWORD pBase = (DWORD)GetModuleHandle(lpLibFileName);
    if (pBase) {
        void Main_UnprotectModule(HMODULE hModule);
        Main_UnprotectModule(hModule);

        if (strstr(lpLibFileName, "cgame_mp") != NULL) {
            CG_Init(pBase);
        } else if (strstr(lpLibFileName, "ui_mp") != NULL) {
            UI_Init(pBase);
        } else if (strstr(lpLibFileName, "game_mp") != NULL) {
            G_Init(pBase);
        }
    }

    return hModule;
}


// CHATGPT
BYTE original_bytes[5];
BYTE* trampoline = NULL; // dynamically allocated

void patch_opcode_loadlibrary(void)
{
    DWORD oldProtect;
    BYTE* pLoadLibrary = (BYTE*)GetProcAddress(GetModuleHandleA("kernel32.dll"), "LoadLibraryA");

    if (!pLoadLibrary)
    {
        printf("Failed to find LoadLibraryA\n");
        return;
    }

    printf("LoadLibraryA address: %p\n", pLoadLibrary);

    // Save original bytes
    memcpy(original_bytes, pLoadLibrary, 5);

    // Allocate trampoline with execute permission
    trampoline = (BYTE*)VirtualAlloc(NULL, 10, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    if (!trampoline)
    {
        printf("Failed to allocate trampoline\n");
        return;
    }

    // Copy original bytes into trampoline
    memcpy(trampoline, original_bytes, 5);

    // Calculate jump back from trampoline+5 to LoadLibraryA+5
    uintptr_t jump_back_addr = (uintptr_t)(pLoadLibrary + 5);
    uintptr_t trampoline_jump_src = (uintptr_t)(trampoline + 5);
    intptr_t rel_jump_back = jump_back_addr - trampoline_jump_src - 5;

    trampoline[5] = 0xE9; // JMP opcode
    *(DWORD*)(trampoline + 6) = (DWORD)rel_jump_back;

    // Set trampoline function pointer
    orig_LoadLibraryA = (LoadLibraryA_t)trampoline;

    // Change protection to writable
    if (!VirtualProtect(pLoadLibrary, 5, PAGE_EXECUTE_READWRITE, &oldProtect))
    {
        printf("VirtualProtect failed\n");
        return;
    }

    // Calculate relative JMP from LoadLibraryA to hLoadLibraryA
    uintptr_t hook_addr = (uintptr_t)hLoadLibraryA;
    uintptr_t loadlib_addr = (uintptr_t)pLoadLibrary;
    intptr_t rel_addr = hook_addr - loadlib_addr - 5;

    pLoadLibrary[0] = 0xE9; // JMP opcode
    *(DWORD*)(pLoadLibrary + 1) = (DWORD)rel_addr;

    // Restore original protection
    if (!VirtualProtect(pLoadLibrary, 5, oldProtect, &oldProtect))
    {
        printf("Failed to restore protection\n");
        return;
    }

    // Flush CPU instruction cache so CPU executes new code
    if (!FlushInstructionCache(GetCurrentProcess(), pLoadLibrary, 5))
    {
        printf("FlushInstructionCache failed\n");
        return;
    }

    printf("Hook installed on LoadLibraryA successfully\n");
}


void _InitMSG() {
    Com_Printf("%s %s build %s %s\n", "CODRA", __RAVERSION__, "win-x86", __DATE__);
}

extern cHook *hook_sv_addoperatorcommands;
extern cHook *hook_CL_UpdatePacketInfo;
extern cHook *hook_CL_ConnectionlessPacket;

extern cHook *hook_CL_PlayDemo_f;
extern cHook *hook_CL_DemoCompleted;
extern cHook *hook_FS_AddCommands;
extern cHook *hook_RE_EndFrame;
extern cHook *hook_CL_Connect_f;
extern cHook *hook_SV_ConnectionlessPacket;

void apply_hooks()
{
	memset((void*)0x5083b1, 0x00, 1); // Alt + Tab fix
	patch_opcode_loadlibrary();



    __call(0x46319B, (int)sub_40E2B0); //cleanup exit
	__call(0x528948, (int)WinMain);
//    __call(0x00411748, (int)Port_Chng);

	// masterlist override
	//memcpy((void*)0x00566120, "", strlen("")+1);
    memcpy((void*)0x00566C18, "1.00.0", strlen("1.00.0")+1);
    // memcpy((void*)0x0055dd78, "CoDRAHost", strlen("CoDRAHost")+1);
    memcpy((void*)0x0055bd4c, "Call of Duty - Risen Arena", strlen("Call of Duty - Risen Arena")+1);
	
    memcpy((void*)0x0563f88, "ra_config_mp.cfg", strlen("ra_config_mp.cfg") + 1);
    memcpy((void*)0x00562784, "exec ra_config_mp.cfg\n", strlen("exec ra_config_mp.cfg\n") + 1);

    PatchStr(0x0055BD28, "CoDRA Console");
    PatchStr(0x0055BD68, "codra.bmp");

    // srv is diff ver
    std::string patchString = std::string("RA ") + __RAVERSION__;
    memcpy((void*)0x00566C18, patchString.c_str(), patchString.size() + 1); // +1 for null terminator    
    
    __call(0x004375E2, (int)_InitMSG);
    __call(0x00437A5E, (int)_InitMSG);

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
    // End GSC

    // CoDExtended "bug fixes"
    // NOP out the calls to CL_Motd (crash upon startup net not loaded and socket being sent or smth)
	__nop(0x40F6DA, 0x40F6DA + 5);
	__nop(0x4117B6, 0x4117B6 + 5);
	
	__nop(0x411815, 1);

	/* annoying bugs */
	__nop(0x42D122, 5); //call Com_AppendCDKey (fixes the invalid cdkey with fs_game)
	__nop(0x40BC18, 5); //fixes spam with "MAX_PACKET_USERCMDS" if you have 1000 fps
	__nop(0x43BA04, 5); //Removing second "Need Paks:" because it's useless one is enough


    __call(0x0042d21a, (int)_FS_Startup);
    __call(0x0042d2d1, (int)_FS_Startup);
    __call(0x0043bb0b, (int)_FS_Startup);

//    __call(0x0042D12A , (int)_FS_AddCommands);
//    __call(0x0042ce3c, (int)_FS_Init);

    __call(0x0045A9BB, (int)_SVC_DirectConnect);

    __call(0x004591B3, (int)SV_Init_Hostname);

    // Auto updater call at CL_Init()
    __jmp(0x411650, (int)CL_CheckAutoUpdate);
    __jmp(0x4117E0, (int)CL_GetAutoUpdate_f);

    // todo: fix client crash when player is already banned and trying to connect to local server


    // q3infoboom fix
    // fixes the buffer overrun crash but the console is still spammed with getinfo requests
    *(unsigned char*)(0x00444EA7) = 1;

    
    // server crack
    // untested
    __nop(0x004531C8, 6); // nop out the Cmd_Argv ptr 
    // mov     edi, dword_890BF8 <- original
    __call(0x004531C8, (int)hook_AuthorizeState); // calling AuthorizeState
    __nop(0x004531C8 + 5, 1); //pad the  extraaaa byte


    // Patch RCON half-second limit //TODO: Do like zk_libcod instead
    /* See:
    - https://aluigi.altervista.org/patches/q3rconz.lpatch
    - https://github.com/ibuddieat/zk_libcod/blob/0f07cacf303d104a0375bf6235b8013e30b668ca/code/libcod.cpp#L3486
    */
    *(unsigned char*)0x45A600 = 0xeb;
    

    // SV_ADdOPFunc 452C50
    hook_sv_addoperatorcommands = new cHook(0x452C50, (int)custom_SV_AddOperatorCommands);
    hook_sv_addoperatorcommands->hook();

    hook_CL_PlayDemo_f = new cHook(0x40E540, (int)custom_CL_PlayDemo_f);
    hook_CL_PlayDemo_f->hook();

    hook_CL_DemoCompleted = new cHook(0x40E920, (int)custom_CL_DemoCompleted);
    hook_CL_DemoCompleted->hook();

    hook_FS_AddCommands = new cHook(0x43BA80, (int)custom_FS_AddCommands);
    hook_FS_AddCommands->hook();

    void custom_CL_UpdatePacketInfo(netadr_t adr); //412F70
    hook_CL_UpdatePacketInfo = new cHook(0x412F70, (int)custom_CL_UpdatePacketInfo);
    hook_CL_UpdatePacketInfo->hook();

    void custom_CL_ConnectionlessPacket(netadr_t from, msg_t* msg);
    hook_CL_ConnectionlessPacket = new cHook(0x4109D0, (int)custom_CL_ConnectionlessPacket);
    hook_CL_ConnectionlessPacket->hook();

    void custom_SV_ConnectionlessPacket(netadr_t from, msg_t* msg);
    hook_SV_ConnectionlessPacket = new cHook(0x45A820, (int)custom_SV_ConnectionlessPacket);
    hook_SV_ConnectionlessPacket->hook();

    char* __cdecl CL_SetServerInfo_HostnameStrncpy(char*, char*, size_t);
    __call(0x412A2C, (int)CL_SetServerInfo_HostnameStrncpy);
    
	void CL_GlobalServers_f(void);
    __jmp(0x413890, (int)CL_GlobalServers_f);

	void _Com_Init(char *commandLine);
    __call(0x004641dc, (int)_Com_Init);



	void _CL_Init();
	__call(0x437B4B, (int)_CL_Init);
	__call(0x438178, (int)_CL_Init);

    void _CL_Frame(int msec);
	__call(0x43822C, (int)_CL_Frame);

//    void _Com_Frame();
//    __call(0x046426F, (int)_Com_Frame);

    hook_RE_EndFrame = new cHook(0x004de4b0, (int)custom_RE_EndFrame);
    hook_RE_EndFrame->hook();

    hook_CL_Connect_f = new cHook(0x0040F6A0, (int)custom_CL_Connect_f);
    hook_CL_Connect_f->hook();



    __jmp(0x459EE0, (int)custom_SVC_Status);

	void _SV_Init();
    __call(0x00437b34, (int)_SV_Init);

    //__call(0x0045A925, (int)SVC_Status); // original SVC_Status

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


    // Custom URL protocol: codra://1.2.3.4 to connect to a server.
    //from cex
	std::string strCmdLine = std::string(lpCmdLine);
	if (strCmdLine.rfind("codra://", 0) == 0) {
		// Remove codra:// and ending slash from string.
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

    // CoD4 Style Demo open with CoDMP support


    void loadRealMSS32();
    loadRealMSS32();

    extern bool miles32_loaded;
    if (!miles32_loaded)
        return 0;

    return WinMain_original(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
}