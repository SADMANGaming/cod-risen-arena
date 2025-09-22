#include "file_system.hpp"
#include "functions.hpp"
extern cvar_t* fs_basegame;

void _FS_Init()
{
	fs_basegame = Cvar_Get("fs_basegame", "ra", CVAR_ROM);
}