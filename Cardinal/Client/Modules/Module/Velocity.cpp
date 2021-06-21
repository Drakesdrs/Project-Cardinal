#include "Velocity.h"

void Velocity::onLerp(Actor* a, Vec3* v) {
	if (a == player) *v = this->velocity;
}