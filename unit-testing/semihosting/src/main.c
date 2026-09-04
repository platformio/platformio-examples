#include <stdio.h>
#include <string.h>

#include "stm32l1xx_hal.h"

extern void initialise_monitor_handles(void);

int main(int argc, char* argv[]) {
    
    initialise_monitor_handles();

    HAL_Init();

    while(1) {
        printf("Hello world!\n");
        HAL_Delay(1000);
    }
}

void SysTick_Handler(void)
{
    HAL_IncTick();
}
