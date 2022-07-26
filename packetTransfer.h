#pragma once
#include <string>
#include "osc/OscOutboundPacketStream.h"
#include "ip/UdpSocket.h"

namespace packetTransfer {

	void sendPacket(std::string header, float x, float y);
}