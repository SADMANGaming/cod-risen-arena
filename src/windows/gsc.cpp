#include "gsc.hpp"
#include <stdint.h>
#include <sys/time.h>
#include <unordered_map>
#include <string>

scr_function_t scriptFunctions[] =
{
    {"testFunction", gsc_testfunction, qfalse},
    {NULL, NULL, qfalse} // Terminator
};

scr_method_t scriptMethods[] =
{
    {"testMethod", gsc_testmethod, qfalse},
    {"getHWID", gsc_player_getHWID, qfalse},
    {"isBannedHWID", gsc_player_isBannedHWID, qfalse},
    {NULL, NULL, qfalse} // Terminator
};



xfunction_t Scr_GetCustomFunction(const char **fname, int *fdev)
{
    xfunction_t m = Scr_GetFunction(fname, fdev);  // Fix: Pass correct argument types
    if(m)
        return m;

    for (int i = 0; scriptFunctions[i].name; i++)
    {
        if(strcasecmp(*fname, scriptFunctions[i].name))
            continue;

        scr_function_t func = scriptFunctions[i];
        *fname = func.name;
        *fdev = func.developer;
        return func.call;
    }
    return NULL;
}


xmethod_t Scr_GetCustomMethod(const char **fname, qboolean *fdev)
{
    xmethod_t m = Scr_GetMethod(fname, fdev);  // Fix: Pass correct argument types
    if(m)
        return m;;

    for (int i = 0; scriptMethods[i].name; i++)
    {
        if(strcasecmp(*fname, scriptMethods[i].name))
            continue;
        
        scr_method_t func = scriptMethods[i];
        *fname = func.name;
        *fdev = func.developer;
        return func.call;
    }
    return NULL;
}

void gsc_testfunction()
{
    Com_Printf("ohioohio\n");
    stackPushUndefined();
}

void gsc_testmethod(scr_entref_t ref)
{
    Com_Printf("ohioohio\n");
}

void gsc_testmethod2(scr_entref_t ref)
{
    printf("##### gsc_testmethod2\n");

    int id = ref.entnum;

    if ( id >= MAX_CLIENTS )
    {
        stackError("gsc_player_testcommand() entity %i is not a player", id);
        stackPushUndefined();
        return;
    }

    client_t* client = &svs.clients[id];
    //gentity_t* gentity = &g_entities[id];
    //playerState_t *ps = SV_GameClientNum(id);
    //gclient_t *gclient = gentity->client;


    //Com_Printf("##### ps->gravity = %i\n", ps->gravity);
    //Com_Printf("##### ps->viewangles[0] = %f, ps->viewangles[1] = %f, ps->viewangles[2] = %f\n", ps->viewangles[0], ps->viewangles[1], ps->viewangles[2]);
}

void stackError(const char *format, ...)
{
    char s[MAX_STRINGLENGTH];
    int len = 0;
    va_list va;

    va_start(va, format);
    Q_vsnprintf(s, sizeof(s) - 1, format, va);
    va_end(va);

    len = strlen(s);
    s[len] = '\n';
    s[len + 1] = '\0';
    Com_PrintMessage(0, s);
    //Scr_CodeCallback_Error(qfalse, qfalse, "stackError", s);
    Scr_Error(s); //TODO: look about calling Scr_CodeCallback_Error instead
}

int stackGetParams(const char *params, ...)
{
    va_list args;
    va_start(args, params);

    int errors = 0;

    for ( size_t i = 0; i < strlen(params); i++ )
    {
        switch ( params[i] )
        {
        case ' ': // Ignore param
            break;

        case 'i':
        {
            int *tmp = va_arg(args, int *);
            if ( !stackGetParamInt(i, tmp) )
            {
                Com_DPrintf("\nstackGetParams() Param %i is not an int\n", i);
                errors++;
            }
            break;
        }

        case 'v':
        {
            float *tmp = va_arg(args, float *);
            if ( !stackGetParamVector(i, tmp) )
            {
                Com_DPrintf("\nstackGetParams() Param %i is not a vector\n", i);
                errors++;
            }
            break;
        }

        case 'f':
        {
            float *tmp = va_arg(args, float *);
            if ( ! stackGetParamFloat(i, tmp) )
            {
                Com_DPrintf("\nstackGetParams() Param %i is not a float\n", i);
                errors++;
            }
            break;
        }

        case 's':
        {
            char **tmp = va_arg(args, char **);
            if ( !stackGetParamString(i, tmp) )
            {
                Com_DPrintf("\nstackGetParams() Param %i is not a string\n", i);
                errors++;
            }
            break;
        }

        case 'c':
        {
            unsigned int *tmp = va_arg(args, unsigned int *);
            if ( !stackGetParamConstString(i, tmp) )
            {
                Com_DPrintf("\nstackGetParams() Param %i is not a const string\n", i);
                errors++;
            }
            break;
        }

        case 'l':
        {
            char **tmp = va_arg(args, char **);
            if ( !stackGetParamLocalizedString(i, tmp) )
            {
                Com_DPrintf("\nstackGetParams() Param %i is not a localized string\n", i);
                errors++;
            }
            break;
        }

        default:
            errors++;
            Com_DPrintf("\nUnknown identifier [%c] passed to stackGetParams()\n", params[i]);
            break;
        }
    }

    va_end(args);
    return errors == 0; // success if no errors
}

int stackGetParamInt(int param, int *value)
{
    if ( param >= Scr_GetNumParam() )
        return 0;

    VariableValue *var;
    var = &scrVmPub.top[-param];

    if ( var->type == STACK_FLOAT )
    {
        *value = var->u.floatValue;
        return 1;
    }

    if ( var->type != STACK_INT )
        return 0;

    *value = var->u.intValue;

    return 1;
}

int stackGetParamFunction(int param, int *value)
{
    printf("####### stackGetParamFunction\n");
    

    if ( param >= Scr_GetNumParam() )
        return 0;

    VariableValue *var;
    var = &scrVmPub.top[-param];

    if ( var->type != STACK_FUNCTION )
        return 0;

    *value = var->u.codePosValue - scrVarPub.programBuffer;

    return 1;
}

int stackGetParamString(int param, char **value)
{
    if ( param >= Scr_GetNumParam() )
        return 0;

    VariableValue *var;
    var = &scrVmPub.top[-param];

    if ( var->type != STACK_STRING )
        return 0;

    *value = SL_ConvertToString(var->u.stringValue);

    return 1;
}

int stackGetParamConstString(int param, unsigned int *value)
{
    if ( param >= Scr_GetNumParam() )
        return 0;

    VariableValue *var;
    var = &scrVmPub.top[-param];

    if ( var->type != STACK_STRING )
        return 0;

    *value = var->u.stringValue;

    return 1;
}

int stackGetParamLocalizedString(int param, char **value)
{
    if ( param >= Scr_GetNumParam() )
        return 0;

    VariableValue *var;
    var = &scrVmPub.top[-param];

    if ( var->type != STACK_LOCALIZED_STRING )
        return 0;

    *value = SL_ConvertToString(var->u.stringValue);

    return 1;
}

int stackGetParamVector(int param, vec3_t value)
{
    if ( param >= Scr_GetNumParam() )
        return 0;

    VariableValue *var;
    var = &scrVmPub.top[-param];

    if ( var->type != STACK_VECTOR )
        return 0;

    VectorCopy(var->u.vectorValue, value);

    return 1;
}

int stackGetParamFloat(int param, float *value)
{
    if ( param >= Scr_GetNumParam() )
        return 0;

    VariableValue *var;
    var = &scrVmPub.top[-param];

    if ( var->type == STACK_INT )
    {
        *value = var->u.intValue;
        return 1;
    }

    if ( var->type != STACK_FLOAT )
        return 0;

    *value = var->u.floatValue;

    return 1;
}

int stackGetParamObject(int param, unsigned int *value)
{
    if ( param >= Scr_GetNumParam() )
        return 0;

    VariableValue *var;
    var = &scrVmPub.top[-param];

    if ( var->type != STACK_OBJECT )
        return 0;

    *value = var->u.pointerValue;

    return 1;
}