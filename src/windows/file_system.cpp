#include "file_system.hpp"
#include "functions.hpp"

cvar_t* fs_basegame;

void _FS_Init()
{
	fs_basegame = Cvar_Get("fs_basegame", "ra", CVAR_ROM);
}



void _Check_FS_Bg()
{
	if (fs_basegame && fs_basegame->string && strcmp(fs_basegame->string, "ra") == 0)
	{
		Com_Quit_f();
	}
}