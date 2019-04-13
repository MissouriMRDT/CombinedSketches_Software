#include "ShimbleLighting.h"
//#include "LightingBoard_Software.h"
#include "LightingRestart.h"
//#include "ShimbleBoard_Software.h"
#include "RoveComm.h"

void setup()
{
	RoveComm.begin(RC_LIGHTINGSHIMBLEBOARD_FOURTHOCTET);
    delay(ROVECOMM_DELAY);

	//shimbleSetup();
	//lightingSetup();
	lightingRestartSetup();
	Serial.begin(9600);
}

void loop()
{
	rovecomm_packet packet;
	packet = RoveComm.read();

	//shimbleLoop(packet, &RoveComm);
	//lightingLoop(packet, &RoveComm);
	lightingRestartLoop(packet, &RoveComm);

}
