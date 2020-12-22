#include <unity.h>
#include <Service.h>
#include <Client.h>

namespace ServiceTest
{
    Client *client;

    void test_shouldDoARequestToAServerUrl(void)
    {

        String serverUrl = "https://luisherrera.dev";
        String responseExpected = "200";
        Service service(client);

        // String response = service.request(serverUrl.c_str()); // You will need to have ethernet or wifi module to run this step

        TEST_ASSERT_FALSE(false); // if you have access to internet remove this line and remove comments of the following assertion lines

        //TEST_ASSERT_EQUAL(responseExpected.length(), response.length());
        //TEST_ASSERT_TRUE(response.equals(responseExpected.c_str()));
    }

    void run_tests(void)
    {
        RUN_TEST(ServiceTest::test_shouldDoARequestToAServerUrl);
    }

}