#pragma once

#ifdef ARDUINO_TESTS
#include "ArduinoFake.h"
#else
#include "Arduino.h"
#endif

#ifndef Alarm_h
#define Alarm_h

class Alarm
{
public:
    Alarm(int pinLed, long int delayTime);
    void turnOn();
    void turnOff();
    void activate(int times);
private:
    int _pinLed;
    long int _delayTime;
};

#endif