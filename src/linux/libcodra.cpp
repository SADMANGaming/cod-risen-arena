#include <map> // make_tuple, get, array, 
#include <sstream> // ostringstream
#include <vector>

#include <signal.h>
#include <arpa/inet.h> // sockaddr_in, inet_pton
#include <execinfo.h> // backtrace
#include <dlfcn.h> // dlsym
#include <sys/time.h> // gettimeofday
#include <array>
#include <string>
#include <fstream>
#include <regex>
#include "libcodra.hpp"

#include "hooks.hpp"
#include "shared.hpp"

// Stock cvars
cvar_t *com_cl_running;
cvar_t *com_dedicated;
cvar_t *com_logfile;
cvar_t *com_sv_running;
cvar_t *fs_game;
cvar_t *sv_allowDownload;
cvar_t *sv_floodProtect;
cvar_t *sv_fps;
cvar_t *sv_gametype;
cvar_t *sv_mapRotation;
cvar_t *sv_mapRotationCurrent;
cvar_t *sv_maxclients;
cvar_t *sv_maxRate;
cvar_t *sv_pure;
cvar_t *sv_rconPassword;
cvar_t *sv_serverid;
cvar_t *sv_showAverageBPS;
cvar_t *sv_showCommands;
cvar_t *protocol;
cvar_t *mapname;
cvar_t *fs_restrict;
cvar_t *sv_hostname;
cvar_t *fs_basegame;

// custom
cvar_t *sv_cracked;

// Game lib objects
gentity_t *g_entities;
gclient_t *g_clients;
level_locals_t *level;
pmove_t **pm;
pml_t *pml;
stringIndex_t *scr_const;

// Game lib functions
G_Say_t G_Say;
G_RegisterCvars_t G_RegisterCvars;
G_AddEvent_t G_AddEvent;
G_AddPredictableEvent_t G_AddPredictableEvent;
trap_SendServerCommand_t trap_SendServerCommand;
trap_GetConfigstringConst_t trap_GetConfigstringConst;
trap_GetConfigstring_t trap_GetConfigstring;
BG_GetNumWeapons_t BG_GetNumWeapons;
BG_GetInfoForWeapon_t BG_GetInfoForWeapon;
BG_GetWeaponIndexForName_t BG_GetWeaponIndexForName;
BG_AnimationIndexForString_t BG_AnimationIndexForString;
BG_AnimScriptEvent_t BG_AnimScriptEvent;
Scr_GetFunctionHandle_t Scr_GetFunctionHandle;
Scr_GetNumParam_t Scr_GetNumParam;
Scr_IsSystemActive_t Scr_IsSystemActive;
Scr_GetInt_t Scr_GetInt;
Scr_GetString_t Scr_GetString;
Scr_GetType_t Scr_GetType;
Scr_GetEntity_t Scr_GetEntity;
Scr_AddBool_t Scr_AddBool;
Scr_AddInt_t Scr_AddInt;
Scr_AddFloat_t Scr_AddFloat;
Scr_AddString_t Scr_AddString;
Scr_AddUndefined_t Scr_AddUndefined;
Scr_AddVector_t Scr_AddVector;
Scr_MakeArray_t Scr_MakeArray;
Scr_AddArray_t Scr_AddArray;
Scr_AddObject_t Scr_AddObject;
Scr_LoadScript_t Scr_LoadScript;
Scr_ExecThread_t Scr_ExecThread;
Scr_ExecEntThread_t Scr_ExecEntThread;
Scr_ExecEntThreadNum_t Scr_ExecEntThreadNum;
Scr_FreeThread_t Scr_FreeThread;
Scr_GetFunction_t Scr_GetFunction;
Scr_GetMethod_t Scr_GetMethod;
Scr_Error_t Scr_Error;
Scr_ObjectError_t Scr_ObjectError;
Scr_GetConstString_t Scr_GetConstString;
Scr_ParamError_t Scr_ParamError;
Q_strlwr_t Q_strlwr;
Q_strupr_t Q_strupr;
Q_strcat_t Q_strcat;
Q_strncpyz_t Q_strncpyz;
Q_CleanStr_t Q_CleanStr;
StuckInClient_t StuckInClient;
trap_Argv_t trap_Argv;
ClientCommand_t ClientCommand;
Com_SkipRestOfLine_t Com_SkipRestOfLine;
Com_ParseRestOfLine_t Com_ParseRestOfLine;
Com_ParseInt_t Com_ParseInt;
Jump_Check_t Jump_Check;
PM_GetEffectiveStance_t PM_GetEffectiveStance;
va_t va;

// Stock callbacks
int codecallback_startgametype = 0;
int codecallback_playerconnect = 0;
int codecallback_playerdisconnect = 0;
int codecallback_playerdamage = 0;
int codecallback_playerkilled = 0;


callback_t callbacks[] =
{
    {&codecallback_startgametype, "CodeCallback_StartGameType", false},
    {&codecallback_playerconnect, "CodeCallback_PlayerConnect", false},
    {&codecallback_playerdisconnect, "CodeCallback_PlayerDisconnect", false},
    {&codecallback_playerdamage, "CodeCallback_PlayerDamage", false},
    {&codecallback_playerkilled, "CodeCallback_PlayerKilled", false},

};


customPlayerState_t customPlayerState[MAX_CLIENTS];

cHook *hook_Com_Init;
cHook *hook_SV_AddOperatorCommands;
cHook *hook_Sys_LoadDll;

#define __RAVERSION__ "1.00.0"


// Base time in seconds
time_t sys_timeBase = 0;
// Current time in ms, using sys_timeBase as origin
uint64_t Sys_Milliseconds64(void)
{
    struct timeval tp;

    gettimeofday(&tp, NULL);

    if (!sys_timeBase)
    {
        sys_timeBase = tp.tv_sec;
        return tp.tv_usec / 1000;
    }

    return (tp.tv_sec - sys_timeBase) * 1000 + tp.tv_usec / 1000;
}


void SV_Init_Protocol()
{
  	protocol = Cvar_Get("protocol", "7", CVAR_ROM | CVAR_SERVERINFO);
  	Cvar_Set("protocol", "7");
	//void(*SV_Init)();
	//* (int*)(&SV_Init) = 0x808a94c;
	//SV_Init();
}


void SV_Init_Hostname()
{
    sv_hostname = Cvar_Get("sv_hostname", "CoDRAHost", CVAR_SERVERINFO | CVAR_ARCHIVE);
}

void _FS_Startup(const char *gameName)
{

 	fs_basegame = Cvar_Get("fs_basegame", "ra", CVAR_ROM);

    void(*FS_Startup)(const char *gameName);
	* (int*)(&FS_Startup) = 0x8061C6C;
	FS_Startup(gameName);
}

// See https://github.com/xtnded/codextended/blob/855df4fb01d20f19091d18d46980b5fdfa95a712/src/shared.c#L632
#define MAX_VA_STRING 32000
char *custom_va(const char *format, ...)
{
    va_list argptr;
    static char temp_buffer[MAX_VA_STRING];
    static char string[MAX_VA_STRING];
    static int index = 0;
    char *buf;
    int len;

    va_start(argptr, format);
    vsprintf(temp_buffer, format, argptr);
    va_end(argptr);

    if ((len = strlen(temp_buffer)) >= MAX_VA_STRING)
        Com_Error(ERR_DROP, "Attempted to overrun string in call to va()\n");

    if (len + index >= MAX_VA_STRING - 1)
        index = 0;

    buf = &string[index];
    memcpy(buf, temp_buffer, len + 1);

    index += len + 1;

    return buf;
}

 
void custom_Com_Init(char *commandLine)
{
    hook_Com_Init->unhook();
    void (*Com_Init)(char *commandLine);
    *(int*)&Com_Init = hook_Com_Init->from;
    Com_Init(commandLine);
    hook_Com_Init->hook();
    
    // Get references to stock cvars
    com_cl_running = Cvar_FindVar("cl_running");
    com_dedicated = Cvar_FindVar("dedicated");
    com_logfile = Cvar_FindVar("logfile");
    com_sv_running = Cvar_FindVar("sv_running");
    fs_game = Cvar_FindVar("fs_game");
    sv_allowDownload = Cvar_FindVar("sv_allowDownload");
    sv_floodProtect = Cvar_FindVar("sv_floodProtect");
    sv_fps = Cvar_FindVar("sv_fps");
    sv_gametype = Cvar_FindVar("g_gametype");
    sv_mapRotation = Cvar_FindVar("sv_mapRotation");
    sv_mapRotationCurrent = Cvar_FindVar("sv_mapRotationCurrent");
    sv_maxclients = Cvar_FindVar("sv_maxclients");
    sv_maxRate = Cvar_FindVar("sv_maxRate");
    sv_pure = Cvar_FindVar("sv_pure");
    sv_rconPassword = Cvar_FindVar("rconpassword");
    sv_serverid = Cvar_FindVar("sv_serverid");
    sv_showAverageBPS = Cvar_FindVar("sv_showAverageBPS");
    sv_showCommands = Cvar_FindVar("sv_showCommands");

    mapname = Cvar_FindVar("mapname");
    fs_restrict = Cvar_FindVar("fs_restrict");

    // Register custom cvars
    Cvar_Get("codra-sv", "1", CVAR_SERVERINFO);
    Cvar_Get("sv_wwwBaseURL", "", CVAR_SYSTEMINFO | CVAR_ARCHIVE);
    Cvar_Get("sv_wwwDownload", "0", CVAR_SYSTEMINFO | CVAR_ARCHIVE);
   
    Cvar_Get("shortversion", "1.00.0", CVAR_SERVERINFO | CVAR_ARCHIVE);
    
    
    sv_cracked = Cvar_Get("sv_cracked", "0", CVAR_ARCHIVE);

    /*
    Force cl_allowDownload on client, otherwise 1.1x can't download to join the server
    See: https://github.com/xtnded/codextended-client/blob/45af251518a390ab08b1c8713a6a1544b70114a1/cl_main.cpp#L41
    TODO: Force only for 1.1x clients
    */
    Cvar_Get("cl_allowDownload", "1", CVAR_SYSTEMINFO);
}

// See https://github.com/xtnded/codextended/blob/855df4fb01d20f19091d18d46980b5fdfa95a712/src/script.c#L944
static int localized_string_index = 128;
int custom_G_LocalizedStringIndex(const char *string)
{
    int i;
    char s[MAX_STRINGLENGTH];

    if(localized_string_index >= 256)
        localized_string_index = 128;

    if(!string || !*string)
        return 0;
    
    int start = 1244;

    for (i = 1; i < 256; i++)
    {
        trap_GetConfigstring(start + i, s, sizeof(s));
        if(!*s)
            break;
        if (!strcmp(s, string))
            return i;
    }
    if(i == 256)
        i = localized_string_index;

    SV_SetConfigstring(i + 1244, string);
    ++localized_string_index;
    
    return i;
}














// HWID BAN LOGIC
bool isValidSHA256(const std::string& str)
{
    return std::regex_match(str, std::regex("^[A-Fa-f0-9]{64}$"));
}


bool checkHWIDBan(const std::string& hwidHash)
{
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


static void SV_zzStatus_f( void )
{
	int i, j, l;
	client_t    *cl;
	const char      *s;
	int ping;

	// make sure server is running
	if ( !com_sv_running->integer )
	{
		Com_Printf( "Server is not running.\n" );
		return;
	}

	Com_Printf( "map: %s\n", mapname->string );

	Com_Printf( "num ping uid             name            lastmsg ip\n" );
	Com_Printf( "--- ---- --------------- --------------- ------- ---------------------\n" );
	for ( i = 0,cl = svs.clients ; i < sv_maxclients->integer ; i++,cl++ )
	{
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


void custom_SV_AddOperatorCommands()
{
    hook_SV_AddOperatorCommands->unhook();
    void (*SV_AddOperatorCommands)();
    *(int*)&SV_AddOperatorCommands = hook_SV_AddOperatorCommands->from;
    SV_AddOperatorCommands();
    hook_SV_AddOperatorCommands->hook();

    Cmd_AddCommand("ban", Cmd_Ban);
    Cmd_AddCommand("unban", Cmd_Unban);
    Cmd_RemoveCommand("status");
    Cmd_AddCommand("status", SV_zzStatus_f);
}



void hook_SVC_DirectConnect(netadr_t from)
{
	char* userinfo = Cmd_Argv(1);
	if (!userinfo) {
    	Com_Printf("Connection rejected: Missing userinfo.\n");
    	return;
	}

	std::string hwid = Info_ValueForKey(userinfo, "cl_hwid");
    std::string uid = Info_ValueForKey(userinfo, "cl_uid");
    const char* protocolcl = Info_ValueForKey(userinfo, "protocol");
    std::string patchString = std::string("RA ") + __RAVERSION__;

    if (strcmp(protocolcl, protocol->string) != 0)
    {
        Com_Printf("Connection rejected from a client with protocol: %s\n", protocolcl);
    	NET_OutOfBandPrint( NS_SERVER, from, va("error\nEXE_SERVER_IS_DIFFERENT_VER\x15%s\n", patchString.c_str()) );
        return;
    }

	if (hwid.empty()) {
		hwid = "unknown";
	}

    if(uid.empty())
    {
        uid = "unknown";
    }

	if(hwid == "unknown" || !isValidSHA256(hwid)) {
		Com_Printf("Connection rejected: HWID is wrong.\n"/*, NET_AdrToString(from)*/);
	    NET_OutOfBandPrint( NS_SERVER, from, "error\nDVCODEXE_INVALIDHWID\x15\n");	
		return; // reject connection
	}

    if(uid == "unknown")
    {
        Com_Printf("Connection rejected: Invalid UID.\n"/*, NET_AdrToString(from)*/);
	    NET_OutOfBandPrint( NS_SERVER, from, "error\nDVCODEXE_INVALIDUID\x15\n");	
		return; // reject connection
    }

	if (checkHWIDBan(hwid)) {
		Com_Printf("Connection from rejected: HWID banned.\n"/*, NET_AdrToString(from)*/);
	    NET_OutOfBandPrint( NS_SERVER, from, "error\nDVCODEXE_HWIDBANNED\x15\n");	
		return; // reject connection
	}


	Com_Printf("Connection accepted from UID: %s\n", uid.c_str());

	SV_DirectConnect(from);
}


void custom_SVC_Status(netadr_t from)
{
    char player[MAX_INFO_STRING];
    char infostring[MAX_INFO_STRING];
    char keywords[MAX_INFO_STRING];
    char status[MAX_MSGLEN];
    int statusLength;
    size_t playerLength;
    int i;
    client_t *cl;
    char *g_password;


    strcpy(infostring, Cvar_InfoString(CVAR_SERVERINFO));

    // sv_hostname = Cvar_FindVar("sv_hostname");

    // if(!strstr(infostring, "sv_hostname") && sv_hostname->string )
    // {
    //     Info_SetValueForKey(infostring, "sv_hostname", va("%s", sv_hostname->string));
    // }

    
    Info_SetValueForKey(infostring, "challenge", Cmd_Argv(1));
    
    if (fs_restrict->string)
    {
        Com_sprintf(keywords, sizeof(keywords), "demo %s", Info_ValueForKey(infostring, "sv_keywords"));
        Info_SetValueForKey(infostring, "sv_keywords", keywords);
    }
    
    status[0] = 0;
    statusLength = 0;
    for (i = 0; i < sv_maxclients->integer; i++)
    {
        cl = &svs.clients[i];
        if (cl->state >= CS_CONNECTED)
        {
            int clientScore = 0;

            clientScore = cl->gentity->client->sess.score;
 
            Com_sprintf(player, sizeof(player), "%i %i \"%s\" \"%s\"\n",
            clientScore,
            cl->ping,
            cl->name,
            Info_ValueForKey(cl->userinfo, "cl_uid")
            );
            
            playerLength = strlen(player);
            if(statusLength + playerLength >= sizeof(status))
                break;

            strcpy(status + statusLength, player);
            statusLength += playerLength;
        }
    }
    
    g_password = Cvar_VariableString("g_password");
    Info_SetValueForKey(infostring, "pswrd", va("%i", *g_password ? 1 : 0));

    // Inform about fs_game usage, by default for player's convenience
    Info_SetValueForKey(infostring, "fs_game", va("%s", *fs_game->string ? fs_game->string : "0"));

    NET_OutOfBandPrint(NS_SERVER, from, "statusResponse\n%s\n%s", infostring, status);
}







// See https://nachtimwald.com/2017/04/02/constant-time-string-comparison-in-c/
bool str_iseq(const char *s1, const char *s2)
{
    int             m = 0;
    volatile size_t i = 0;
    volatile size_t j = 0;
    volatile size_t k = 0;

    if (s1 == NULL || s2 == NULL)
        return false;

    while (1) {
        m |= s1[i]^s2[j];

        if (s1[i] == '\0')
            break;
        i++;

        if (s2[j] != '\0')
            j++;
        if (s2[j] == '\0')
            k++;
    }

    return m == 0;
}

const char* hook_AuthorizeState(int arg)
{
    const char* s = Cmd_Argv(arg);
    if(sv_cracked->integer && !strcmp(s, "deny"))
        return "accept";
    return s;
}



void ServerCrash(int sig)
{
    int fd;
    FILE *fp;
    void *array[20];
    size_t size = backtrace(array, 20);

    // Write to crash log
    fp = fopen("./crash.log", "a");
    if (fp)
    {
        fd = fileno(fp);
        fseek(fp, 0, SEEK_END);
        fprintf(fp, "Error: Server crashed with signal 0x%x {%d}\n", sig, sig);
        fflush(fp);
        backtrace_symbols_fd(array, size, fd);
    }
    
    // Write to stderr
    fprintf(stderr, "Error: Server crashed with signal 0x%x {%d}\n", sig, sig);
    backtrace_symbols_fd(array, size, STDERR_FILENO);
    
    system("stty sane");
    exit(1);
}

void _InitMSG() {
    Com_Printf("%s %s build %s %s\n", "CODRA", __RAVERSION__, "linux-i386", __DATE__);
}

void *custom_Sys_LoadDll(const char *name, char *fqpath, int (**entryPoint)(int, ...), int (*systemcalls)(int, ...))
{
    hook_Sys_LoadDll->unhook();
    void *(*Sys_LoadDll)(const char *name, char *fqpath, int (**entryPoint)(int, ...), int (*systemcalls)(int, ...));
    *(int*)&Sys_LoadDll = hook_Sys_LoadDll->from;
    void* libHandle = Sys_LoadDll(name, fqpath, entryPoint, systemcalls);
    hook_Sys_LoadDll->hook();

    //// Unprotect game.mp.i386.so
    // See https://github.com/xtnded/codextended/blob/855df4fb01d20f19091d18d46980b5fdfa95a712/src/librarymodule.c#L55
    char libPath[512];
    char buf[512];
    char flags[4];
    void *low, *high;
    FILE *fp;
    
    if(*fs_game->string)
        sprintf(libPath, "%s/game.mp.i386.so", fs_game->string);
    else if (*fs_basegame->string)
        sprintf(libPath, "%s/game.mp.i386.so", fs_basegame->string);
    else
        sprintf(libPath, "main/game.mp.i386.so");
    
    fp = fopen("/proc/self/maps", "r");
    if(!fp)
        return 0;

    while (fgets(buf, sizeof(buf), fp))
    {
        if(!strstr(buf, libPath))
            continue;
        if(sscanf (buf, "%p-%p %4c", &low, &high, flags) != 3)
            continue;
        mprotect((void *)low, (int)high-(int)low, PROT_READ | PROT_WRITE | PROT_EXEC);
    }
    fclose(fp);
    ////
    
    //// Objects
    g_clients = (gclient_t*)dlsym(libHandle, "g_clients");
    g_entities = (gentity_t*)dlsym(libHandle, "g_entities");
    level = (level_locals_t*)dlsym(libHandle, "level");
    pm = (pmove_t**)dlsym(libHandle, "pm");
    pml = (pml_t*)dlsym(libHandle, "pml");
    scr_const = (stringIndex_t*)dlsym(libHandle, "scr_const");
    ////

    //// Functions
    Scr_GetFunctionHandle = (Scr_GetFunctionHandle_t)dlsym(libHandle, "Scr_GetFunctionHandle");
    Scr_GetNumParam = (Scr_GetNumParam_t)dlsym(libHandle, "Scr_GetNumParam");
    trap_Argv = (trap_Argv_t)dlsym(libHandle, "trap_Argv");
    ClientCommand = (ClientCommand_t)dlsym(libHandle, "ClientCommand");
    Com_SkipRestOfLine = (Com_SkipRestOfLine_t)dlsym(libHandle, "Com_SkipRestOfLine");
    Com_ParseRestOfLine = (Com_ParseRestOfLine_t)dlsym(libHandle, "Com_ParseRestOfLine");
    Com_ParseInt = (Com_ParseInt_t)dlsym(libHandle, "Com_ParseInt");
    Scr_GetFunction = (Scr_GetFunction_t)dlsym(libHandle, "Scr_GetFunction");
    Scr_GetMethod = (Scr_GetMethod_t)dlsym(libHandle, "Scr_GetMethod");
    trap_SendServerCommand = (trap_SendServerCommand_t)dlsym(libHandle, "trap_SendServerCommand");
    Scr_ExecThread = (Scr_ExecThread_t)dlsym(libHandle, "Scr_ExecThread");
    Scr_ExecEntThread = (Scr_ExecEntThread_t)dlsym(libHandle, "Scr_ExecEntThread");
    Scr_ExecEntThreadNum = (Scr_ExecEntThreadNum_t)dlsym(libHandle, "Scr_ExecEntThreadNum");
    Scr_FreeThread = (Scr_FreeThread_t)dlsym(libHandle, "Scr_FreeThread");
    Scr_Error = (Scr_Error_t)dlsym(libHandle, "Scr_Error");
    Scr_ObjectError = (Scr_ObjectError_t)dlsym(libHandle, "Scr_ObjectError");
    Scr_GetConstString = (Scr_GetConstString_t)dlsym(libHandle, "Scr_GetConstString");
    Scr_ParamError = (Scr_ParamError_t)dlsym(libHandle, "Scr_ParamError");
    G_Say = (G_Say_t)dlsym(libHandle, "G_Say");
    G_RegisterCvars = (G_RegisterCvars_t)dlsym(libHandle, "G_RegisterCvars");
    G_AddEvent = (G_AddEvent_t)dlsym(libHandle, "G_AddEvent");
    G_AddPredictableEvent = (G_AddPredictableEvent_t)dlsym(libHandle, "G_AddPredictableEvent");
    trap_GetConfigstringConst = (trap_GetConfigstringConst_t)dlsym(libHandle, "trap_GetConfigstringConst");
    trap_GetConfigstring = (trap_GetConfigstring_t)dlsym(libHandle, "trap_GetConfigstring");
    BG_GetNumWeapons = (BG_GetNumWeapons_t)dlsym(libHandle, "BG_GetNumWeapons");
    BG_GetInfoForWeapon = (BG_GetInfoForWeapon_t)dlsym(libHandle, "BG_GetInfoForWeapon");
    BG_GetWeaponIndexForName = (BG_GetWeaponIndexForName_t)dlsym(libHandle, "BG_GetWeaponIndexForName");
    BG_AnimationIndexForString = (BG_AnimationIndexForString_t)dlsym(libHandle, "BG_AnimationIndexForString");
    BG_AnimScriptEvent = (BG_AnimScriptEvent_t)dlsym(libHandle, "BG_AnimScriptEvent");
    Scr_IsSystemActive = (Scr_IsSystemActive_t)dlsym(libHandle, "Scr_IsSystemActive");
    Scr_GetInt = (Scr_GetInt_t)dlsym(libHandle, "Scr_GetInt");
    Scr_GetString = (Scr_GetString_t)dlsym(libHandle, "Scr_GetString");
    Scr_GetType = (Scr_GetType_t)dlsym(libHandle, "Scr_GetType");
    Scr_GetEntity = (Scr_GetEntity_t)dlsym(libHandle, "Scr_GetEntity");
    Scr_AddBool = (Scr_AddBool_t)dlsym(libHandle, "Scr_AddBool");
    Scr_AddInt = (Scr_AddInt_t)dlsym(libHandle, "Scr_AddInt");
    Scr_AddFloat = (Scr_AddFloat_t)dlsym(libHandle, "Scr_AddFloat");
    Scr_AddString = (Scr_AddString_t)dlsym(libHandle, "Scr_AddString");
    Scr_AddUndefined = (Scr_AddUndefined_t)dlsym(libHandle, "Scr_AddUndefined");
    Scr_AddVector = (Scr_AddVector_t)dlsym(libHandle, "Scr_AddVector");
    Scr_MakeArray = (Scr_MakeArray_t)dlsym(libHandle, "Scr_MakeArray");
    Scr_AddArray = (Scr_AddArray_t)dlsym(libHandle, "Scr_AddArray");
    Scr_AddObject = (Scr_AddObject_t)dlsym(libHandle, "Scr_AddObject");
    Scr_LoadScript = (Scr_LoadScript_t)dlsym(libHandle, "Scr_LoadScript");
    StuckInClient = (StuckInClient_t)dlsym(libHandle, "StuckInClient");
    Q_strlwr = (Q_strlwr_t)dlsym(libHandle, "Q_strlwr");
    Q_strupr = (Q_strupr_t)dlsym(libHandle, "Q_strupr");
    Q_strcat = (Q_strcat_t)dlsym(libHandle, "Q_strcat");
    Q_strncpyz = (Q_strncpyz_t)dlsym(libHandle, "Q_strncpyz");
    Q_CleanStr = (Q_CleanStr_t)dlsym(libHandle, "Q_CleanStr");
    Jump_Check = (Jump_Check_t)((int)dlsym(libHandle, "_init") + 0x76F4);
    PM_GetEffectiveStance = (PM_GetEffectiveStance_t)dlsym(libHandle, "PM_GetEffectiveStance");
    va = (va_t)dlsym(libHandle, "va");
    ////

    //// Patch codmsgboom
    /* See:
    - https://aluigi.altervista.org/adv/codmsgboom-adv.txt
    - https://github.com/xtnded/codextended/blob/855df4fb01d20f19091d18d46980b5fdfa95a712/src/librarymodule.c#L146
    */
    *(int*)((int)dlsym(libHandle, "G_Say") + 0x50e) = 0x37f;
    *(int*)((int)dlsym(libHandle, "G_Say") + 0x5ca) = 0x37f;
    ////


    hook_jmp((int)dlsym(libHandle, "G_LocalizedStringIndex"), (int)custom_G_LocalizedStringIndex);
    hook_jmp((int)dlsym(libHandle, "va"), (int)custom_va);
    


    return libHandle;
}

class libcodra
{
    public:
    libcodra()
    {
        // Don't inherit lib of parent
        unsetenv("LD_PRELOAD");

        // Crash handlers for debugging
        signal(SIGSEGV, ServerCrash);
        signal(SIGABRT, ServerCrash);
        
        // Otherwise the printf()'s are printed at crash/end on older os/compiler versions
        // See https://github.com/M-itch/libcod/blob/e58d6a01b11c911fbf886659b6ea67795776cf4a/libcod.cpp#L1346
        setbuf(stdout, NULL);

        // Allow to write in executable memory
        mprotect((void *)0x08048000, 0x135000, PROT_READ | PROT_WRITE | PROT_EXEC);

        // Patch q3infoboom
        /* See:
        - https://aluigi.altervista.org/adv/q3infoboom-adv.txt
        - https://github.com/xtnded/codextended/blob/855df4fb01d20f19091d18d46980b5fdfa95a712/src/codextended.c#L295
        */
        *(byte*)0x807f459 = 1;

        // Patch RCON half-second limit //TODO: Do like zk_libcod instead
        /* See:
        - https://aluigi.altervista.org/patches/q3rconz.lpatch
        - https://github.com/xtnded/codextended/blob/855df4fb01d20f19091d18d46980b5fdfa95a712/src/codextended.c#L291
        - https://github.com/ibuddieat/zk_libcod/blob/0f07cacf303d104a0375bf6235b8013e30b668ca/code/libcod.cpp#L3486
        */
        *(unsigned char*)0x808C41F = 0xeb;

        //hook_call(0x806cc80, (int)SV_Init_Protocol);
        hook_call(0x0808A9A4, (int)SV_Init_Protocol);


        hook_call(0x08085213, (int)hook_AuthorizeState);
        hook_call(0x08094c54, (int)Scr_GetCustomFunction);
        hook_call(0x080951c4, (int)Scr_GetCustomMethod);
        hook_call(0x0808c7b8, (int)hook_SVC_DirectConnect);

        hook_call(0x0806C679, (int)_InitMSG);

        hook_jmp(0x0808bd58, (int)custom_SVC_Status);

        hook_call(0x0806224A, (int)_FS_Startup);
        hook_call(0x08062532, (int)_FS_Startup);
        hook_call(0x08071432, (int)_FS_Startup);

        hook_call(0x0808A9ED, (int)SV_Init_Hostname);


        memcpy((void*)0x080CF69A, "1.00.0", strlen("1.00.0")+1);
//        memcpy((void*)0x080D5620, "CoDRAHost", strlen("CoDRAHost")+1);
	
        memcpy((void*)0x080CDF8D, "ra_config_mp_server.cfg", strlen("ra_config_mp_server.cfg") + 1);
        memcpy((void*)0x080CF706, "exec ra_config_mp_server.cfg", strlen("exec ra_config_mp_server.cfg") + 1);
        memcpy((void*)0x080CF92D, "ra_config_mp_server.cfg", strlen("ra_config_mp_server.cfg") + 1);
        std::string patchString = std::string("RA ") + __RAVERSION__;
        memcpy((void*)0x080D42ED, patchString.c_str(), patchString.size() + 1); // +1 for null terminator
        /* *
    uintptr_t addr = 0x0808C21A; //this mf causing the filter issue
    uint8_t patch[] = { 0x6A, 0x07 }; // PUSH 0x7
    memcpy((void*)addr, patch, sizeof(patch));
*/
    uintptr_t addr2 = 0x0808551B;
    uint8_t patch2[] = { 0x6A, 0x07 }; // PUSH 0x7
    memcpy((void*)addr2, patch2, sizeof(patch2));

    uintptr_t addr3 = 0x080854FC;
    uint8_t patch3 = 0x07; // Change immediate from 0x01 to 0x07
    *(uint8_t*)(addr3 + 2) = patch3;

    
        hook_Sys_LoadDll = new cHook(0x080c5fe4, (int)custom_Sys_LoadDll);
        hook_Sys_LoadDll->hook();
        hook_Com_Init = new cHook(0x0806c654, (int)custom_Com_Init);
        hook_Com_Init->hook();
        hook_SV_AddOperatorCommands = new cHook(0x08084a3c, (int)custom_SV_AddOperatorCommands);
        hook_SV_AddOperatorCommands->hook();

    }

    ~libcodra()
    {
        printf("CoD: Risen Arena :: SHUTDOWN\n");
        system("stty sane");
    }
};

libcodra *ra;
void __attribute__ ((constructor)) lib_load(void)
{
    ra = new libcodra;
}
void __attribute__ ((destructor)) lib_unload(void)
{
    delete ra;
}