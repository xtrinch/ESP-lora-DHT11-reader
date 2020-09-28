#include "main.h"

void setup() { 
  Serial.begin(115200);
  while (!Serial);

  if (!setupLoRa()) {
    ardprintf("Setup LoRa failed");
    while(1);
  }
}

void loop() {
   
  Serial.print("Sending packet: ");

  //Send LoRa packet to receiver
  LoRa.beginPacket();

  float humidity = 50;
  float temperature = 25.0;

  char buffer[400];
  snprintf(buffer, 400, "{" 
    "\"url\":\"http://%s/api/measurements/multi\","
    "\"auth\":\"%s\","
    "\"data\":{"
      "\"measurements\":["
        "{"
            "\"measurement\":%.1f,"
            "\"measurementType\":\"humidity\""
        "},"
        "{"
            "\"measurement\":%.1f,"
            "\"measurementType\":\"temperature\""
        "}"
      "]"
    "}"
  "}", CFG_SENSOR_DASHBOARD_URL, CFG_ACCESS_TOKEN, humidity, temperature);
  ardprintf(buffer);
  LoRa.print(buffer);
  LoRa.endPacket();
  
  goToSleep();
}