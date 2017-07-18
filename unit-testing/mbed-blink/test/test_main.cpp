#include <mbed.h>
#include <unity.h>

#ifdef UNIT_TEST

DigitalOut myled(LED1);

// void setUp(void) {
// // set stuff up here
// }

// void tearDown(void) {
// // clean stuff up here
// }

void test_pin_is_connected(void) {
    TEST_ASSERT_EQUAL(myled.is_connected(), 1);
}

void test_led_state_high(void) {
    myled.write(1);
    TEST_ASSERT_EQUAL(myled.read(), 1);
}

void test_led_state_low(void) {
    myled.write(0);
    TEST_ASSERT_EQUAL(myled.read(), 0);
}

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_pin_is_connected);
    
    for (int i = 0; i < 5; ++i){
        RUN_TEST(test_led_state_high);
        wait_ms(500);
        RUN_TEST(test_led_state_low);
        wait_ms(500);
        i++;
    }
    
    UNITY_END(); // stop unit testing
    
    while(1){}
}

#endif
