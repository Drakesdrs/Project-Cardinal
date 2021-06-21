#include "BoostHit.h"

Vec2 getRotationsToEnt(Actor* p, Actor* t) {
	Vec3 currPos = *p->getPos();
	Vec3 targetPos = *t->getPos();
	float dX = currPos.x - targetPos.x;
	float dY = currPos.y - targetPos.y;
	float dZ = currPos.z - targetPos.z;
	float distance = sqrt(dX * dX + dY * dY + dZ * dZ);
	return Vec2(-(float)atan2(dY, distance) * (180.0f / PI), (float)atan2(dZ, dX) * (180.0f / PI) + 90.0f);
};

void BoostHit::onGmAttack(GameMode* GM, Actor* a) {
	if (!everythingIsValid())
		return;

	if (GM->player == player) {
		float yaw = getRotationsToEnt(player, a).y + 90.0f;
		player->velocity()->x = cos((yaw) * (PI / 180.0f)) * boost;
		player->velocity()->z = sin((yaw) * (PI / 180.0f)) * boost;
	}
}