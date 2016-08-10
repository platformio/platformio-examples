#ifndef UNIT_TEST

#include <Arduino.h>
#include "calculator.h"

Calculator calc;

void blink_once(unsigned int delay_ms)
{
    digitalWrite(LED_BUILTIN, HIGH);
    delay(delay_ms);
    digitalWrite(LED_BUILTIN, LOW);
    delay(delay_ms);
}


void setup() {
    Serial.begin(9600);
    Serial.println("Program started!");
}

void loop() {
    Serial.print("Addition: ");
    Serial.println(calc.add(25, 17));
    blink_once(200);
    Serial.print("Subtraction: ");
    Serial.println(calc.sub(10, 3));
    blink_once(200);
    Serial.print("Multiplication: ");
    Serial.println(calc.mul(3, 3));
    blink_once(200);
    Serial.print("Division: ");
    Serial.println(calc.div(100, 3));
    blink_once(200);
}

#endif
