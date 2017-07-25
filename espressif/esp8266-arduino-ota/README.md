
# Arduino OTA

## About

OTA (Over the Air) update is the process of loading the firmware to ESP module using Wi-Fi connection rather that a serial port.

This example is adapted from https://arduino-esp8266.readthedocs.io/en/latest/ota_updates/readme.html

## Execute the example

Change directory to the example and edit src/main.cpp to set the SSID and password of your WiFi network.

    const char* ssid = "WIFI_SSID";
    const char* password = "WIFI_PASS";

Compile and upload to your esp8266:

    pio run -e esp8266 -t upload

## Test OTA

Use another example ([blink is good option](https://github.com/platformio/platformio-examples/tree/develop/wiring-blink)) to generate the firmware and upload:

    pio run -e nodemcu -t upload --upload-port IP_ADDRESS

IP address of board is printed on the serial interface (115200 bps):

```
$ pio device monitor -b 115200
--- Miniterm on /dev/ttyUSB0  115200,8,N,1 ---
--- Quit: Ctrl+C | Menu: Ctrl+T | Help: Ctrl+T followed by Ctrl+H ---
Ready
IP address: 192.168.10.190
```

This is a demo of OTA uploading:

```
$ pio run -e nodemcu -t upload --upload-port 192.168.10.190

[Mon Dec 19 21:35:48 2016] Processing nodemcu (platform: espressif8266, board:
nodemcu, framework: arduino)
------------------------------------------------------------------------------
Verbose mode can be enabled via `-v, --verbose` option
Collected 23 compatible libraries
Looking for dependencies...
Project does not have dependencies
Looking for upload port...
Use manually specified: 192.168.10.190
Uploading .pioenvs/nodemcu/firmware.bin
21:35:49 [DEBUG]: Options: {'esp_ip': '192.168.10.190', 'host_port': 31639,
'image': '.pioenvs/nodemcu/firmware.bin', 'host_ip': '0.0.0.0', 'auth': '',
'esp_port': 8266, 'spiffs': False, 'debug': True, 'progress': True}
21:35:49 [INFO]: Starting on 0.0.0.0:31639
21:35:49 [INFO]: Upload size: 226272
21:35:49 [INFO]: Sending invitation to: 192.168.10.190
21:35:49 [INFO]: Waiting for device...
Uploading: [============================================================] 100%
Done...

21:35:53 [INFO]: Waiting for result...
21:35:53 [INFO]: Result: OK
===================== [SUCCESS] Took 4.67 seconds ==========================

============================= [SUMMARY] ====================================
Environment uno          	[SKIP]
Environment nodemcu      	[SUCCESS]
Environment teensy31     	[SKIP]
Environment lpmsp430g2553[SKIP]
===================== [SUCCESS] Took 4.67 seconds ==========================
```



