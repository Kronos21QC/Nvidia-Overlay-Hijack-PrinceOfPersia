#pragma once
#include "..\struct\structs.h"
#include "..\..\memory\memory2.h"


void Bones(uintptr_t bonearray, ViewMatrix VM)
{
	Vector3 PlayerHead1 = Memory::Read<Vector3>(bonearray + 6 * 32);
	Vector3 PlayerNeck = Memory::Read<Vector3>(bonearray + 5 * 32);
	Vector3 PlayerSpine = Memory::Read<Vector3>(bonearray + 4 * 32);
	Vector3 PlayerSpine2 = Memory::Read<Vector3>(bonearray + 2 * 32);
	Vector3 PlayerLeftShoulder = Memory::Read<Vector3>(bonearray + 8 * 32);
	Vector3 PlayerLeftArm = Memory::Read<Vector3>(bonearray + 9 * 32);
	Vector3 PlayerLeftHand = Memory::Read<Vector3>(bonearray + 11 * 32);
	Vector3 Player7od = Memory::Read<Vector3>(bonearray + 0 * 32);
	Vector3 PlayerRightShoulder = Memory::Read<Vector3>(bonearray + 13 * 32);
	Vector3 PlayerRightArm = Memory::Read<Vector3>(bonearray + 14 * 32);
	Vector3 PlayerRightHand = Memory::Read<Vector3>(bonearray + 16 * 32);
	Vector3 PlayerLeftHip = Memory::Read<Vector3>(bonearray + 22 * 32);
	Vector3 PlayerLeftKnee = Memory::Read<Vector3>(bonearray + 23 * 32);
	Vector3 PlayerLeftFeet = Memory::Read<Vector3>(bonearray + 24 * 32);
	Vector3 PlayerRighthip = Memory::Read<Vector3>(bonearray + 25 * 32);
	Vector3 PlayerRightKnee = Memory::Read<Vector3>(bonearray + 26 * 32);
	Vector3 PlayerRightFeet = Memory::Read<Vector3>(bonearray + 27 * 32);

	Vector3 PlayerHeadW2S;
	Vector3 PlayerNeckW2S;
	Vector3 PlayerSpineW2S;
	Vector3 PlayerSpine2W2S;
	Vector3 PlayerLeftShoulderW2S;
	Vector3 PlayerLeftArmW2S;
	Vector3 PlayerLeftHandW2S;
	Vector3 Player7odW2S;
	Vector3 PlayerightShoulderW2S;
	Vector3 PlayerRightArmW2S;
	Vector3 PlayerRightHandW2S;
	Vector3 PlayerLeftHipW2S;
	Vector3 PlayerLeftKneeW2S;
	Vector3 PlayerLeftFeetW2S;
	Vector3 PlayerighthipW2S;
	Vector3 PlayerRightKneeW2S;
	Vector3 PlayerrightFeetW2S;



	if (WTS(PlayerNeck, PlayerNeckW2S, VM) && WTS(PlayerHead1, PlayerHeadW2S, VM))
	{
		ImGui::GetBackgroundDrawList()->AddLine({ PlayerNeckW2S.x, PlayerNeckW2S.y }, { PlayerHeadW2S.x, PlayerHeadW2S.y }, ImColor(1.f, 1.f, 1.f), 1.f);
	}

	if (WTS(PlayerNeck, PlayerNeckW2S, VM) && WTS(PlayerSpine, PlayerSpineW2S, VM))
	{
		ImGui::GetBackgroundDrawList()->AddLine({ PlayerNeckW2S.x, PlayerNeckW2S.y }, { PlayerSpineW2S.x, PlayerSpineW2S.y }, ImColor(1.f, 1.f, 1.f), 1.f);
	}

	if (WTS(PlayerSpine, PlayerSpineW2S, VM) && WTS(PlayerLeftShoulder, PlayerLeftShoulderW2S, VM))
	{
		ImGui::GetBackgroundDrawList()->AddLine({ PlayerSpineW2S.x, PlayerSpineW2S.y }, { PlayerLeftShoulderW2S.x, PlayerLeftShoulderW2S.y }, ImColor(1.f, 1.f, 1.f), 1.f);
	}


	if (WTS(PlayerLeftShoulder, PlayerLeftShoulderW2S, VM) && WTS(PlayerLeftArm, PlayerLeftArmW2S, VM))
	{
		ImGui::GetBackgroundDrawList()->AddLine({ PlayerLeftShoulderW2S.x, PlayerLeftShoulderW2S.y }, { PlayerLeftArmW2S.x, PlayerLeftArmW2S.y }, ImColor(1.f, 1.f, 1.f), 1.f);
	}


	if (WTS(PlayerLeftArm, PlayerLeftArmW2S, VM) && WTS(PlayerLeftHand, PlayerLeftHandW2S, VM))
	{
		ImGui::GetBackgroundDrawList()->AddLine({ PlayerLeftArmW2S.x, PlayerLeftArmW2S.y }, { PlayerLeftHandW2S.x, PlayerLeftHandW2S.y }, ImColor(1.f, 1.f, 1.f), 1.f);
	}


	if (WTS(PlayerSpine, PlayerSpineW2S, VM) && WTS(PlayerRightShoulder, PlayerightShoulderW2S, VM))
	{
		ImGui::GetBackgroundDrawList()->AddLine({ PlayerSpineW2S.x, PlayerSpineW2S.y }, { PlayerightShoulderW2S.x, PlayerightShoulderW2S.y }, ImColor(1.f, 1.f, 1.f), 1.f);
	}

	if (WTS(PlayerRightShoulder, PlayerightShoulderW2S, VM) && WTS(PlayerRightArm, PlayerRightArmW2S, VM))
	{
		ImGui::GetBackgroundDrawList()->AddLine({ PlayerightShoulderW2S.x, PlayerightShoulderW2S.y }, { PlayerRightArmW2S.x, PlayerRightArmW2S.y }, ImColor(1.f, 1.f, 1.f), 1.f);
	}

	if (WTS(PlayerRightArm, PlayerRightArmW2S, VM) && WTS(PlayerRightHand, PlayerRightHandW2S, VM))
	{
		ImGui::GetBackgroundDrawList()->AddLine({ PlayerRightArmW2S.x, PlayerRightArmW2S.y }, { PlayerRightHandW2S.x, PlayerRightHandW2S.y }, ImColor(1.f, 1.f, 1.f), 1.f);
	}

	if (WTS(PlayerSpine, PlayerSpineW2S, VM) && WTS(PlayerSpine2, PlayerSpine2W2S, VM))
	{
		ImGui::GetBackgroundDrawList()->AddLine({ PlayerSpineW2S.x, PlayerSpineW2S.y }, { PlayerSpine2W2S.x, PlayerSpine2W2S.y }, ImColor(1.f, 1.f, 1.f), 1.f);
	}

	if (WTS(PlayerSpine2, PlayerSpine2W2S, VM) && WTS(Player7od, Player7odW2S, VM))
	{
		ImGui::GetBackgroundDrawList()->AddLine({ PlayerSpine2W2S.x, PlayerSpine2W2S.y }, { Player7odW2S.x, Player7odW2S.y }, ImColor(1.f, 1.f, 1.f), 1.f);
	}

	if (WTS(Player7od, Player7odW2S, VM) && WTS(PlayerLeftHip, PlayerLeftHipW2S, VM))
	{
		ImGui::GetBackgroundDrawList()->AddLine({ Player7odW2S.x, Player7odW2S.y }, { PlayerLeftHipW2S.x, PlayerLeftHipW2S.y }, ImColor(1.f, 1.f, 1.f), 1.f);
	}

	if (WTS(PlayerLeftHip, PlayerLeftHipW2S, VM) && WTS(PlayerLeftKnee, PlayerLeftKneeW2S, VM))
	{
		ImGui::GetBackgroundDrawList()->AddLine({ PlayerLeftHipW2S.x, PlayerLeftHipW2S.y }, { PlayerLeftKneeW2S.x, PlayerLeftKneeW2S.y }, ImColor(1.f, 1.f, 1.f), 1.f);
	}

	if (WTS(PlayerLeftKnee, PlayerLeftKneeW2S, VM) && WTS(PlayerLeftFeet, PlayerLeftFeetW2S, VM))
	{
		ImGui::GetBackgroundDrawList()->AddLine({ PlayerLeftKneeW2S.x, PlayerLeftKneeW2S.y }, { PlayerLeftFeetW2S.x, PlayerLeftFeetW2S.y }, ImColor(1.f, 1.f, 1.f), 1.f);
	}

	if (WTS(Player7od, Player7odW2S, VM) && WTS(PlayerRighthip, PlayerighthipW2S, VM))
	{
		ImGui::GetBackgroundDrawList()->AddLine({ Player7odW2S.x, Player7odW2S.y }, { PlayerighthipW2S.x, PlayerighthipW2S.y }, ImColor(1.f, 1.f, 1.f), 1.f);
	}

	if (WTS(PlayerRighthip, PlayerighthipW2S, VM) && WTS(PlayerRightKnee, PlayerRightKneeW2S, VM))
	{
		ImGui::GetBackgroundDrawList()->AddLine({ PlayerighthipW2S.x, PlayerighthipW2S.y }, { PlayerRightKneeW2S.x, PlayerRightKneeW2S.y }, ImColor(1.f, 1.f, 1.f), 1.f);
	}

	if (WTS(PlayerRightKnee, PlayerRightKneeW2S, VM) && WTS(PlayerRightFeet, PlayerrightFeetW2S, VM))
	{
		ImGui::GetBackgroundDrawList()->AddLine({ PlayerRightKneeW2S.x, PlayerRightKneeW2S.y }, { PlayerrightFeetW2S.x, PlayerrightFeetW2S.y }, ImColor(1.f, 1.f, 1.f), 1.f);
	}
}