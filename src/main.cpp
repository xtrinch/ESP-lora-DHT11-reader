#include "main.h"

DHT_Unified dht(DHT11_PIN, DHT11);

void setup() { 
  Serial.begin(115200);
  while (!Serial);

  if (!setupLoRa()) {
    ardprintf("Setup LoRa failed");
    goToSleep();
  }

  dht.begin();
  // sensor_t sensor;
  // dht.temperature().getSensor(&sensor);
  // Serial.println(F("------------------------------------"));
  // Serial.println(F("Temperature Sensor"));
  // Serial.print  (F("Sensor Type: ")); Serial.println(sensor.name);
  // Serial.print  (F("Driver Ver:  ")); Serial.println(sensor.version);
  // Serial.print  (F("Unique ID:   ")); Serial.println(sensor.sensor_id);
  // Serial.print  (F("Max Value:   ")); Serial.print(sensor.max_value); Serial.println(F("°C"));
  // Serial.print  (F("Min Value:   ")); Serial.print(sensor.min_value); Serial.println(F("°C"));
  // Serial.print  (F("Resolution:  ")); Serial.print(sensor.resolution); Serial.println(F("°C"));
  // Serial.println(F("------------------------------------"));
  // // Print humidity sensor details.
  // dht.humidity().getSensor(&sensor);
  // Serial.println(F("Humidity Sensor"));
  // Serial.print  (F("Sensor Type: ")); Serial.println(sensor.name);
  // Serial.print  (F("Driver Ver:  ")); Serial.println(sensor.version);
  // Serial.print  (F("Unique ID:   ")); Serial.println(sensor.sensor_id);
  // Serial.print  (F("Max Value:   ")); Serial.print(sensor.max_value); Serial.println(F("%"));
  // Serial.print  (F("Min Value:   ")); Serial.print(sensor.min_value); Serial.println(F("%"));
  // Serial.print  (F("Resolution:  ")); Serial.print(sensor.resolution); Serial.println(F("%"));
  // Serial.println(F("------------------------------------"));
}

void loop() {
  float temperature, humidity;

  // read sensor data
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    Serial.println(F("Error reading temperature!"));
    goToSleep();
  }
  else {
    Serial.print(F("Temperature: "));
    Serial.print(event.temperature);
    Serial.println(F("°C"));
    temperature = event.temperature;
  }
  // Get humidity event and print its value.
  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    Serial.println(F("Error reading humidity!"));
    goToSleep();
  }
  else {
    Serial.print(F("Humidity: "));
    Serial.print(event.relative_humidity);
    Serial.println(F("%"));
    humidity = event.relative_humidity;
  }

  // send sensor data

  //Send LoRa packet to receiver
  LoRa.beginPacket();

  char buffer[400];
  snprintf(buffer, 400, "{" 
    "\"url\":\"https://%s/api/measurements/multi\","
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