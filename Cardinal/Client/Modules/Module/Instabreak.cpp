#include "Instabreak.h"

void Instabreak::onGmStartDestroy(GameMode* _this, Vec3i* blockPos, UCHAR blockFace) {
	_this->destroyBlock(*blockPos, blockFace);
}