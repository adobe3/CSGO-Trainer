#pragma once

#include "../../Stdafx.h"

#define D2DOV_REQUIRE_FOREGROUND	(1 << 0)
#define D2DOV_DRAW_FPS				(1 << 1)
#define D2DOV_VSYNC					(1 << 2)
#define D2DOV_FONT_CALIBRI			(1 << 3)
#define D2DOV_FONT_ARIAL			(1 << 4)
#define D2DOV_FONT_COURIER			(1 << 5)
#define D2DOV_FONT_GABRIOLA			(1 << 6)
#define D2DOV_FONT_IMPACT			(1 << 7)

namespace Graphics 
{
	namespace Rendering
	{
		typedef void(*DirectOverlayCallback)(int width, int height);

		void DirectOverlaySetOption(DWORD option);
		void DirectOverlaySetup(DirectOverlayCallback callbackFunction); /* Internals */
		void DirectOverlaySetup(DirectOverlayCallback callbackFunction, HWND targetWindow); /* Externals */

		void DrawLine(float x1, float y1, float x2, float y2, float thickness, float r, float g, float b, float a = 1);
		void DrawBox(float x, float y, float width, float height, float thickness, float r, float g, float b, float a, bool filled);
		void DrawCircle(float x, float y, float radius, float thickness, float r, float g, float b, float a, bool filled);
		void DrawEllipse(float x, float y, float width, float height, float thickness, float r, float g, float b, float a, bool filled);
		void DrawString(std::string str, float fontSize, float x, float y, float r, float g, float b, float a = 1);

		void Begin(int width, int height);

		inline float gameWidth, gameHeight;
	}
}