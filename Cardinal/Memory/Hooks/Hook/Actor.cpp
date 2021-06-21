#include "Actor.h"
#include "../../../Client/Client.h"

Client* aClient = nullptr;

typedef void(__thiscall* lerpMotion)(Actor*, Vec3*);
lerpMotion _lerpMotion;

void lerpCallback(Actor* a, Vec3* v) {
	if (aClient != nullptr) {
		for (auto c : aClient->categories) {
			for (auto m : c->modules) {
				if(m->isEnabled) m->onLerp(a, v);
			}
		}
	}
	_lerpMotion(a, v);
}

void Actor_Hook::init() {
	aClient = client;
	{
		Utils::DebugLogF("Finding address for lerpMotion Hook!");
		uintptr_t sig = Utils::FindSig("8B 02 89 81 ? ? ? ? 8B 42 ? 89 81 ? ? ? ? 8B 42 ? 89 81 ? ? ? ? C3 CC CC CC CC CC 48");
		if (!sig) {
			Utils::DebugLogF("Unable to find address needed for lerpMotion Hook!");
		}
		else {
			if (MH_CreateHook((void*)sig, &lerpCallback, reinterpret_cast<LPVOID*>(&_lerpMotion)) == MH_OK) {
				Utils::DebugLogF("Successfully made hook for lerpMotion, enabling hook now...");
				MH_EnableHook((void*)sig);
			}
			else Utils::DebugLogF("Failed to create hook for lerpMotion Hook!");
		}
	}
}