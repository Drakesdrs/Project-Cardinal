#pragma once
#include "../Module.h"

class Commands : public Module {
public:
	Commands(Client* c, Category* o) : Module(c, o, "Commands") {
		this->isEnabled = true;
	};
	void onPacket(Packet*, bool*);

	std::string prefix = ".";
};