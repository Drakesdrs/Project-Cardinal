#include "TestMod.h"
#include "../../../Client/Client.h"

bool _once = false;

void TestMod::onGmTick(GameMode* GM) {
	if (!everythingIsValid()) {
		_once = false;
		return;
	}

	if (!_once) {
		_once = true;

		MovePlayerPacket* packet = new MovePlayerPacket(player->getRuntimeId(), *player->getPos(), *player->bodyRot(), player->bodyRot()->y);
		instance->loopbackPacketSender()->send(packet);
	}
}

void TestMod::onPacket(Packet* packet, bool* cancel) {
	if (packet->instanceOf<MovePlayerPacket>()) {
		Utils::DebugLogF("Move Player Packet!");
	}
}