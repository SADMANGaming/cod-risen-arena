#pragma once
#include <windows.h>

// Declare the function (extern linkage)
bool CreateMiniDump(EXCEPTION_POINTERS* pep);

// Install the crash handler (call this once, e.g. in DllMain or WinMain)
void InstallCrashHandler();
