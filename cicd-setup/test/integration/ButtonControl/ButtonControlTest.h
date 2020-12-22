#include <unity.h>
#include <ButtonControl.h>

namespace ButtonControlTest
{

    const int PIN_BUTTON_UP = 8;
    const int PIN_BUTTON_SELECT = 9;
    const int PIN_BUTTON_DOWN = 10;


    void test_shouldReturnM_WhenButtonUpIsPressedTwoTimes()
    {
        String expectedSize = "M";
        const int expectedValueSize = 38;
        ButtonControl buttonControl(PIN_BUTTON_UP, PIN_BUTTON_SELECT, PIN_BUTTON_DOWN);
        digitalWrite(PIN_BUTTON_UP, HIGH);

        buttonControl.readButtonStates();
        buttonControl.readButtonStates();

        TEST_ASSERT_EQUAL(expectedValueSize, buttonControl.getValueSize());
        TEST_ASSERT_EQUAL_STRING(expectedSize.c_str(), buttonControl.getSize().c_str());
    }

    void test_shouldSetXSSizeAndSetTrueMenuState_WhenButtonSelectIsPressed()
    {
        String expectedSize = "XS";
        const int expectedValueSize = 30;
        ButtonControl buttonControl(PIN_BUTTON_UP, PIN_BUTTON_SELECT, PIN_BUTTON_DOWN);
        digitalWrite(PIN_BUTTON_SELECT, HIGH);

        buttonControl.readButtonStates();

        TEST_ASSERT_EQUAL(true, buttonControl.getMenuState());
        TEST_ASSERT_EQUAL(expectedValueSize, buttonControl.getValueSize());
        TEST_ASSERT_EQUAL_STRING(expectedSize.c_str(), buttonControl.getSize().c_str());
    }

    void run_tests(void)
    {
        RUN_TEST(ButtonControlTest::test_shouldReturnM_WhenButtonUpIsPressedTwoTimes);
        RUN_TEST(ButtonControlTest::test_shouldSetXSSizeAndSetTrueMenuState_WhenButtonSelectIsPressed);
    }
}