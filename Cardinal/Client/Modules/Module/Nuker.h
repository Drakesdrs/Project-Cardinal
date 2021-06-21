#pragma once
#include "../Module.h"

class Nuker : public Module {
public:
	Nuker(Client* c, Category* o) : Module(c, o, "Nuker") {};
	void onGmStartDestroy(GameMode*, Vec3i*, UCHAR);

	int range = 4;
};