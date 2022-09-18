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
			if (Trainer::ESP::boxStatus == 1)
			{
				Graphics::Rendering::DrawBox(x - width / 2, y, width, height, 0.7, 1.0, 0.0, 0.0, 0.1, true);
				Graphics::Rendering::DrawBox(x - width / 2, y, width, height, 0.7, 1.0, 0.0, 0.0, 1.0, false);
			}

			// Snapline ESP
			if (Trainer::ESP::snaplineStatus == 1) // BOTTOM
				Graphics::Rendering::DrawLine(Graphics::Rendering::gameWidth / 2, Graphics::Rendering::gameHeight, x, y, 0.7, 1.0, 0.0, 0.0, 1.0);
			else if (Trainer::ESP::snaplineStatus == 2) // MIDDLE
			{
				float radius = 50.0;					 // Center circle's radius
				float x1 = static_cast<float>(Graphics::Rendering::gameWidth / 2);			// Center X
				float y1 = static_cast<float>(Graphics::Rendering::gameHeight / 2);		// Center Y
				float x2 = entityHead2D.x;				 // Entity X
				float y2 = entityHead2D.y;				 // Entity Y
				float a = y2 - y1;						 // Distance between Entity Y and Center Y
				float b = x2 - x1;						 // Distance between Entity X and Center X
				float c = sqrt(a * a + b * b);			 // Hypotenuse of entity triangle
				float x3 = 0.0;
				float y3 = 0.0;
				float angle = atan(a / b);				 // Angle degrees from Center + Entity's right triangle

				if (b >= 0)								 // Normalize the result if (Entity X - Center X) is less than 0
				{
					x3 = radius * cos(angle) + x1;       // Calculate the circle's X position (radius * angle's cosine + center x)
					y3 = radius * sin(angle) + y1;       // Calculate the circle's Y position (radius * angle's sine + center x)
				}
				else
				{
					x3 = radius * (-cos(angle)) + x1;
					y3 = radius * (-sin(angle)) + y1;
				}

				if(c >= radius)												// If entity is not inside circle radius
					Graphics::Rendering::DrawLine(x2, y2, x3, y3, 0.7, 1.0, 0.0, 0.0, 1.0);		// Draw line from Entity X, Entity Y to Circle X, Circle Y
			} 
			else if (Trainer::ESP::snaplineStatus == 3) // TOP
				Graphics::Rendering::DrawLine(Graphics::Rendering::gameWidth / 2, 0, entityHead2D.x, entityHead2D.y, 0.7, 1.0, 0.0, 0.0, 1.0);

			// Healthbar ESP
			if (Trainer::ESP::healthbarStatus == 1) 
			{
				int entityHealth = Memory::Read<int>(localEntity + Game::Offsets::m_iHealth);
				float healthFrac = static_cast<float>(entityHealth) / 100;

				Graphics::Rendering::DrawBox(x + width / 1.9f, y, height / 80.f, height, 0.7, 0.0, 0.0, 0.0, 0.4, true);
				Graphics::Rendering::DrawBox(x + width / 1.9f, y, height / 80.f, healthFrac * height, 0.7, 1 - healthFrac, healthFrac, 0.0, 1.0, true);
				Graphics::Rendering::DrawBox(x + width / 1.9f, y, height / 80.f, height, 0.7, 0.0, 0.0, 0.0, 0.4, false);
			}

			// Head ESP
			if (Trainer::ESP::headStatus == 1)
			{
				Graphics::Rendering::DrawCircle(entityHead2D.x, entityHead2D.y, 0.1 - width / 6, 0.7, 1.0, 0.0, 0.0, 0.1, true);
				Graphics::Rendering::DrawCircle(entityHead2D.x, entityHead2D.y, 0.1 - width / 6, 0.7, 1.0, 0.0, 0.0, 1.0, false);
			}

			// Distance ESP
			if (Trainer::ESP::distanceStatus == 1)
			{
				int entityDistance = sqrt(pow(playerOrigin.x - entityOrigin.x, 2) + pow(playerOrigin.y - entityOrigin.y, 2) + pow(playerOrigin.z - entityOrigin.z, 2)) * 0.0254f;

				std::string strEntityDistance = std::to_string(entityDistance);
				Graphics::Rendering::DrawString(strEntityDistance, 6.9, x - width / 1.7f, y + height, 1.0, 0.0, 0.0, 1.0);
			}
		}
}