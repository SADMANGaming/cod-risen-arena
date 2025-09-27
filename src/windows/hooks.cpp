#include <windows.h>
#include "hooks.hpp"

void hook_jmp(int from, int to)
{
    int relative = to - (from + 5); // +5 is the position of next opcode
    memset((void*)from, 0xE9, 1); // JMP-OPCODE
    memcpy((void*)(from + 1), &relative, 4); // set relative address with endian
}

cHook::cHook(int from, int to)
{
    this->from = from;
    this->to = to;
}

void cHook::hook()
{
    memcpy((void*)oldCode, (void*)from, 5);
    hook_jmp(from, to);
}

void cHook::unhook()
{
    memcpy((void*)from, (void*)oldCode, 5);
}

uint8_t originalBytes[5];
void AttachFunction(uintptr_t target, void* detour)
{
    DWORD oldProtect;
    VirtualProtect((void*)target, 5, PAGE_EXECUTE_READWRITE, &oldProtect);

    // Save original bytes
    memcpy(originalBytes, (void*)target, 5);

    // Calculate relative jump
    intptr_t rel = (intptr_t)detour - (intptr_t)target - 5;
    *(uint8_t*)target = 0xE9;              // JMP opcode
    *(int32_t*)((uint8_t*)target + 1) = (int32_t)rel;

    VirtualProtect((void*)target, 5, oldProtect, &oldProtect);
}