#pragma once

#include "../../Stdafx.h"

namespace Trainer
{
	namespace ESP
	{
		void Run();

		inline bool boxStatus = false; // FALSE: Off, TRUE: On
		inline float boxColor[4] = { 1, 0, 0, 1 };
		inline int boxType = 0; // 0: Full, 1: Cornered

		inline bool snaplineStatus = false; // FALSE: Off, TRUE: On
		inline float snaplineColor[4] = { 1, 0, 0, 1 };
		inline int snaplineType = 0; // 0: Bottom, 1: Middle, 2: Top

		inline bool healthStatus = false; // FALSE: Off, TRUE: On
		inline int healthType = 0; // 0: Bar, 1: Text
		inline float healthColor[4] = { 1, 0, 0, 1 };

		inline bool headStatus = false; // FALSE: Off, TRUE: On
		inline float headColor[4] = { 1, 0, 0, 1 };
		inline float headBackgroundColor[4] = { headColor[0], headColor[1], headColor[2], 0.2};

		inline bool distanceStatus = false; // FALSE: Off, TRUE: On
		inline float distanceColor[4] = { 1, 0, 0, 1 };
	}
}