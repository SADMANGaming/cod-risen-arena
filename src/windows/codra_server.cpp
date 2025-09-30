#include "codra_server.hpp"
#include <fstream>
#include <string>
#include <vector>

SV_DirectConnect_t SV_DirectConnect = (SV_DirectConnect_t)0x453390;
NET_OutOfBandPrint_t NET_OutOfBandPrint = (NET_OutOfBandPrint_t)0x449490;

void _SV_Init()
{
	char* v0 = va("%i", 7);
  	Cvar_Get("protocol", v0, 68);
  	Cvar_Set("protocol", v0);

	void(*SV_Init)();
	* (int*)(&SV_Init) = 0x00459130;
	SV_Init();
}

// HWID BAN LOGIC

bool checkHWIDBan(const std::string& hwidHash) {
    std::ifstream banFile("ban.txt");
    if (!banFile.is_open()) {
        std::ofstream createFile("ban.txt"); // get gud
        createFile.close();
        return false;
    }

    std::string line;
    while (std::getline(banFile, line)) {
        if (line.empty()) continue; // skip empty lines
        if (line == hwidHash) {
            return true;
        }
    }
    return false;
}

void banHWID(const std::string& hwidHash) {
    std::ifstream banFile("ban.txt");
    std::vector<std::string> lines;
    bool alreadyBanned = false;

    if (banFile.is_open()) {
        std::string line;
        while (std::getline(banFile, line)) {
            if (line.empty()) continue;

            lines.push_back(line);

            if (line == hwidHash) {
                alreadyBanned = true; // already in ban list
            }
        }
        banFile.close();
    }

    if (alreadyBanned) {
        Com_Printf("banHWID: HWID already banned: %s\n", hwidHash.c_str());
        return;
    }

    lines.push_back(hwidHash); // add new banned HWID

    std::ofstream outFile("ban.txt", std::ios::trunc);
    if (!outFile.is_open()) {
        Com_Printf("banHWID: Failed to open ban.txt for writing\n");
        return;
    }

    for (const auto& l : lines) {
        outFile << l << "\n";
    }

    Com_Printf("banHWID: Added HWID to ban list: %s\n", hwidHash.c_str());
}


void unbanHWID(const std::string& hwidHash) {
    std::ifstream banFile("ban.txt");
    if (!banFile.is_open()) {
        Com_Printf("unbanHWID: Failed to open ban.txt\n");
        return;
    }

    std::vector<std::string> lines;
    std::string line;

    // Read all lines except the one we want to remove
    while (std::getline(banFile, line)) {
        if (!line.empty() && line != hwidHash) {
            lines.push_back(line);
        }
    }
    banFile.close();

    // Overwrite the file without the banned HWID
    std::ofstream outFile("ban.txt", std::ios::trunc);
    if (!outFile.is_open()) {
        Com_Printf("unbanHWID: Failed to open ban.txt for writing\n");
        return;
    }

    for (const auto& l : lines) {
        outFile << l << "\n";
    }

    Com_Printf("unbanHWID: Removed HWID: %s\n", hwidHash.c_str());
}

void _SVC_DirectConnect(netadr_t from)
{
	char* userinfo = Cmd_Argv(1);
	if (!userinfo) {
    	Com_Printf("Connection rejected: Missing userinfo.\n");
    	return;
	}

	std::string hwid = Info_ValueForKey(userinfo, "cl_hwid");
	if (hwid.empty()) {
		hwid = "unknown";
	}
	if(hwid == "unknown") {
		Com_Printf("Connection from rejected: No HWID provided.\n"/*, NET_AdrToString(from)*/);
		return; // reject connection
	}

	if (checkHWIDBan(hwid)) {
		Com_Printf("Connection from rejected: HWID banned.\n"/*, NET_AdrToString(from)*/);
		NET_OutOfBandPrint(NS_SERVER, from, "print\nYour HWID is banned.\n");
		return; // reject connection
	}

	Com_Printf("Connection accepted from HWID: %s\n", hwid.c_str());

	SV_DirectConnect(from);
}