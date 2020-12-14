#include "Service.h"

Service::Service(Client *client)
{
    _client = client;
    _message = "STATUS";
}

String Service::request(const char *server)
{
    String response;

    if (_client->connect(server, 80))
    {
        _client->println(_message.c_str());
        _client->println();
    }

    while (_client->available())
    {
        response.concat(_client->read());
    }

    _client->stop();

    return response;
}

String Service::getMessage(){
    return _message;
}

void Service::setMessage(String message){
    _message = message;
}