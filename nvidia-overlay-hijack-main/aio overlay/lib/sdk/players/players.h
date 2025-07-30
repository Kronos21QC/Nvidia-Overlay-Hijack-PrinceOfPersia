#pragma once
#include <iostream>
#include <numbers>
#include "..\..\..\src\offsets.h"
#include "..\struct\structs.h"
#include "..\..\memory\memory.h"

extern HANDLE hProcess;
extern uintptr_t clientBase;

uintptr_t GetPlayers(int i)
{
	uintptr_t entityAddress = clientBase + offsets::dwEntityList + (i * 0x8);
	return entityAddress;
}


int GetPlayerHealth(uintptr_t PlayerNumber)
{
	int Health = Memory::Read<int>(PlayerNumber + offsets::m_iHealth);

	return Health;
}

int GetPlayerTeam(uintptr_t PlayerNumber)
{
	int Team = Memory::Read<int>(PlayerNumber + offsets::TeamNum);

	return Team;
}

Vector3 GetPlayerOrigin(uintptr_t PlayerNumber)
{
	Vector3 LocalOrigin = Memory::Read<Vector3>(PlayerNumber + offsets::VecOrigin);

	return LocalOrigin;
}


Vector3 GetPlayerHeadPos(uintptr_t PlayerNumber)
{

	uintptr_t Playergamescene = Memory::Read<uintptr_t>(PlayerNumber + 0x310);
	uintptr_t bonearray = Memory::Read<uintptr_t>(Playergamescene + 0x160 + 0x80);
	Vector3 PlayerHead = Memory::Read<Vector3>(bonearray + 6 * 32);

	return PlayerHead;
}

float GetDistance(Vector3& enemyPos, Vector3& LocalPos)
{
	Vector3 Delta
	{
		enemyPos.x - LocalPos.x, enemyPos.y - LocalPos.y, enemyPos.z - LocalPos.z };

	return sqrtf(Delta.x * Delta.x + Delta.y * Delta.y + Delta.z * Delta.z);
}


