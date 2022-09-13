#include "Logging.h"

void Logging::Log(const char* msg) 
{
    std::cout << skCrypt("{>} ") << msg << std::endl;
}

void Logging::LogError(const char* msg)
{
    std::cout << std::endl << skCrypt("[Error] ") << msg;
    getchar();
    exit(0);
}

void Logging::LogErrorMB(LPCSTR msg)
{
    MessageBoxA(NULL, msg, skCrypt("Fatal Error"), MB_OK | MB_ICONERROR);
    exit(0);
}

void Logging::LogAddress(const char* msg, DWORD value)
{
    std::cout << skCrypt("{>} ") << msg << skCrypt(": 0x") << std::hex << value << std::endl;
}

void Logging::LogInteger(const char* msg, int value)
{
    std::cout << skCrypt("{>} ") << msg << skCrypt(": ") << std::dec << value << std::endl;
}

void Logging::LogFloat(const char* msg, float value)
{
    std::cout << skCrypt("{>} ") << msg << skCrypt(": ") << std::defaultfloat << value << std::endl;
}