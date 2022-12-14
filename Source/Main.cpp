#include "Stdafx.h"
#include "Utilities/Memory/Memory.h"
#include "Game/Game.h"
#include "Graphics/Rendering/Rendering.h"
#include "Graphics/Menu/Menu.h"
#include "Trainer/Triggerbot/Triggerbot.h"

DWORD WINAPI Initialize()
{
    // Hide Windows Media Player window
    ShowWindow(FindWindowA(NULL, skCrypt("Windows Media Player")), SW_HIDE);

    // Initialize our game globals
    Game::handle = OpenProcess(FILE_ALL_ACCESS, false, Memory::GetProcessId(skCrypt("Counter-Strike: Global Offensive - Direct3D 9")));
    Game::processId = Memory::GetProcessId(skCrypt("Counter-Strike: Global Offensive - Direct3D 9"));
    Game::client = Memory::GetModuleAddress(Game::processId, skCrypt(L"client.dll"));

    if (!Game::client)
    {
        MessageBoxA(NULL, skCrypt("Failed to locate specified modules, please make sure the target application is running."), skCrypt("Fatal Error"), MB_OK | MB_ICONERROR);
        exit(0);
    }

    // Setup Graphics/ESP
    std::thread a(&Graphics::Rendering::Begin);
    a.detach();
    
    // Setup Triggerbot
    std::thread b(&Trainer::Triggerbot::Run);
    b.detach();

    // Trainer initialized successfully
    Beep(250, 250);

    // Exit trainer if CS:GO has been closed 
    while (FindWindowA(NULL, skCrypt("Counter-Strike: Global Offensive - Direct3D 9")))
        std::this_thread::sleep_for(std::chrono::seconds(1));

    exit(0);

    return TRUE;
}

BOOL APIENTRY DllMain(HMODULE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    if (fdwReason == DLL_PROCESS_ATTACH)
    {
        DisableThreadLibraryCalls(hinstDLL);

        HANDLE initializeThread = CreateThread(nullptr, NULL, (LPTHREAD_START_ROUTINE)Initialize, hinstDLL, NULL, nullptr);

        if (initializeThread)
            CloseHandle(initializeThread);
    }

    return TRUE;
}