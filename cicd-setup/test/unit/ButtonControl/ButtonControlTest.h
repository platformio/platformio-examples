#include "ArduinoFake.h"

namespace ButtonControlTest {
    const int PIN_BUTTON_UP = 1;
    const int PIN_BUTTON_SELECT = 2;
    const int PIN_BUTTON_DOWN = 3;

    void test_shouldInitButtonsOnInputMode()
    {
        When(Method(ArduinoFake(), pinMode)).AlwaysReturn();

        ButtonControl buttonControl(PIN_BUTTON_UP, PIN_BUTTON_SELECT, PIN_BUTTON_DOWN);

        Verify(Method(ArduinoFake(), pinMode).Using(PIN_BUTTON_UP, INPUT)).Once();
        Verify(Method(ArduinoFake(), pinMode).Using(PIN_BUTTON_SELECT, INPUT)).Once();
        Verify(Method(ArduinoFake(), pinMode).Using(PIN_BUTTON_DOWN, INPUT)).Once();

    }

    void test_shouldReadButtonStatus()
    {
        When(Method(ArduinoFake(), pinMode)).AlwaysReturn();
        When(Method(ArduinoFake(), digitalRead)).AlwaysReturn();

        ButtonControl buttonControl(PIN_BUTTON_UP, PIN_BUTTON_SELECT, PIN_BUTTON_DOWN);
        buttonControl.readButtonStates();

        Verify(Method(ArduinoFake(), digitalRead).Using(PIN_BUTTON_UP)).Once();
        Verify(Method(ArduinoFake(), digitalRead).Using(PIN_BUTTON_SELECT)).Once();
        Verify(Method(ArduinoFake(), digitalRead).Using(PIN_BUTTON_DOWN)).Once();
    }

    void test_shouldReturnM_WhenButtonUpIsPressedTwoTimes()
    {
        When(Method(ArduinoFake(), pinMode)).AlwaysReturn();
                                                    //  UP  DOWN SELECT UP DOWN SELECT
        When(Method(ArduinoFake(), digitalRead)).Return(HIGH, LOW, LOW, HIGH, LOW, LOW);
        String expectedSize = "M";
        const int expectedValueSize = 38;

        ButtonControl buttonControl(PIN_BUTTON_UP, PIN_BUTTON_SELECT, PIN_BUTTON_DOWN);
        buttonControl.readButtonStates();
        buttonControl.readButtonStates();

        TEST_ASSERT_EQUAL(expectedValueSize, buttonControl.getValueSize());
        TEST_ASSERT_EQUAL_STRING(expectedSize.c_str(), buttonControl.getSize().c_str());
    }

    void test_shouldReturnS_WhenButtonUpIsPressedTwoTimesAndButtonDownIsPressedOneTime()
    {
        When(Method(ArduinoFake(), pinMode)).AlwaysReturn();
                                                    //  UP  DOWN SELECT UP DOWN SELECT  UP DOWN SELECT
        When(Method(ArduinoFake(), digitalRead)).Return(HIGH, LOW, LOW, HIGH, LOW, LOW, LOW, HIGH, LOW);
        String expectedSize = "S";
        const int expectedValueSize = 34;

        ButtonControl buttonControl(PIN_BUTTON_UP, PIN_BUTTON_SELECT, PIN_BUTTON_DOWN);
        buttonControl.readButtonStates();
        buttonControl.readButtonStates();
        buttonControl.readButtonStates();

        TEST_ASSERT_EQUAL(expectedValueSize, buttonControl.getValueSize());
        TEST_ASSERT_EQUAL_STRING(expectedSize.c_str(), buttonControl.getSize().c_str());
    }

    void test_shouldSetXSSizeAndSetTrueMenuState_WhenButtonSelectIsPressed()
    {
        When(Method(ArduinoFake(), pinMode)).AlwaysReturn();
                                                     // UP  DOWN SELECT 
        When(Method(ArduinoFake(), digitalRead)).Return(LOW, LOW, HIGH);
        String expectedSize = "XS";
        const int expectedValueSize = 30;

        ButtonControl buttonControl(PIN_BUTTON_UP, PIN_BUTTON_SELECT, PIN_BUTTON_DOWN);
        buttonControl.readButtonStates();

        TEST_ASSERT_EQUAL(true, buttonControl.getMenuState());
        TEST_ASSERT_EQUAL(expectedValueSize, buttonControl.getValueSize());
        TEST_ASSERT_EQUAL_STRING(expectedSize.c_str(), buttonControl.getSize().c_str());
    }

    void run_tests(void)
    {
        RUN_TEST(ButtonControlTest::test_shouldInitButtonsOnInputMode);
        RUN_TEST(ButtonControlTest::test_shouldReadButtonStatus);
        RUN_TEST(ButtonControlTest::test_shouldReturnM_WhenButtonUpIsPressedTwoTimes);
        RUN_TEST(ButtonControlTest::test_shouldReturnS_WhenButtonUpIsPressedTwoTimesAndButtonDownIsPressedOneTime);
        RUN_TEST(ButtonControlTest::test_shouldSetXSSizeAndSetTrueMenuState_WhenButtonSelectIsPressed);
    }
} // namespace ButtonControlTest
