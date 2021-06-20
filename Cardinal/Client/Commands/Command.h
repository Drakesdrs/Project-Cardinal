#pragma once
#include <string>
#include <vector>

#include "../../Memory/SDK/Minecraft.h"
#include "../../Utils/Utils.h"

class Cmd {
public:
	std::string input;
	std::string description;
	
	Cmd(std::string input, std::string description) {
		this->input = input;
		this->description = description;
	}

	virtual void execute(std::string, std::vector<std::string>) {};

	ClientInstance* instance;
	Player* player;
};