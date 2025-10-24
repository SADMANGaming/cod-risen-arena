#include "functions.hpp"
#include "cl_commands.hpp"
#include "codra_client.hpp"
#include "freeze_detector.hpp"
#include "auto_updater.hpp"
#include "hwid.hpp"
#include "hooks.hpp"
#include "discord.hpp"
#include <thread>
#include <iostream>
#include <chrono>
#include <fstream>

cvar_t* cl_running;
cvar_t* com_cl_running;
cvar_t* cl_freezeDetect;
cvar_t* cl_hwid;
cvar_t* cg_discord;
cvar_t* cl_master;
cvar_t* devcod_master;
cvar_t* cl_uid;

cvar_t* cl_updateavailable;
cvar_t* cl_updateversion;
cvar_t* cl_updateoldversion;
cvar_t* cl_updatefiles;

extern cvar_t* fs_basepath;

void _CL_Init(void)
{
	CL_UpdateReq();

	cl_updateavailable = Cvar_Get("cl_updateavailable", /*isUpdateable()*/"0", 64);
  	cl_updateoldversion = Cvar_Get("cl_updateoldversion", __RAVERSION__, 64);
  	cl_updateversion = Cvar_Get("cl_updateversion", /*getLatestUpdate()*/"None", 64);
	cl_updatefiles = Cvar_Get("cl_updatefiles", "None", 64);

	void(*CL_Init)();
	* (int*)(&CL_Init) = 0x411E60;
	CL_Init();

    Cvar_Set("version", va("CoDRA MP %s build %d %s %s win-x86", __RAVERSION__, __RABUILD__, __DATE__, __TIME__));

	Cvar_Get("codra-cl", "1", CVAR_USERINFO | CVAR_ROM);

	cl_hwid = Cvar_Get("cl_hwid", generateHWID().c_str(), CVAR_USERINFO | CVAR_ROM);


	com_cl_running = Cvar_Get("cl_running", "0", CVAR_ROM);
	cl_running = Cvar_FindVar("cl_running");
	cl_freezeDetect = Cvar_Get("cl_freezeDetect", "1", CVAR_ARCHIVE);

	cg_discord = Cvar_Get("cg_discord", "1", CVAR_LATCH | CVAR_ARCHIVE);

	cl_master = Cvar_Get("cl_master", "", CVAR_ARCHIVE);
	devcod_master = Cvar_Get("devcod_master", "0", CVAR_ROM);

	cl_uid = Cvar_Get("cl_uid", std::to_string(CL_GetCDKeyHash()).c_str(), CVAR_ARCHIVE | CVAR_ROM | CVAR_USERINFO);

	// UPDATER
  	//Cvar_Get("cl_updatefiles", &String, 64);

	Cvar_Set("com_hunkmegs", "512");

	Cvar_Set("sv_hostname", "CoDRAHost");

	Cmd_AddCommand("minimize", Cmd_Minimize);
	Cmd_AddCommand("getautoupdate", Cmd_Update);

	if (cg_discord->integer)
		CL_DiscordInitialize();
// period
}

cvar_t *sv_running;
cvar_t *mapname;
cvar_t *sv_maxclients;
void _Com_Init(char *commandLine)
{
	Cvar_Get("shortversion", __RAVERSION__, 68);
	Cvar_Set("shortversion", __RAVERSION__);


	void(*Com_Init)(char *commandLine);
	* (int*)(&Com_Init) = 0x004375c0;
	Com_Init(commandLine);

    sv_running = Cvar_FindVar("sv_running");
	mapname = Cvar_FindVar("mapname");
	sv_maxclients = Cvar_FindVar("sv_maxclients");

	Cvar_Set("nextmap", "cinematic devcod_logo.roq");
}

static bool freezeDetectionStarted = false;
void _CL_Frame(int msec) {
    void(*call)(int);
    *(DWORD*)&call = 0x411280;

    if (!cl_running->integer)
        return;


    if (cl_freezeDetect->integer == 1 && !freezeDetectionStarted && *cls_state == 6) {
        InitFreezeDetection();
        freezeDetectionStarted = true;
    }

    if (cl_freezeDetect->integer == 1) {
        OnFrame();
    }

	if (cg_discord->integer)
		CL_DiscordFrame();

	call(msec);
}

void _Com_Frame()
{
    //void(*call)();
    //*(DWORD*)&call = 0x437F40;

	if (cl_freezeDetect->integer == 1 && !freezeDetectionStarted) {
        InitFreezeDetection();
        freezeDetectionStarted = true;
    }

    if (cl_freezeDetect->integer == 1) {
        OnFrame();
    }
}


char* __cdecl CL_SetServerInfo_HostnameStrncpy(char* a1, char* a2, size_t a3) {
	return strncpy(a1, Com_CleanHostname(a2, true), a3);
}

void CL_GlobalServers_f(void) {
	if (Cmd_Argc() < 3) {
		Com_Printf("usage: globalservers <master# 0-1> <protocol> [keywords]\n");
		return;
	}

	Com_Printf("Master: %s, Protocol: %s\n", Cmd_Argv(1), Cmd_Argv(2));

	netadr_t to;
	int i;
	int count;
	char* buffptr;
	char command[1024];

	*cls_numglobalservers = -1;
	*cls_pingUpdateSource = 1;

	if (devcod_master->integer) {
		//if (NET_StringToAdr("cod.pm", &to)) {
		//	Com_Printf("Requesting servers from CoD 1.1x master...\n");
		//}
		Com_Printf("The masterserver is not implemented yet\n");
	}

	if(cl_master->string && cl_master->string[0] != '\0')
	{
		if (NET_StringToAdr(cl_master->string, &to)) {
			Com_Printf("Requesting servers from %s...\n", cl_master->string);
		}
	} else {
		if (NET_StringToAdr("codmaster.activision.com", &to)) {
			Com_Printf("Requesting servers from codmaster.activision.com...\n");
		}
	}

	short BigShort(short);
	to.type = NA_IP;
	to.port = BigShort(20510);

	sprintf(command, "getservers %s", Cmd_Argv(2));

	buffptr = command + strlen(command);
	count = Cmd_Argc();
	for (i = 3; i < count; i++)
		buffptr += sprintf(buffptr, " %s", Cmd_Argv(i));

	NET_OutOfBandPrint(NS_SERVER, to, command);
}


uint64_t CL_GetCDKeyHash()
{
    std::ifstream f("main/codkey", std::ios::binary);
    if (!f.is_open()) return 0;

    std::string line, cdkey;
    while (std::getline(f, line)) {
        // trim
        line.erase(0, line.find_first_not_of(" \t\r\n"));
        line.erase(line.find_last_not_of(" \t\r\n") + 1);
        if (line.empty() || line.rfind("//", 0) == 0) continue;
        cdkey = line;
        break;
    }
    if (cdkey.empty()) return 0;

    std::string sha = hashSHA256(cdkey);
    uint64_t val = 0;
    for (int i = 0; i < 16; i += 2) {
        uint8_t byte = static_cast<uint8_t>(std::stoul(sha.substr(i, 2), nullptr, 16));
        val = (val << 8) | byte;
    }
    return val % 1000000000000000ULL;
}


cHook* hook_CL_ConnectionlessPacket;

void custom_CL_ConnectionlessPacket(netadr_t from, msg_t* msg)
{
    hook_CL_ConnectionlessPacket->unhook();
    void (*CL_ConnectionlessPacket)(netadr_t from, msg_t* msg);
    *(int *)&CL_ConnectionlessPacket = hook_CL_ConnectionlessPacket->from;
    CL_ConnectionlessPacket(from, msg);
/*
    Com_Printf("=== CONNECTIONLESS PACKET RECEIVED ===\n");
    Com_Printf("From: %s\n", NET_AdrToString(from));
    //Com_Printf("Raw packet payload: %s\n", buffer);


    const char *cmdx = (const char *)msg->data;
    Cmd_TokenizeString(cmdx, 0);

    const char* cmd = Cmd_Argv(0);
    Com_Printf("Arg count: %d\n", Cmd_Argc());

    Com_Printf("Command: %s\n", cmd ? cmd : "NULL");

    for (int i = 0; i < Cmd_Argc(); i++)
    {
        const char* arg = Cmd_Argv(i);
        Com_Printf("Arg %d: %s\n", i, arg ? arg : "NULL");
    }

    // Only handle updateResponse
    if (Q_stricmp(cmd, "updateResponse") == 0) {
        const char* arg1 = Cmd_Argv(1);
        const char* arg2 = Cmd_Argv(2);
        const char* arg3 = Cmd_Argv(3);

        Com_Printf("***** UPDATE RESPONSE DETECTED! *****\n");
        Com_Printf("Arg1: %s\n", arg1 ? arg1 : "NULL");
        Com_Printf("Arg2: %s\n", arg2 ? arg2 : "NULL");
        Com_Printf("Arg3: %s\n", arg3 ? arg3 : "NULL");

        // If you have a handler function, call it here:
        // CL_UpdateInfoPacket(from, buffer);
    }
        */
}
