/*
 Copyright (c) 2014-present PlatformIO <contact@platformio.org>

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
**/

#include <mbed.h>
#include <unity.h>

DigitalOut myled(LED1);

// void setUp(void) {
// // set stuff up here
// }

// void tearDown(void) {
// // clean stuff up here
// }

void test_pin_is_connected(void) {
    TEST_ASSERT_EQUAL(1, myled.is_connected());
}

void test_led_state_high(void) {
    myled.write(1);
    TEST_ASSERT_EQUAL(1, myled.read());
}

void test_led_state_low(void) {
    myled.write(0);
    TEST_ASSERT_EQUAL(0, myled.read());
}

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_pin_is_connected);

    for (int i = 0; i < 5; ++i){
        RUN_TEST(test_led_state_high);
        thread_sleep_for(500);
        RUN_TEST(test_led_state_low);
        thread_sleep_for(500);
        i++;
    }

    UNITY_END(); // stop unit testing

    while(1){}
}
