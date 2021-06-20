#include "Killaura.h"

void Killaura::onGmTick(GameMode* GM) {
	auto level = player->getLevel();
	if (level == nullptr)
		return;
	
	auto ents = level->getEntities();
	auto pos = *player->getPos();

	if (multi) {
		for (auto e : ents) {
			if (e == player)
				continue;

			auto dis = e->getPos()->distance(pos);

			if (dis <= range) {
				GM->attack(e);
				player->swing();
			}
		}
	}
	else {
		std::vector<float> distances = std::vector<float>();
		for (auto e : ents) {
			if (e == player)
				continue;

			auto dis = e->getPos()->distance(pos);

			if (dis <= range) distances.push_back(dis);
		}

		std::sort(distances.begin(), distances.end());

		if (distances.empty())
			return;

		for (auto e : ents) {
			auto dis = e->getPos()->distance(pos);

			if (dis == distances[0]) {
				GM->attack(e);
				player->swing();
			}
		}
	}
}