#pragma once
#include "../Module.h"

class Velocity : public Module {
public:
	Velocity(Client* c, Category* o) : Module(c, o, "Velocity") {};
	void onLerp(Actor*, Vec3*);

	Vec3 velocity = Vec3(0, 0, 0);
};