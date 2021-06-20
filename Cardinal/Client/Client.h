#pragma once
#include <Windows.h>
#include <vector>
#include <string>
#include <map>

#include "Categories/Category.h"
#include "Modules/Module.h"
#include "Commands/Command.h"

class Client {
public:
	HMODULE hModule;
	bool isRunning = false;

	std::string name;

	std::vector<Category*> categories;
	std::vector<Module*> modules;
	std::vector<Cmd*> commands;

	Client(std::string name);

	std::map<uint64_t, bool> keyMap = std::map<uint64_t, bool>();

	void init();
};