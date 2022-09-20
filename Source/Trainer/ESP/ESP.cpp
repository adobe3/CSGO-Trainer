#include "ESP.h"
#include "../../Utilities/Memory/Memory.h"
#include "../../Game/Game.h"
#include "../../Graphics/Rendering/Rendering.h"
#include "../../Utilities/Math/Math.h"

void Trainer::ESP::Run() 
{
		// Ranked: 10, Casual: 20, Community: ~32~
	for (int i = 1; i < 32; i++)
	{
		DWORD localPlayer = Game::GetLocalPlayer();
		DWORD localEntity = Game::GetLocalEntity(i);

		if (!Game::ValidateEntity(i))
			continue;

		if (!Game::TeamCheck(i))
			continue;

		// Get our view matrix
		Math::view_matrix_t viewMatrix = Memory::Read<Math::view_matrix_t>(Game::client + Game::Offsets::dwViewMatrix);

		// Get our players origin, used for 2D Distance
		Math::Vector3 playerOrigin = Memory::Read<Math::Vector3>(localPlayer + Game::Offsets::m_vecOrigin);

		// Get our entity origin & head
		Math::Vector3 entityOrigin = Memory::Read<Math::Vector3>(localEntity + Game::Offsets::m_vecOrigin);
		Math::Vector3 entityHead = Game::GetEntityBone(localEntity, 8);

		// Convert entities origin & head into 2D space
		Math::Vector3 entityOrigin2D = Math::WorldToScreen(entityOrigin, viewMatrix);
		Math::Vector3 entityHead2D = Math::WorldToScreen(entityHead, viewMatrix);

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
			if (Trainer::ESP::boxType == 0)
			{
				Graphics::Rendering::DrawFilledRect(x - width / 2, y, width, height, Trainer::ESP::boxBackgroundColor);
				Graphics::Rendering::DrawRect(x - width / 2, y, width, height, Trainer::ESP::boxColor, 1);
			}
			else if (Trainer::ESP::boxType == 1)
			{
				Graphics::Rendering::DrawFilledRect(x - width / 2, y, width, height, Trainer::ESP::boxBackgroundColor);
				Graphics::Rendering::DrawCornerBox(x - width / 2, y, width, height, 1, Trainer::ESP::boxColor);
			}
		}

		// Snapline ESP
		if (Trainer::ESP::snaplineStatus == true)
		{
			if (Trainer::ESP::snaplineType == 0) // Bottom
				Graphics::Rendering::DrawLine(Graphics::Rendering::gameWidth / 2, Graphics::Rendering::gameHeight, x, y, Trainer::ESP::snaplineColor, 1);
			else if (Trainer::ESP::snaplineType == 1) // Middle
			{
				float radius = 45.f;
				float a = entityHead2D.y - Graphics::Rendering::gameHeight / 2;				// Distance between Entity Y and Center Y
				float b = entityHead2D.x - Graphics::Rendering::gameWidth / 2;				// Distance between Entity X and Center X										// Hypotenuse of entity triangle
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

				if (sqrt(a * a + b * b) >= radius)											// If hypotenuse is greater than or equal to raidus, draw snaplines
					Graphics::Rendering::DrawLine(entityHead2D.x, entityHead2D.y, x3, y3, Trainer::ESP::snaplineColor, 1);
			}
			else if (Trainer::ESP::snaplineType == 2) // Top
				Graphics::Rendering::DrawLine(Graphics::Rendering::gameWidth / 2, 0, entityHead2D.x, entityHead2D.y, Trainer::ESP::snaplineColor, 1);
		}

		float red[4] = { 0, 0, 255, 255 };

		// Healthbar ESP
		if (Trainer::ESP::healthbarStatus == true) 
		{
			int entityHealth = Memory::Read<int>(localEntity + Game::Offsets::m_iHealth);
			float healthFrac = static_cast<float>(entityHealth) / 100;

			Graphics::Rendering::DrawFilledRect(x + width / 1.9f, y, height / 80.f, height, red);
			Graphics::Rendering::DrawFilledRect(x + width / 1.9f, y, height / 80.f, healthFrac * height, red);
			Graphics::Rendering::DrawRect(x + width / 1.9f, y, height / 80.f, height, red, 1);
		}

		// Head ESP
		if (Trainer::ESP::headStatus == true)
		{
			Graphics::Rendering::DrawCircleFilled(entityHead2D.x, entityHead2D.y, 0.1 - width / 6, Trainer::ESP::headBackgroundColor);
			Graphics::Rendering::DrawCircle(entityHead2D.x, entityHead2D.y, 0.1 - width / 6, Trainer::ESP::headColor, 0);
		}

		// Distance ESP
		if (Trainer::ESP::distanceStatus == true)
		{
			char entityDistance[64];
			sprintf_s(entityDistance, "%0.fm", sqrt(pow(playerOrigin.x - entityOrigin.x, 2) + pow(playerOrigin.y - entityOrigin.y, 2) + pow(playerOrigin.z - entityOrigin.z, 2)) * 0.0254f);

			Graphics::Rendering::DrawStrokeString(x - width / 1.7f, y, Trainer::ESP::distanceColor, entityDistance);
		}
	}
}