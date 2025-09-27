#include "functions.hpp"
#include "cl_commands.hpp"
#include "codra_client.hpp"
#include "freeze_detector.hpp"
#include "auto_updater.hpp"

cvar_t* cl_running;
cvar_t* com_cl_running;
cvar_t* protocol;
cvar_t* cl_freezeDetect;

void _CL_Init(void)
{
	void(*CL_Init)();
	* (int*)(&CL_Init) = 0x411E60;
	CL_Init();

    Cvar_Set("version", va("CoDRA MP 1.00.0 build %d %s %s win-x86", __RABUILD__, __DATE__, __TIME__));

	Cvar_Get("codra-cl", "1", CVAR_USERINFO | CVAR_ROM);


	com_cl_running = Cvar_Get("cl_running", "0", CVAR_ROM);
	cl_running = Cvar_FindVar("cl_running");
	cl_freezeDetect = Cvar_Get("cl_freezeDetect", "1", CVAR_ARCHIVE);

	Cvar_Set("com_hunkmegs", "512");

	Cvar_Set("sv_hostname", "CoDRAHost");

	Cmd_AddCommand("minimize", Cmd_Minimize);
	Cmd_AddCommand("update", Cmd_Update);
}

void _Com_Init()
{
	Cvar_Get("shortversion", __RAVERSION__, 68);
	Cvar_Set("shortversion", __RAVERSION__);


	void(*Com_Init)(void);
	* (int*)(&Com_Init) = 0x004375c0;
	Com_Init();
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

    call(msec);
}
