#pragma once
#include <string>
#include <windows.h>
#include <map>


#define MAX_MSGLEN 16384


extern DWORD cgame_mp;
extern DWORD game_mp;

#define GAME_OFF(x) (game_mp + (x - 0x20000000))
#define CGAME_OFF(x) (cgame_mp + (x - 0x30000000))

#define __RAVERSION__ "1.00.0"
#define __RABUILD__ 1000   // current client build

#define gameWindow ((HWND*)0x16C35E8)
static void(*Com_Quit_f)() = (void(*)())0x0043a2c0;

#define CVAR_ARCHIVE        1   // set to cause it to be saved to vars.rc
#define CVAR_USERINFO       2   // sent to server on connect or change
#define CVAR_SERVERINFO     4   // sent in response to front end requests
#define CVAR_SYSTEMINFO     8   // these cvars will be duplicated on all clients
#define CVAR_INIT           16  // don't allow change from console at all,
#define CVAR_LATCH          32  // will only change when C code next does

#define CVAR_ROM            64  // display only, cannot be set by user at all
#define CVAR_USER_CREATED   128 // created by a set command
#define CVAR_TEMP           256 // can be set even when cheats are disabled, but is not archived
#define CVAR_CHEAT          512 // can not be changed if cheats are disabled
#define CVAR_NORESTART      1024    // do not clear when a cvar_restart is issued
#define CVAR_WOLFINFO       2048    // DHM - NERVE :: Like userinfo, but for wolf multiplayer info

#define CVAR_UNSAFE         4096    // ydnar: unsafe system cvars (renderer, sound settings, anything that might cause a crash)
#define CVAR_SERVERINFO_NOUPDATE        8192    // gordon: WONT automatically send this to clients, but server browsers will see it

#define MAX_STRINGLENGTH            1024
#define MAX_STRING_CHARS    1024 // max length of a string passed to Cmd_TokenizeString
#define MAX_STRING_TOKENS   256 // max tokens resulting from Cmd_TokenizeString
#define MAX_RELIABLE_COMMANDS 64
#define MAX_INFO_STRING     1024
#define MAX_INFO_KEY        1024
#define MAX_INFO_VALUE      1024
#define	MAX_NAME_LENGTH     32
#define MAX_NETNAME                 36

#define MAX_CONFIGSTRINGS           2048
#define MAX_DOWNLOAD_BLKSIZE        2048
#define MAX_DOWNLOAD_BLKSIZE_FAST   0x2000 // See https://github.com/ibuddieat/zk_libcod/blob/dff123fad25d7b46d65685e9bca2111c8946a36e/code/declarations.hpp#L60
#define MAX_DOWNLOAD_WINDOW         8
#define PACKET_BACKUP 32

#define BIG_INFO_STRING     8192 // used for system info key only
#define BIG_INFO_KEY        8192
#define BIG_INFO_VALUE      8192

#define Q_COLOR_ESCAPE  '^'
#define Q_IsColorString( p )  ( p && *( p ) == Q_COLOR_ESCAPE && *( ( p ) + 1 ) && *( ( p ) + 1 ) != Q_COLOR_ESCAPE )

#define DotProduct( x,y )         ( ( x )[0] * ( y )[0] + ( x )[1] * ( y )[1] + ( x )[2] * ( y )[2] )
#define VectorCopy( a,b )         ( ( b )[0] = ( a )[0],( b )[1] = ( a )[1],( b )[2] = ( a )[2] )

#define cls_realtime ((int*)0x155F3E0)
#define cls_state ((int*)0x155F2C0)
#define cls_downloadRestart ((PINT)0x15EEFBC)
#define clc_downloadList ((PCHAR)0x15EEBBC)
#define clc_stringData ((PCHAR)0x1436A7C)
#define clc_stringOffsets ((PINT)0x1434A7C)
#define cs0 (clc_stringData + clc_stringOffsets[0])
#define cs1 (clc_stringData + clc_stringOffsets[1])
#define clc_demoplaying ((PINT)0x15EF004)
#define gameInitialized ((int*)0x14073D0)

#define mouseInitialized ((int*)0x8e2524) //from WinMouseVars_t
#define mouseActive ((int*)0x8e2520) //from WinMouseVars_t


#define cls_numglobalservers ((int*)0x1565004)
#define cls_numGlobalServerAddresses ((int*)0x15C1008)
#define cls_pingUpdateSource ((int*)0x15C9C10)



#define MAX_QPATH 64
#define MAX_OSPATH 256
typedef int fileHandle_t;
typedef int qhandle_t;

typedef float vec_t;
typedef vec_t vec2_t[2];
typedef vec_t vec3_t[3];

typedef enum
{
	EXEC_NOW,
	EXEC_INSERT,
	EXEC_APPEND
} cbufExec_t;

typedef enum
{
	qfalse,
	qtrue
} qboolean;

typedef struct cvar_s
{
	char* name;
	char* string;
	char* resetString; // cvar_restart will reset to this value
	char* latchedString; // for CVAR_LATCH vars
	int flags;
	qboolean modified; // set each time the cvar is changed
	int modificationCount; // incremented each time the cvar is changed
	float value; // atof( string )
	int integer; // atoi( string )
	struct cvar_s* next;
	//struct cvar_s* hashNext; //whats that? what is a hashnext?
} cvar_t;

typedef enum
{
	CA_UNINITIALIZED,
	CA_DISCONNECTED = 0,
	CA_CONNECTING,
	CA_CHALLENGING,
	CA_CONNECTED,
} connstate_t;


	typedef enum
	{
		/*
		these are taken from 1.5 I have commented out the one's that I haven't used yet.
		unsure if these are 100% correct as there are differences between versions
		*/
		// ...
		CG_PRINT = 0x0,
		CG_ERROR = 0x1,
		CG_GAMEMESSAGE = 0x2,
		//CG_BOLDGAMEMESSAGE = 0x3,
		//CG_DEATHMESSAGE = 0x4,
		//CG_SUBTITLE = 0x5,
		CG_MILLISECONDS = 0x6,
		//CG_CVAR_REGISTER = 0x7,
		//CG_CVAR_UPDATE = 0x8,
		//CG_CVAR_SET = 0x9,
		//CG_CVAR_SETVAR = 0xa,
		//CG_CVAR_VARIABLESTRINGBUFFER = 0xb,
		//CG_ARGC = 0xc,
		//CG_ARGV = 0xd,
		//CG_ARGS = 0xe,
		//CG_FS_FOPENFILE = 0xf,
		//CG_FS_READ = 0x10,
		//CG_FS_WRITE = 0x11,
		//CG_FS_FCLOSEFILE = 0x12,
		//CG_FS_GETFILELIST = 0x13,
		//CG_COM_SAVECVARSTOBUFFER = 0x14,
		//CG_COM_LOADCVARSFROMBUFFER = 0x15,
		//CG_SENDCONSOLECOMMAND = 0x16,
		//CG_ADDCOMMAND = 0x17,
		//CG_SENDCLIENTCOMMAND = 0x18,
		//CG_UPDATESCREEN = 0x19,
		//CG_DRAWNOTIFYLINES = 0x1a,
		//CG_DRAWBOLDMESSAGES = 0x1b,
		//CG_DRAWMINICONSOLE = 0x1c,
		//CG_DRAWSUBTITLES = 0x1d,
		//CG_DRAWSAY = 0x1e,
		//CG_CM_LOADMAP = 0x1f,
		//CG_CM_NUMINLINEMODELS = 0x20,
		//CG_CM_INLINEMODEL = 0x21,
		//CG_CM_TEMPBOXMODEL = 0x23,
		//CG_CM_POINTCONTENTS = 0x24,
		//CG_CM_TRANSFORMEDPOINTCONTENTS = 0x25,
		//CG_CM_BOXTRACE = 0x26,
		//CG_CM_TRANSFORMEDBOXTRACE = 0x27,
		//CG_CM_CAPSULETRACE = 0x28,
		//CG_CM_TRANSFORMEDCAPSULETRACE = 0x29,
		//CG_CM_TEMPCAPSULEMODEL = 0x2a,
		//CG_R_MARKFRAGMENTS = 0x2b,
		//CG_R_LOADWORLDMAP = 0x2c,
		//CG_R_REGISTERMODEL = 0x2d,
		//CG_R_FINISHLOADINGMODELS = 0x2e,
		CG_R_REGISTERSHADER = 0x30,
		//CG_R_GETXMODELBYHANDLE = 0x32,
		//CG_R_TEXT_WIDTH = 0x34,
		//CG_R_TEXT_HEIGHT = 0x35,
		//CG_R_TEXT_PAINT = 0x36,
		//CG_SE_TRANSLATEREFERENCE = 0x38,
		//CG_SE_LOCALIZEMESSAGE = 0x39,
		//CG_SE_PRINTSTRLEN = 0x3a,
		//CG_SE_READCHARFROMSTRING = 0x3b,
		//CG_R_CLEARSCENE = 0x3c,
		//CG_R_ADDREFENTITYTOSCENE = 0x3d,
		//CG_HUNKUSED = 0x3f,
		//CG_R_ADDPOLYTOSCENE = 0x40,
		//CG_R_ADDLIGHTTOSCENE = 0x42,
		//CG_R_SETFOG = 0x44,
		//CG_R_RENDERSCENE = 0x45,
		//CG_R_SAVESCREEN = 0x46,
		//CG_R_BLENDSAVEDSCREEN = 0x47,
		CG_R_SETCOLOR = 0x48,
		CG_R_DRAWSTRETCHPIC = 0x49,
		//CG_R_DRAWSTRETCHPICROTATE = 0x4b,
		CG_R_DRAWQUADPIC = 0x4c,
		//CG_R_MODELBOUNDS = 0x4d,
		//CG_GETGLCONFIG = 0x4e,
		//CG_GETGAMESTATE = 0x4f,
		//CG_GETCURRENTSNAPSHOTNUMBER = 0x50,
		//CG_GETSNAPSHOT = 0x51,
		//CG_GETSERVERCOMMAND = 0x52,
		//CG_GETCURRENTCMDNUMBER = 0x53,
		//CG_GETUSERCMD = 0x54,
		//CG_SETUSERCMDVALUE = 0x55,
		//CG_SETUSERCMDAIMVALUES = 0x56,
		//CG_SETUSERCMDINSHELLSHOCK = 0x57,
		CG_R_REGISTERSHADERNOMIP = 0x58,
		//CG_MEMORYREMAINING = 0x59,
		//CG_CL_LOOKUPCOLOR = 0x5e,
		//CG_PC_LOADSOURCE = 0x60,
		//CG_PC_FREESOURCE = 0x61,
		//CG_PC_READTOKEN = 0x62,
		//CG_PC_SOURCEFILEANDLINE = 0x63,
		//CG_SNAPVECTOR = 0x65,
		//CG_CIN_PLAYCINEMATIC = 0x67,
		//CG_CIN_STOPCINEMATIC = 0x68,
		//CG_CIN_RUNCINEMATIC = 0x69,
		//CG_CIN_DRAWCINEMATIC = 0x6a,
		//CG_CIN_SETEXTENTS = 0x6b,
		//CG_R_TRACKSTATISTICS = 0x6c,
		//CG_R_PICKSHADER = 0x6d,
		//CG_UI_LOADMENU = 0x7a,
		//CG_UI_POPUP = 0x7b,
		//CG_UI_CLOSEPOPUP = 0x7c,
		//CG_UI_CLOSEALLMENUS = 0x7d,
		//CG_UI_GETMAPDISPLAYNAME = 0x7e,
		//CG_UI_GETGAMETYPEDISPLAYNAME = 0x7f,
		//CG_CL_GETSERVERIPADDRESS = 0x80,
		//CG_XANIMPRECACHE = 0x81,
		//CG_XANIMCREATEANIMS = 0x82,
		//CG_XANIMCREATE = 0x83,
		//CG_XANIMCREATETREE = 0x84,
		//CG_XANIMBLEND = 0x85,
		//CG_XANIMCLEARGOALWEIGHT = 0x87,
		//CG_XANIMCLEARTREEGOALWEIGHTS = 0x88,
		//CG_XANIMCLEARTREEGOALWEIGHTSSTRICT = 0x89,
		//CG_XANIMSETCOMPLETEGOALWEIGHTKNOBALL = 0x8b,
		//CG_XANIMSETGOALWEIGHT = 0x8d,
		//CG_XANIMSETCOMPLETEGOALWEIGHT = 0x8e,
		//CG_XANIMSETANIMRATE = 0x8f,
		//CG_XANIMISLOOPED = 0x90,
		//CG_XANIMISLOOPING = 0x91,
		//CG_XANIMSETTIME = 0x92,
		//CG_XANIMGETTIME = 0x93,
		//CG_XANIMGETWEIGHT = 0x94,
		//CG_DOBJINVALIDATESKELS = 0x95,
		//CG_DOBJUPDATEINFO = 0x96,
		//CG_DOBJGETCLIENTNOTIFYLIST = 0x97,
		//CG_DOBJCALCANIM = 0x98,
		//CG_DOBJDISPLAYANIM = 0x99,
		//CG_XANIMCALCABSDELTA = 0x9b,
		//CG_XANIMGETRELDELTA = 0x9c,
		//CG_DOBJGETMATRIXARRAY = 0x9e,
		//CG_DOBJGETROTTRANSARRAY = 0x9f,
		//CG_DOBJSETROTTRANSINDEX = 0xa0,
		//CG_DOBJSETCONTROLROTTRANSINDEX = 0xa1,
		//CG_GETDOBJ = 0xa2,
		//CG_DOBJCREATE = 0xa5,
		//CG_SAFEDOBJFREE = 0xa6,
		//CG_DOBJCREATESKELFORBONE = 0xa9,
		//CG_DOBJCREATESKELFORBONES = 0xaa,
		//CG_DOBJGETHIERARCHYBITS = 0xab,
		//CG_DOBJCALCSKEL = 0xac,
		//CG_DOBJGETBONEINDEX = 0xaf,
		//CG_DOBJGETTREE = 0xb2,
		//CG_XANIMISPRIMITIVE = 0xb3,
		//CG_XANIMGETLENGTH = 0xb4,
		//CG_XANIMHASFINISHED = 0xb5,
		//CG_XANIMGETNUMCHILDREN = 0xb6,
		//CG_XANIMGETCHILDAT = 0xb7,
		//CG_XANIMGETANIMTREESIZE = 0xb8,
		//CG_XANIMCLONEANIMTREE = 0xb9,
		//CG_GETSTATSARRAY = 0xbc,
		//CG_Z_MALLOCINTERNAL = 0xbd,
		//CG_Z_FREEINTERNAL = 0xbe,
		//CG_COM_LOADSOUNDALIASES = 0xbf,
		//CG_COM_SOUNDALIASSTRING = 0xc0,
		//CG_COM_PICKSOUNDALIAS = 0xc1,
		//CG_MSS_PLAYSOUNDALIAS = 0xc3,
		//CG_MSS_PLAYBLENDEDSOUNDALIASES = 0xc4,
		//CG_SURFACETYPEFROMNAME = 0xc5,
		//CG_SURFACETYPETONAME = 0xc6,
		//CG_ADDDEBUGLINE = 0xC7,
		//CG_GETWEAPONINFOMEMORY = 0xc8,
		//CG_FREEWEAPONINFOMEMORY = 0xc9,
		//CG_HUNK_ALLOCINTERNAL = 0xca,
		//CG_HUNK_ALLOCLOWINTERNAL = 0xcb,
		//CG_HUNK_ALLOCLOWALIGNINTERNAL = 0xcd,
		//CG_GETNUMSCRIPTVARS = 0xce,
		//CG_GETNUMSCRIPTTHREADS = 0xcf
		//CG_GETSTRINGUSAGE = 0xd0,
		//CG_SETCLIENTLERPORIGIN = 0xd1,
		//CG_MSS_SETLISTENER = 0xd2,
		//CG_MSS_UPDATELOOPINGSOUNDS = 0xd3,
		//CG_MSS_STOPSOUNDS = 0xd4,
		//CG_MSS_PLAYMUSICALIAS = 0xd5,
		//CG_MSS_STOPMUSIC = 0xd6,
		//CG_MSS_PLAYAMBIENTALIAS = 0xd7,
		//CG_MSS_FADEALLSOUNDS = 0xd8,
		//CG_MSS_FADESELECTSOUNDS = 0xd9,
		//CG_MSS_SETENVIRONMENTEFFECTS = 0xda,
		//CG_MSS_GETSOUNDOVERLAY = 0xdb,
		//CG_FX_REGISTEREFFECT = 0xdf,
		//CG_FX_GETBONEINDEX = 0xe0,
		//CG_FX_PLAYSIMPLEEFFECTID = 0xe4,
		//CG_FX_PLAYEFFECTID = 0xe5,
		//CG_FX_PLAYENTITYEFFECTID = 0xe6,
		//CG_FX_ADDSCHEDULEDEFFECTS = 0xe7,
		//CG_FX_INITSYSTEM = 0xe8,
		//CG_FX_FREESYSTEM = 0xe9,
		//CG_FX_FREEACTIVE = 0xea,
		//CG_FX_ADJUSTTIME = 0xeb,
		//CG_FX_ADJUSTCAMERA = 0xec,
		//CG_CAPTURNRATE = 0xf1,
		//CG_SETVIEWANGLES = 0xf2,
		//CG_SYNCTIMES = 0xf3,
		//CG_DATETIMESTAMP = 0xf4,
		//CG_EXECUTESTRING = 0xf5
		// ...
	} cgameImport_t;

typedef enum
{
	NA_BOT,
	NA_BAD, // an address lookup failed
	NA_LOOPBACK,
	NA_BROADCAST,
	NA_IP,
	NA_IPX,
	NA_BROADCAST_IPX
} netadrtype_t;

typedef enum
{
	NS_CLIENT,
	NS_SERVER
} netsrc_t;

typedef struct
{
	netadrtype_t type;
	union
	{
		int _ip;
		unsigned char ip[4];
	};
	unsigned char ipx[10];
	unsigned short port;
} netadr_t;
#define clc_serverAddress (*(netadr_t*)0x015ce86c)


typedef struct
{
    qboolean overflowed;
    byte *data;
    int maxsize;
    int cursize;
    int readcount;
    int bit;
} msg_t;

typedef enum
{
	ERR_FATAL,				// exit the entire game with a popup window
	//ERR_VID_FATAL,		// exit the entire game with a popup window and doesn't delete profile.pid
	ERR_DROP,				// print to console and disconnect from game
	ERR_SERVERDISCONNECT,	// don't kill server
	ERR_DISCONNECT,			// client disconnected from the server
	ERR_NEED_CD,			// pop up the need-cd dialog
	ERR_AUTOUPDATE
} errorParm_t;

typedef struct
{
	netsrc_t	sock;
	int			dropped;			// between last packet and previous
	netadr_t	remoteAddress;
	int			qport;				// qport value to write when transmitting
	int			incomingSequence;
	int			outgoingSequence;
	// incoming fragment assembly buffer
	int			fragmentSequence;
	int			fragmentLength;
	byte		fragmentBuffer[MAX_MSGLEN];
	// outgoing fragment buffer
	// we need to space out the sending of large fragmented messages
	qboolean	unsentFragments;
	int			unsentFragmentStart;
	int			unsentLength;
	byte		unsentBuffer[MAX_MSGLEN];
} netchan_t;

typedef struct
{
	int			clientNum;
	int			lastPacketSentTime;			// for retransmits during connection
	int			lastPacketTime;				// for timeouts
	netadr_t	serverAddress;
	int			connectTime;				// for connection retransmits
	int			connectPacketCount;			// for display on connection dialog
	char		serverMessage[MAX_STRING_TOKENS];	// for display on connection dialog
	int			challenge;					// from the server to use for connecting
	int			checksumFeed;				// from the server for checksum calculations
	int			reliableSequence;
	int			reliableAcknowledge;		// the last one the server has executed
	char		reliableCommands[MAX_RELIABLE_COMMANDS][MAX_STRING_CHARS];
	// server message (unreliable) and command (reliable) sequence
	// numbers are NOT cleared at level changes, but continue to
	// increase as long as the connection is valid
	// message sequence is used by both the network layer and the
	// delta compression layer
	int			serverMessageSequence;
	// reliable messages received from server
	int			serverCommandSequence;
	int			lastExecutedServerCommand;		// last server command grabbed or executed with CL_GetServerCommand
	char		serverCommands[MAX_RELIABLE_COMMANDS][MAX_STRING_CHARS];
	// file transfer from server
	fileHandle_t download;
	char		downloadTempName[MAX_OSPATH];
	char		downloadName[MAX_OSPATH];
	int			downloadNumber;
	int			downloadBlock;	// block we are waiting for
	int			downloadCount;	// how many bytes we got
	int			downloadSize;	// how many bytes we got
	char		downloadList[MAX_INFO_STRING]; // list of paks we need to download
	qboolean	downloadRestart;	// if true, we need to do another FS_Restart because we downloaded a pak
	char		demoName[MAX_QPATH];
	qboolean	spDemoRecording;
	qboolean	demorecording;
	qboolean	demoplaying;
	qboolean	demowaiting;	// don't record until a non-delta message is received
	qboolean	firstDemoFrameSkipped;
	fileHandle_t	demofile;
	int			timeDemoFrames;		// counter of rendered frames
	int			timeDemoStart;		// cls.realtime before first frame
	int			timeDemoBaseTime;	// each frame will be at this time + frameNum * 50
	netchan_t	netchan;
} clientConnection_t;

typedef enum
{
	PM_NORMAL = 0x0,
	PM_NORMAL_LINKED = 0x1,
	PM_NOCLIP = 0x2,
	PM_UFO = 0x3,
	PM_SPECTATOR = 0x4,
	PM_INTERMISSION = 0x5,
	PM_DEAD = 0x6,
	PM_DEAD_LINKED = 0x7,
} pmtype_t;

typedef enum
{
	WEAPON_READY = 0x0,
	WEAPON_RAISING = 0x1,
	WEAPON_DROPPING = 0x2,
	WEAPON_FIRING = 0x3,
	WEAPON_RECHAMBERING = 0x4,
	WEAPON_RELOADING = 0x5,
	WEAPON_RELOADING_INTERUPT = 0x6,
	WEAPON_RELOAD_START = 0x7,
	WEAPON_RELOAD_START_INTERUPT = 0x8,
	WEAPON_RELOAD_END = 0x9,
	WEAPON_MELEE_INIT = 0xA,
	WEAPON_MELEE_FIRE = 0xB,
	WEAPONSTATES_NUM = 0xC,
} weaponstate_t;

typedef struct playerState_s
{
	int commandTime;
	pmtype_t pm_type;
	int bobCycle;
	int pm_flags;
	int pm_time;
	vec3_t origin;
	vec3_t velocity;
	vec2_t oldVelocity;
	int weaponTime;
	int weaponDelay;
	int gravity;
	float leanf;
	int speed;
	vec3_t delta_angles;
	int groundEntityNum;
	vec3_t vLadderVec;
	int jumpTime;
	float jumpOriginZ;
	int legsTimer;
	int legsAnim;
	int torsoTimer;
	int torsoAnim;
	int movementDir;
	int eFlags;
	int eventSequence;
	int events[4];
	unsigned int eventParms[4];
	int oldEventSequence;
	int clientNum;
	unsigned int weapon;
	weaponstate_t weaponstate;
	float fWeaponPosFrac;
	int viewmodelIndex;
	vec3_t viewangles;
	int viewHeightTarget;
	float viewHeightCurrent;
	byte pad[8188];
} playerState_t;

typedef struct usercmd_s
{
	int serverTime;
	byte buttons; // console, chat, ads, attack, use
	byte wbuttons; // lean left, lean right, reload
	byte weapon;
	byte flags;
	int angles[3];
	signed char forwardmove, rightmove, upmove;
	byte unknown;
} usercmd_t;

struct pmove_t
{
	playerState_t* ps;
	usercmd_t cmd;
	// some remains
};
typedef enum
{
    CS_FREE,
    CS_ZOMBIE,
    CS_CONNECTED,
    CS_PRIMED,
    CS_ACTIVE
} clientConnectState_t;

// typedef struct client_s
// {
//     clientConnectState_t state;
//     qboolean sendAsActive;
//     const char *dropReason;
//     char userinfo[MAX_INFO_STRING];
// 	// ...
// } client_t;

typedef struct customClient_s
{
	char* hwid;
	char* uid;
} customClient_t;

typedef struct
{
    playerState_t ps;
    int num_entities;
    int num_clients;
    int first_entity;
    int first_client;
    unsigned int messageSent;
    unsigned int messageAcked;
    int messageSize;
} clientSnapshot_t;
typedef struct
{
    char command[MAX_STRINGLENGTH];
    int cmdTime;
    int cmdType;
} reliableCommands_t;
typedef struct gclient_s gclient_t;
typedef struct gentity_s gentity_t;
typedef enum
{
    CON_DISCONNECTED,
    CON_CONNECTING,
    CON_CONNECTED
} clientConnected_t;
typedef enum
{
    STATE_PLAYING,
    STATE_DEAD,
    STATE_SPECTATOR,
    STATE_INTERMISSION
} sessionState_t;
typedef struct
{
    sessionState_t sessionState;
    int forceSpectatorClient;
    int statusIcon;
    int archiveTime;
    int score;
    int deaths;
    byte gap[4];
    clientConnected_t connected;
    usercmd_t cmd;
    usercmd_t oldcmd;
    qboolean localClient;
    byte gap2[8];
    char netname[MAX_NETNAME];
    int maxHealth;
    byte gap3[128];
} clientSession_t;

struct gclient_s
{
    playerState_t ps;
    clientSession_t sess;
    int spectatorClient;
    qboolean noclip;
    qboolean ufo;
    byte gap2[228];
};
struct gentity_s
{
    //entityState_t s;        // 0x0
    //entityShared_t r;       // 0xF0
	unsigned char _pad[240];
	unsigned char _pad2[100];

    byte gap_0x154[0x4];

    gclient_t *client;      // 0x158

    byte gap_0x15C[0x34];
    int clipmask;           // 0x190
    byte gap_0x194[0x180];
};
// typedef struct gentity_s
// {
//     unsigned char _pad[788]; // 200000000000000iq shit lol
// } gentity_t;


typedef struct client_s
{
    clientConnectState_t state;
    qboolean sendAsActive;
    const char *dropReason;
    char userinfo[MAX_INFO_STRING];
    reliableCommands_t reliableCommands[MAX_RELIABLE_COMMANDS];
    int reliableSequence;
    int reliableAcknowledge;
    int reliableSent;
    int messageAcknowledge;
    int gamestateMessageNum;
    int challenge;
    usercmd_t lastUsercmd;
    int lastClientCommand;
    char lastClientCommandString[MAX_STRINGLENGTH];
    gentity_t *gentity;
	char name[MAX_NAME_LENGTH];
    char downloadName[MAX_QPATH];
    fileHandle_t download;
    int downloadSize;
    int downloadCount;
    int downloadClientBlock;
    int downloadCurrentBlock;
    int downloadXmitBlock;
    unsigned char *downloadBlocks[MAX_DOWNLOAD_WINDOW];
    int downloadBlockSize[MAX_DOWNLOAD_WINDOW];
    qboolean downloadEOF;
    int downloadSendTime;
    int deltaMessage;
    int nextReliableTime;
    int lastPacketTime;
    int lastConnectTime;
    int nextSnapshotTime;
    qboolean rateDelayed;
    int timeoutCount;
    clientSnapshot_t frames[PACKET_BACKUP];
    int ping;
    int rate;
    int snapshotMsec;
    int pureAuthentic;
    netchan_t netchan;
    unsigned short clscriptid;
    int bIsTestClient;
    int serverId;
} client_t;


typedef struct {
	netadr_t adr; //0
	int challenge; //20
	int time; //24
	int pingTime; //28
	int firstTime; //32
	int firstPing; //36
	int connected; //40
} challenge_t;

char *Cvar_InfoString_RAH(int bit);

typedef void (*Cmd_RemoveCommand_t)(const char* cmd_name);
extern Cmd_RemoveCommand_t Cmd_RemoveCommand;

typedef void(*Cvar_Set_t)(const char*, const char*);
typedef cvar_t* (*Cvar_Get_t)(const char*, const char*, int);

typedef void(*Cvar_Set2_t)(const char*, const char*);

typedef cvar_t* (*Cvar_FindVar_t)(const char*);

typedef char* (*Cvar_InfoString_t)(unsigned short bit);
extern Cvar_InfoString_t Cvar_InfoString;

typedef char* (*Cvar_InfoString_Big_t)(int bit);
extern Cvar_InfoString_Big_t Cvar_InfoString_Big;

typedef void (__cdecl *FS_AddPakFilesForGameDirectory_t)(const char*, const char*);
extern FS_AddPakFilesForGameDirectory_t FS_AddPakFilesForGameDirectory;

typedef void (*FS_AddGameDirectory_t)(const char*, const char*, qboolean);
extern FS_AddGameDirectory_t FS_AddGameDirectory;

typedef void(*FS_Restart_t)(int);
extern FS_Restart_t FS_Restart;

extern Cvar_Set_t Cvar_Set;
extern Cvar_Get_t Cvar_Get;
extern Cvar_Set2_t Cvar_Set2;

extern Cvar_FindVar_t Cvar_FindVar;

qboolean    NET_StringToAdr(const char *s, netadr_t *a);
char* Cvar_VariableString(const char*);
int Cvar_VariableIntegerValue(const char* var_name);
float Cvar_VariableValue(const char *var_name);
void __cdecl Com_sprintf(char* dest, int size, const char* fmt, ...);
void Info_RemoveKey(char* s, const char* key);
void Info_RemoveKey_Big(char* s, const char* key);
void Info_SetValueForKey(char *s, const char *key, const char *value);
const char* Info_ValueForKey(const char* s, const char* key); //FIXME: overflow check?
int Q_stricmpn(const char* s1, const char* s2, int n);
int Q_stricmp(const char* s1, const char* s2);
std::string getFormattedDate();
std::string getFormattedTime();


char* Cmd_Argv(int index);
int Cmd_Argc();

typedef void(*Com_Printf_t)(const char*, ...);
extern Com_Printf_t Com_Printf;
typedef void(*Com_DPrintf_t)(const char*, ...);
extern Com_DPrintf_t Com_DPrintf;



typedef void(*Com_Error_t)(int, const char*, ...);
extern Com_Error_t Com_Error;

typedef void(*xfunc)(void);

typedef void(*Cmd_AddCommand_t)(const char*, xfunc);
extern Cmd_AddCommand_t Cmd_AddCommand;

typedef void(*SCR_DrawString_t)(float x, float y, int fontID, float scale, float* color, const char* text, float spaceBetweenChars, int maxChars, int arg9);
extern SCR_DrawString_t SCR_DrawString;

typedef void (*Cbuf_AddText_t)(const char* text);
extern Cbuf_AddText_t Cbuf_AddText;

typedef void (*Cbuf_ExecuteText_t)(cbufExec_t exec_when, const char* text);
extern Cbuf_ExecuteText_t Cbuf_ExecuteText;

typedef void (*SV_DirectConnect_t)(netadr_t from);
extern SV_DirectConnect_t SV_DirectConnect;

typedef void(*NET_OutOfBandPrint_t)(netsrc_t, netadr_t, const char*, ...);
extern NET_OutOfBandPrint_t NET_OutOfBandPrint;

typedef const char * (*NET_AdrToString_t)(netadr_t a);
extern NET_AdrToString_t NET_AdrToString;

typedef void (*Cmd_TokenizeString_t)(const char*, int);
extern Cmd_TokenizeString_t Cmd_TokenizeString;

typedef void(*idkwhat_t)(msg_t);
extern idkwhat_t idkwhat;

typedef qboolean (*NET_CompareBaseAdr_t)(netadr_t a, netadr_t b);
extern NET_CompareBaseAdr_t NET_CompareBaseAdr;

// typedef void (*Info_SetValueForKey_t)(char *s, const char *key, const char *value);
// extern Info_SetValueForKey_t Info_SetValueForKey;

// typedef char* (*Info_ValueForKey_t)(const char *s, const char *key);
// extern Info_ValueForKey_t Info_ValueForKey;

typedef void (*Info_SetValueForKey_Big_t)(char *s, const char *key, const char *value);
extern Info_SetValueForKey_Big_t Info_SetValueForKey_Big;

///////////// ######## GSC ######## /////////////
#include <cstdint>
#define MAX_CLIENTS 64
typedef unsigned char byte;

typedef struct scr_entref_s
{
    uint16_t entnum;
    uint16_t classnum;
} scr_entref_t;

union VariableUnion
{
    int intValue;
    float floatValue;
    unsigned int stringValue;
    const float *vectorValue;
    const char *codePosValue;
    unsigned int pointerValue;
    //...
};

typedef struct
{
    union VariableUnion u;
    int type;
} VariableValue;

typedef struct
{
    const char *fieldBuffer;
    byte pad[0x4176];
    unsigned int levelId;
    // ...
    const char *programBuffer;
    // ... 
} scrVarPub_t; // TODO: finish setup
typedef struct
{
    unsigned int *localVars;
    byte pad[356];
    VariableValue *top;
    //...
} scrVmPub_t; // TODO: verify

typedef void (*xfunction_t)();
typedef void (*xmethod_t)(scr_entref_t);

typedef struct scr_function_s
{
    const char      *name;
    xfunction_t     call;
    qboolean        developer;
} scr_function_t;

typedef struct scr_method_s
{
    const char     *name;
    xmethod_t      call;
    qboolean       developer;
} scr_method_t;
typedef struct
{
    qboolean initialized;
    int time;
    int snapFlagServerBit;
    client_t *clients;
    //...
} serverStatic_t;
typedef void *unzFile;



typedef char* (*SL_ConvertToString_t)(unsigned int);
typedef void (*Scr_MakeArray_t)();
typedef void (*Scr_AddArray_t)();
typedef void (*Scr_Error_t)(const char*);
typedef int (*Scr_AddFloat_t)(float);
typedef int (*Scr_AddInt_t)(int);
typedef int (*Scr_AddBool_t)(bool);
typedef int (*Scr_AddString_t)(char*);
typedef int (*Scr_AddVector_t)(vec3_t);
typedef int (*Scr_AddUndefined_t)();
typedef void (*Scr_AddEntity_t)(int*);
typedef int (*Scr_GetNumParam_t)();
typedef int (*Scr_GetPointerType_t)(int);
typedef int (*Scr_GetType_t)(int);
typedef void (*Com_PrintMessage_t)(int channel, const char *message);

typedef xfunction_t (*Scr_GetFunction_t)(const char**, int*);
typedef xmethod_t   (*Scr_GetMethod_t)(const char**, qboolean*);
typedef client_t * (*SV_GetPlayerByNum_t)(void);
typedef void (*SV_DropClient_t)(client_t *drop, const char *reason);


extern SL_ConvertToString_t SL_ConvertToString;
extern Scr_MakeArray_t Scr_MakeArray;
extern Scr_AddArray_t Scr_AddArray;
extern Scr_Error_t Scr_Error;
extern Scr_GetNumParam_t Scr_GetNumParam;
extern Scr_GetPointerType_t Scr_GetPointerType;
extern Scr_GetType_t Scr_GetType;
extern Scr_AddInt_t Scr_AddInt;
extern Scr_AddBool_t Scr_AddBool;
extern Scr_AddString_t Scr_AddString;
extern Scr_AddVector_t Scr_AddVector;
extern Scr_AddUndefined_t Scr_AddUndefined;
extern Scr_AddEntity_t Scr_AddEntity;

extern Scr_GetFunction_t Scr_GetFunction;
extern Scr_GetMethod_t Scr_GetMethod;

extern Com_PrintMessage_t Com_PrintMessage;
extern SV_GetPlayerByNum_t SV_GetPlayerByNum;
extern SV_DropClient_t SV_DropClient;

static const int svs_offset = 0x16B2AA0;
static const int varpub_offset = 0x976468;
static const int vmpub_offset = 0xA7A508;

#define scrVarPub (*((scrVarPub_t*)( varpub_offset )))
#define scrVmPub (*((scrVmPub_t*)( vmpub_offset )))
#define svs (*((serverStatic_t*)( svs_offset )))
//////////////////////////////////////////////////
char* va(const char* format, ...);

void Q_strncpyz(char *dest, const char *src, int destsize);
char* Q_CleanStr(char* string, bool colors = false);
char* Com_CleanHostname(char* hostname, bool colors);
const char* Com_CleanForFile(const char* input);
char* Com_CleanMapname(char* mapname);
const char* Com_GametypeName(char* gt, bool colors = false);

int MSG_ReadLong( msg_t *msg );
char *MSG_ReadStringLine( msg_t *msg );
msg_t *MSG_BeginReading(msg_t *msg);