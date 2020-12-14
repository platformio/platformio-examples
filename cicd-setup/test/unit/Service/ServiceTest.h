#include "ArduinoFake.h"

namespace ServiceTest
{
    void test_shouldDoARequestToAServerUrl(void)
    {
        When(Method(ArduinoFake(Client), stop)).AlwaysReturn();
        When(Method(ArduinoFake(Client), available)).Return(1, 1, 1, 0);
        When(OverloadedMethod(ArduinoFake(Client), read, int())).Return(2, 0, 0);
        When(OverloadedMethod(ArduinoFake(Client), println, size_t())).AlwaysReturn();
        When(OverloadedMethod(ArduinoFake(Client), println, size_t(const char *))).AlwaysReturn();
        When(OverloadedMethod(ArduinoFake(Client), connect, int(const char *, uint16_t))).Return(1);
        String serverUrl = "myserver.com";
        String responseExpected = "200";
        String message = "status=ok";
        Client *clientMock = ArduinoFakeMock(Client);

        Service service(clientMock);
        service.setMessage(message);
        String response = service.request(serverUrl.c_str());

        TEST_ASSERT_EQUAL(responseExpected.length(), response.length());
        TEST_ASSERT_TRUE(response.equals(responseExpected.c_str()));

        Verify(Method(ArduinoFake(Client), stop)).Once();
        Verify(Method(ArduinoFake(Client), available)).Exactly(4_Times);
        Verify(OverloadedMethod(ArduinoFake(Client), read, int())).Exactly(3_Times);
        Verify(OverloadedMethod(ArduinoFake(Client), println, size_t())).Once();
        Verify(OverloadedMethod(ArduinoFake(Client), connect, int(const char *, uint16_t)).Using(serverUrl.c_str(), 80)).Once();
    }

    void run_tests(void)
    {
        RUN_TEST(ServiceTest::test_shouldDoARequestToAServerUrl);
    }

}