#include "ArduinoFake.h"
#include <unity.h>
#include <Alarm.h>
#include <ButtonControl.h>
#include <Service.h>

using namespace fakeit;

#ifdef UNIT_TEST

#include "Alarm/AlarmTest.h"
#include "ButtonControl/ButtonControlTest.h"
#include "Service/ServiceTest.h"

#define RUN_TEST_GROUP(TEST)                                                           \
    if (!std::getenv("TEST_GROUP") || (strcmp(#TEST, std::getenv("TEST_GROUP")) == 0)) \
    {                                                                                  \
        TEST::run_tests();                                                             \
    }

void setUp(void)
{
    ArduinoFakeReset();
}

int main(int argc, char **argv)
{
    UNITY_BEGIN();

    RUN_TEST_GROUP(AlarmTest);
    RUN_TEST_GROUP(ButtonControlTest);
    RUN_TEST_GROUP(ServiceTest);

    UNITY_END();

    return 0;
}

#endif