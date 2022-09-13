#include "../Graphics.h"
#include "../../Trainer/Trainer.h"

void Graphics::DrawMenu()
{
	if (Trainer::Settings::menu)
	{
		/* 2D Boxes */
		if (Graphics::activeItem == 5)
		{
			DrawString((std::string)skCrypt("2D Boxes"), 14.0, 400, 45, 1.0, 1.0, 0.0, 1.0);

			if (Trainer::Settings::boxes2D == 0)
				DrawString((std::string)skCrypt("<OFF>"), 14.0, 497, 45, 1.0, 0.0, 0.0, 1.0);
			else if (Trainer::Settings::boxes2D == 1)
				DrawString((std::string)skCrypt("<ON>"), 14.0, 497, 45, 0.0, 1.0, 0.0, 1.0);
		}
		else
		{
			DrawString((std::string)skCrypt("2D Boxes"), 14.0, 400, 45, 1.0, 1.0, 1.0, 1.0);

			if (Trainer::Settings::boxes2D == 0)
				DrawString((std::string)skCrypt("<OFF>"), 14.0, 497, 45, 1.0, 0.0, 0.0, 1.0);
			else if (Trainer::Settings::boxes2D == 1)
				DrawString((std::string)skCrypt("<ON>"), 14.0, 497, 45, 0.0, 1.0, 0.0, 1.0);
		}

		/* 2D Snaplines */
		if (Graphics::activeItem == 4)
		{
			DrawString((std::string)skCrypt("2D Snaplines"), 14.0, 400, 60, 1.0, 1.0, 0.0, 1.0);

			if (Trainer::Settings::snaplines2D == 0)
				DrawString((std::string)skCrypt("<OFF>"), 14.0, 497, 60, 1.0, 0.0, 0.0, 1.0);
			else if (Trainer::Settings::snaplines2D == 1)
				DrawString((std::string)skCrypt("<BOTTOM>"), 14.0, 497, 60, 0.0, 1.0, 0.0, 1.0);
			else if (Trainer::Settings::snaplines2D == 2)
				DrawString((std::string)skCrypt("<MIDDLE>"), 14.0, 497, 60, 0.0, 1.0, 0.0, 1.0);
			else if (Trainer::Settings::snaplines2D == 3)
				DrawString((std::string)skCrypt("<TOP>"), 14.0, 497, 60, 0.0, 1.0, 0.0, 1.0);
		}
		else
		{
			DrawString((std::string)skCrypt("2D Snaplines"), 14.0, 400, 60, 1.0, 1.0, 1.0, 1.0);

			if (Trainer::Settings::snaplines2D == 0)
				DrawString((std::string)skCrypt("<OFF>"), 14.0, 497, 60, 1.0, 0.0, 0.0, 1.0);
			else if (Trainer::Settings::snaplines2D == 1)
				DrawString((std::string)skCrypt("<BOTTOM>"), 14.0, 497, 60, 0.0, 1.0, 0.0, 1.0);
			else if (Trainer::Settings::snaplines2D == 2)
				DrawString((std::string)skCrypt("<MIDDLE>"), 14.0, 497, 60, 0.0, 1.0, 0.0, 1.0);
			else if (Trainer::Settings::snaplines2D == 3)
				DrawString((std::string)skCrypt("<TOP>"), 14.0, 497, 60, 0.0, 1.0, 0.0, 1.0);
		}

		/* 2D Healthbars */
		if (Graphics::activeItem == 3)
		{
			DrawString((std::string)skCrypt("2D Healthbars"), 14.0, 400, 75, 1.0, 1.0, 0.0, 1.0);

			if (Trainer::Settings::healthbars2D == 0)
				DrawString((std::string)skCrypt("<OFF>"), 14.0, 497, 75, 1.0, 0.0, 0.0, 1.0);
			else if (Trainer::Settings::healthbars2D == 1)
				DrawString((std::string)skCrypt("<ON>"), 14.0, 497, 75, 0.0, 1.0, 0.0, 1.0);
		}
		else
		{
			DrawString((std::string)skCrypt("2D Healthbars"), 14.0, 400, 75, 1.0, 1.0, 1.0, 1.0);

			if (Trainer::Settings::healthbars2D == 0)
				DrawString((std::string)skCrypt("<OFF>"), 14.0, 497, 75, 1.0, 0.0, 0.0, 1.0);
			else if (Trainer::Settings::healthbars2D == 1)
				DrawString((std::string)skCrypt("<ON>"), 14.0, 497, 75, 0.0, 1.0, 0.0, 1.0);
		}

		/* 2D Heads */
		if (Graphics::activeItem == 2)
		{
			DrawString((std::string)skCrypt("2D Heads"), 14.0, 400, 90, 1.0, 1.0, 0.0, 1.0);

			if (Trainer::Settings::heads2D == 0)
				DrawString((std::string)skCrypt("<OFF>"), 14.0, 497, 90, 1.0, 0.0, 0.0, 1.0);
			else if (Trainer::Settings::heads2D == 1)
				DrawString((std::string)skCrypt("<ON>"), 14.0, 497, 90, 0.0, 1.0, 0.0, 1.0);
		}
		else
		{
			DrawString((std::string)skCrypt("2D Heads"), 14.0, 400, 90, 1.0, 1.0, 1.0, 1.0);

			if (Trainer::Settings::heads2D == 0)
				DrawString((std::string)skCrypt("<OFF>"), 14.0, 497, 90, 1.0, 0.0, 0.0, 1.0);
			else if (Trainer::Settings::heads2D == 1)
				DrawString((std::string)skCrypt("<ON>"), 14.0, 497, 90, 0.0, 1.0, 0.0, 1.0);
		}

		/* Triggerbot */
		if (Graphics::activeItem == 1)
		{
			DrawString((std::string)skCrypt("Triggerbot"), 14.0, 400, 105, 1.0, 1.0, 0.0, 1.0);

			if (Trainer::Settings::triggerbot == 0)
				DrawString((std::string)skCrypt("<OFF>"), 14.0, 497, 105, 1.0, 0.0, 0.0, 1.0);
			else if (Trainer::Settings::triggerbot == 1)
				DrawString((std::string)skCrypt("<ON>"), 14.0, 497, 105, 0.0, 1.0, 0.0, 1.0);
		}
		else
		{
			DrawString((std::string)skCrypt("Triggerbot"), 14.0, 400, 105, 1.0, 1.0, 1.0, 1.0);

			if (Trainer::Settings::triggerbot == 0)
				DrawString((std::string)skCrypt("<OFF>"), 14.0, 497, 105, 1.0, 0.0, 0.0, 1.0);
			else if (Trainer::Settings::triggerbot == 1)
				DrawString((std::string)skCrypt("<ON>"), 14.0, 497, 105, 0.0, 1.0, 0.0, 1.0);
		}

		/* Triggerbot delay */
		std::string strTriggerbotDelay = std::to_string(Trainer::Settings::triggerbotDelay);

		if (Trainer::Settings::triggerbotDelay < 100) 
		{
			strTriggerbotDelay = (std::string)skCrypt("0") + strTriggerbotDelay;

			if (Trainer::Settings::triggerbotDelay < 10) 
				strTriggerbotDelay = (std::string)skCrypt("0") + strTriggerbotDelay;
		}

		if (Graphics::activeItem == 0)
		{
			DrawString((std::string)skCrypt("Triggerbot Delay"), 14.0, 400, 120, 1.0, 1.0, 0.0, 1.0);

			DrawString((std::string)skCrypt("<"), 14.0, 497, 120, 0.0, 0.45, 1.0, 1.0);
			DrawString(strTriggerbotDelay, 14.0, 504, 120, 0.0, 0.45, 1.0, 1.0);
			DrawString((std::string)skCrypt(">"), 14.0, 526, 120, 0.0, 0.45, 1.0, 1.0);
		}
		else
		{
			DrawString((std::string)skCrypt("Triggerbot Delay"), 14.0, 400, 120, 1.0, 1.0, 1.0, 1.0);

			DrawString((std::string)skCrypt("<"), 14.0, 497, 120, 0.0, 0.45, 1.0, 1.0);
			DrawString(strTriggerbotDelay, 14.0, 504, 120, 0.0, 0.45, 1.0, 1.0);
			DrawString((std::string)skCrypt(">"), 14.0, 526, 120, 0.0, 0.45, 1.0, 1.0);
		}
	}
}

void Graphics::MenuHandler()
{
	if (Trainer::Settings::menu)
	{
		if (GetAsyncKeyState(VK_UP) & 1)
			Graphics::activeItem++;
		else if (GetAsyncKeyState(VK_DOWN) & 1)
			Graphics::activeItem--;

		switch (Graphics::activeItem)
		{
			case 5: /* 2D Boxes */
				if (GetAsyncKeyState(VK_RIGHT) & 1 && Trainer::Settings::boxes2D < 1)
					Trainer::Settings::boxes2D++;
				else if (GetAsyncKeyState(VK_LEFT) & 1 && Trainer::Settings::boxes2D > 0)
					Trainer::Settings::boxes2D--;
				break;

			case 4: /* 2D Snaplines */
				if (GetAsyncKeyState(VK_RIGHT) & 1 && Trainer::Settings::snaplines2D < 3)
					Trainer::Settings::snaplines2D++;
				else if (GetAsyncKeyState(VK_LEFT) & 1 && Trainer::Settings::snaplines2D > 0)
					Trainer::Settings::snaplines2D--;
				break;

			case 3: /* 2D Healthbars */
				if (GetAsyncKeyState(VK_RIGHT) & 1 && Trainer::Settings::healthbars2D < 1)
					Trainer::Settings::healthbars2D++;
				else if (GetAsyncKeyState(VK_LEFT) & 1 && Trainer::Settings::healthbars2D > 0)
					Trainer::Settings::healthbars2D--;
				break;

			case 2: /* 2D Heads */
				if (GetAsyncKeyState(VK_RIGHT) & 1 && Trainer::Settings::heads2D < 1)
					Trainer::Settings::heads2D++;
				else if (GetAsyncKeyState(VK_LEFT) & 1 && Trainer::Settings::heads2D > 0)
					Trainer::Settings::heads2D--;
				break;

			case 1: /* Triggerbot */
				if (GetAsyncKeyState(VK_RIGHT) & 1 && Trainer::Settings::triggerbot < 1)
					Trainer::Settings::triggerbot++;
				else if (GetAsyncKeyState(VK_LEFT) & 1 && Trainer::Settings::triggerbot > 0)
					Trainer::Settings::triggerbot--;
				break;

			case 0: /* Triggerbot Delay */
				if (GetAsyncKeyState(VK_RIGHT) & 1 && Trainer::Settings::triggerbotDelay < 300)
					Trainer::Settings::triggerbotDelay++;
				else if (GetAsyncKeyState(VK_LEFT) & 1 && Trainer::Settings::triggerbotDelay > 0)
					Trainer::Settings::triggerbotDelay--;
				break;

			default: /* If user goes over final menu selection, reset it */
				if (Graphics::activeItem == 6)
					Graphics::activeItem = 0;
				else if (Graphics::activeItem == -1)
					Graphics::activeItem = 5;
		}
	}
}