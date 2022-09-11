#include "Game.h"
#include "../Utilities/Utilities.h"

bool Game::Initialize(HANDLE& handle, DWORD& processId, DWORD& client, DWORD& engine)
{
	handle = OpenProcess(FILE_ALL_ACCESS, false, Utilities::GetProcessId(skCrypt("Counter-Strike: Global Offensive - Direct3D 9")));
	processId = Utilities::GetProcessId(skCrypt("Counter-Strike: Global Offensive - Direct3D 9"));
	client = Utilities::GetModuleAddress(processId, skCrypt(L"client.dll"));
	engine = Utilities::GetModuleAddress(processId, skCrypt(L"engine.dll"));

	if (!client || !engine)
		Utilities::LogErrorMB(skCrypt("Failed to load specified modules, please make sure the application is running."));

	return true;
}

DWORD Game::GetLocalPlayer()
{
	DWORD localPlayer = Utilities::Read<DWORD>(Game::client + Game::Offsets::dwLocalPlayer);

	return localPlayer;
}

DWORD Game::GetLocalEntity(int i)
{
	DWORD localEntity = Utilities::Read<DWORD>(Game::client + Game::Offsets::dwEntityList + (i * 0x10));

	return localEntity;
}

bool Game::ValidateEntity(int i) 
{
	DWORD localEntity = Utilities::Read<DWORD>(Game::client + Game::Offsets::dwEntityList + (i * 0x10));

	int entityHealth = Utilities::Read<int>(localEntity + Game::Offsets::m_iHealth);
	bool entityDormant = Utilities::Read<int>(localEntity + Game::Offsets::m_bDormant);

	if (entityHealth < 1 || entityHealth > 100 || entityDormant == true)
		return false;

	return true;
}

bool Game::TeamCheck(int i) 
{
	DWORD localPlayer = Utilities::Read<DWORD>(Game::client + Game::Offsets::dwLocalPlayer);
	DWORD localEntity = Utilities::Read<DWORD>(Game::client + Game::Offsets::dwEntityList + (i * 0x10));

	int localTeam = Utilities::Read<int>(localPlayer + Game::Offsets::m_iTeamNum);
	int entityTeam = Utilities::Read<int>(localEntity + Game::Offsets::m_iTeamNum);

	if (localTeam == entityTeam)
		return false;

	return true;
}