#pragma once

namespace Trainer
{
	namespace Triggerbot
	{
		void Run();

		inline int status = 0; // 0: OFF | 1: ON
		inline int delay = 0; // 0-300ms
		inline int hotkey = 0x06;
	}
}