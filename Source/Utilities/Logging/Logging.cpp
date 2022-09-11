#include "../Utilities.h"

void Utilities::Log(const char* msg) 
{
    std::cout << skCrypt("{>} ") << msg << std::endl;
}

void Utilities::LogError(const char* msg) 
{
    std::cout << std::endl << skCrypt("[Error] ") << msg;
    getchar();
    exit(0);
}

void Utilities::LogErrorMB(LPCSTR msg) 
{
    MessageBoxA(NULL, msg, skCrypt("Fatal Error"), MB_OK | MB_ICONERROR);
    exit(0);
}

void Utilities::LogAddress(const char* msg, DWORD value) 
{
    std::cout << skCrypt("{>} ") << msg << skCrypt(": 0x") << std::hex << value << std::endl;
}

void Utilities::LogInteger(const char* msg, int value) 
{
    std::cout << skCrypt("{>} ") << msg << skCrypt(": ") << std::dec << value << std::endl;
}

void Utilities::LogFloat(const char* msg, float value) 
{
    std::cout << skCrypt("{>} ") << msg << skCrypt(": ") << std::defaultfloat << value << std::endl;
}