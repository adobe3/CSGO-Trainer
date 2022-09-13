#include "Memory.h"
#include "../Logging/Logging.h"
#include "../../Game/Game.h"

DWORD Memory::GetProcessId(const char* windowTitle) 
{
    DWORD processId = 0;

    HWND hwnd = FindWindowA(NULL, windowTitle);

    if (!hwnd)
        Logging::LogErrorMB(skCrypt("Failed to locate process identifier, please make sure the target application is running."));

    GetWindowThreadProcessId(hwnd, &processId);

    return processId;
}

uintptr_t Memory::GetModuleAddress(DWORD processId, const wchar_t* moduleName) 
{
    uintptr_t modBaseAddr = 0;

    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, processId);
    if (hSnap != INVALID_HANDLE_VALUE)
    {
        MODULEENTRY32 modEntry;
        modEntry.dwSize = sizeof(modEntry);
        if (Module32First(hSnap, &modEntry))
        {
            do
            {
                if (!_wcsicmp(modEntry.szModule, moduleName))
                {
                    modBaseAddr = (uintptr_t)modEntry.modBaseAddr;
                    break;
                }
            } while (Module32Next(hSnap, &modEntry));
        }
    }

    CloseHandle(hSnap);

    return modBaseAddr;
}

void Memory::GetWindow(const char* windowTitle, HWND& hwnd, int& width, int& height, int& x, int& y) 
{
    hwnd = FindWindowA(NULL, windowTitle);

    if (!hwnd)
        Logging::LogErrorMB(skCrypt("Failed to locate the target window, please make sure the application is running."));

    RECT RECT;
    GetWindowRect(hwnd, &RECT);

    width = RECT.right - RECT.left;
    height = RECT.bottom - RECT.top;
    x = RECT.left;
    y = RECT.top;
}