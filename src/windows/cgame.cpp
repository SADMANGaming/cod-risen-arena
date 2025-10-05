#include "cgame.hpp"
DWORD cgame_mp;
#include "functions.hpp"
#include <windows.h>
#include <mmsystem.h>


void CG_Init(DWORD base)
{
	cgame_mp = base;
	
}