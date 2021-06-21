#include "Scaffold.h"

bool Scaffold::tryScaffold(GameMode* GM, Vec3 blockBelow) {
	blockBelow = blockBelow.floor();

	Block* block = player->getRegionConst()->getBlock(Vec3i(blockBelow.x, blockBelow.y, blockBelow.z));
	BlockLegacy* legacy = block->BlockLegacy;

	if (legacy->Material->isReplaceable) {
		Vec3i blok = Vec3i(Vec3i(blockBelow.x, blockBelow.y, blockBelow.z));
		static std::vector<Vec3i*> checklist;
		if (checklist.empty()) {
			checklist.push_back(new Vec3i(0, -1, 0));
			checklist.push_back(new Vec3i(0, 1, 0));

			checklist.push_back(new Vec3i(0, 0, -1));
			checklist.push_back(new Vec3i(0, 0, 1));

			checklist.push_back(new Vec3i(-1, 0, 0));
			checklist.push_back(new Vec3i(1, 0, 0));
		}

		bool foundCandidate = false;
		int i = 0;
		for (auto current : checklist) {
			Vec3i calc = blok.sub(*current);
			bool Y = ((player->getRegionConst()->getBlock(calc)->BlockLegacy))->Material->isReplaceable;
			if (!((player->getRegionConst()->getBlock(calc)->BlockLegacy))->Material->isReplaceable) {
				foundCandidate = true;
				blok = calc;
				break;
			}
			i++;
		}
		if (foundCandidate) {
			GM->buildBlock(blok, i);
			GM->stopBuildBlock();
			player->swing();
			return true;
		}
	}
}

void Scaffold::onGmTick(GameMode* GM) {
	if (!everythingIsValid())
		return;

	auto heldItem = player->getSelectedItem();
	if (heldItem->getId() > 0) {
		auto item = heldItem->getItem();
		if (!item->isStackedByData() || item->isFood() || item->isCamera())
			return;
	} else return;

	auto vel = *player->velocity();
	auto speed = vel.magnitudexz();
	vel = vel.normalize();

	Vec3 blockBelow = *player->getPos();
	blockBelow.y -= player->collision()->y;
	blockBelow.y -= 0.5f;

	if (!tryScaffold(GM, blockBelow)) {
		if (speed > 0.05f) {
			blockBelow.z -= vel.z * 0.4f;
			if (!tryScaffold(GM, blockBelow)) {
				blockBelow.x -= vel.x * 0.4f;
				if (!tryScaffold(GM, blockBelow)) {
					blockBelow.z += vel.z;
					blockBelow.x += vel.x;
					tryScaffold(GM, blockBelow);
				}
			}
		}
	}
}