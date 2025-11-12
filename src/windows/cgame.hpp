#include <windows.h>
#include "functions.hpp"

void CG_Init(DWORD base);


#define cg_refdef_width  (*(int*)CGAME_OFF(0x30209584))
#define cg_refdef_height (*(int*)CGAME_OFF(0x30209588))

#define weaponbase (*(char**)CGAME_OFF(0x30209484))

// typedef int (__cdecl *CG_Syscall_t)(int, ...);
// extern CG_Syscall_t CG_Syscall;

template<typename... Args>
int CG_ShitassSyscall(cgameImport_t cmd, Args... args)
{
    auto fn = *(int(__cdecl**)(cgameImport_t, ...))CGAME_OFF(0x30074898);
    return fn(cmd, args...);
}


typedef void(*trap_R_stretchpic_t)(float x, float y, float w, float h, float s1, float t1, float s2, float t2, qhandle_t hShader);
extern trap_R_stretchpic_t trap_R_stretchpic;
