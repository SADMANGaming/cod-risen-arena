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

cvar_t* cl_running;
cvar_t* com_cl_running;
cvar_t* protocol;
cvar_t* cl_freezeDetect;
cvar_t* cl_hwid;
cvar_t* cg_discord;
cvar_t* cl_master;
cvar_t* devcod_master;

extern cvar_t* fs_basepath;

void _CL_Init(void)
{
	void(*CL_Init)();
	* (int*)(&CL_Init) = 0x411E60;
	CL_Init();

    Cvar_Set("version", va("CoDRA MP 1.00.0 build %d %s %s win-x86", __RABUILD__, __DATE__, __TIME__));

	Cvar_Get("codra-cl", "1", CVAR_USERINFO | CVAR_ROM);

	cl_hwid = Cvar_Get("cl_hwid", generateHWID().c_str(), CVAR_USERINFO | CVAR_ROM);


	com_cl_running = Cvar_Get("cl_running", "0", CVAR_ROM);
	cl_running = Cvar_FindVar("cl_running");
	cl_freezeDetect = Cvar_Get("cl_freezeDetect", "1", CVAR_ARCHIVE);

	cg_discord = Cvar_Get("cg_discord", "1", CVAR_LATCH | CVAR_ARCHIVE);

	cl_master = Cvar_Get("cl_master", "", CVAR_ARCHIVE);
	devcod_master = Cvar_Get("devcod_master", "0", CVAR_ROM);

	Cvar_Set("com_hunkmegs", "512");

	Cvar_Set("sv_hostname", "CoDRAHost");

	Cmd_AddCommand("minimize", Cmd_Minimize);
	Cmd_AddCommand("update", Cmd_Update);

	if (cg_discord->integer)
		CL_DiscordInitialize();
}

void _Com_Init(char *commandLine)
{
	Cvar_Get("shortversion", __RAVERSION__, 68);
	Cvar_Set("shortversion", __RAVERSION__);

	void(*Com_Init)(char *commandLine);
	* (int*)(&Com_Init) = 0x004375c0;
	Com_Init(commandLine);
}

static bool freezeDetectionStarted = false;
void _CL_Frame(int msec) {
    void(*call)(int);
    *(DWORD*)&call = 0x411280;

    if (!cl_running->integer)
        return;


    if (cl_freezeDetect->integer == 1 && !freezeDetectionStarted) {
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