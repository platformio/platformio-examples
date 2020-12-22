#include "Alarm.h"

Alarm::Alarm(int pinLed, long int delayTime){
    pinMode(pinLed, OUTPUT);
    _pinLed = pinLed;
    _delayTime = delayTime;
}

void Alarm::activate(int times){
    int indexTimes = 0;
    while (indexTimes < times){
        turnOn();
        delay(_delayTime);
        turnOff();
        delay(_delayTime);
        indexTimes += 1;
    }
}

void Alarm::turnOn(){
    digitalWrite(_pinLed, HIGH);
}

void Alarm::turnOff(){
    digitalWrite(_pinLed, LOW);
}
