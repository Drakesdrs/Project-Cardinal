#include "ModuleList.h"
#include "../../Client.h"

class _OffXC {
public:
	int ID = 0;
	float offX;

	_OffXC(int ID, float offX) {
		this->ID = ID;
		this->offX = offX;
	}

	void shiftX(float newX, float mplyr = 0.5f) {
		if (offX < newX) {
			offX += mplyr;
		}
		else if (offX > newX) {
			offX -= mplyr;
		}
	}
};

std::vector<class _OffXC*> comps;

void ModuleList::updateAlpha() {
	float modifier = 0.03f;
	MinecraftGame* game = instance->minecraftGame();
	if (game->canUseKeys) {
		if (alpha < 1.0f) alpha += modifier;
	}
	else {
		if (alpha > 0) alpha -= modifier;
	}
}

bool o = false;

void ModuleList::onRender(Renderer* r) {
	if (!everythingIsValid())
		return;
	
	updateAlpha();

	alpha = 1; /* Temp */

	int ID = 0;
	auto data = instance->guiData();
	auto size = data->GuiScale() * 10;
	auto res = data->res;

	for (auto c : client->categories) {
		for (auto m : c->modules) {
			if (m->isEnabled) {
				std::wstring text = std::wstring(m->name.begin(), m->name.end());

				auto metrics = r->getTextMetrics(text, size);
				auto oMetrics = r->getOverhangMetrics(text, size);

				float len = 70;
				Vec2 tPos = Vec2(res.x - len, (ID * (size + 5)));
				//r->drawString(text, size, tPos, _RGBA(255, 255, 255, alpha));
				ID++;
			}
		}
	}
	
	std::wstring text = std::wstring(L"Modules"); //TestTestTestTestTestTestTestTest
	float s = 20.f;

	auto textMetrics = r->getTextMetrics(text, s);
	auto oMetrics = r->getOverhangMetrics(text, s);

	//float len = (textMetrics.height / 2) - (91.9921875 - (11.816406 * 2)); /* TestTestTestTestTestTestTestTest */
	
	/* Test */
	float len = (textMetrics.height / 2) - (22.998047 - (11.123047 * 2)); /* Test */
	len -= ((oMetrics.bottom / 8) / 2); /* Test */

	/* Modules */
	//float len = (textMetrics.height / 2) - (40.246582 - (16.660156 * 2)); /* Modules */
	//len -= ((oMetrics.bottom / 8) / 2);

	Vec2 pos = Vec2(res.x - len, res.y - 50);

	r->fillRectangle(pos, Vec2(res.x, res.y - 60), _RGBA(30, 70, 115, alpha));
	r->drawString(text, s, pos, _RGBA(255, 255, 255, alpha));

	if (!o) {
		Utils::DebugLogF(std::string("Text: " + std::string(text.begin(), text.end())).c_str());

		Utils::DebugLogF(std::string("Height: " + std::to_string(textMetrics.height)).c_str());
		Utils::DebugLogF(std::string("Width: " + std::to_string(textMetrics.width)).c_str());
		Utils::DebugLogF(std::string("Width with whitespace: " + std::to_string(textMetrics.widthIncludingTrailingWhitespace)).c_str());

		Utils::DebugLogF(std::string("Layout Width: " + std::to_string(textMetrics.layoutWidth)).c_str());
		Utils::DebugLogF(std::string("Layout Height: " + std::to_string(textMetrics.layoutHeight)).c_str());

		Utils::DebugLogF(std::string("Top: " + std::to_string(textMetrics.top)).c_str());
		Utils::DebugLogF(std::string("Left: " + std::to_string(textMetrics.left)).c_str());

		Utils::DebugLogF("Overhang Metrics:");

		Utils::DebugLogF(std::string("Left: " + std::to_string(oMetrics.left)).c_str());
		Utils::DebugLogF(std::string("Right: " + std::to_string(oMetrics.right)).c_str());

		Utils::DebugLogF(std::string("Top: " + std::to_string(oMetrics.top)).c_str());
		Utils::DebugLogF(std::string("Bottom: " + std::to_string(oMetrics.bottom)).c_str());

		Utils::DebugLogF("\n");

		Utils::DebugLogF(std::string("Res X: " + std::to_string(res.x)).c_str());
		Utils::DebugLogF(std::string("Res Y: " + std::to_string(res.y)).c_str());

		o = true;
	}

	//Utils::DebugLogF(std::to_string(data->GuiScale()).c_str());
}