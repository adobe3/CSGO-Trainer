#pragma once

#include "../../Stdafx.h"
#include "../../Game/Game.h"

namespace Memory 
{
    DWORD GetProcessId(const char* windowTitle);
    uintptr_t GetModuleAddress(DWORD processId, const wchar_t* moduleName);
    void GetWindow(const char* windowTitle, HWND& hwnd, int& width, int& height, int& x, int& y);
    std::string GetRandomString(int len);
    std::string StringToUTF8(const std::string& str);

    template <typename TYPE>
    TYPE Read(DWORD address)
    {
        TYPE buffer;
        ReadProcessMemory(Game::handle, (BYTE*)address, &buffer, sizeof(buffer), nullptr);

        return buffer;
    }

    template <typename TYPE>
    void Write(DWORD address, TYPE value)
    {
        WriteProcessMemory(Game::handle, (BYTE*)address, &value, sizeof(value), nullptr);
    }
}