#include <Arduino.h>
#include "calculator.h"
#include "unity.h"


#ifdef UNIT_TEST

Calculator calc;

// void setUp(void) {
// // set stuff up here
// }

// void tearDown(void) {
// // clean stuff up here
// }

void test_function_calculator_addition(void) {
    TEST_ASSERT_EQUAL(32, calc.add(25, 7));
}

void test_function_calculator_subtraction(void) {
    TEST_ASSERT_EQUAL(20, calc.sub(23, 3));
}

void test_function_calculator_multiplication(void) {
    TEST_ASSERT_EQUAL(50, calc.mul(25, 2));
}

void test_function_calculator_division(void) {
    TEST_ASSERT_EQUAL(32, calc.div(100, 3));
}

void setup() {
    // NOTE!!! Wait for >2 secs
    // if board doesn't support software reset via Serial.DTR/RTS
    delay(2000);

    UNITY_BEGIN();
    RUN_TEST(test_function_calculator_addition);
    RUN_TEST(test_function_calculator_subtraction);
    RUN_TEST(test_function_calculator_multiplication);
    RUN_TEST(test_function_calculator_division);
    UNITY_END();
}

void loop() {
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
    delay(500);
}

#endif