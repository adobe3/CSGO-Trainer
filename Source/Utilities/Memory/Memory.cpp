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

std::string Memory::GetRandomString(int len) 
{
    srand(time(NULL));
    std::string str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::string newstr;
    int pos;
    while (newstr.size() != len) {
        pos = ((rand() % (str.size() - 1)));
        newstr += str.substr(pos, 1);
    }
    return newstr;
}

std::string Memory::StringToUTF8(const std::string& str) 
{
    int nwLen = ::MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);
    wchar_t* pwBuf = new wchar_t[nwLen + 1];
    ZeroMemory(pwBuf, nwLen * 2 + 2);
    ::MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.length(), pwBuf, nwLen);
    int nLen = ::WideCharToMultiByte(CP_UTF8, 0, pwBuf, -1, NULL, NULL, NULL, NULL);
    char* pBuf = new char[nLen + 1];
    ZeroMemory(pBuf, nLen + 1);
    ::WideCharToMultiByte(CP_UTF8, 0, pwBuf, nwLen, pBuf, nLen, NULL, NULL);
    std::string retStr(pBuf);
    delete[]pwBuf;
    delete[]pBuf;
    pwBuf = NULL;
    pBuf = NULL;
    return retStr;
}