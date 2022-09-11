#pragma once

namespace Trainer 
{
	bool Initialize();

	void Esp2D();
	void Triggerbot();

	namespace Settings 
	{
		inline bool menu = true;

		inline int boxes2D = 0; /* 0 OFF, 1 ON */
		inline int snaplines2D = 0; /* 0 OFF, 1 BOTTOM, 2 TOP */

		inline int triggerbot = 0; /* 0 OFF, 1 ON */
		inline int triggerbotDelay = 0; /* 0ms - 300ms */
		inline int triggerbotHotkey = 0x06; // X2 mouse
	}
}