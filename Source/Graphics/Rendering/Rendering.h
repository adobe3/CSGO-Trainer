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
		void Begin();

		void DrawStrokeString(int x, int y, float color[], const char* str);
		void DrawString(int x, int y, float color[], const char* str);
		void DrawRect(int x, int y, int w, int h, float color[], int thickness);
		void DrawFilledRect(int x, int y, int w, int h, float color[]);
		void DrawCircleFilled(int x, int y, int radius, float color[]);
		void DrawCircle(int x, int y, int radius, float color[], int segments);
		void DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, float color[], float thickness);
		void DrawTriangleFilled(int x1, int y1, int x2, int y2, int x3, int y3, float color[]);
		void DrawLine(int x1, int y1, int x2, int y2, float color[], int thickness);
		void DrawCornerBox(int x, int y, int w, int h, int borderPx, float color[]);

		inline float gameWidth, gameHeight;
		inline float gameX, gameY;
	}
}