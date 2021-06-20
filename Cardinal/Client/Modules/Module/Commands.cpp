#include "Commands.h"
#include "../../Client.h"

void tokenize(std::string const& str, const char delim,
	std::vector<std::string>& out)
{
	std::stringstream ss(str);

	std::string s;
	while (std::getline(ss, s, delim)) {
		out.push_back(s);
	}
}

void Commands::onPacket(Packet* packet, bool* cancel) {
	if (packet->instanceOf<TextPacket>()) {
		auto currPacket = (TextPacket*)packet;
		auto text = currPacket->message;

		if (!(text.rfind(prefix, 0) == 0))
			return;

		*cancel = true; /* Input begins with prefix, command it seems so cancel it from reaching the chat */
		auto message = text; /* Clone */
		
		message.erase(0, prefix.length()); /* Remove Prefix */
		if (message.empty()) return; /* Message is now empty */

		const char delim = ' '; /* Space Delimiter */

		std::vector<std::string> words; /* Store our words */

		tokenize(message, delim, words);

		for (auto c : client->commands) {
			c->instance = instance;
			c->player = player;

			if(c->input == words.at(0)) return c->execute(message, words);
		}

		player->printToChat("Unknown Command!");
	}
}