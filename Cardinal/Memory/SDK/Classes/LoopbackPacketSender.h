#pragma once

class LoopbackPacketSender {
private:
	virtual ~LoopbackPacketSender();
public:
	virtual void send(Packet* packet);
};