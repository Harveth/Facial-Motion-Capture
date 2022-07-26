#include "packetTransfer.h"
#include "configs.h"
#include <iostream>

using namespace configs;

void packetTransfer::sendPacket(std::string header, float x, float y)
{
	const char* c = header.c_str();
	UdpTransmitSocket transmitSocket(IpEndpointName(ADDRESS, PORT));

	char buffer[OUTPUT_BUFFER_SIZE];
	osc::OutboundPacketStream p(buffer, OUTPUT_BUFFER_SIZE);

	p << osc::BeginBundleImmediate
		<< osc::BeginMessage(c)
		<< (float)x << (float)y << osc::EndMessage
		<< osc::EndBundle;

	transmitSocket.Send(p.Data(), p.Size());
	std::cout << "sent packet : " << header << "  " << x << " " << y << "\n";
}
