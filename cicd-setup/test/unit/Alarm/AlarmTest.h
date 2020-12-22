#include "ArduinoFake.h"

namespace AlarmTest {
    const int PIN_LED = 13;
    long int delayTime = 1000;

    // You could refactor these tests and extract the 2 first line in another method like an init mocks method
    
    void test_shouldTurnOnAlarmLed()
    {
        When(Method(ArduinoFake(), pinMode)).AlwaysReturn();
        When(Method(ArduinoFake(), digitalWrite)).AlwaysReturn();

        Alarm alarm(PIN_LED, delayTime);
        alarm.turnOn();

        Verify(Method(ArduinoFake(), pinMode).Using(PIN_LED, OUTPUT)).Once();
        Verify(Method(ArduinoFake(), digitalWrite).Using(PIN_LED, HIGH)).Once();
    }

    void test_shouldTurnOffAlarmLed()
    {
        When(Method(ArduinoFake(), pinMode)).AlwaysReturn();
        When(Method(ArduinoFake(), digitalWrite)).AlwaysReturn();

        Alarm alarm(PIN_LED, delayTime);
        alarm.turnOff();

        Verify(Method(ArduinoFake(), pinMode).Using(PIN_LED, OUTPUT)).Once();
        Verify(Method(ArduinoFake(), digitalWrite).Using(PIN_LED, LOW)).Once();
    }

    void test_shouldTurnOnandTurnOffAlarm_WhenAlarmIsActivate()
    {
        When(Method(ArduinoFake(), pinMode)).AlwaysReturn();
        When(Method(ArduinoFake(), digitalWrite)).AlwaysReturn();
        When(Method(ArduinoFake(), delay)).AlwaysReturn();
        const int times = 4;

        Alarm alarm(PIN_LED, delayTime);
        alarm.activate(times);

        Verify(Method(ArduinoFake(), pinMode).Using(PIN_LED, OUTPUT)).Once();
        Verify(Method(ArduinoFake(), digitalWrite).Using(PIN_LED, HIGH)).Exactly(times);
        Verify(Method(ArduinoFake(), delay).Using(delayTime)).Exactly(times * 2);
        Verify(Method(ArduinoFake(), digitalWrite).Using(PIN_LED, LOW)).Exactly(times);
    }

    void run_tests(void)
    {
        RUN_TEST(AlarmTest::test_shouldTurnOnAlarmLed);
        RUN_TEST(AlarmTest::test_shouldTurnOffAlarmLed);
        RUN_TEST(AlarmTest::test_shouldTurnOnandTurnOffAlarm_WhenAlarmIsActivate);
    }
} 
