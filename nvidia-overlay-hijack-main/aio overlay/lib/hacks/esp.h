#include "../sdk/players/players.h"
#include "../sdk/struct/structs.h"
#include "../sdk/players/localplayer.h"
#include "../sdk/bones/bones.h"
#include "../sdk/healthbar/healthbar.h"


extern uintptr_t clientBase;


void ESP() {

	uintptr_t LocalPlayer = GetLocalPlayer();

	if (LocalPlayer)
	{

		int LocalPlayerTeam = GetTeam(LocalPlayer);

		uintptr_t EntityList = Memory::Read<uintptr_t>(clientBase + offsets::dwEntityList);

		Vector3 LocalOrigin = GetLocalOrigin(LocalPlayer);

		for (int i = 1; i < 32; ++i)
		{
			ViewMatrix VM = Memory::Read<ViewMatrix>(clientBase + offsets::dwViewMatrix);

			uintptr_t listEntry = Memory::Read<uintptr_t>(EntityList + (8 * (i & 0x7FFF) >> 9) + 0x10);   // = EntityList + 10;


			if (!listEntry)
				continue;

			uintptr_t player = Memory::Read<uintptr_t>(listEntry + 0x78 * (i & 0x1FF)); //الاعب رقم 2     

			if (!player)
				continue;

			uint32_t playerPawn = Memory::Read<uint32_t>(player + offsets::m_hPlayerPawn);   //اللاعب ال2 زائد البون



			uintptr_t listEntry2 = Memory::Read<uintptr_t>(EntityList + 0x8 * ((playerPawn & 0x7FFF) >> 9) + 0x10); //10 SAME THING AS BEFORE LOL (ListEntry)


			uintptr_t pCSPPlayerPawn = Memory::Read<uintptr_t>(listEntry2 + 0x78 * (playerPawn & 0x1FF)); //8430

			if (LocalPlayer == pCSPPlayerPawn)
				continue;

			// Player Health & Team ..
			int PlayerHealth = GetPlayerHealth(pCSPPlayerPawn);

			if (PlayerHealth <= 0.1 || PlayerHealth > 100)
				continue;

			int PlayerTeam = GetPlayerTeam(pCSPPlayerPawn);

			uintptr_t Playergamescene = Memory::Read<uintptr_t>(pCSPPlayerPawn + 0x310);
			uintptr_t bonearray = Memory::Read<uintptr_t>(Playergamescene + 0x160 + 0x80);



			Vector3 PlayerOrigin = GetPlayerOrigin(pCSPPlayerPawn);

			Vector3 PlayerHead
			{
				PlayerOrigin.x, PlayerOrigin.y, PlayerOrigin.z + 72.f
			};

			Vector3 PlayerFeet
			{
				PlayerOrigin.x, PlayerOrigin.y, PlayerOrigin.z - 10.f
			};



			Vector3 Top;
			Vector3 Bottom;


			float CurrentDistance = GetDistance(PlayerOrigin, LocalOrigin);
			ImColor lol(1.f, 0.f, 0.f);


			if (WTS(PlayerHead, Top, VM) && WTS(PlayerFeet, Bottom, VM))
			{
				const float h = Bottom.y - Top.y;
				const float w = h * 0.35;

				char buffer[32];
				snprintf(buffer, sizeof(buffer), "Health: %d", PlayerHealth);

				if (CurrentDistance < 1200.f)
				{
					ImGui::GetBackgroundDrawList()->AddText({ Top.x - 30.f, Top.y - 15.f }, ImColor(1.f, 0.f, 0.f), buffer);
				}

				ImGui::GetBackgroundDrawList()->AddLine({ Top.x - w - 5.f, Top.y }, { Top.x - w - 5.f, Bottom.y - 1.f }, ImColor(0.f, 0.0f, 0.f), 4.f);



				Bones(bonearray, VM);

				//Health Bar
				HealthBar(VM, PlayerHealth, PlayerOrigin, PlayerHead, PlayerFeet, Bottom, Top);

				if (LocalPlayerTeam == PlayerTeam)
				{
					ImGui::GetBackgroundDrawList()->AddRect({ Top.x - w - 1.f, Top.y - 1.f }, { Top.x + w - 1.f, Bottom.y + 1.f }, ImColor(0.f, 0.f, 0.f));
					ImGui::GetBackgroundDrawList()->AddRect({ Top.x - w, Top.y }, { Top.x + w, Bottom.y }, ImColor(0.f, 1.f, 0.f));
					ImGui::GetBackgroundDrawList()->AddRect({ Top.x - w + 1.f, Top.y + 1.f }, { Top.x + w + 1.f, Bottom.y + 1.f }, ImColor(0.f, 0.f, 0.f));
					continue;
				}

				//Box
				ImGui::GetBackgroundDrawList()->AddRectFilled({ Top.x - w, Top.y }, { Top.x + w, Bottom.y }, ImColor(0.f, 0.f, 0.f, 0.3f));
				ImGui::GetBackgroundDrawList()->AddRect({ Top.x - w - 1.f, Top.y - 1.f }, { Top.x + w - 1.f, Bottom.y + 1.f }, ImColor(0.f, 0.f, 0.f));
				ImGui::GetBackgroundDrawList()->AddRect({ Top.x - w, Top.y }, { Top.x + w, Bottom.y }, lol);
				ImGui::GetBackgroundDrawList()->AddRect({ Top.x - w + 1.f, Top.y + 1.f }, { Top.x + w + 1.f, Bottom.y + 1.f }, ImColor(0.f, 0.f, 0.f));


				//BottomLines
				ImGui::GetBackgroundDrawList()->AddLine({ 960.f, 1080.f }, { Top.x, Bottom.y }, lol);


			}

		}

	}
}