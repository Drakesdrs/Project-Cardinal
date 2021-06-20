#pragma once
#include "../Module.h"

class PacketLogger : public Module {
public:
	PacketLogger(Client* c, Category* o) : Module(c, o, "PacketLogger") {};
	void onPacket(Packet*, bool*);
};