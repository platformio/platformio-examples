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

#include <gtest/gtest.h>
#include "include/mock_turtle.h"
#include "include/painter.h"

using ::testing::AtLeast;
TEST(PainterTest, CanDrawSomething)
{
	MockTurtle turtle;
	EXPECT_CALL(turtle, PenDown())
		.Times(AtLeast(1));

	Painter painter(&turtle);

	EXPECT_TRUE(painter.DrawCircle(0, 0, 10));
}

#if defined(ARDUINO)
#include <Arduino.h>

void setup()
{
    // should be the same value as for the `test_speed` option in "platformio.ini"
    // default value is test_speed=115200
    Serial.begin(115200);

    // give the 1-2 seconds to the test runner to connect to the board
    delay(1000);

	::testing::InitGoogleMock();
	if (RUN_ALL_TESTS());
}

void loop()
{
	// nothing to be done here.
	delay(100);
}

#else

int main(int argc, char **argv)
{
	::testing::InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();
}

#endif