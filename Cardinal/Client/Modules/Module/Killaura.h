#pragma once
#include "../Module.h"

class Killaura : public Module {
public:
	Killaura(Client* c, Category* o) : Module(c, o, "Killaura") {};
	void onGmTick(GameMode*);

	float range = 8.f;
	bool multi = true;
};