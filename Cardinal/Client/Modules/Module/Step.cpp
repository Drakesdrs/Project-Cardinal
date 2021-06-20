#include "Step.h"

void Step::onGmTick(GameMode* GM) {
	*player->stepHeight() = 2.0f;
}

void Step::onDisable() {
	if (player == nullptr)
		return;
	*player->stepHeight() = 0.5625;
}