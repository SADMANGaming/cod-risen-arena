@echo off
title [VCODLIB] WINDOWS - DEBUG
cls
echo BUILDING...
md objects

echo ================================================================
echo                  BUILDING CODSO.DLL

echo ##### COMPILE HOOKS.CPP #####
g++ -c -g hooks.cpp -o objects/hooks.opp

echo ##### COMPILE MSS32.CPP #####
g++ -c -g proxy_code_clean.cpp -o objects/mss32.opp

echo ##### COMPILE FUNCTIONS.CPP #####
g++ -c -g functions.cpp -o objects/functions.opp

echo ##### COMPILE CVARS.CPP #####
g++ -c -g cvars.cpp -o objects/cvars.opp

echo ##### COMPILE FILE_SYSTEM.CPP #####
g++ -c -g file_system.cpp -o objects/file_system.opp

echo ##### COMPILE CL_COMMANDS.CPP #####
g++ -c -g cl_commands.cpp -o objects/cl_commands.opp

echo ##### COMPILE CODRA_CLIENT.CPP #####
g++ -c -g codra_client.cpp -o objects/codra_client.opp

echo ##### COMPILE CODRA_SERVER.CPP #####
g++ -c -g codra_server.cpp -o objects/codra_server.opp

echo #### COMPILE CRASH_HANDLER.CPP ####
g++ -c -g crash_handler.cpp -o objects/crash_handler.opp -ldbghelp

echo #### COMPILE MAIN.CPP ####
g++ -c -g main.cpp -o objects/main.opp -Wno-attributes

echo ##### LINK MSS32.dll #####
g++ -m32 -shared -o ..\bin\mss32.dll objects\*.opp -lwinmm -ldbghelp -lws2_32


echo                           DONE
echo ================================================================


rd /s /q objects

echo BUILDING DONE!
pause
