#pragma once

#ifdef ARDUINO_TESTS
#include "ArduinoFake.h"
#else
#include "Arduino.h"
#endif

#ifndef ButtonControl_h
#define ButtonControl_h

class ButtonControl
{
public:
    ButtonControl(const int buttonPinUp, const int buttonPinSelect, const int buttonPinDown);
    String getSize();
    int getUpState();
    int getDownState();
    int getSelectState();
    int getMenuState();
    int getValueSize();
    int getVolume();
    void readButtonStates();
    void setMenuState(bool state);

private:
   int _buttonPinUp;
   int _buttonPinDown;
   int _buttonPinSelect;
   int _currentPosition;
   int _sizeSelected;
   int _sizeOptions;
   bool _menuState;
};

#endif