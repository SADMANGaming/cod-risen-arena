// 4002E7A0 = 1.1

#include "game.hpp"
#include <windows.h>
#include <mmsystem.h>
#include "hooks.hpp"
#include <cstdint>
#include <string>
DWORD game_mp;


void G_Init(DWORD base)
{
	game_mp = base;
    gentity_t* g_entities2 = (gentity_t*)GAME_OFF(0x2016F220);  // Base address

    MessageBoxA(NULL, std::string(("g_entities:") + std::to_string((int)g_entities2)).c_str(), "Error", MB_OK | MB_ICONERROR);
}