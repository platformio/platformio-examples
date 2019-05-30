#pragma once

#include <Arduino.h>
#include <Client.h>

class MyService
{
    public:
        MyService (Client* client);
        String request(const char*  url);

    private:
        Client* _client;
};
