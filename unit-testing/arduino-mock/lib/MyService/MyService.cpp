#include "MyService.h"

MyService::MyService(Client* client)
{
    _client = client;
}

String MyService::request(const char *server) {
    String response;

    if (!_client->connect(server, 80)) {
        return "";
    }

    while(_client->available()) {
        response.concat(_client->read());
    }

    _client->stop();

    return response;
}
