#pragma once
#include "../Module.h"

class BoostHit : public Module {
public:
	BoostHit(Client* c, Category* o) : Module(c, o, "Boost Hit") {};
	void onGmAttack(GameMode*, Actor*);

	float boost = 1.0f;
};