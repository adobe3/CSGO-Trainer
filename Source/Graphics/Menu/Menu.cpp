#include "Menu.h"
#include "../Rendering/Rendering.h"
#include "../../Trainer/ESP/ESP.h"
#include "../../Trainer/Triggerbot/Triggerbot.h"

void Graphics::Menu::Handler()
{
	if (Graphics::Menu::status)
	{
		if (GetAsyncKeyState(VK_UP) & 1)
			Graphics::Menu::activeItem++;
		else if (GetAsyncKeyState(VK_DOWN) & 1)
			Graphics::Menu::activeItem--;

		switch (Graphics::Menu::activeItem)
		{
			case 6: // Box ESP
				if (GetAsyncKeyState(VK_RIGHT) & 1 && Trainer::ESP::boxStatus < 1)
					Trainer::ESP::boxStatus++;
				else if (GetAsyncKeyState(VK_LEFT) & 1 && Trainer::ESP::boxStatus > 0)
					Trainer::ESP::boxStatus--;
				break;

			case 5: // Snapline ESP
				if (GetAsyncKeyState(VK_RIGHT) & 1 && Trainer::ESP::snaplineStatus < 3)
					Trainer::ESP::snaplineStatus++;
				else if (GetAsyncKeyState(VK_LEFT) & 1 && Trainer::ESP::snaplineStatus > 0)
					Trainer::ESP::snaplineStatus--;
				break;

			case 4: // Healthbar ESP
				if (GetAsyncKeyState(VK_RIGHT) & 1 && Trainer::ESP::healthbarStatus < 1)
					Trainer::ESP::healthbarStatus++;
				else if (GetAsyncKeyState(VK_LEFT) & 1 && Trainer::ESP::healthbarStatus > 0)
					Trainer::ESP::healthbarStatus--;
				break;

			case 3: // Head ESP
				if (GetAsyncKeyState(VK_RIGHT) & 1 && Trainer::ESP::headStatus < 1)
					Trainer::ESP::headStatus++;
				else if (GetAsyncKeyState(VK_LEFT) & 1 && Trainer::ESP::headStatus > 0)
					Trainer::ESP::headStatus--;
				break;

			case 2: // Distance ESP
				if (GetAsyncKeyState(VK_RIGHT) & 1 && Trainer::ESP::distanceStatus < 1)
					Trainer::ESP::distanceStatus++;
				else if (GetAsyncKeyState(VK_LEFT) & 1 && Trainer::ESP::distanceStatus > 0)
					Trainer::ESP::distanceStatus--;
				break;

			case 1: // Triggerbot
				if (GetAsyncKeyState(VK_RIGHT) & 1 && Trainer::Triggerbot::status < 1)
					Trainer::Triggerbot::status++;
				else if (GetAsyncKeyState(VK_LEFT) & 1 && Trainer::Triggerbot::status > 0)
					Trainer::Triggerbot::status--;
				break;

			case 0: // Triggerbot Delay
				if (GetAsyncKeyState(VK_RIGHT) & 1 && Trainer::Triggerbot::delay < 300)
					Trainer::Triggerbot::delay++;
				else if (GetAsyncKeyState(VK_LEFT) & 1 && Trainer::Triggerbot::delay > 0)
					Trainer::Triggerbot::delay--;
				break;

			default: // If user goes over final menu selection, reset it
				if (Graphics::Menu::activeItem == 7)
					Graphics::Menu::activeItem = 0;
				else if (Graphics::Menu::activeItem == -1)
					Graphics::Menu::activeItem = 6;
		}
	}
}

void Graphics::Menu::Draw()
{
	Graphics::Menu::Handler();

	float x = (Graphics::Rendering::gameWidth / 4.9);
	float y = 42;
	float width = 174;
	float height = 115;

	if (Graphics::Menu::status)
	{
		// Menu Background
		Graphics::Rendering::DrawBox(x, y, width, height, 1.0, 0.0, 0.0, 0.0, 0.3, true);

		// Box ESP
		if (Graphics::Menu::activeItem == 6)
		{
			Graphics::Rendering::DrawString((std::string)skCrypt("Box ESP"), 14.0, x + 6, 45, 1.0, 1.0, 0.0, 1.0);

			if (Trainer::ESP::boxStatus == 0)
				Graphics::Rendering::DrawString((std::string)skCrypt("<OFF>"), 14.0, x + 106, 45, 1.0, 0.0, 0.0, 1.0);
			else if (Trainer::ESP::boxStatus == 1)
				Graphics::Rendering::DrawString((std::string)skCrypt("<ON>"), 14.0, x + 106, 45, 0.0, 1.0, 0.0, 1.0);
		}
		else
		{
			Graphics::Rendering::DrawString((std::string)skCrypt("Box ESP"), 14.0, x + 6, 45, 1.0, 1.0, 1.0, 1.0);

			if (Trainer::ESP::boxStatus == 0)
				Graphics::Rendering::DrawString((std::string)skCrypt("<OFF>"), 14.0, x + 106, 45, 1.0, 0.0, 0.0, 1.0);
			else if (Trainer::ESP::boxStatus == 1)
				Graphics::Rendering::DrawString((std::string)skCrypt("<ON>"), 14.0, x + 106, 45, 0.0, 1.0, 0.0, 1.0);
		}

		// Snapline ESP
		if (Graphics::Menu::activeItem == 5)
		{
			Graphics::Rendering::DrawString((std::string)skCrypt("Snapline ESP"), 14.0, x + 6, 60, 1.0, 1.0, 0.0, 1.0);

			if (Trainer::ESP::snaplineStatus == 0)
				Graphics::Rendering::DrawString((std::string)skCrypt("<OFF>"), 14.0, x + 106, 60, 1.0, 0.0, 0.0, 1.0);
			else if (Trainer::ESP::snaplineStatus == 1)
				Graphics::Rendering::DrawString((std::string)skCrypt("<BOTTOM>"), 14.0, x + 106, 60, 0.0, 1.0, 0.0, 1.0);
			else if (Trainer::ESP::snaplineStatus == 2)
				Graphics::Rendering::DrawString((std::string)skCrypt("<MIDDLE>"), 14.0, x + 106, 60, 0.0, 1.0, 0.0, 1.0);
			else if (Trainer::ESP::snaplineStatus == 3)
				Graphics::Rendering::DrawString((std::string)skCrypt("<TOP>"), 14.0, x + 106, 60, 0.0, 1.0, 0.0, 1.0);
		}
		else
		{
			Graphics::Rendering::DrawString((std::string)skCrypt("Snapline ESP"), 14.0, x + 6, 60, 1.0, 1.0, 1.0, 1.0);

			if (Trainer::ESP::snaplineStatus == 0)
				Graphics::Rendering::DrawString((std::string)skCrypt("<OFF>"), 14.0, x + 106, 60, 1.0, 0.0, 0.0, 1.0);
			else if (Trainer::ESP::snaplineStatus == 1)
				Graphics::Rendering::DrawString((std::string)skCrypt("<BOTTOM>"), 14.0, x + 106, 60, 0.0, 1.0, 0.0, 1.0);
			else if (Trainer::ESP::snaplineStatus == 2)
				Graphics::Rendering::DrawString((std::string)skCrypt("<MIDDLE>"), 14.0, x + 106, 60, 0.0, 1.0, 0.0, 1.0);
			else if (Trainer::ESP::snaplineStatus == 3)
				Graphics::Rendering::DrawString((std::string)skCrypt("<TOP>"), 14.0, x + 106, 60, 0.0, 1.0, 0.0, 1.0);
		}

		// Healthbar ESP
		if (Graphics::Menu::activeItem == 4)
		{
			Graphics::Rendering::DrawString((std::string)skCrypt("Healthbar ESP"), 14.0, x + 6, 75, 1.0, 1.0, 0.0, 1.0);

			if (Trainer::ESP::healthbarStatus == 0)
				Graphics::Rendering::DrawString((std::string)skCrypt("<OFF>"), 14.0, x + 106, 75, 1.0, 0.0, 0.0, 1.0);
			else if (Trainer::ESP::healthbarStatus == 1)
				Graphics::Rendering::DrawString((std::string)skCrypt("<ON>"), 14.0, x + 106, 75, 0.0, 1.0, 0.0, 1.0);
		}
		else
		{
			Graphics::Rendering::DrawString((std::string)skCrypt("Healthbar ESP"), 14.0, x + 6, 75, 1.0, 1.0, 1.0, 1.0);

			if (Trainer::ESP::healthbarStatus == 0)
				Graphics::Rendering::DrawString((std::string)skCrypt("<OFF>"), 14.0, x + 106, 75, 1.0, 0.0, 0.0, 1.0);
			else if (Trainer::ESP::healthbarStatus == 1)
				Graphics::Rendering::DrawString((std::string)skCrypt("<ON>"), 14.0, x + 106, 75, 0.0, 1.0, 0.0, 1.0);
		}

		// Head ESP
		if (Graphics::Menu::activeItem == 3)
		{
			Graphics::Rendering::DrawString((std::string)skCrypt("Head ESP"), 14.0, x + 6, 90, 1.0, 1.0, 0.0, 1.0);

			if (Trainer::ESP::headStatus == 0)
				Graphics::Rendering::DrawString((std::string)skCrypt("<OFF>"), 14.0, x + 106, 90, 1.0, 0.0, 0.0, 1.0);
			else if (Trainer::ESP::headStatus == 1)
				Graphics::Rendering::DrawString((std::string)skCrypt("<ON>"), 14.0, x + 106, 90, 0.0, 1.0, 0.0, 1.0);
		}
		else
		{
			Graphics::Rendering::DrawString((std::string)skCrypt("Head ESP"), 14.0, x + 6, 90, 1.0, 1.0, 1.0, 1.0);

			if (Trainer::ESP::headStatus == 0)
				Graphics::Rendering::DrawString((std::string)skCrypt("<OFF>"), 14.0, x + 106, 90, 1.0, 0.0, 0.0, 1.0);
			else if (Trainer::ESP::headStatus == 1)
				Graphics::Rendering::DrawString((std::string)skCrypt("<ON>"), 14.0, x + 106, 90, 0.0, 1.0, 0.0, 1.0);
		}

		// Distance ESP
		if (Graphics::Menu::activeItem == 2)
		{
			Graphics::Rendering::DrawString((std::string)skCrypt("Distance ESP"), 14.0, x + 6, 105, 1.0, 1.0, 0.0, 1.0);

			if (Trainer::ESP::distanceStatus == 0)
				Graphics::Rendering::DrawString((std::string)skCrypt("<OFF>"), 14.0, x + 106, 105, 1.0, 0.0, 0.0, 1.0);
			else if (Trainer::ESP::distanceStatus == 1)
				Graphics::Rendering::DrawString((std::string)skCrypt("<ON>"), 14.0, x + 106, 105, 0.0, 1.0, 0.0, 1.0);
		}
		else
		{
			Graphics::Rendering::DrawString((std::string)skCrypt("Distance ESP"), 14.0, x + 6, 105, 1.0, 1.0, 1.0, 1.0);

			if (Trainer::ESP::distanceStatus == 0)
				Graphics::Rendering::DrawString((std::string)skCrypt("<OFF>"), 14.0, x + 106, 105, 1.0, 0.0, 0.0, 1.0);
			else if (Trainer::ESP::distanceStatus == 1)
				Graphics::Rendering::DrawString((std::string)skCrypt("<ON>"), 14.0, x + 106, 105, 0.0, 1.0, 0.0, 1.0);
		}

		// Triggerbot
		if (Graphics::Menu::activeItem == 1)
		{
			Graphics::Rendering::DrawString((std::string)skCrypt("Triggerbot"), 14.0, x + 6, 120, 1.0, 1.0, 0.0, 1.0);

			if (Trainer::Triggerbot::status == 0)
				Graphics::Rendering::DrawString((std::string)skCrypt("<OFF>"), 14.0, x + 106, 120, 1.0, 0.0, 0.0, 1.0);
			else if (Trainer::Triggerbot::status == 1)
				Graphics::Rendering::DrawString((std::string)skCrypt("<ON>"), 14.0, x + 106, 120, 0.0, 1.0, 0.0, 1.0);
		}
		else
		{
			Graphics::Rendering::DrawString((std::string)skCrypt("Triggerbot"), 14.0, x + 6, 120, 1.0, 1.0, 1.0, 1.0);

			if (Trainer::Triggerbot::status == 0)
				Graphics::Rendering::DrawString((std::string)skCrypt("<OFF>"), 14.0, x + 106, 120, 1.0, 0.0, 0.0, 1.0);
			else if (Trainer::Triggerbot::status == 1)
				Graphics::Rendering::DrawString((std::string)skCrypt("<ON>"), 14.0, x + 106, 120, 0.0, 1.0, 0.0, 1.0);
		}

		// Triggerbot Delay
		std::string strTriggerbotDelay = std::to_string(Trainer::Triggerbot::delay);

		if (Trainer::Triggerbot::delay < 100)
		{
			strTriggerbotDelay = (std::string)skCrypt("0") + strTriggerbotDelay;

			if (Trainer::Triggerbot::delay < 10)
				strTriggerbotDelay = (std::string)skCrypt("0") + strTriggerbotDelay;
		}

		if (Graphics::Menu::activeItem == 0)
		{
			Graphics::Rendering::DrawString((std::string)skCrypt("Triggerbot Delay"), 14.0, x + 6, 135, 1.0, 1.0, 0.0, 1.0);

			Graphics::Rendering::DrawString((std::string)skCrypt("<"), 14.0, x + 106, 135, 0.0, 0.45, 1.0, 1.0);
			Graphics::Rendering::DrawString(strTriggerbotDelay, 14.0, x + 113, 135, 0.0, 0.45, 1.0, 1.0);
			Graphics::Rendering::DrawString((std::string)skCrypt(">"), 14.0, x + 135, 135, 0.0, 0.45, 1.0, 1.0);
		}
		else
		{
			Graphics::Rendering::DrawString((std::string)skCrypt("Triggerbot Delay"), 14.0, x + 6, 135, 1.0, 1.0, 1.0, 1.0);

			Graphics::Rendering::DrawString((std::string)skCrypt("<"), 14.0, x + 106, 135, 0.0, 0.45, 1.0, 1.0);
			Graphics::Rendering::DrawString(strTriggerbotDelay, 14.0, x + 113, 135, 0.0, 0.45, 1.0, 1.0);
			Graphics::Rendering::DrawString((std::string)skCrypt(">"), 14.0, x + 135, 135, 0.0, 0.45, 1.0, 1.0);
		}
	}
}