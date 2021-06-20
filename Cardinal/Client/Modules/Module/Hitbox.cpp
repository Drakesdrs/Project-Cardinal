#include "Hitbox.h"

void Hitbox::onGmTick(GameMode* GM) {
	auto level = player->getLevel();
	if (level == nullptr)
		return;

	auto ents = level->getEntities();

	for (auto e : ents) {
		if (e == player)
			continue;

		e->setSize(4, 4);
	}
}

void Hitbox::onDisable() {
	auto level = player->getLevel();
	if (level == nullptr)
		return;

	auto ents = level->getEntities();

	for (auto e : ents) {
		if (e == player)
			continue;

		e->setSize(0.6, 1.8);
	}
}