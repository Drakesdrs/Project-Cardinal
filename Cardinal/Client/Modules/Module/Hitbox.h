#pragma once
#include "../Module.h"

class Hitbox : public Module {
public:
	Hitbox(Client* c, Category* o) : Module(c, o, "Hitbox") {};
	void onGmTick(GameMode*);
	void onDisable();
};