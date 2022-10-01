#pragma once

#include "../Stdafx.h"
#include "../Utilities/Math/Math.h"

namespace Game 
{
	DWORD GetLocalPlayer();
	DWORD GetLocalEntity(int i);
	bool ValidateEntity(int i);
	bool TeamCheck(int i);
	Math::Vector3 GetEntityBone(DWORD localEntity, int boneId);

	inline HANDLE handle;
	inline DWORD processId;
	inline DWORD client;

	// Update offsets from here: https://github.com/frk1/hazedumper/blob/master/csgo.hpp
	namespace Offsets 
	{
		inline DWORD dwLocalPlayer = 0xDC14CC;
		inline DWORD dwEntityList = 0x4DDD93C;
		inline DWORD m_bDormant = 0xED;
		inline DWORD m_iHealth = 0x100;
		inline DWORD m_iTeamNum = 0xF4;
		inline DWORD dwViewMatrix = 0x4DCF254;
		inline DWORD m_vecOrigin = 0x138;
		inline DWORD m_iCrosshairId = 0x11838;
		inline DWORD m_dwBoneMatrix = 0x26A8;
	}
};