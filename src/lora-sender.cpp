#include "lora-sender.h"

bool setupLoRa() {
  // SPI LoRa pins
  SPI.begin(SCK, MISO, MOSI, SS);

  // setup LoRa transceiver module
  LoRa.setPins(SS, RST, DIO0);

  if (!LoRa.begin(BAND)) {
    return false;
  }

  ardprintf("LoRa initialized");

  return true;
}
