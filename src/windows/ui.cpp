// 4002E7A0 = 1.1

#include "ui.hpp"
#include <windows.h>
#include <mmsystem.h>
#include "hooks.hpp"
#include <cstdint>
DWORD ui_mp;


void UI_Init(DWORD base)
{
	ui_mp = base;
    PatchStr(UI_OFF(0x4002E7A0), __RAVERSION__ );
}