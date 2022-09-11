#pragma once

#define WIN32_LEAN_AND_MEAN

#include <iostream>
#include <windows.h>
#include <TlHelp32.h>
#include <thread>
#include <string>
#include <d2d1.h>
#include <dwrite.h>
#include <dwmapi.h>
#include <fstream>
#include <comdef.h>
#include <ctime>

#include "../Dependencies/skCrypter/skCrypter.h"

#pragma comment(lib, "d2d1.lib")
#pragma comment(lib, "dwmapi.lib")
#pragma comment(lib, "dwrite.lib")