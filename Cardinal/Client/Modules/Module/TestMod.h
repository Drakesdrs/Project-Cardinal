#pragma once
#include "../Module.h"

class TestMod : public Module {
public:
	TestMod(Client* c, Category* o) : Module(c, o, "Test Mod") {};
	void onGmTick(GameMode*);
	void onPacket(Packet*, bool*);
};