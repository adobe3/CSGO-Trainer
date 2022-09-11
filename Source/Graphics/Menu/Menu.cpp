#include "../Graphics.h"
#include "../../Trainer/Trainer.h"

void Graphics::DrawMenu()
{
	if (Trainer::Settings::menu)
	{
		/* 2D Boxes */
		if (Graphics::activeItem == 3)
		{
			DrawString((std::string)skCrypt("2D Boxes"), 14.0, 400, 45, 1.0, 1.0, 0.0, 1.0);

			if (Trainer::Settings::boxes2D == 0)
				DrawString((std::string)skCrypt("<OFF>"), 14.0, 497, 45, 1.0, 0.0, 0.0, 1.0);
			if (Trainer::Settings::boxes2D == 1)
				DrawString((std::string)skCrypt("<ON>"), 14.0, 497, 45, 0.0, 1.0, 0.0, 1.0);
		}
		else
		{
			DrawString((std::string)skCrypt("2D Boxes"), 14.0, 400, 45, 1.0, 1.0, 1.0, 1.0);

			if (Trainer::Settings::boxes2D == 0)
				DrawString((std::string)skCrypt("<OFF>"), 14.0, 497, 45, 1.0, 0.0, 0.0, 1.0);
			if (Trainer::Settings::boxes2D == 1)
				DrawString((std::string)skCrypt("<ON>"), 14.0, 497, 45, 0.0, 1.0, 0.0, 1.0);
		}

		/* 2D Snaplines */
		if (Graphics::activeItem == 2)
		{
			DrawString((std::string)skCrypt("2D Snaplines"), 14.0, 400, 60, 1.0, 1.0, 0.0, 1.0);

			if (Trainer::Settings::snaplines2D == 0)
				DrawString((std::string)skCrypt("<OFF>"), 14.0, 497, 60, 1.0, 0.0, 0.0, 1.0);
			if (Trainer::Settings::snaplines2D == 1)
				DrawString((std::string)skCrypt("<BOTTOM>"), 14.0, 497, 60, 0.0, 1.0, 0.0, 1.0);
			if (Trainer::Settings::snaplines2D == 2)
				DrawString((std::string)skCrypt("<TOP>"), 14.0, 497, 60, 0.0, 1.0, 0.0, 1.0);
		}
		else
		{
			DrawString((std::string)skCrypt("2D Snaplines"), 14.0, 400, 60, 1.0, 1.0, 1.0, 1.0);

			if (Trainer::Settings::snaplines2D == 0)
				DrawString((std::string)skCrypt("<OFF>"), 14.0, 497, 60, 1.0, 0.0, 0.0, 1.0);
			if (Trainer::Settings::snaplines2D == 1)
				DrawString((std::string)skCrypt("<BOTTOM>"), 14.0, 497, 60, 0.0, 1.0, 0.0, 1.0);
			if (Trainer::Settings::snaplines2D == 2)
				DrawString((std::string)skCrypt("<TOP>"), 14.0, 497, 60, 0.0, 1.0, 0.0, 1.0);
		}

		/* Triggerbot */
		if (Graphics::activeItem == 1)
		{
			DrawString((std::string)skCrypt("Triggerbot"), 14.0, 400, 75, 1.0, 1.0, 0.0, 1.0);

			if (Trainer::Settings::triggerbot == 0)
				DrawString((std::string)skCrypt("<OFF>"), 14.0, 497, 75, 1.0, 0.0, 0.0, 1.0);
			if (Trainer::Settings::triggerbot == 1)
				DrawString((std::string)skCrypt("<ON>"), 14.0, 497, 75, 0.0, 1.0, 0.0, 1.0);
		}
		else
		{
			DrawString((std::string)skCrypt("Triggerbot"), 14.0, 400, 75, 1.0, 1.0, 1.0, 1.0);

			if (Trainer::Settings::triggerbot == 0)
				DrawString((std::string)skCrypt("<OFF>"), 14.0, 497, 75, 1.0, 0.0, 0.0, 1.0);
			if (Trainer::Settings::triggerbot == 1)
				DrawString((std::string)skCrypt("<ON>"), 14.0, 497, 75, 0.0, 1.0, 0.0, 1.0);
		}

		/* Triggerbot delay */
		std::string strTriggerbotDelay = std::to_string(Trainer::Settings::triggerbotDelay);

		if (Trainer::Settings::triggerbotDelay < 100) 
		{
			strTriggerbotDelay = (std::string)skCrypt("0") + strTriggerbotDelay;

			if (Trainer::Settings::triggerbotDelay < 10) 
			{
				strTriggerbotDelay = (std::string)skCrypt("0") + strTriggerbotDelay;
			}
		}

		if (Graphics::activeItem == 0)
		{
			DrawString((std::string)skCrypt("Triggerbot Delay"), 14.0, 400, 90, 1.0, 1.0, 0.0, 1.0);

			DrawString((std::string)skCrypt("<"), 14.0, 497, 90, 0.0, 0.45, 1.0, 1.0);
			DrawString(strTriggerbotDelay, 14.0, 504, 90, 0.0, 0.45, 1.0, 1.0);
			DrawString((std::string)skCrypt(">"), 14.0, 526, 90, 0.0, 0.45, 1.0, 1.0);
		}
		else
		{
			DrawString((std::string)skCrypt("Triggerbot Delay"), 14.0, 400, 90, 1.0, 1.0, 1.0, 1.0);

			DrawString((std::string)skCrypt("<"), 14.0, 497, 90, 0.0, 0.45, 1.0, 1.0);
			DrawString(strTriggerbotDelay, 14.0, 504, 90, 0.0, 0.45, 1.0, 1.0);
			DrawString((std::string)skCrypt(">"), 14.0, 526, 90, 0.0, 0.45, 1.0, 1.0);
		}
	}
}

void Graphics::MenuHandler()
{
	if (Trainer::Settings::menu)
	{
		if (GetAsyncKeyState(VK_UP) & 1)
			Graphics::activeItem++;

		if (GetAsyncKeyState(VK_DOWN) & 1)
			Graphics::activeItem--;

		switch (Graphics::activeItem)
		{
		case 3: /* 2D Boxes */
			if (GetAsyncKeyState(VK_RIGHT) & 1)
			{
				Trainer::Settings::boxes2D++;

				if (Trainer::Settings::boxes2D == 2)
					Trainer::Settings::boxes2D = 1;
			}

			if (GetAsyncKeyState(VK_LEFT) & 1)
			{
				Trainer::Settings::boxes2D--;

				if (Trainer::Settings::boxes2D == -1)
					Trainer::Settings::boxes2D = 0;
			}
			break;
		case 2: /* 2D Snaplines */
			if (GetAsyncKeyState(VK_RIGHT) & 1)
			{
				Trainer::Settings::snaplines2D++;

				if (Trainer::Settings::snaplines2D == 3)
					Trainer::Settings::snaplines2D = 2;
			}

			if (GetAsyncKeyState(VK_LEFT) & 1)
			{
				Trainer::Settings::snaplines2D--;

				if (Trainer::Settings::snaplines2D == -1)
					Trainer::Settings::snaplines2D = 0;
			}
		case 1: /* Triggerbot */
			if (GetAsyncKeyState(VK_RIGHT) & 1)
			{
				Trainer::Settings::triggerbot++;

				if (Trainer::Settings::triggerbot == 2)
					Trainer::Settings::triggerbot = 1;
			}

			if (GetAsyncKeyState(VK_LEFT) & 1)
			{
				Trainer::Settings::triggerbot--;

				if (Trainer::Settings::triggerbot == -1)
					Trainer::Settings::triggerbot = 0;
			}
		case 0: /* Triggerbot Delay */
			if (GetAsyncKeyState(VK_RIGHT) & 1)
			{
				Trainer::Settings::triggerbotDelay++;

				if (Trainer::Settings::triggerbotDelay == 301)
					Trainer::Settings::triggerbotDelay = 300;
			}

			if (GetAsyncKeyState(VK_LEFT) & 1)
			{
				Trainer::Settings::triggerbotDelay--;

				if (Trainer::Settings::triggerbotDelay == -1)
					Trainer::Settings::triggerbotDelay = 0;
			}
			break;
		default: /* If user goes over final menu selection, reset it */
			if (Graphics::activeItem == 4)
				Graphics::activeItem = 0;

			else if(Graphics::activeItem == -1)
				Graphics::activeItem = 3;
		}
	}
}