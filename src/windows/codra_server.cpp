#include "codra_server.hpp"
#include <fstream>
#include <string>
#include <vector>
#include "hooks.hpp"
#include "functions.hpp"
#include "hwid.hpp"

cvar_t *dedicated;
cvar_t *protocol;
cvar_t *sv_hostname;
cvar_t *sv_cracked;

SV_DirectConnect_t SV_DirectConnect = (SV_DirectConnect_t)0x453390;
NET_OutOfBandPrint_t NET_OutOfBandPrint = (NET_OutOfBandPrint_t)0x449490;

void _SV_Init()
{
	char* v0 = va("%i", 7);
  	protocol = Cvar_Get("protocol", v0, 68); //CVAR_
  	Cvar_Set("protocol", v0);
    sv_cracked = Cvar_Get("sv_cracked", "0", CVAR_ARCHIVE);

	void(*SV_Init)();
	* (int*)(&SV_Init) = 0x00459130;
	SV_Init();
}

void SV_Init_Hostname()
{
    sv_hostname = Cvar_Get("sv_hostname", "CoDRAHost", CVAR_SERVERINFO | CVAR_ARCHIVE);
}

const char* hook_AuthorizeState(int arg)
{
    const char* s = Cmd_Argv(arg);
    if(sv_cracked->integer && !strcmp(s, "deny"))
        return "accept";
    return s;
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

std::string AdrToStringKey(const netadr_t &adr)
{
    return std::string(NET_AdrToString(adr));
}

extern cvar_t *sv_running;
extern cvar_t *mapname;
extern cvar_t *sv_maxclients;

static void SV_zzStatus_f( void )
{
	int i, j, l;
	client_t    *cl;
	const char      *s;
	int ping;

	// make sure server is running
	if ( !sv_running->integer )
	{
		Com_Printf( "Server is not running.\n" );
		return;
	}

	Com_Printf( "map: %s\n", mapname->string );

	Com_Printf( "num ping uid             name            lastmsg ip\n" );
	Com_Printf( "--- ---- --------------- --------------- ------- ---------------------\n" );
	for ( i = 0 ; i < sv_maxclients->integer; i++ )
	{
        cl = &svs.clients[i];

        if (!cl)
            continue;

        if (cl->state != CS_CONNECTED && cl->state != CS_ACTIVE)
            continue;

		Com_Printf( "%3i ", i ); //num
		if ( cl->state == CS_CONNECTED )
		{
			Com_Printf( "CNCT " );
		}
		else if ( cl->state == CS_ZOMBIE )
		{
			Com_Printf( "ZMBI " );
		}
		else
		{
			ping = cl->ping < 9999 ? cl->ping : 9999;
			Com_Printf( "%4i ", ping );
		}

		Com_Printf( "%15s ", Info_ValueForKey( cl->userinfo, "cl_uid" ) ); //uid
		Com_Printf( "%s^7", cl->name );
		l = 16 - strlen( cl->name );
		for ( j = 0 ; j < l ; j++ )
			Com_Printf( " " );

		Com_Printf( "%7i ", svs.time - cl->lastPacketTime );

		s = NET_AdrToString( cl->netchan.remoteAddress );
		Com_Printf( "%s", s );
		l = 22 - strlen( s );
		for ( j = 0 ; j < l ; j++ )
			Com_Printf( " " );

		Com_Printf( "\n" );
	}
	Com_Printf( "\n" );
}


void custom_SVC_Status(netadr_t from)
{
    char player[1024];           // single player line buffer
    char infostring[16384] = {0}; // big server info buffer
    char keywords[1024];          // keywords buffer
    char status[16384] = {0};     // big status buffer for all players
    unsigned int statusLength = 0;
    size_t playerLength = 0;
    int i;
    client_t *cl;
    const char *g_password;
    const char *fs_game;

    strcpy(infostring, Cvar_InfoString_RAH(CVAR_SERVERINFO));
    
    Info_SetValueForKey(infostring, "challenge", Cmd_Argv(1));


    if (Cvar_VariableValue("fs_restrict"))
    {
        Com_sprintf(keywords, sizeof(keywords), "demo %s", Info_ValueForKey(infostring, "sv_keywords"));
        Info_SetValueForKey(infostring, "sv_keywords", keywords);
    }

    for (i = 0; i < sv_maxclients->integer; i++)
    {
        cl = &svs.clients[i];
        if (cl->state >= CS_CONNECTED)
        {
            if (!cl->gentity || !cl->gentity->client || !cl->name)
                continue; // skip invalid entries

            Com_sprintf(player, sizeof(player), "%i %i \"%s\" \"%s\"\n",
                cl->gentity->client->sess.score,
                cl->ping,
                cl->name,
                Info_ValueForKey(cl->userinfo, "cl_uid"));

            playerLength = strlen(player);
            if (statusLength + playerLength >= sizeof(status))
                break; // avoid overflow

            strcpy(status + statusLength, player);
            statusLength += playerLength;
        }
    }
    fs_game = Cvar_VariableString("fs_game");
    g_password = Cvar_VariableString("g_password");
    Info_SetValueForKey(infostring, "pswrd", va("%i", *g_password ? 1 : 0));

    Info_SetValueForKey(infostring, "fs_game", va("%s", *fs_game ? fs_game : "0"));

    NET_OutOfBandPrint(NS_SERVER, from, "statusResponse\n%s\n%s", infostring, status);

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
    Cmd_RemoveCommand("status");
    Cmd_AddCommand("status", SV_zzStatus_f);

    hook_sv_addoperatorcommands->hook();
}

void _SVC_DirectConnect(netadr_t from)
{
	char* userinfo = Cmd_Argv(1);
	if (!userinfo) {
    	Com_Printf("Connection rejected: Missing userinfo.\n");
    	return;
	}
    std::string patchString = std::string("RA ") + __RAVERSION__;
	std::string hwid = Info_ValueForKey(userinfo, "cl_hwid");
    std::string uid = Info_ValueForKey(userinfo, "cl_uid");
    const char* protocolcl = Info_ValueForKey(userinfo, "protocol");
	int qport = atoi( Info_ValueForKey( userinfo, "qport" ) );

    // if (strcmp(protocolcl, protocol->string) != 0)
    // {
    //     Com_Printf("Connection rejected from a client with protocol: %s\n", protocolcl);
    // 	NET_OutOfBandPrint( NS_SERVER, from, va("error\nEXE_SERVER_IS_DIFFERENT_VER\x15%s\nVisit: devcod.pages.dev for more info about Risen Arena mod\n", patchString.c_str()) );
    //     return;
    // }
    

    if(atoi(protocolcl) != protocol->integer)
    {
        const char* msg;
        switch (atoi(protocolcl))
        {
            case 1: msg = "Your CoD1 version is 1.1\nYou need CoD1.1 and CoDRA\nVisit: devcod.pages.dev for more info about Risen Arena mod\n"; break;
            case 2: msg = "Your CoD1 version is 1.2\nYou need CoD1.1 and CoDRA\nVisit: devcod.pages.dev for more info about Risen Arena mod\n"; break;
            case 3: msg = "Your CoD1 version is 1.3\nYou need CoD1.1 and CoDRA\nVisit: devcod.pages.dev for more info about Risen Arena mod\n"; break;
            case 4: msg = "Your CoD1 version is 1.3 beta\nYou need CoD1.1 and CoDRA\nVisit: devcod.pages.dev for more info about Risen Arena mod\n"; break;
            case 5: msg = "Your CoD1 version is 1.4\nYou need CoD1.1 and CoDRA\nVisit: devcod.pages.dev for more info about Risen Arena mod\n"; break;
            case 6: msg = "Your CoD1 version is 1.5\nYou need CoD1.1 and CoDRA\nVisit: devcod.pages.dev for more info about Risen Arena mod\n"; break;
            default: msg = "Your CoD1 version is unknown\nYou need CoD1.1 and CoDRA\nVisit: devcod.pages.dev for more info about Risen Arena mod\n"; break;

        }
        Com_DPrintf("    rejected connect from protocol version %i (should be %i)\n", atoi(protocolcl), protocol->integer);
        NET_OutOfBandPrint( NS_SERVER, from, va("error\nEXE_SERVER_IS_DIFFERENT_VER\x15%s\n%s\n", patchString.c_str(), msg) );
        return;
    }

	if (hwid.empty())
    {
		hwid = "unknown";
	}

    if(uid.empty())
    {
        uid = "unknown";
    }

	if(hwid == "unknown" || !isValidSHA256(hwid))
    {
		Com_Printf("Connection rejected: HWID is wrong.\n"/*, NET_AdrToString(from)*/);
	    NET_OutOfBandPrint( NS_SERVER, from, "error\nDVCODEXE_INVALIDHWID\x15\n");	
		return; // reject connection
	}

	if(uid == "unknown")
    {
		Com_Printf("Connection rejected: UID is wrong.\n"/*, NET_AdrToString(from)*/);
	    NET_OutOfBandPrint( NS_SERVER, from, "error\nDVCODEXE_INVALIDUID\x15\n");	
		return; // reject connection
	}

	if (checkHWIDBan(hwid))
    {
		Com_Printf("Connection from rejected: HWID banned.\n"/*, NET_AdrToString(from)*/);
	    NET_OutOfBandPrint( NS_SERVER, from, "error\nDVCODEXE_HWIDBANNED\x15\n");	
		return; // reject connection
	}

	Com_Printf("Connection accepted from UID: %s\n", uid.c_str());


	SV_DirectConnect(from);
}


cHook* hook_SV_ConnectionlessPacket;
void custom_SV_ConnectionlessPacket(netadr_t from, msg_t* msg)
{
    hook_SV_ConnectionlessPacket->unhook();
    void (*SV_ConnectionlessPacket)(netadr_t from, msg_t* msg);
    *(int *)&SV_ConnectionlessPacket = hook_SV_ConnectionlessPacket->from;
    SV_ConnectionlessPacket(from, msg);
    hook_SV_ConnectionlessPacket->hook();

    const char *cmdx = (const char *)msg->data;
    std::string adrKey = AdrToStringKey(from);

    //Cmd_TokenizeString(cmdx, 0);

    const char* cmd = Cmd_Argv(0);

    if (Q_stricmp(cmd, "uidResponse") == 0)
	{
    }

	if(Q_stricmp(cmd, "hwidResponse") == 0)
	{
	}
}
