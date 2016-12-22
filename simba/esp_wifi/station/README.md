
# WiFi station

## About

This application connects to a WiFi network and displays the configuration
with every change of the connection status:

```
----------------------------------------
General information:
  Operating mode: STA
  Physical mode: 11n

SoftAP:
  DHCP server status: running
  Address: 0.0.0.0
  Netmask: 0.0.0.0
  Gateway: 0.0.0.0
  Number of connections: 0

Station:
  DHCP client status: running
  Conenction status: connecting
  Address: 0.0.0.0
  Netmask: 0.0.0.0
  Gateway: 0.0.0.0

----------------------------------------
General information:
  Operating mode: STA
  Physical mode: 11n

SoftAP:
  DHCP server status: running
  Address: 0.0.0.0
  Netmask: 0.0.0.0
  Gateway: 0.0.0.0
  Number of connections: 0

Station:
  DHCP client status: running
  Conenction status: got-ip
  Address: 192.168.10.190
  Netmask: 255.255.255.0
  Gateway: 192.168.10.1
```

## Execute the example

Change directory to the example and execute this command to compile and upload
to your esp8266:

    pio run -e espressif_esp12e -t upload

You can monitor the serial output with:

    pio device monitor -b 76800

Note the BPS are 76800 because is the default speed configured by expressif
SDK. In next releases it could change (I hope!) to another value...


## Tested

This example was tested OK in 

- [X] NodeMCU 0.9


