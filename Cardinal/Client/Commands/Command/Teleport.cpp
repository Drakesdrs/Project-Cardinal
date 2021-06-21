#include "Teleport.h"

bool stringIsFlt(const std::string& str) {
	std::istringstream iss(str);
	float f;
	iss >> std::noskipws >> f;
	return iss.eof() && !iss.fail();
};

void TeleportCmd::execute(std::string message, std::vector<std::string> args) {
	if (!(args.size() > 3))
		return player->printToChat("Invalid Arguments Length!");

	bool correctParams = true;
	for (auto I = 0; I < args.size(); I++) {
		if (I == 0) continue;
		if (!stringIsFlt(args.at(I))) correctParams = false;
	}

	if (correctParams) {
		Vec3 tpPos = Vec3(std::atoi(args.at(1).c_str()), std::atoi(args.at(2).c_str()), std::atoi(args.at(3).c_str()));
		player->_setPos(&tpPos);
		player->printToChat("Teleported to | X: " + args.at(1) + ", Y: " + args.at(2) + ". Z: " + args.at(3));
	}
	else return player->printToChat("Invalid Params!");
}