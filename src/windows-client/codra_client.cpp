#include "functions.hpp"
#include "cl_commands.hpp"

cvar_t* cl_running;
cvar_t* com_cl_running;
cvar_t* protocol;
cvar_t* fs_basegame;
cvar_t* g_vanilla;

static void(*Com_Quit_f)() = (void(*)())0x0043a2c0;

void _Check_FS_Bg()
{
	if (fs_basegame && fs_basegame->string && strcmp(fs_basegame->string, "ra") == 0)
	{
		Com_Quit_f();
	}
}

void _CL_Init(void)
{
	void(*CL_Init)();
	* (int*)(&CL_Init) = 0x411E60;
	CL_Init();

    Cvar_Set("version", va("CoDRA MP 1.00.0 build %d %s %s win-x86", 10000, __DATE__, __TIME__));

	Cvar_Get("codra-cl", "1", CVAR_USERINFO | CVAR_ROM);

    Cvar_Get("g_vanilla", "0", CVAR_ROM);

	com_cl_running = Cvar_Get("cl_running", "0", CVAR_ROM);
	cl_running = Cvar_FindVar("cl_running");

	Cvar_Set("com_hunkmegs", "512");

	Cvar_Set("sv_hostname", "CoDRAHost");

	Cmd_AddCommand("minimize", Cmd_Minimize);
}

void _Com_Init()
{
	Cvar_Get("shortversion", "1.00.0", 68);
	Cvar_Set("shortversion", "1.00.0");
	void(*Com_Init)(void);
	* (int*)(&Com_Init) = 0x004375c0;
	Com_Init();
}

void _Change_Protocol()
{
	Cvar_Set2("protocol", "221");
	//Cvar_Set2("sv_master1", "");
}

