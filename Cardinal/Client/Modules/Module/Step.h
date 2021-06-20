#pragma once
#include "../Module.h"

class Step : public Module {
public:
	Step(Client* c, Category* o) : Module(c, o, "Step") {};
	void onGmTick(GameMode*);
	void onDisable();
};