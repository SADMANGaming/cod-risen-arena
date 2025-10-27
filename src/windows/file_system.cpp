#include "file_system.hpp"
#include "functions.hpp"
#include <direct.h>
#include "hooks.hpp"
FS_AddPakFilesForGameDirectory_t FS_AddPakFilesForGameDirectory = (FS_AddPakFilesForGameDirectory_t)0x042bd30;
FS_AddGameDirectory_t FS_AddGameDirectory = (FS_AddGameDirectory_t)0x42C250;
FS_Restart_t FS_Restart = (FS_Restart_t)0x0042d2b0;

cvar_t* fs_basegame;
cvar_t* fs_movies;
//cvar_t *fs_basepath;

typedef void (*FS_Startup_t)(const char *);
FS_Startup_t FS_Startup_original = (FS_Startup_t)0x0042CDB0;

void _FS_Startup(const char *gameName)
{

 	fs_basegame = Cvar_Get("fs_basegame", "ra", CVAR_ROM);
	fs_movies = Cvar_Get("fs_movies", "movies", CVAR_ARCHIVE);

	FS_Startup_original(gameName);
}

cHook *hook_FS_AddCommands;
void custom_FS_AddCommands()
{

	if (*clc_demoplaying) {
		if(fs_movies->string)
		{
			const char* fs_basepath = Cvar_VariableString("fs_basepath");
			FS_AddGameDirectory(fs_basepath, fs_movies->string, qfalse);
		}
    } //

	hook_FS_AddCommands->unhook();
    void (*FS_AddCommands)();
    *(int *)&FS_AddCommands = hook_FS_AddCommands->from;
    FS_AddCommands();
	hook_FS_AddCommands->hook();
	
	//0x43BA80
}

cHook *hook_CL_PlayDemo_f;
void custom_CL_PlayDemo_f()
{
    hook_CL_PlayDemo_f->unhook();
    void (*CL_PlayDemo_f)();
    *(int *)&CL_PlayDemo_f = hook_CL_PlayDemo_f->from;
    CL_PlayDemo_f();
	hook_CL_PlayDemo_f->hook();
}

cHook *hook_CL_DemoCompleted;
void custom_CL_DemoCompleted()
{
    hook_CL_DemoCompleted->unhook();
    void (*CL_DemoCompleted)();
    *(int *)&CL_DemoCompleted = hook_CL_DemoCompleted->from;
    CL_DemoCompleted();
	hook_CL_DemoCompleted->hook();

}


void _Check_FS_Bg()
{
	if (fs_basegame && fs_basegame->string && strcmp(fs_basegame->string, "ra") == 0)
	{
		Com_Quit_f();
	}
}