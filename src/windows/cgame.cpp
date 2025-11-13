#include "cgame.hpp"
DWORD cgame_mp;
#include <windows.h>
#include <mmsystem.h>
#include "hooks.hpp"
#include <cstdint>
#include <math.h>
#include <string>

cvar_t *cg_Speedometer;
cvar_t *cg_fixedAspect;
trap_R_stretchpic_t trap_R_stretchpic;
// CG_Syscall_t CG_Syscall = (CG_Syscall_t)0x30074898; FUCK THIS MF

cHook *hook_CG_DrawUpperRight;
static void custom_CG_DrawUpperRight()
{
	hook_CG_DrawUpperRight->unhook();
	void (*CG_DrawUpperRight)();
	*(int *)&CG_DrawUpperRight = hook_CG_DrawUpperRight->from;
	CG_DrawUpperRight();
	hook_CG_DrawUpperRight->hook();

	if (cg_Speedometer->integer)
		Draw_Speedometer();

}

static void Draw_Speedometer()
{
	const auto x = 280;
	const auto y = 420;
	const auto fontID = 4;
	const auto scale = 0.25f;
	float color[4] = { 1.f, 1.f, 1.f, 1.0f };
	float color_shadow[4] = { 0.f, 0.f, 0.f, 0.80f };
	float velY = cg_velocity_Y;
	float velX = cg_velocity_X;
	float velZ = cg_velocity_Z;

	float speed = sqrtf(velX * velX + velY * velY);

	if (cg_Speedometer->integer == 2)
		speed = sqrtf(velX * velX + velY * velY + velZ * velZ);

	std::string text = va("Speed: %.2f", speed);

	SCR_DrawString(x + 1, y + 1, fontID, scale, color_shadow, text.c_str(), NULL, NULL, NULL);
	SCR_DrawString(x, y, fontID, scale, color, text.c_str(), NULL, NULL, NULL);
}

#define FPS_FRAMES 4
extern cvar_t* cg_drawFPS;
extern cvar_t* cg_drawFPS_x;
extern cvar_t* cg_drawFPS_y;
void _CG_DrawFPS(float y)
{
	if (cg_drawFPS->integer && cg_drawFPS->integer == 3)
	{
		//TODO: do like original code instead

		static int previousTimes[FPS_FRAMES];
		static int index;
		int	i, total;
		int	fps;
		static int previous;
		int	t, frameTime;

		t = timeGetTime();
		frameTime = t - previous;
		previous = t;
		previousTimes[index % FPS_FRAMES] = frameTime;
		index++;

		if (index > FPS_FRAMES)
		{
			total = 0;
			for (i = 0; i < FPS_FRAMES; i++)
			{
				total += previousTimes[i];
			}
			if (!total)
			{
				total = 1;
			}
			fps = 1000 * FPS_FRAMES / total;

			const char* s; // = va("%ifps", fps);
			if(fps < 60)
			{
				s = va("^1%ifps", fps);
			} else {
				s = va("%ifps", fps);
			}

			void(*CG_DrawBigString)(float x, float y, const char* s, float alpha);
			*(int*)&CG_DrawBigString = CGAME_OFF(0x30019710);
			CG_DrawBigString(cg_drawFPS_x->integer, cg_drawFPS_y->integer, s, 1.0F);
		}
	}
	else
	{
		void(*CG_DrawFPS)(float);
		*(int*)&CG_DrawFPS = CGAME_OFF(0x30014A00);
		CG_DrawFPS(y);
	}
}




void CG_Init(DWORD base)
{
	cgame_mp = base;


	cg_Speedometer = Cvar_Get("cg_Speedometer", "0", CVAR_ARCHIVE);
	cg_fixedAspect = Cvar_Get("cg_fixedAspect", "1", CVAR_ARCHIVE);

	trap_R_stretchpic = (trap_R_stretchpic_t)CGAME_OFF(0x300310f0);
	// CG_Syscall = (CG_Syscall_t)CGAME_OFF(0x30074898);


	void CG_DrawWeapReticle_Stub(float x, float y, float w, float h, float s1, float t1, float s2, float t2, qhandle_t hShader);	
    void CG_DrawReticleParts_Stub(float x, float y, float w, float h, float s1, float t1, float s2, float t2, qhandle_t hShader);

	hook_CG_DrawUpperRight = new cHook(CGAME_OFF(0x30015070), (int)custom_CG_DrawUpperRight);
	hook_CG_DrawUpperRight->hook();

	__call(CGAME_OFF(0x3001509E), (int)_CG_DrawFPS);

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

	__nop(CGAME_OFF(0x3002CC29), 6); // Voice chat not found error, leftover from quake3.
	__nop(CGAME_OFF(0x300217BA), 5); // Railcore shader not found warning, leftover from quake3.
    
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