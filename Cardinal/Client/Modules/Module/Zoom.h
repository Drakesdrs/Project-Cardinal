#pragma once
#include "../Module.h"

class Zoom : public Module {
public:
	Zoom(Client* c, Category* o) : Module(c, o, "Zoom", 0x43) {
		this->isEnabled = true;
	};
	
	void onLoop();
	void onGmTick(GameMode*);
	void onDisable();
};