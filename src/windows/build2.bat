@echo off
title [devCoD - Risen Arena] WINDOWS - DEBUG
cls

echo BUILDING...
md objects

echo ================================================================
echo                  BUILDING MSS32.DLL
echo.

REM Loop through all cpp files in current directory
for %%f in (*.cpp) do (
    echo ##### COMPILE %%f #####
    g++ -c -g "%%f" -o "objects/%%~nf.opp"
)

echo ##### LINK MSS32.dll #####
g++ -m32 -shared  -fexceptions -o ..\..\bin\mss32.dll objects\*.opp -lwinmm -ldbghelp -lws2_32 -lwininet -lshlwapi

echo.
echo                           DONE
echo ================================================================

rd /s /q objects

echo BUILDING DONE!
pause
