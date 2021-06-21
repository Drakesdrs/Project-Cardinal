#pragma once
#include "../Module.h"

class Instabreak : public Module {
public:
	Instabreak(Client* c, Category* o) : Module(c, o, "Instabreak") {};
	void onGmStartDestroy(GameMode*, Vec3i*, UCHAR);
};