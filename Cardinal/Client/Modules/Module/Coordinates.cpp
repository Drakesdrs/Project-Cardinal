#include "Coordinates.h"

void Coords::updateAlpha() {
	float modifier = 0.03f;

	if (instance->minecraftGame()->canUseKeys) {
		if (textColor.a < 1) textColor.a += modifier;
	}
	else {
		if (textColor.a >= 0) textColor.a -= modifier;
	}
}

void Coords::onGmTick(GameMode* GM) {
	cPos = *player->getPos();
}

void Coords::onRender(Renderer* r) {
	if (!everythingIsValid())
		return;

	updateAlpha();

	if (textColor.a <= 0)
		return;

	std::string cText = std::string("X: " + std::to_string((int)cPos.x) + ", Y: " + std::to_string((int)cPos.y) + ", Z: " + std::to_string((int)cPos.z));

	auto data = instance->guiData();
	auto scale = data->GuiScale();
	auto res = data->res;

	float yPos = (res.y - (scale * 10) - 10);
	r->drawString(std::wstring(cText.begin(), cText.end()), scale * 10, Vec2(0, yPos), textColor);
}