#include "../Trainer.h"
#include "../../Utilities/Memory/Memory.h"
#include "../../Game/Game.h"
#include "../../Graphics/Graphics.h"
#include "../../Utilities/Math/Math.h"

void Trainer::Esp2D() 
{
		/* Ranked: 10 entities, Casual: 20 entities, Community: ~32~ entities */
		for (int i = 1; i < 32; i++) 
		{ 
			DWORD localEntity = Game::GetLocalEntity(i);

			if (!Game::ValidateEntity(i))
				continue;

			if (!Game::TeamCheck(i))
				continue;

			Math::view_matrix_t viewMatrix = Memory::Read<Math::view_matrix_t>(Game::client + Game::Offsets::dwViewMatrix);

			/* Get our entity origin & head */
			Math::Vector3 entityOrigin = Memory::Read<Math::Vector3>(localEntity + Game::Offsets::m_vecOrigin);
			Math::Vector3 entityHead = Game::GetEntityBone(localEntity, 8);

			/* Convert entities origin & head into 2D space */
			Math::Vector3 entityOrigin2D = Math::WorldToScreen(entityOrigin, viewMatrix);
			Math::Vector3 entityHead2D = Math::WorldToScreen(entityHead, viewMatrix);

			/* Prevents drawing behind us */
			if (entityOrigin2D.z < 0.01f || entityHead2D.z < 0.01f)
				continue;

			float x = entityHead2D.x;
			float y = entityOrigin2D.y;
			float height = entityHead2D.y - entityOrigin2D.y;
			float width = height / 2.4f;

			DrawCircle(entityHead2D.x, entityHead2D.y, 0.1f - width / 2, 0.7, 1.0, 0.0, 0.0, 1.0, false);

			/* 2D Boxes */
			if (Trainer::Settings::boxes2D == 1)
			{
				DrawBox(x - width / 2, y, width, height, 0.7, 1.0, 0.0, 0.0, 0.1, true);
				DrawBox(x - width / 2, y, width, height, 0.7, 1.0, 0.0, 0.0, 1.0, false);
			}

			/* 2D Snaplines */
			if (Trainer::Settings::snaplines2D == 1) /* BOTTOM */
				DrawLine(Graphics::gameWidth / 2, Graphics::gameHeight, x, y, 0.7, 1.0, 0.0, 0.0, 1.0);
			else if (Trainer::Settings::snaplines2D == 2) /* MIDDLE */
			{
				float radius = 50.0;					 // Center circle's radius
				float x1 = Graphics::gameWidth / 2;		 // Center X
				float y1 = Graphics::gameHeight / 2;	 // Center Y
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
					DrawLine(x2, y2, x3, y3, 0.7, 1.0, 0.0, 0.0, 1.0);		// Draw line from Entity X, Entity Y to Circle X, Circle Y
			} 
			else if (Trainer::Settings::snaplines2D == 3) /* TOP */
				DrawLine(Graphics::gameWidth / 2, 0, entityHead2D.x, entityHead2D.y, 0.7, 1.0, 0.0, 0.0, 1.0);
		}
}