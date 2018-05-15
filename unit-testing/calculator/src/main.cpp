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

#include <Arduino.h>
#include <calculator.h>

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
    pinMode(LED_BUILTIN, OUTPUT);
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
