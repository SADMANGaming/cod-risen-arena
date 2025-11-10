#include <windows.h>
#include <string>
#include <fstream>
#include "auto_updater.hpp"
#include "hooks.hpp"
#include "functions.hpp"
#include <wininet.h>
#include <iostream>
#include <shlwapi.h>

const char* updateAvailableNumber = NULL;
const char* files;
int isUpdateablevar;
netadr_t autoUpdater_adr;
int checkingForUpdate = 0;

void CL_CheckAutoUpdate() //Run in Com_Init or somewhere???????????
{
    char command[1024];
    checkingForUpdate = 1;

    Com_Printf("Auto-Updater: Checking for updates...\n");

    if (!NET_StringToAdr("raupdate.duckdns.org", &autoUpdater_adr)) {
        Com_Printf("Auto-Updater: Couldn't resolve auto updater URL\n");
        return;
    }
    
    short BigShort(short);
	autoUpdater_adr.type = NA_IP;
	autoUpdater_adr.port = BigShort(20560);

    
    Com_Printf("Auto-Updater resolved to %d.%d.%d.%d:%d\n",
               autoUpdater_adr.ip[0], 
               autoUpdater_adr.ip[1], 
               autoUpdater_adr.ip[2], 
               autoUpdater_adr.ip[3], 
               ntohs(autoUpdater_adr.port)
            );

    sprintf(command, "getUpdateInfo \"%s\" \"win-x86\" \"client\"", __RAVERSION__);
    
    NET_OutOfBandPrint(NS_CLIENT, autoUpdater_adr, command);
    checkingForUpdate = 0;
}


cHook * hook_CL_UpdatePacketInfo;
void custom_CL_UpdatePacketInfo(netadr_t adr)
{
    hook_CL_UpdatePacketInfo->unhook();
    void (*CL_UpdatePacketInfo)(netadr_t adr);
    *(int *)&CL_UpdatePacketInfo = hook_CL_UpdatePacketInfo->from;
    CL_UpdatePacketInfo(adr);

    if(autoUpdater_adr.type == NA_BAD)
    {
        Com_Printf("Auto-Updater has bad address\n");
        return;
    }

    if(!NET_CompareBaseAdr(autoUpdater_adr, adr))
    {
        Com_DPrintf("Received update packet from unexpected IP.\n");
        return;
    }

    Com_Printf("Auto-Updater response from %s\n", NET_AdrToString(adr));
    
    updateAvailableNumber = Cmd_Argv(3);    // Version or status
    isUpdateablevar = atoi(Cmd_Argv(1));//atoi(Cmd_Argv(1));
    files = Cmd_Argv(2);

    Cvar_Set("cl_updateavailable", Cmd_Argv(1));
    Cvar_Set("cl_updateversion", updateAvailableNumber);
    Cvar_Set("cl_updatefiles", files);
}
////// UDP END


const char* isUpdateable()
{  
    if (isUpdateablevar == 1 || isUpdateablevar == 2) {
        return "1"; // Update available
    } else {
        return "0"; // Up to date or older
    }
}

const char* getLatestUpdate()
{
    if(updateAvailableNumber)
    {
        return updateAvailableNumber;
    } else {
        return "None";
    }
}

bool DownloadFile(const std::string& url, const std::string& outFile) {
    HINTERNET hInternet = InternetOpenA("CoD:Risen Arena", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
    if (!hInternet) {
        DWORD err = GetLastError();
        std::cout << "InternetOpenA failed: " << err << "\n";
        return false;
    }

    HINTERNET hFile = InternetOpenUrlA(
        hInternet,
        url.c_str(),
        NULL,
        0,
        INTERNET_FLAG_RELOAD | INTERNET_FLAG_SECURE,
        0
    );

    if (!hFile) {
        DWORD err = GetLastError();
        std::cout << "InternetOpenUrlA failed: " << err << "\n";
        InternetCloseHandle(hInternet);
        return false;
    }

    FILE* fp = fopen(outFile.c_str(), "wb");
    if (!fp) {
        std::cout << "Failed to open output file: " << outFile << "\n";
        InternetCloseHandle(hFile);
        InternetCloseHandle(hInternet);
        return false;
    }

    char buffer[4096];
    DWORD bytesRead = 0;

    while (true) {
        BOOL res = InternetReadFile(hFile, buffer, sizeof(buffer), &bytesRead);
        if (!res) {
            DWORD err = GetLastError();
            std::cout << "InternetReadFile failed: " << err << "\n";
            break;
        }
        if (bytesRead == 0) break; // download finished
        fwrite(buffer, 1, bytesRead, fp);
        std::cout << "Downloaded " << bytesRead << " bytes\n";
    }

    fclose(fp);
    InternetCloseHandle(hFile);
    InternetCloseHandle(hInternet);

    return true;
}


bool stat_updating = false;
void CL_GetAutoUpdate_f()
{
    stat_updating = true;

    std::string updateUrl = Cvar_VariableString("cl_updatefiles");
    if (updateUrl.empty()) {
        Com_Printf("Auto-Updater: Files missing\n");
        return;
    }

    DownloadFile(updateUrl, "update.zip");

    if (UnzipWithPowerShell("update.zip", ".")) {
        remove("update.zip");
        char path[MAX_PATH];
        GetModuleFileNameA(NULL, path, MAX_PATH);
        PathRemoveFileSpecA(path);
        strcat(path, "\\CoDMP.exe");
        remove("__CoDMP");
        // Run via cmd so process is independent
        ShellExecuteA(NULL, "open", "cmd.exe", (std::string("/c start \"\" \"") + path + "\"").c_str(), NULL, SW_SHOWNORMAL);
        ExitProcess(0);
    }

    stat_updating = false;
}

bool UnzipWithPowerShell(const char* zipPath, const char* destPath) {
    std::string cmd = "powershell.exe -NoProfile -Command \"Expand-Archive -Path '";
    cmd += zipPath;
    cmd += "' -DestinationPath '";
    cmd += destPath;
    cmd += "' -Force\"";

    STARTUPINFOA si = { sizeof(si) };
    PROCESS_INFORMATION pi;

    if (!CreateProcessA(
        NULL,
        cmd.data(), // command line
        NULL,
        NULL,
        FALSE,
        CREATE_NO_WINDOW,
        NULL,
        NULL,
        &si,
        &pi
    )) {
        DWORD err = GetLastError();
        std::cout << "Failed to run PowerShell: " << err << "\n";
        return false;
    }

    // Wait until unzip finishes
    WaitForSingleObject(pi.hProcess, INFINITE);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return true;
}