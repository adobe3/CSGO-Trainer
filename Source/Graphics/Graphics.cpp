#include "Graphics.h"

bool Graphics::Initialize()
{
	DirectOverlaySetOption(D2DOV_FONT_CALIBRI | D2DOV_REQUIRE_FOREGROUND);
	DirectOverlaySetup(drawLoop, FindWindowA(NULL, skCrypt("Counter-Strike: Global Offensive - Direct3D 9")));

	RECT rect;
	GetWindowRect(FindWindowA(NULL, skCrypt("Counter-Strike: Global Offensive - Direct3D 9")), &rect);

	Graphics::gameWidth = rect.right - rect.left;
	Graphics::gameHeight = rect.bottom - rect.top;

	return true;
}