#include "file_system.hpp"
#include "functions.hpp"
#include <direct.h>

FS_AddPakFilesForGameDirectory_t FS_AddPakFilesForGameDirectory = (FS_AddPakFilesForGameDirectory_t)0x042bd30;
FS_AddGameDirectory_t FS_AddGameDirectory = (FS_AddGameDirectory_t)0x042c250;
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


    const char *fs_cdpath   = Cvar_VariableString("fs_cdpath");
    const char *fs_basepath = Cvar_VariableString("fs_basepath");
    const char *fs_homepath = Cvar_VariableString("fs_homepath");

    if (fs_basepath[0] && fs_basepath[0] && Q_stricmp(fs_homepath, fs_basepath)) {
        FS_AddGameDirectory(fs_homepath, "movies", qfalse, 0);
    }

	FS_Startup_original(gameName);
}



// void _FS_Startup(const char *gameName)
// {

// 	char cwd[MAX_OSPATH];
// 	_getcwd (cwd, sizeof(cwd));

// 	fs_basegame = Cvar_Get("fs_basegame", "ra", CVAR_ROM);
// 	fs_movies = Cvar_Get ("fs_movies", "movies", CVAR_ARCHIVE );

// 	//fs_basepath = Cvar_Get ("fs_basepath", cwd, CVAR_INIT );

// 	const char *fs_cdpath = Cvar_VariableString("fs_cdpath");
// 	const char *fs_basepath = Cvar_VariableString("fs_basepath");
// 	const char *fs_homepath = Cvar_VariableString("fs_homepath");

// 	if (fs_basepath[0] && Q_stricmp(fs_homepath,fs_basepath)) {
// 		FS_AddGameDirectory(fs_homepath, fs_movies->string, qfalse, 0);
// 		FS_AddGameDirectory(fs_cdpath, fs_movies->string, qtrue, 0);
// 	}
	

// 	void(*FS_Startup)(const char *gameName);
// 	* (int*)(&FS_Startup) = 0x0042cdb0;
// 	FS_Startup(gameName);
// }

void _Check_FS_Bg()
{
	if (fs_basegame && fs_basegame->string && strcmp(fs_basegame->string, "ra") == 0)
	{
		Com_Quit_f();
	}
}