#include <unity.h>
#include "Alarm/AlarmTest.h"
#include "ButtonControl/ButtonControlTest.h"
#include "Service/ServiceTest.h"

#ifdef UNIT_TEST

#define RUN_TEST_GROUP(TEST)                                                           \
        TEST::run_tests();                                                             \
    
void setUp(void){}

int main(int argc, char **argv)
{
    UNITY_BEGIN();

    RUN_TEST_GROUP(AlarmTest);
    RUN_TEST_GROUP(ButtonControlTest);
    RUN_TEST_GROUP(ServiceTest);

    UNITY_END();

    return 0;
}

#endif