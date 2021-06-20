#pragma once
#include "../Command.h"

class TeleportCmd : public Cmd {
public:
	TeleportCmd() : Cmd("tp", "Teleport to the given coordinates!") {};
	void execute(std::string, std::vector<std::string>);
};