#include "ESP.h"
#include "../../Utilities/Memory/Memory.h"
#include "../../Game/Game.h"
#include "../../Graphics/Rendering/Rendering.h"
#include "../../Utilities/Math/Math.h"

void Trainer::ESP::Run() 
{
	for (int i = 1; i < 32; i++) // Ranked: 10, Casual: 20, Community: ~32~
	{
		DWORD localPlayer = Game::GetLocalPlayer();
		DWORD localEntity = Game::GetLocalEntity(i);

		if (!Game::ValidateEntity(i))
			continue;

		if (!Game::TeamCheck(i))
			continue;

		// Get our view matrix
		Math::ViewMatrix viewMatrix = Memory::Read<Math::ViewMatrix>(Game::client + Game::Offsets::dwViewMatrix);

		// Get our players origin, used for 2D Distance
		Math::Vector3 playerOrigin = Memory::Read<Math::Vector3>(localPlayer + Game::Offsets::m_vecOrigin);

		// Get our entity origin & head
		Math::Vector3 entityOrigin = Memory::Read<Math::Vector3>(localEntity + Game::Offsets::m_vecOrigin);
		Math::Vector3 entityHead = Game::GetEntityBone(localEntity, 8);

		// Convert entities origin & head into 2D space
		Math::Vector3 entityOrigin2D = Math::WorldToScreen(entityOrigin, viewMatrix);
		Math::Vector3 entityHead2D = Math::WorldToScreen(entityHead, viewMatrix);

		// Get entity's team number, for CT/T dependent coloring
		int entityTeam = Memory::Read<int>(localEntity + Game::Offsets::m_iTeamNum);

		// Prevents drawing behind us
		if (entityOrigin2D.z < 0.01f || entityHead2D.z < 0.01f)
			continue;

		float x = entityHead2D.x;
		float y = entityOrigin2D.y;
		float height = entityHead2D.y - entityOrigin2D.y;
		float width = height / 2.4f;

		// Box ESP
		if (Trainer::ESP::boxStatus == true)
		{
			if (entityTeam == 2) // If entity is a terrorist
			{
				// Sync our background color to border color
				float boxBackgroundColor[4] = { boxColorT[0], boxColorT[1], boxColorT[2], 0.2f };

				Graphics::Rendering::DrawFilledRect(x - width / 2, y, width, height / 0.9, boxBackgroundColor);
				Graphics::Rendering::DrawRect(x - width / 2, y, width, height / 0.9, Trainer::ESP::boxColorT, 1);
			}
			else if (entityTeam == 3) // If entity is a counter-terrorist
			{
				// Sync our background color to border color
				float boxBackgroundColor[4] = { boxColorCT[0], boxColorCT[1], boxColorCT[2], 0.2f };

				Graphics::Rendering::DrawFilledRect(x - width / 2, y, width, height / 0.9, boxBackgroundColor);
				Graphics::Rendering::DrawRect(x - width / 2, y, width, height / 0.9, Trainer::ESP::boxColorCT, 1);
			}
		}

		// Snapline ESP
		if (Trainer::ESP::snaplineStatus == true)
		{
			if (Trainer::ESP::snaplineType == 0) // Bottom
			{
				if (entityTeam == 2) // If entity is a terrorist
				{
					Graphics::Rendering::DrawLine(Graphics::Rendering::gameWidth / 2, Graphics::Rendering::gameHeight, x, y, Trainer::ESP::snaplineColorT, 1);
				}
				else if (entityTeam == 3) // If entity is a counter-terrorist
				{
					Graphics::Rendering::DrawLine(Graphics::Rendering::gameWidth / 2, Graphics::Rendering::gameHeight, x, y, Trainer::ESP::snaplineColorCT, 1);
				}
			}
			else if (Trainer::ESP::snaplineType == 1) // Middle
			{
				float radius = 45.f;
				float a = entityHead2D.y - Graphics::Rendering::gameHeight / 2;				// Distance between Entity Y and Center Y
				float b = entityHead2D.x - Graphics::Rendering::gameWidth / 2;				// Distance between Entity X and Center X
				float x3, y3;
				float angle = atan(a / b);													// Angle degrees from Center + Entity's right triangle

				if (b >= 0)																	// Normalize the result if (Entity X - Center X) is less than 0
				{
					x3 = radius * cos(angle) + Graphics::Rendering::gameWidth / 2;			// Calculate the circle's X position (radius * angle's cosine + center x)
					y3 = radius * sin(angle) + Graphics::Rendering::gameHeight / 2;			// Calculate the circle's Y position (radius * angle's sine + center x)
				}
				else
				{
					x3 = radius * (-cos(angle)) + Graphics::Rendering::gameWidth / 2;
					y3 = radius * (-sin(angle)) + Graphics::Rendering::gameHeight / 2;
				}

				if (sqrt(a * a + b * b) >= radius && entityTeam == 2) // If entity is a terrorist
				{
					Graphics::Rendering::DrawLine(entityHead2D.x, entityHead2D.y, x3, y3, Trainer::ESP::snaplineColorT, 1);
				}
				else if (sqrt(a * a + b * b) >= radius && entityTeam == 3)  // If entity is a counter-terrorist
				{
					Graphics::Rendering::DrawLine(entityHead2D.x, entityHead2D.y, x3, y3, Trainer::ESP::snaplineColorCT, 1);
				}
			}
		}

		// Healthbar ESP
		if (Trainer::ESP::healthbarStatus == true) 
		{
			int entityHealth = Memory::Read<int>(localEntity + Game::Offsets::m_iHealth);
			float healthFrac = static_cast<float>(entityHealth) / 100;

			float healthbarBackgroundColor[4] = { 0, 0, 0, 0.2 };
			float healthbarBackgroundColor2[4] = { 0, 0, 0, 1.0 };
			float healthbarColor[4] = { 1 - healthFrac, healthFrac, 0, 1 };

			// Don't ask, don't tell.
			Graphics::Rendering::DrawFilledRect(x + width / 1.9f, y, width / 500.f + 1.9f, height / 0.9, healthbarBackgroundColor);
			Graphics::Rendering::DrawRect(x + width / 1.9f, y, width / 500.f + 1.9f, height / 0.9, healthbarBackgroundColor2, 1.f);
			Graphics::Rendering::DrawFilledRect(x + width / 1.9f, y, width / 500.f + 1.9f, height * healthFrac / 0.9, healthbarColor);
		}

		// Head ESP
		if (Trainer::ESP::headStatus == true)
		{
			if (entityTeam == 2) // If entity is a terrorist
			{
				// Sync our background color to border color
				float headBackgroundColor[4] = { headColorT[0], headColorT[1], headColorT[2], 0.1f };

				Graphics::Rendering::DrawCircleFilled(entityHead2D.x, entityHead2D.y, 0.1 - width / 8, headBackgroundColor);
				Graphics::Rendering::DrawCircle(entityHead2D.x, entityHead2D.y, 0.1 - width / 8, Trainer::ESP::headColorT, 0);
			}
			else if (entityTeam == 3) // If entity is a counter-terrorist
			{
				// Sync our background color to border color
				float headBackgroundColor[4] = { headColorCT[0], headColorCT[1], headColorCT[2], 0.1f };

				Graphics::Rendering::DrawCircleFilled(entityHead2D.x, entityHead2D.y, 0.1 - width / 8, headBackgroundColor);
				Graphics::Rendering::DrawCircle(entityHead2D.x, entityHead2D.y, 0.1 - width / 8, Trainer::ESP::headColorCT, 0);
			}
		}

		// Distance ESP
		if (Trainer::ESP::distanceStatus == true)
		{
			char strEntityDistance[64];
			sprintf_s(strEntityDistance, skCrypt("[%0.fm]"), sqrt(pow(playerOrigin.x - entityOrigin.x, 2) + pow(playerOrigin.y - entityOrigin.y, 2) + pow(playerOrigin.z - entityOrigin.z, 2)) * 0.0254f);

			if (entityTeam == 2) // If entity is a terrorist
			{
				Graphics::Rendering::DrawString(entityOrigin2D.x - width / 1.7f, entityOrigin2D.y, Trainer::ESP::distanceColorT, strEntityDistance);
			}
			else if (entityTeam == 3) // If entity is a counter-terrorist
			{
				Graphics::Rendering::DrawString(entityOrigin2D.x - width / 1.7f, entityOrigin2D.y, Trainer::ESP::distanceColorCT, strEntityDistance);
			}
		}
	}
}