#include "Stdafx.h"
#include "Game/Game.h"
#include "Graphics/Graphics.h"
#include "Utilities/Utilities.h"

DWORD WINAPI Initialize(LPVOID lpParam)
{
    FILE* file;

    AllocConsole();
    freopen_s(&file, "CONOUT$", "w", stdout);

    /* Game initialization */
    Game::Initialize(Game::handle, Game::processId, Game::client, Game::engine);

    /* Graphics initialization */
    DirectOverlaySetOption(D2DOV_FONT_CALIBRI | D2DOV_REQUIRE_FOREGROUND);
    DirectOverlaySetup(drawLoop, FindWindowA(NULL, skCrypt("Counter-Strike: Global Offensive - Direct3D 9")));

    /* Trainer initialization */
    Trainer::Initialize();

    while (!GetAsyncKeyState(VK_END) & 1)
        std::this_thread::sleep_for(std::chrono::milliseconds(1));

    /* Unload trainer */
    FreeLibraryAndExitThread(static_cast<HMODULE>(lpParam), EXIT_SUCCESS);
}

BOOL APIENTRY DllMain(HMODULE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    if (fdwReason == DLL_PROCESS_ATTACH)
    {
        DisableThreadLibraryCalls(hinstDLL);

        const HANDLE initializeThread = CreateThread(
            nullptr,
            NULL,
            Initialize,
            hinstDLL,
            NULL,
            nullptr
        );

        if (initializeThread)
            CloseHandle(initializeThread);
    }

    return TRUE;
}