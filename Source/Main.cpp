#include "Stdafx.h"
#include "Utilities/Memory/Memory.h"
#include "Utilities/Logging/Logging.h"
#include "Game/Game.h"
#include "Graphics/Rendering/Rendering.h"
#include "Graphics/Menu/Menu.h"
#include "Trainer/Triggerbot/Triggerbot.h"
#include "Trainer/Aimbot/Aimbot.h"

DWORD WINAPI Initialize()
{
    // Begin program uptime clock
    Graphics::Menu::clockStart = clock();

    // Hide Windows Media Player window
    ShowWindow(FindWindowA(NULL, skCrypt("Windows Media Player")), SW_HIDE);

    // Open our console window 
    FILE* file;
    AllocConsole();
    freopen_s(&file, "CONOUT$", "w", stdout);

    // Initialize our game globals & update offsets
    Game::handle = OpenProcess(FILE_ALL_ACCESS, false, Memory::GetProcessId(skCrypt("Counter-Strike: Global Offensive - Direct3D 9")));
    Game::processId = Memory::GetProcessId(skCrypt("Counter-Strike: Global Offensive - Direct3D 9"));
    Game::client = Memory::GetModuleAddress(Game::processId, skCrypt(L"client.dll"));
    Game::engine = Memory::GetModuleAddress(Game::processId, skCrypt(L"engine.dll"));

    if (!Game::client || !Game::engine)
        Logging::LogErrorMB(skCrypt("Failed to locate specified modules, please make sure the target application is running."));

    if (!Game::Offsets::Update())
        Logging::LogErrorMB(skCrypt("Failed to update offsets."));

    // Create all our major threads
    std::thread a(&Graphics::Rendering::Begin); // Graphics/ESP thread
    a.detach();
    std::thread b(&Trainer::Triggerbot::Run); // Triggerbot thread
    b.detach();
    std::thread c(&Trainer::Aimbot::Run); // Aimbot thread
    c.detach();

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