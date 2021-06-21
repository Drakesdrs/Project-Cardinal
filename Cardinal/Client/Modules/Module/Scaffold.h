#pragma once
#include "../Module.h"

class Scaffold : public Module {
public:
	Scaffold(Client* c, Category* o) : Module(c, o, "Scaffold") {};
	void onGmTick(GameMode*);
	bool tryScaffold(GameMode*, Vec3);
};