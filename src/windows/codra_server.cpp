#include "codra_server.hpp"
#include <fstream>
#include <string>
#include <vector>
#include "hooks.hpp"
#include "functions.hpp"

cvar_t *dedicated;
SV_DirectConnect_t SV_DirectConnect = (SV_DirectConnect_t)0x453390;
NET_OutOfBandPrint_t NET_OutOfBandPrint = (NET_OutOfBandPrint_t)0x449490;

void _SV_Init()
{
	char* v0 = va("%i", 7);
  	Cvar_Get("protocol", v0, 68); //CVAR_
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
        Com_Printf("SV_BanHWID: HWID already banned: %s\n", hwidHash.c_str());
        return;
    }

    lines.push_back(hwidHash); // add new banned HWID

    std::ofstream outFile("ban.txt", std::ios::trunc);
    if (!outFile.is_open()) {
        Com_Printf("SV_BanHWID: Failed to open ban.txt for writing\n");
        return;
    }

    for (const auto& l : lines) {
        outFile << l << "\n";
    }

    Com_Printf("SV_BanHWID: Added HWID to ban list: %s\n", hwidHash.c_str());
}


void unbanHWID(const std::string& hwidHash) {
    std::ifstream banFile("ban.txt");
    if (!banFile.is_open()) {
        Com_Printf("SV_UnbanHWID: Failed to open ban.txt\n");
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
        Com_Printf("SV_UnbanHWID: Failed to open ban.txt for writing\n");
        return;
    }

    for (const auto& l : lines) {
        outFile << l << "\n";
    }

    Com_Printf("SV_UnbanHWID: Removed HWID: %s\n", hwidHash.c_str());
}
// End of HWID

void Cmd_Ban() {
    const char* arg = Cmd_Argv(1);
    const char* reason = Cmd_Argv(2);

    if (!arg || arg[0] == '\0') {
        Com_Printf("Usage: ban <client id> <reason>\n");
        return;
    }

    int cl = atoi(arg);
    if (cl < 0 || cl >= 64) {
        Com_Printf("Invalid client id: %s\n", arg);
        return;
    }

    client_t* client = SV_GetPlayerByNum();
    if (!client) {
        Com_Printf("Client with id %d not found.\n", cl);
        return;
    }

    const char* hwid = Info_ValueForKey(client->userinfo, "cl_hwid");
    if (!hwid || hwid[0] == '\0') {
        Com_Printf("Client %d has no HWID.\n", cl);
        return;
    }

    std::string hwidStr(hwid);
    banHWID(hwidStr);

    if (reason && reason[0] != '\0') {
        SV_DropClient(client, reason);
    } else {
        SV_DropClient(client, NULL);
    }

    Com_Printf("Client %d's HWID '%s' has been banned with reason '%s'.\n", cl, hwid, reason ? reason : "No reason");
}


void Cmd_Unban() {
    const char* hwid = Cmd_Argv(1);

    if (!hwid || hwid[0] == '\0') {
        Com_Printf("Usage: unban <hwid>\n");
        return;
    }

    std::string hwidStr(hwid);
    unbanHWID(hwidStr);

    Com_Printf("Client HWID '%s' has been unbanned.\n", hwid);
}



cHook *hook_sv_addoperatorcommands;
void custom_SV_AddOperatorCommands()
{
    hook_sv_addoperatorcommands->unhook();
    void (*SV_AddOperatorCommands)();
    *(int *)&SV_AddOperatorCommands = hook_sv_addoperatorcommands->from;
    SV_AddOperatorCommands();

    Cmd_AddCommand("ban", Cmd_Ban);
    Cmd_AddCommand("unban", Cmd_Unban);

    hook_sv_addoperatorcommands->hook();
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