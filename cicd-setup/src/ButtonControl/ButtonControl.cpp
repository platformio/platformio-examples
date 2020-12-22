#include "ButtonControl.h"

ButtonControl::ButtonControl(const int buttonPinUp, const int buttonPinSelect, const int buttonPinDown)
{
    pinMode(buttonPinUp, INPUT);
    pinMode(buttonPinDown, INPUT);
    pinMode(buttonPinSelect, INPUT);

    _buttonPinUp = buttonPinUp;
    _buttonPinDown = buttonPinDown;
    _buttonPinSelect = buttonPinSelect;
    _sizeOptions = 5;
    _sizeSelected = 1;
    _menuState = false;

}

String ButtonControl::getSize()
{
    switch (_sizeSelected)
    {
    case 1:
        return "XS";
        break;
    case 2:
        return "S";
        break;
    case 3:
        return "M";
        break;
    case 4:
        return "L";
        break;
    case 5:
        return "XL";
        break;
    }
    return "AA";
}


int ButtonControl::getValueSize(){
    switch (_sizeSelected)
    {
    case 1:
        return 30;
        break;
    case 2:
        return 34;
        break;
    case 3:
        return 38;
        break;
    case 4:
        return 42;
        break;
    case 5:
        return 46;
        break;
    }
    return 0;
}

void ButtonControl::readButtonStates()
{

    int upState = getUpState();
    int downState = getDownState();
    int selectState = getSelectState();
    int maxOption = _sizeOptions;
 

    if (selectState == HIGH){
       _menuState = true;
    }
    else if (upState == HIGH and (_sizeSelected < maxOption)){
        _sizeSelected += 1;
    }
    else if (downState == HIGH and (_sizeSelected > 1)){
        _sizeSelected -= 1;
    }
}

int ButtonControl::getUpState(){
    return digitalRead(_buttonPinUp);
}

int ButtonControl::getDownState(){
    return digitalRead(_buttonPinDown);
}

int ButtonControl::getSelectState(){
    return digitalRead(_buttonPinSelect);
}

int ButtonControl::getMenuState(){
    return _menuState;
}

void ButtonControl::setMenuState(bool state){
    _menuState = state;
}

