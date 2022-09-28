#pragma once

#include "../../Stdafx.h"

namespace Trainer
{
	namespace Triggerbot
	{
		void Run();

		inline bool status = false; // FALSE: Off, TRUE: On
		inline float delay = 0.f; // 0-300ms
		inline int hotkey = 0x05; // 0x00 Always On, 0x01 Left Mouse, 0x02 Right Mouse, 0x03 Pause/Break Key, 0x04 Middle Mouse, 0x05 X1 Mouse, 0x06 X2 Mouse
	}
}