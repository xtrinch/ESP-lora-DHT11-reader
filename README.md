# ESP-lora-DHT11-reader

Reads DHT11 temperature & humidity measurements and forwards them [sensor dashboard](http://iotfreezer.com/), by using the [gateway sketch](https://github.com/sensor-dashboard/ESP-lora-gateway) running on another TTGO-Lora32. Made for TTGO-Lora32, with adapting the pins for LoRa can work for any ESP32 dev board.

Built with PlatformIO.

See also [backend](https://github.com/xtrinch/sensor-dashboard-nestjs-backend) and [frontend](https://github.com/xtrinch/sensor-dashboard-react-frontend), or [see it live](http://iotfreezer.com) with some sensor data from my living room.

## Setup

0. Make sure to clone with `git clone --recursive REPO-URL` to make sure ESP-make-easy submodule is cloned along
1. Have a sensor dashboard backend running (see https://github.com/xtrinch/sensor-dashboard-nestjs-backend)
2. Copy `import_env.example.py` to `import_env.py` and define the variables.

## Components
- TTGO-Lora32
