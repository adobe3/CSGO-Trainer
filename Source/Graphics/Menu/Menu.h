#pragma once

#include "../../Stdafx.h"

namespace Graphics 
{
	namespace Menu
	{
		void Draw();

		inline bool status = true;
		inline clock_t clockStart, clockEnd, clockElapsed;
	}
}