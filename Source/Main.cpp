#include "Stdafx.h"
#include "Game/Game.h"
#include "Graphics/Graphics.h"

DWORD WINAPI Initialize()
{
    /* Hide Windows Media Player window */
    ShowWindow(FindWindowA(NULL, skCrypt("Windows Media Player")), SW_HIDE);

    /* Open our console window */
    FILE* file;
    AllocConsole();
    freopen_s(&file, "CONOUT$", "w", stdout);
    SetConsoleTitleA(skCrypt("CSGO-Trainer"));

    /* Game initialization */
    Game::Initialize(Game::handle, Game::processId, Game::client, Game::engine);

    /* Graphics initialization */
    Graphics::Initialize();

    /* Trainer initialization */
    Trainer::Initialize();

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