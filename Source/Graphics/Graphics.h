#include "../Stdafx.h"
#include "../Trainer/Trainer.h"

namespace Graphics 
{
	bool Initialize();
	inline int gameWidth, gameHeight;

	/* Menu */
	void DrawMenu();
	void MenuHandler();

	inline int activeItem = 5;

	/* Rendering */
}

#define D2DOV_REQUIRE_FOREGROUND	(1 << 0) /* Requires the target window to be actice to render */
#define D2DOV_DRAW_FPS				(1 << 1)
#define D2DOV_VSYNC					(1 << 2)
#define D2DOV_FONT_CALIBRI			(1 << 3)
#define D2DOV_FONT_ARIAL			(1 << 4)
#define D2DOV_FONT_COURIER			(1 << 5)
#define D2DOV_FONT_GABRIOLA			(1 << 6)
#define D2DOV_FONT_IMPACT			(1 << 7)

// The function you call to set up the above options.  Make sure its called before the DirectOverlaySetup function
void DirectOverlaySetOption(DWORD option);

// typedef for the callback function, where you'll do the drawing.
typedef void(*DirectOverlayCallback)(int width, int height);

void DirectOverlaySetup(DirectOverlayCallback callbackFunction); /* Internals */
void DirectOverlaySetup(DirectOverlayCallback callbackFunction, HWND targetWindow); /* Externals */

void DrawLine(float x1, float y1, float x2, float y2, float thickness, float r, float g, float b, float a = 1);
void DrawBox(float x, float y, float width, float height, float thickness, float r, float g, float b, float a, bool filled);
void DrawCircle(float x, float y, float radius, float thickness, float r, float g, float b, float a, bool filled);
void DrawEllipse(float x, float y, float width, float height, float thickness, float r, float g, float b, float a, bool filled);
void DrawString(std::string str, float fontSize, float x, float y, float r, float g, float b, float a = 1);

void drawLoop(int width, int height);
