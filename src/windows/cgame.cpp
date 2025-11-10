#include "cgame.hpp"
DWORD cgame_mp;
#include "functions.hpp"
#include <windows.h>
#include <mmsystem.h>

cvar_t *cg_fixedAspect;
void CG_Init(DWORD base)
{
	cg_fixedAspect = Cvar_Get("cg_fixedAspect", "1", CVAR_ARCHIVE);
	cgame_mp = base;
	
}