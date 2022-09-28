#pragma once

#include "../../Stdafx.h"

namespace Trainer
{
	namespace ESP
	{
		void Run();

		inline bool boxStatus = false; // FALSE: Off, TRUE: On
		inline float boxColorCT[4] = { 0.3f, 0.5f, 0.7f, 1 };
		inline float boxColorT[4] = { 0.9f, 0.75f, 0.4f, 1 };

		inline bool snaplineStatus = false; // FALSE: Off, TRUE: On
		inline float snaplineColorCT[4] = { 0.3f, 0.5f, 0.7f, 1 };
		inline float snaplineColorT[4] = { 0.9f, 0.75f, 0.4f, 1 };
		inline int snaplineType = 0; // 0: Bottom, 1: Middle

		inline bool healthbarStatus = false; // FALSE: Off, TRUE: On

		inline bool headStatus = false; // FALSE: Off, TRUE: On
		inline float headColorCT[4] = { 0.3f, 0.5f, 0.7f, 1 };
		inline float headColorT[4] = { 0.9f, 0.75f, 0.4f, 1 };

		inline bool distanceStatus = false; // FALSE: Off, TRUE: On
		inline float distanceColorCT[4] = { 0.3f, 0.5f, 0.7f, 1 };
		inline float distanceColorT[4] = { 0.9f, 0.75f, 0.4f, 1 };
	}
}