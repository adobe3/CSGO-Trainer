#pragma once

#include "../Stdafx.h"
#include "../Game/Game.h"

namespace Utilities {
    /* Memory */
    DWORD GetProcessId(const char* windowTitle);
    uintptr_t GetModuleAddress(DWORD processId, const wchar_t* moduleName);
    void GetWindow(const char* windowTitle, HWND& hwnd, int& width, int& height, int& x, int& y);

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

    /* Math */
    struct Vector3 
    {
        float x, y, z;
    };
    struct view_matrix_t 
    {
        float matrix[16];
    };

    struct Vector3 WorldToScreen(const struct Vector3 pos, struct view_matrix_t matrix);

    /* Logging */
    void Log(const char* msg);
    void LogError(const char* msg);
    void LogErrorMB(LPCSTR msg);
    void LogAddress(const char* msg, DWORD value);
    void LogInteger(const char* msg, int value);
    void LogFloat(const char* msg, float value);
};