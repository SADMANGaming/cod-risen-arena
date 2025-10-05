#ifndef _SHARED_HPP_
#define _SHARED_HPP_

#include <unistd.h> // access
#include <stdint.h> // uint16_t
#include <cstdio> // printf, snprintf
#include <cstring> // strcasecmp, strlen, strcmp, strerror, strncpy...
#include <stdlib.h> // atoi
#include <stdarg.h> // va
#include <string>

#include "declarations.hpp"
#include "functions.hpp"

#include "gsc_player.hpp"

#define STACK_UNDEFINED 0
#define STACK_STRING 1
#define STACK_LOCALIZED_STRING 2
#define STACK_VECTOR 3
#define STACK_FLOAT 4
#define STACK_INT 5
#define STACK_OBJECT 7
#define STACK_FUNCTION 9

#define stackPushUndefined Scr_AddUndefined
#define stackPushBool Scr_AddBool
#define stackPushInt Scr_AddInt
#define stackPushFloat Scr_AddFloat
#define stackPushString Scr_AddString
#define stackPushVector Scr_AddVector
#define stackPushEntity Scr_AddEntity
#define stackPushArray Scr_MakeArray
#define stackPushArrayLast Scr_AddArray
#define stackPushObject Scr_AddObject
#define stackPushFunc Scr_AddFunc

extern uintptr_t resume_addr_Jump_Check;
extern uintptr_t resume_addr_Jump_Check_2;

extern customPlayerState_t customPlayerState[MAX_CLIENTS];


xfunction_t Scr_GetCustomFunction(const char **fname, qboolean *fdev);
xmethod_t Scr_GetCustomMethod(const char **fname, qboolean *fdev);

int Q_vsnprintf(char *s0, size_t size, const char *fmt, va_list args);

int stackGetParams(const char *params, ...);
void stackError(const char *format, ...);

int stackGetParamInt(int param, int *value);
int stackGetParamFunction(int param, int *value);
int stackGetParamString(int param, char **value);
int stackGetParamConstString(int param, unsigned int *value);
int stackGetParamLocalizedString(int param, char **value);
int stackGetParamVector(int param, vec3_t value);
int stackGetParamFloat(int param, float *value);
int stackGetParamObject(int param, unsigned int *value);


// For tests
void gsc_testfunction();
void gsc_testmethod(scr_entref_t ref);
#endif