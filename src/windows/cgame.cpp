#include "cgame.hpp"
DWORD cgame_mp;
#include <windows.h>
#include <mmsystem.h>
#include "hooks.hpp"
#include <cstdint>


trap_R_stretchpic_t trap_R_stretchpic;
// CG_Syscall_t CG_Syscall = (CG_Syscall_t)0x30074898; FUCK THIS MF




void CG_Init(DWORD base)
{
	cgame_mp = base;


	trap_R_stretchpic = (trap_R_stretchpic_t)CGAME_OFF(0x300310f0);
	// CG_Syscall = (CG_Syscall_t)CGAME_OFF(0x30074898);


	void CG_DrawWeapReticle_Stub(float x, float y, float w, float h, float s1, float t1, float s2, float t2, qhandle_t hShader);	
    void CG_DrawReticleParts_Stub(float x, float y, float w, float h, float s1, float t1, float s2, float t2, qhandle_t hShader);

    __call(CGAME_OFF(0x30016114), (int)CG_DrawWeapReticle_Stub);    // top left quadrant - used to change scope
	__call(CGAME_OFF(0x30016134), (int)CG_DrawReticleParts_Stub);   // quadrant 2
	__call(CGAME_OFF(0x30016153), (int)CG_DrawReticleParts_Stub);   // quadrant 3
	__call(CGAME_OFF(0x30016173), (int)CG_DrawReticleParts_Stub);   // quadrant 4
	__call(CGAME_OFF(0x300163ad), (int)CG_DrawReticleParts_Stub);   // fg42 vertical
	__call(CGAME_OFF(0x30016406), (int)CG_DrawReticleParts_Stub);   // fg42 left
	__call(CGAME_OFF(0x30016494), (int)CG_DrawReticleParts_Stub);   // springfield vertical
	__call(CGAME_OFF(0x3001654f), (int)CG_DrawReticleParts_Stub);   // G43 vertical
	__call(CGAME_OFF(0x300165a9), (int)CG_DrawReticleParts_Stub);   // G43 left horizontal
	__call(CGAME_OFF(0x300165df), (int)CG_DrawReticleParts_Stub);   // fg24 & G43 right, springfield horizontal

    // NOP out CG_DrawReticleParts calls
    // __nop(CGAME_OFF(0x30016134), 5);   // quadrant 2
    // __nop(CGAME_OFF(0x30016153), 5);   // quadrant 3
    // __nop(CGAME_OFF(0x30016173), 5);   // quadrant 4
    // __nop(CGAME_OFF(0x300163ad), 5);   // fg42 vertical
    // __nop(CGAME_OFF(0x30016406), 5);   // fg42 left
    // __nop(CGAME_OFF(0x30016494), 5);   // springfield vertical
    // __nop(CGAME_OFF(0x3001654f), 5);   // G43 vertical
    // __nop(CGAME_OFF(0x300165a9), 5);   // G43 left horizontal
    // __nop(CGAME_OFF(0x300165df), 5);   // fg24 & G43 right, springfield horizontal
}