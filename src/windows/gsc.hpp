#ifndef GSC_HPP
#define GSC_HPP

#include <cstring> // For strcasecmp
#include <Windows.h>
#include <string>
#include <stdio.h>
#include <iostream>
#include <sys/stat.h>
#include <map>
#include <cstdint> // For uintptr_t
#include "functions.hpp"

#include "gsc_player.hpp"

#define STACK_UNDEFINED 0
#define STACK_STRING 1
#define STACK_LOCALIZED_STRING 2
#define STACK_VECTOR 3
#define STACK_FLOAT 4
#define STACK_INT 5
#define STACK_CODEPOS 6
#define STACK_OBJECT 7
#define STACK_KEY_VALUE 8
#define STACK_FUNCTION 9
#define STACK_STACK 10
#define STACK_ANIMATION 11
#define STACK_THREAD 12
#define STACK_ENTITY 13
#define STACK_STRUCT 14
#define STACK_ARRAY 15
#define STACK_DEAD_THREAD 16
#define STACK_DEAD_ENTITY 17
#define STACK_DEAD_OBJECT 18


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

int stackGetParams(const char *params, ...);
void stackError(const char *format, ...);
#ifndef Q_vsnprintf
int Q_vsnprintf(char *s0, size_t size, const char *fmt, va_list args);
#endif
int stackGetParamInt(int param, int *value);
int stackGetParamFunction(int param, int *value);
int stackGetParamString(int param, char **value);
int stackGetParamConstString(int param, unsigned int *value);
int stackGetParamLocalizedString(int param, char **value);
int stackGetParamVector(int param, vec3_t value);
int stackGetParamFloat(int param, float *value);
int stackGetParamObject(int param, unsigned int *value);


xfunction_t Scr_GetCustomFunction(const char **fname, int *fdev);
xmethod_t Scr_GetCustomMethod(const char **fname, qboolean *fdev);

void gsc_testfunction(void);
void gsc_testmethod(scr_entref_t ent);
void gsc_testmethod2(scr_entref_t ref);
#endif // GSC_HPP