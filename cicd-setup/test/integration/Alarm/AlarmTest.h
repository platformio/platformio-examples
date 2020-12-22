#include <unity.h>
#include <Alarm.h>

namespace AlarmTest
{
    const int PIN_LED = 13;
    long int delayTime = 0;
    Alarm alarm(PIN_LED, delayTime);

    void test_shouldTurnOnAlarmLed(void)
    {
        bool expectedLedStatus = HIGH;
        
        alarm.turnOn();

        TEST_ASSERT_EQUAL(expectedLedStatus, digitalRead(PIN_LED));
    }

    void test_shouldTurnOffAlarmLed(void)
    {
        bool expectedLedStatus = LOW;

        alarm.turnOff();

        TEST_ASSERT_EQUAL(expectedLedStatus, digitalRead(PIN_LED));
    }

    void test_shouldTurnOnandTurnOffAlarm_WhenAlarmIsActivate()
    {

        bool expectedLedStatus = LOW;
        const int times = 1;

        alarm.activate(times);

        TEST_ASSERT_EQUAL(expectedLedStatus, digitalRead(PIN_LED));
    }

    void run_tests(void)
    {
        RUN_TEST(AlarmTest::test_shouldTurnOnAlarmLed);
        RUN_TEST(AlarmTest::test_shouldTurnOffAlarmLed);
        RUN_TEST(AlarmTest::test_shouldTurnOnandTurnOffAlarm_WhenAlarmIsActivate);
    }
}