#include "Game.h"
#include "../Utilities/Memory/Memory.h"
#include "../Utilities/Logging/Logging.h"

DWORD Game::GetLocalPlayer()
{
	DWORD localPlayer = Memory::Read<DWORD>(Game::client + Game::Offsets::dwLocalPlayer);

	return localPlayer;
}

DWORD Game::GetLocalEntity(int i)
{
	DWORD localEntity = Memory::Read<DWORD>(Game::client + Game::Offsets::dwEntityList + (i * 0x10));

	return localEntity;
}

bool Game::ValidateEntity(int i) 
{
	DWORD localEntity = Memory::Read<DWORD>(Game::client + Game::Offsets::dwEntityList + (i * 0x10));

	int entityHealth = Memory::Read<int>(localEntity + Game::Offsets::m_iHealth);
	bool entityDormant = Memory::Read<int>(localEntity + Game::Offsets::m_bDormant);

	if (entityHealth < 1 || entityHealth > 100 || entityDormant == true)
		return false;

	return true;
}

bool Game::TeamCheck(int i) 
{
	DWORD localPlayer = Memory::Read<DWORD>(Game::client + Game::Offsets::dwLocalPlayer);
	DWORD localEntity = Memory::Read<DWORD>(Game::client + Game::Offsets::dwEntityList + (i * 0x10));

	int localTeam = Memory::Read<int>(localPlayer + Game::Offsets::m_iTeamNum);
	int entityTeam = Memory::Read<int>(localEntity + Game::Offsets::m_iTeamNum);

	if (localTeam == entityTeam)
		return false;

	return true;
}

Math::Vector3 Game::GetEntityBone(DWORD localEntity, int boneId)
{
	DWORD boneMatrix = Memory::Read<DWORD>(localEntity + Game::Offsets::m_dwBoneMatrix);

	Math::Vector3 entityBone = Math::Vector3
	{
		Memory::Read<float>(boneMatrix + 0x30 * boneId + 0x0C), // X
		Memory::Read<float>(boneMatrix + 0x30 * boneId + 0x1C), // Y
		Memory::Read<float>(boneMatrix + 0x30 * boneId + 0x2C), // Z
	};

	return entityBone;
}

bool Game::Offsets::Update() 
{

	return true;
}