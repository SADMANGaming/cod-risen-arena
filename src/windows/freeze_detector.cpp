#include <windows.h>
#include <chrono>
#include "freeze_detector.hpp"
#include "functions.hpp"

static std::chrono::steady_clock::time_point lastFrameTime;
static bool freezeReported = false;

void OnFrame() {
    lastFrameTime = std::chrono::steady_clock::now();
    freezeReported = false; // reset freeze warning
}

DWORD WINAPI FreezeDetector(LPVOID) {
    while (true) {
        auto now = std::chrono::steady_clock::now();
        auto diff = std::chrono::duration_cast<std::chrono::seconds>(now - lastFrameTime).count();

        if (diff > 5 && !freezeReported) { // no frame for 5 seconds
            freezeReported = true; // prevent multiple warnings
            MessageBoxA(nullptr, "For some reason, Call of Duty - Risen Arena has frozen.\nDo you want to quit Call of Duty - Risen Arena?", "CoD:Risen Arena", MB_ICONERROR);
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
