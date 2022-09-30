#pragma once

#define WIN32_LEAN_AND_MEAN

#include <iostream>
#include <windows.h>
#include <TlHelp32.h>
#include <thread>
#include <string>
#include <dwmapi.h>
#include <d3d9.h>

#include "../Dependencies/skCrypter/skCrypter.h"
#include "../Dependencies/Dear ImGui/imgui.h"
#include "../Dependencies/Dear ImGui/imgui_impl_dx9.h"
#include "../Dependencies/Dear ImGui/imgui_impl_win32.h"

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "dwmapi.lib")