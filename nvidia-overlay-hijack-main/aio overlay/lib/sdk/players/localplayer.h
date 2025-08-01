#pragma once
#include <iostream>
#include <numbers>
#include "..\..\..\src\offsets.h"
#include "..\struct\structs.h"
#include "..\..\memory\memory.h"

extern uintptr_t clientBase;

uintptr_t GetLocalPlayer()
{
	uintptr_t MyLocalPlayer = Memory::Read<uintptr_t>(clientBase + offsets::dwLocalPlayerPawn);
#ifdef _DEBUG
	if (!MyLocalPlayer)  // Check if pointer is invalid (returned zero/nullptr)
	{
		std::cerr << "[DEBUG] Couldn't find LocalPlayerPawn (LocalPlayer is nullptr)." << std::endl;
		system("pause");
	}
	else
	{
		std::cout << "[DEBUG] Found LocalPlayerPawn at address: 0x" << std::hex << MyLocalPlayer << std::dec << std::endl;
	}
#endif
	return MyLocalPlayer;
}

int GetLocalHealth(uintptr_t LocalPlayer)
{
	int Health = Memory::Read<int>(LocalPlayer + offsets::m_iHealth);

	return Health;
}

int GetTeam(uintptr_t LocalPlayer)
{
	int Team = Memory::Read<int>(LocalPlayer + offsets::TeamNum);

	return Team;
}

Vector3 GetLocalOrigin(uintptr_t LocalPlayer)
{
	Vector3 LocalOrigin = Memory::Read<Vector3>(LocalPlayer + offsets::VecOrigin);

	return LocalOrigin;
}

/*Vector3 GetLocalAngles(uintptr_t Client, uintptr_t LocalPlayer)
{
	Vector3 LocalAnglesView = rpm<Vector3>(Client + offsets::ViewAngles);

	return LocalAnglesView;
}*/


Vector3 LocalEyePos(uintptr_t LocalPlayer)
{
	Vector3 LocalOrigin = GetLocalOrigin(LocalPlayer);

	Vector3 EyePos = Memory::Read<Vector3>(LocalPlayer + offsets::m_vecViewOffset) + LocalOrigin;

	return EyePos;
}
float GetEditedAimPunch(uintptr_t LocalPlayer)
{
	float AimPunch = Memory::Read<float>(LocalPlayer + offsets::m_aimPunchAngle);

	return AimPunch * 2;
}
float GetAimPunch(uintptr_t LocalPlayer)
{
	float AimPunch = Memory::Read<float>(LocalPlayer + offsets::m_aimPunchAngle);

	return AimPunch;
}

/*Vector3 CalculateAngle(Vector3& LocalPlayerHead, Vector3& EnemyHead, uintptr_t Client, uintptr_t LocalPlayer)
{
	float AimPunch = GetEditedAimPunch(LocalPlayer);
	Vector3 Delta
	{
		EnemyHead.x - LocalPlayerHead.x, EnemyHead.y - LocalPlayerHead.y, EnemyHead.z - LocalPlayerHead.z
	};

	Vector3 LocalPlayerAngles = rpm<Vector3>(Client + offsets::ViewAngles);

	Vector3 Angles
	{
		atan2(-Delta.z, hypot(Delta.x, Delta.y)) * (180.0f / std::numbers::pi_v<float>),
		atan2(Delta.y, Delta.x) * (180.0f / std::numbers::pi_v<float>),
		0.0f
	};

	Vector3 FinalAngel
	{
		Angles - (LocalPlayerAngles + AimPunch)
	};

	return FinalAngel;

}*/
/*Vector3 GetLocalFov(const Vector3& EnemyPos, const Vector3& LocalPos, uintptr_t Client)
{
	uintptr_t LocalPlayer = GetLocalPlayer(Client);

	Vector3 LocalViewAngles = GetLocalAngles(Client, LocalPlayer);

	Vector3 Delta = EnemyPos - LocalPos;

	Vector3 Angles
	{
		atan2(-Delta.z, hypot(Delta.x, Delta.y)) * (180.0f / std::numbers::pi_v<float>),
		atan2(Delta.y, Delta.x) * (180.0f / std::numbers::pi_v<float>),
		0.f
	};

	return (Angles - LocalViewAngles);

}*/
