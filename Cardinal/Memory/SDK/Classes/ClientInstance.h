#pragma once
#include "../Minecraft.h"
#include "MinecraftGame.h"
#include "GuiData.h"
#include "ItemStack.h"
#include "Player.h"
#include "PlayerInventory.h"
#include "GameMode.h"
#include "BlockSource.h"
#include "Dimension.h"
#include "Level.h"
#include "Block.h"

#include "LoopbackPacketSender.h"
#include "Packet.h"

#include "TextHolder.h"

class ClientInstance {
public:
	class Player* GetLocalPlayer() {
		static unsigned int offset = 0;
		if (offset == NULL)
			offset = *reinterpret_cast<int*>(Utils::FindSig("48 8B 81 ? ? ? ? C3 CC CC CC CC CC CC CC CC CC CC CC CC 48 89 91 ? ? ? ?") + 3);
		return *reinterpret_cast<Player**>((uintptr_t)(this) + offset);
	}
	class MinecraftGame* minecraftGame() {
		static unsigned int offset = 0;
		if (offset == NULL)
			offset = *reinterpret_cast<int*>(Utils::FindSig("83 B9 ? ? ? ? ? 48 8B D9 ? ? 48 8B 01 FF 90 ? ? ? ? 48 85 C0") + 2);
		return *reinterpret_cast<MinecraftGame**>((uintptr_t)(this) + (offset + 0x8));
	}

	class GuiData* guiData() {
		static unsigned int offset = 0;
		if (offset == NULL)
			offset = *reinterpret_cast<int*>(Utils::FindSig("48 8B 81 ? ? ? ? C3 CC CC CC CC CC CC CC CC 48 8B 81 ? ? ? ? C3 CC CC CC CC CC CC CC CC 40 53 48 83 EC ? 48 8B 89 ? ? ? ? 48 8B DA 48 8D") + 3);
		return *reinterpret_cast<GuiData**>((uintptr_t)(this) + offset);
	}

	class LoopbackPacketSender* loopbackPacketSender() {
		static unsigned int offset = 0;
		if (offset == NULL)
			offset = *reinterpret_cast<int*>(Utils::FindSig("48 8B 88 ? ? ? ? 48 8B D3 48 8B 01 48 83 C4 20") + 3); //Offset in LoopbackPacketSender::flush */
		return *reinterpret_cast<LoopbackPacketSender**>((uintptr_t)(this) + offset);
	}
};