#pragma once

#include "../Stdafx.h"

namespace Game 
{
	bool Initialize(HANDLE& handle, DWORD& processId, DWORD& client, DWORD& engine);
	DWORD GetLocalPlayer();
	DWORD GetLocalEntity(int i);
	bool ValidateEntity(int i);
	bool TeamCheck(int i);

	inline HANDLE handle;
	inline DWORD processId;
	inline DWORD client;
	inline DWORD engine;

	/* Update offsets from here, https://github.com/frk1/hazedumper/blob/master/csgo.hpp */
	namespace Offsets 
	{
		bool Update();

		inline DWORD dwLocalPlayer = 0xDC14CC;
		inline DWORD dwEntityList = 0x4DDD91C;
		inline DWORD m_bDormant = 0xED;
		inline DWORD m_iHealth = 0x100;
		inline DWORD m_iTeamNum = 0xF4;
		inline DWORD dwViewMatrix = 0x4DCF234;
		inline DWORD m_vecOrigin = 0x138;
		inline DWORD m_iCrosshairId = 0x11838;
	}
};