#include "functions.hpp"
#include "codra_server.hpp"

void _SV_Init()
{
	char* v0 = va("%i", 7);
  	Cvar_Get("protocol", v0, 68);
  	Cvar_Set("protocol", v0);

	void(*SV_Init)();
	* (int*)(&SV_Init) = 0x00459130;
	SV_Init();
}