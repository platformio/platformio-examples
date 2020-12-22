#pragma once

#ifdef ARDUINO_TESTS
#include "ArduinoFake.h"
#else
#include "Arduino.h"
#endif

#include <Client.h>

#ifndef Service_h
#define Service_h

class Service
{
public:
    Service(Client *client);
    String request(const char *url);
    String getMessage();
    void setMessage(String message);

private:
    Client *_client;
    String _message;
};

#endif