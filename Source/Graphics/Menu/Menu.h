#pragma once

#include "../../Stdafx.h"

namespace Graphics 
{
	namespace Menu 
	{
		void Draw();
		void Handler();

		inline bool status = true; // FALSE: Menu closed | TRUE: Menu opened
		inline int activeItem = 6;
	}
}