#pragma once
#include "../Module.h"

class Jetpack : public Module {
public:
	Jetpack(Client* c, Category* o) : Module(c, o, "Jetpack", 0x46) {};
	void onLoop();
	void onGmTick(GameMode*);

	float speed = 1.0f;
};