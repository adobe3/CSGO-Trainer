#pragma once

#include "../../Stdafx.h"

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