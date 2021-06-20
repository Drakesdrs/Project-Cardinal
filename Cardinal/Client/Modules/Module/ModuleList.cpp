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

void ModuleList::onRender(Renderer* r) {
	if (!everythingIsValid())
		return;
	
	updateAlpha();

	int ID = 0;
}