#pragma once

namespace Trainer
{
	namespace ESP
	{
		void Run();

		inline int boxStatus = 0; // 0: OFF | 1: ON
		inline int snaplineStatus = 0; // 0: OFF | 1: BOTTOM | 2: MIDDLE | 3: TOP
		inline int healthbarStatus = 0; // 0: OFF | 1: ON
		inline int headStatus = 0; // 0: OFF | 1: ON
		inline int distanceStatus = 0; // 0: OFF | 1: ON
	}
}