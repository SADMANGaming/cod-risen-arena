@echo off
title [devCoD - Risen Arena] WINDOWS - DEBUG
cls

echo BUILDING...
taskkill /F /IM CoDMP.exe /T
rd /s /q objects
md objects

echo ================================================================
echo                  BUILDING MSS32.DLL
echo.

echo ##### COMPILE libs/sha256.c #####
g++ -c -g libs/sha256.c -o "objects/sha256.opp"

echo ##### COMPILE libs/qvsnprintf.c #####
g++ -c -g libs/qvsnprintf.c -o "objects/qvsnprintf.opp"

for %%f in (*.cpp) do (
    echo ##### COMPILE %%f #####
    g++ -c -g "%%f" -o "objects/%%~nf.opp"
)

echo ##### LINK MSS32.dll #####
g++ -m32 -shared  -fexceptions -o ..\..\bin\mss32.dll objects\*.opp -lwinmm -ldbghelp -lws2_32 -lwininet -lshlwapi -lwinmm -liphlpapi

echo.
echo                           DONE
echo ================================================================

rd /s /q objects

echo BUILDING DONE!
pause

