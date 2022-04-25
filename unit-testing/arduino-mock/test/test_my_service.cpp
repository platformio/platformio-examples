#include <Arduino.h>
#include <unity.h>

using namespace fakeit;

#include "MyService.h"

void setUp(void)
{
    ArduinoFakeReset();
}

void tearDown(void) {
    // clean stuff up here
}

void test_request(void)
{
    When(Method(ArduinoFake(Client), stop)).AlwaysReturn();
    When(Method(ArduinoFake(Client), available)).Return(1, 1, 1, 0);
    When(OverloadedMethod(ArduinoFake(Client), read, int())).Return(2, 0, 0);
    When(OverloadedMethod(ArduinoFake(Client), connect, int(const char*, uint16_t))).Return(1);

    Client* clientMock = ArduinoFakeMock(Client);

    MyService service(clientMock);

    String response = service.request("myserver.com");

    TEST_ASSERT_EQUAL(3, response.length());
    TEST_ASSERT_TRUE(response.equals("200"));

    Verify(Method(ArduinoFake(Client), stop)).Once();
    Verify(Method(ArduinoFake(Client), available)).Exactly(4_Times);
    Verify(OverloadedMethod(ArduinoFake(Client), read, int())).Exactly(3_Times);
    Verify(OverloadedMethod(ArduinoFake(Client), connect, int(const char*, uint16_t)).Using("myserver.com", 80)).Once();
}

int main(int argc, char **argv)
{
    UNITY_BEGIN();

    RUN_TEST(test_request);

    return UNITY_END();
}
