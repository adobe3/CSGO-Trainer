#pragma once

#include "../../Stdafx.h"

namespace Trainer
{
	namespace ESP
	{
		void Run();

		inline bool boxStatus = false; // FALSE: Off, TRUE: On
		inline float boxColor[4] = { 1, 0, 0, 1 };
		inline float boxBackgroundColor[4] = { 1, 0, 0, 0.2 };
		inline int boxType = 0; // 0: Full, 1: Cornered

		inline bool snaplineStatus = false; // FALSE: Off, TRUE: On
		inline float snaplineColor[4] = { 1, 0, 0, 1 };
		inline int snaplineType = 0; // 0: Bottom, 1: Middle, 2: Top

		inline bool healthbarStatus = false; // FALSE: Off, TRUE: On

		inline bool headStatus = false; // FALSE: Off, TRUE: On
		inline float headColor[4] = { 1, 0, 0, 1 };
		inline float headBackgroundColor[4] = { 1, 0, 0, 0.2 };

		inline bool distanceStatus = false; // FALSE: Off, TRUE: On
		inline float distanceColor[4] = { 1, 0, 0, 1 };
	}
}