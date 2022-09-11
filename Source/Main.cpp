/*
Author:
    - Discord: adobe#3361
    - Github: https://github.com/adobe3
Features:
    - Easily expandable codebase
    - Direct2D Graphics
    - Compile time string obfuscation
    - Various cheats such as 2D ESP, Aimbot, Triggerbot, & more.
    - Automatic updater via signature scanning
    - Great preformance with 0.3% average CPU usage
Compilation & Runtime Instructions:
    - Install "DirectX Software Development Kit"
    - Compile CSGO-Trainer.sln as Release/x86
    - Run Counter-Strike: Global Offensive with "-insecure" flag
    - Set the games display mode & resolution as "Fullscreen Windowed" & "1920x1080"
    - Run CSGO-Trainer.exe as administrator
    - Navigate the trainers menu with UP, DOWN, LEFT, & RIGHT arrow keys, toggle the menu with INSERT.
Improvements:
    - Compile with Obfuscator-LLVM to change the programs signature (https://www.unknowncheats.me/forum/anti-cheat-bypass/500042-ollvm-13-llvm-obfuscator-vs2022-compatible.html)
    - Add dynamic resolution support
    - Use a manually mapped driver to preform memory operations
Credits:
    - coltonon for D2DOverlay
    - skadro-official for skCrypter
*/

#include "Stdafx.h"
#include "Game/Game.h"
#include "Graphics/Graphics.h"
#include "Utilities/Utilities.h"

DWORD WINAPI Setup(LPVOID lpParam)
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

    // THIS DOESNT WORK FIX !!! test
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

        const HANDLE hThread = CreateThread(
            nullptr,
            NULL,
            Setup,
            hinstDLL,
            NULL,
            nullptr
        );

        if (hThread)
            CloseHandle(hThread);
    }

    return TRUE;
}