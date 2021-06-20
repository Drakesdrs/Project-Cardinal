#pragma once
#include "../Module.h"

class AirJump : public Module {
public:
	AirJump(Client* c, Category* o) : Module(c, o, "AirJump") {};
	void onGmTick(GameMode*);
};