#pragma once
#include "../Module.h"

class ModuleList : public Module {
public:
	ModuleList(Client* c, Category* o) : Module(c, o, "ModuleList") {
		this->isEnabled = true;
	};
	void onRender(Renderer*);
	void updateAlpha();

	float alpha = 0.f;
};