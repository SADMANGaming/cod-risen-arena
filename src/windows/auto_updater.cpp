#include <windows.h>
#include <string>
#include <fstream>
#include "auto_updater.hpp"
#include "functions.hpp"
#include <wininet.h>
#include <iostream>
#include <shlwapi.h>


std::string findValue(const std::string& json, const std::string& key) {
    size_t pos = json.find("\"" + key + "\"");
    if (pos == std::string::npos) return "";

    pos = json.find(":", pos);
    if (pos == std::string::npos) return "";

    size_t start = json.find_first_not_of(" \t\n\r", pos + 1);

    if (json[start] == '"') {
        size_t end = json.find("\"", start + 1);
        return json.substr(start + 1, end - start - 1);
    } else {
        size_t end = json.find_first_of(",}", start);
        return json.substr(start, end - start);
    }
}


std::string HttpGet(const char* url) {
    HINTERNET hInternet = InternetOpenA("CoD:Risen Arena", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
    if (!hInternet) return "";

    HINTERNET hConnect = InternetOpenUrlA(hInternet, url, NULL, 0, INTERNET_FLAG_RELOAD, 0);
    if (!hConnect) {
        InternetCloseHandle(hInternet);
        return "";
    }

    char buffer[4096];
    DWORD bytesRead;
    std::string result;

    while (InternetReadFile(hConnect, buffer, sizeof(buffer), &bytesRead) && bytesRead != 0) {
        result.append(buffer, bytesRead);
    }

    InternetCloseHandle(hConnect);
    InternetCloseHandle(hInternet);

    return result;
}
bool stat_updating = false;

void Cmd_Update() {
    stat_updating = true;
    std::string json = HttpGet("https://devcod.pages.dev/update/ra/current_ver.json");
    if (json.empty()) {
        MessageBoxA(NULL, "Failed to contact update server.", "Updater", MB_OK | MB_ICONERROR);
        return;
    }

    std::string buildStr = findValue(json, "build");
    std::string nameStr  = findValue(json, "name");
    int serverBuild = atoi(buildStr.c_str());

    if (serverBuild == __RABUILD__) {
        MessageBoxA(NULL, "You are running the latest version!", "Updater", MB_OK | MB_ICONINFORMATION);
    } else {
        char msg[512];
        sprintf(msg, "New update found:\nName: %s\nBuild: %d\n\nDo you want to update?",
                nameStr.c_str(), serverBuild);

        int choice = MessageBoxA(NULL, msg, "Update Available", MB_YESNO | MB_ICONQUESTION);

        if (choice == IDYES) {
            std::string updateUrl = findValue(json, "url");
            if (updateUrl.empty()) {
                MessageBoxA(NULL, "Update URL missing in server JSON.", "Updater", MB_OK | MB_ICONERROR);
                return;
            }

            HINTERNET hInternet = InternetOpenA("CoD:Risen Arena", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
            HINTERNET hFile = InternetOpenUrlA(hInternet, updateUrl.c_str(), NULL, 0, INTERNET_FLAG_RELOAD, 0);

            FILE* fp = fopen("update.zip", "wb");
            if (hFile && fp) {
                char buffer[4096];
                DWORD bytesRead;
                while (InternetReadFile(hFile, buffer, sizeof(buffer), &bytesRead) && bytesRead != 0) {
                    fwrite(buffer, 1, bytesRead, fp);
                }
                fclose(fp);
                InternetCloseHandle(hFile);
                UnzipWithPowerShell("update.zip", ".");

            if (remove("update.zip") == 0) {
                char path[MAX_PATH];
                GetModuleFileNameA(NULL, path, MAX_PATH);
                PathRemoveFileSpecA(path);
                strcat(path, "\\CoDMP.exe");
                remove("__CoDMP");
                // Run via cmd so process is independent
                ShellExecuteA(NULL, "open", "cmd.exe", (std::string("/c start \"\" \"") + path + "\"").c_str(), NULL, SW_SHOWNORMAL);
                ExitProcess(0);
            }


                MessageBoxA(NULL, "Update downloaded! Please restart the game to install.", "Updater", MB_OK | MB_ICONINFORMATION);
            }

            InternetCloseHandle(hInternet);
        }
    }
    stat_updating = false;
}

void UnzipWithPowerShell(const char* zipPath, const char* destPath) {
    char cmd[1024];
    sprintf(cmd, "powershell -Command \"Expand-Archive -Path '%s' -DestinationPath '%s' -Force\"", zipPath, destPath);
    system(cmd);
}
