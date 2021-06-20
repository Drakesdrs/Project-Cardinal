#include "PacketLogger.h"

int movePacketID = 0;
int authPacketID = 0;
int textPacketID = 0;

int unknownPacketID = 0;

void PacketLogger::onPacket(Packet* packet, bool* cancel) {
	std::string fPath;

	if (packet->instanceOf<MovePlayerPacket>()) {
		movePacketID++;
		fPath = std::string("Move-" + std::to_string(movePacketID));
	}
	else if (packet->instanceOf<PlayerAuthInputPacket>()) {
		fPath = std::string("Auth-" + std::to_string(authPacketID));
		authPacketID++;
	}

	else if (packet->instanceOf<TextPacket>()) {
		fPath = std::string("Text-" + std::to_string(textPacketID));
		textPacketID++;
	}
	else {
		fPath += std::string("Unknown-" + std::to_string(unknownPacketID));
		unknownPacketID++;

		auto vtable = *(uint64_t**)packet;
		std::ostringstream o;
		o << std::hex << vtable << std::endl;
		Utils::DebugLogF(o.str().c_str());

	}

	std::string dirP = getenv("APPDATA") + std::string("\\..\\Local\\Packages\\Microsoft.MinecraftUWP_8wekyb3d8bbwe\\RoamingState\\Packets\\" + std::string(fPath));

	/* Path Check */

	struct stat buffer;

	if (!(stat(dirP.c_str(), &buffer) == 0)) {
		std::filesystem::create_directories(std::filesystem::path(dirP).parent_path());
	}

	char logged[0x200];
	memcpy(logged, packet, 0x0200);

	CloseHandle(CreateFileA(dirP.c_str(), GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL));

	std::ofstream fout;
	fout.open(dirP, std::ios::binary | std::ios::out);
	fout.write(logged, 0x0110);
	fout.close();
}