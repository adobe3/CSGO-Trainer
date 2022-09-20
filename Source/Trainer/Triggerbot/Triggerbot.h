#pragma once

namespace Trainer
{
	namespace Triggerbot
	{
		void Run();

		inline bool status = false; // FALSE: Off, TRUE: On
		inline float delay = 0.f; // 0-300ms
		inline int hotkey = 0x05; // x1 mouse
	}
}