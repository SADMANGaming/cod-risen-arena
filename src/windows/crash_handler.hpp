#pragma once
#include <windows.h>

LONG WINAPI exception_handler(EXCEPTION_POINTERS* pExceptionInfo);
const char* exception_getText(DWORD exceptionCode);
bool exception_createMiniDump(EXCEPTION_POINTERS* pExceptionInfo);
void exception_init();
