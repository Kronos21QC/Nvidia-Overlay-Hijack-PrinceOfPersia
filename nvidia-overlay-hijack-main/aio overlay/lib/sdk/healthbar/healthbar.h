#pragma once
#include "..\struct\structs.h"
#include "..\..\memory\memory2.h"



void HealthBar(ViewMatrix VM, int PlayerHealth, Vector3 PlayerOrigin, Vector3 PlayerHead, Vector3 PlayerFeet, Vector3 Bottom, Vector3 Top)
{

	Vector3 Playerhealth10
	{
		PlayerOrigin.x, PlayerOrigin.y, PlayerOrigin.z + 65.f
	};


	Vector3 Playerhealth9
	{
		PlayerOrigin.x, PlayerOrigin.y, PlayerOrigin.z + 58.f
	};


	Vector3 Playerhealth8
	{
		PlayerOrigin.x, PlayerOrigin.y, PlayerOrigin.z + 51.f
	};

	Vector3 Playerhealth7
	{
		PlayerOrigin.x, PlayerOrigin.y, PlayerOrigin.z + 44.f
	};

	Vector3 Playerhealth6
	{
		PlayerOrigin.x, PlayerOrigin.y, PlayerOrigin.z + 37.f
	};

	Vector3 Playerhealth5
	{
		PlayerOrigin.x, PlayerOrigin.y, PlayerOrigin.z + 30.f
	};


	Vector3 Playerhealth4
	{
		PlayerOrigin.x, PlayerOrigin.y, PlayerOrigin.z + 23.f
	};


	Vector3 Playerhealth3
	{
		PlayerOrigin.x, PlayerOrigin.y, PlayerOrigin.z + 16.f
	};

	Vector3 Playerhealth2
	{
		PlayerOrigin.x, PlayerOrigin.y, PlayerOrigin.z + 9.f
	};

	Vector3 Playerhealth1
	{
		PlayerOrigin.x, PlayerOrigin.y, PlayerOrigin.z + 2.f
	};

	Vector3 TopHealth;


	const float h = Bottom.y - Top.y;
	const float w = h * 0.35;

	if (WTS(Playerhealth10, TopHealth, VM) && PlayerHealth <= 100 && PlayerHealth > 90)
	{
		ImGui::GetBackgroundDrawList()->AddLine({ Top.x - w - 5.f, Top.y }, { Top.x - w - 5.f, Bottom.y - 1.f }, ImColor(0.0f, 1.0f, 0.f), 2.f);
	}



	if (WTS(Playerhealth9, TopHealth, VM) && PlayerHealth <= 90 && PlayerHealth > 80)
	{
		ImGui::GetBackgroundDrawList()->AddLine({ Top.x - w - 5.f, TopHealth.y }, { Top.x - w - 5.f, Bottom.y - 1.f }, ImColor(0.2f, 1.0f, 0.0f), 2.f);
	}



	if (WTS(Playerhealth8, TopHealth, VM) && PlayerHealth <= 80 && PlayerHealth > 70)
	{
		ImGui::GetBackgroundDrawList()->AddLine({ Top.x - w - 5.f, TopHealth.y }, { Top.x - w - 5.f, Bottom.y - 1.f }, ImColor(0.4f, 1.0f, 0.0f), 2.f);
	}



	if (WTS(Playerhealth7, TopHealth, VM) && PlayerHealth <= 70 && PlayerHealth > 60)
	{
		ImGui::GetBackgroundDrawList()->AddLine({ Top.x - w - 5.f, TopHealth.y }, { Top.x - w - 5.f, Bottom.y - 1.f }, ImColor(0.6f, 1.0f, 0.0f), 2.f);
	}



	if (WTS(Playerhealth6, TopHealth, VM) && PlayerHealth <= 60 && PlayerHealth > 50)
	{
		ImGui::GetBackgroundDrawList()->AddLine({ Top.x - w - 5.f, TopHealth.y }, { Top.x - w - 5.f, Bottom.y - 1.f }, ImColor(0.8f, 1.0f, 0.0f), 2.f);
	}


	if (WTS(Playerhealth5, TopHealth, VM) && PlayerHealth <= 50 && PlayerHealth > 40)
	{
		ImGui::GetBackgroundDrawList()->AddLine({ Top.x - w - 5.f, TopHealth.y }, { Top.x - w - 5.f, Bottom.y - 1.f }, ImColor(1.0f, 0.8f, 0.0f), 2.f);
	}


	if (WTS(Playerhealth4, TopHealth, VM) && PlayerHealth <= 40 && PlayerHealth > 30)
	{
		ImGui::GetBackgroundDrawList()->AddLine({ Top.x - w - 5.f, TopHealth.y }, { Top.x - w - 5.f, Bottom.y - 1.f }, ImColor(1.0f, 0.6f, 0.0f), 2.f);
	}



	if (WTS(Playerhealth3, TopHealth, VM) && PlayerHealth <= 30 && PlayerHealth > 20)
	{
		ImGui::GetBackgroundDrawList()->AddLine({ Top.x - w - 5.f, TopHealth.y }, { Top.x - w - 5.f, Bottom.y - 1.f }, ImColor(1.0f, 0.4f, 0.0f), 2.f);

	}


	if (WTS(Playerhealth2, TopHealth, VM) && PlayerHealth <= 20 && PlayerHealth > 10)
	{
		ImGui::GetBackgroundDrawList()->AddLine({ Top.x - w - 5.f, TopHealth.y }, { Top.x - w - 5.f, Bottom.y - 1.f }, ImColor(1.0f, 0.2f, 0.0f), 2.f);
	}



	if (WTS(Playerhealth1, TopHealth, VM) && PlayerHealth <= 10 && PlayerHealth > 0)
	{

		ImGui::GetBackgroundDrawList()->AddLine({ Top.x - w - 5.f, TopHealth.y }, { Top.x - w - 5.f, Bottom.y - 1.f }, ImColor(1.0f, 0.0f, 0.0f), 2.f);
	}

}