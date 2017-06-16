
#include <Arduino.h>

// Identify analog pins in green at
// http://www.pighixxx.com/test/portfolio-items/esp32
#define AINPUT 34

void setup()
{
  Serial.begin(115200);

  // default for ESP32 is 12 bits, but we are Arduino classic
  analogSetWidth(10);
}

void loop()
{
  // read the value
  int v = analogRead(AINPUT);

  // send by serial port
  Serial.println(v);

  // every second
  delay(1000);
}
