#include "../Trainer.h"
#include "../../Game/Game.h"
#include "../../Utilities/Memory/Memory.h"

void Trainer::Triggerbot()
{
	while (true) 
	{
		while (Trainer::Settings::triggerbot == 1) 
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(1));

			DWORD localPlayer = Game::GetLocalPlayer();
			DWORD crosshairId = Memory::Read<DWORD>(localPlayer + Game::Offsets::m_iCrosshairId);
			
			if (!Game::TeamCheck(crosshairId - 1))
				continue;

			if (GetAsyncKeyState(Trainer::Settings::triggerbotHotkey) && crosshairId > 0 && crosshairId < 32)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(Trainer::Settings::triggerbotDelay));

				mouse_event(MOUSEEVENTF_LEFTDOWN, NULL, NULL, 0, 0);
				mouse_event(MOUSEEVENTF_LEFTUP, NULL, NULL, 0, 0);
			}
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(15));
	}
}