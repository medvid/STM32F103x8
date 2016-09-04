#include <stdio.h>
#include "stm32f10x.h"
#include "bsp.h"
#include "config.h"

int main(void)
{
    BSP_LEDInit(LED);
  
    // Init cycle counter
    BSP_CounterInit();

    // SysTick
    SysTick_Config(SystemCoreClock / 1000);

    /* Infinite loop */
    while (1)
    {
        BSP_LEDToggle(LED);
        delay(1000);
    }
}
