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

copy "C:\Users\SADMAN\Desktop\Call of Duty - Risen Arena\Dev\risen-arena-1.0.0\bin\mss32.dll" "C:\Users\SADMAN\Desktop\Call of Duty - Risen Arena\Game" /y
"C:\Users\SADMAN\Desktop\Call of Duty - Risen Arena\Game\CoDMP.exe" +set developer 1 +set fs_movies "movies" +set dedicated 2 +set g_gametype bel +map Mp_Harbor

echo BUILDING DONE!
pause
