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

TEST(DummyTest, ShouldPass)
{
    EXPECT_EQ(1, 1);
}

void Sub1(int n)
{
    EXPECT_EQ(n, 1);
}

TEST(FooTest, Bar)
{
    {
        SCOPED_TRACE("A"); // This trace point will be included in
                           // every failure in this scope.
        Sub1(1);
    }
    // Now it won't.
    Sub1(9);
}

TEST(SkipTest, DoesSkip)
{
    GTEST_SKIP() << "Skipping single test";
    EXPECT_EQ(0, 1); // Won't fail; it won't be executed
}

#if defined(ARDUINO)
#include <Arduino.h>

void setup()
{
    Serial.begin(115200);
    delay(1000);
    ::testing::InitGoogleTest();
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
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#endif