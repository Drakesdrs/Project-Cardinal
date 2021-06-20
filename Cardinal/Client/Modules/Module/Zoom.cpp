#include "Zoom.h"
#include "../../../Client/Client.h"

void Zoom::onLoop() {
	if (key == NULL) key = 0x43;
	this->isEnabled = client->keyMap[key];

	if (player == nullptr) this->isEnabled = false;
}

void Zoom::onGmTick(GameMode* GM) {
	player->setFieldOfView(0.3f);
}

void Zoom::onDisable() {
	if (player == nullptr)
		return;

	player->setFieldOfView(1);
}