#include "Nuker.h"

void Nuker::onGmStartDestroy(GameMode* _this, Vec3i* blockPos, UCHAR blockFace) {
	_this->destroyBlock(*blockPos, blockFace);

	auto playerPos = *_this->player->getPos();

	for (int x = -range; x < range; x++) {
		for (int y = -range; y < range; y++) {
			for (int z = -range; z < range; z++) {
				Vec3i currPos = Vec3i(blockPos->x + x, blockPos->y + y, blockPos->z + z);
				_this->destroyBlock(currPos, blockFace);
				_this->stopDestroyBlock(currPos);
			}
		}
	}
}