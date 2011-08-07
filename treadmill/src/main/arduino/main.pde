#include <SPI.h>

#include <Client.h>
#include <Server.h>
#include <Udp.h>
#include "TcpComLink.h"

extern "C" {
  #include "Slim.h"
}

Slim * slim;

void setup()
{
  slim = Slim_Create();

  Serial.begin(9600);
}

#include "SerialComLink.h"
void loop_serial()
{
  Slim_HandleConnection(slim, (void*)0, &SerialComLink_send, &SerialComLink_recv);
}

void loop()
{
  loop_serial();
}

