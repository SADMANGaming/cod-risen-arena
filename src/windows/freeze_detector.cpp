#include <windows.h>
#include <chrono>
#include "freeze_detector.hpp"
#include "functions.hpp"

extern cvar_t* cl_freezeDetect;
extern bool stat_updating;
extern cvar_t* cl_running;

static std::chrono::steady_clock::time_point lastFrameTime;
static bool freezeReported = false;

void OnFrame() {
    lastFrameTime = std::chrono::steady_clock::now();
    freezeReported = false; // reset freeze warning
}

DWORD WINAPI FreezeDetector(LPVOID) {
    while (true) {
        if (cl_freezeDetect->integer == 0)
        {
            Sleep(1000);
            continue; // skip detection when disabled
        }
        if (stat_updating)
        {
            Sleep(1000);
            continue; // skip detection when disabled
        }
        if(cl_running->integer == 0)
        {
            Sleep(1000);
            continue; // skip detection when not in game
        }
        if(*cls_state == CA_CHALLENGING || *cls_state == CA_CONNECTING)
        {
            Sleep(1000);
            continue; // skip detection when not in game
        }

        auto now = std::chrono::steady_clock::now();
        auto diff = std::chrono::duration_cast<std::chrono::seconds>(now - lastFrameTime).count();

        if (diff > 3 && !freezeReported) { // no frame for 5 seconds
            freezeReported = true;
            MessageBoxA(nullptr,
                "For some reason, Call of Duty - Risen Arena has frozen.\nDo you want to quit Call of Duty - Risen Arena?",
                "CoD:Risen Arena",
                MB_ICONERROR);
            ExitProcess(0);
        }

        Sleep(1000);
    }
    return 0;
}


void InitFreezeDetection() {
    lastFrameTime = std::chrono::steady_clock::now();
    CreateThread(nullptr, 0, FreezeDetector, nullptr, 0, nullptr);
}
