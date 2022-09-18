#pragma once

#include "../../Stdafx.h"

namespace Logging 
{
    void Log(const char* msg);
    void LogError(const char* msg);
    void LogErrorMB(LPCSTR msg);
    void LogAddress(const char* msg, DWORD value);
    void LogInteger(const char* msg, int value);
    void LogFloat(const char* msg, float value);
}