#include <stdio.h>
#include "stm32f10x.h"
#include "bsp.h"
#include "config.h"

#define BUTTON_ON       0
#define BUTTON_OFF      1

int main(void)
{
    int ledState;
    uint32_t lastDebounceTime = 0;
    uint8_t buttonState;
    
    GPIO_InitTypeDef  GPIO_InitStructure;
    
    // Init LED
    BSP_LEDInit(LED);
    
    // Init cycle counter
    BSP_CounterInit();

    // SysTick
    SysTick_Config(SystemCoreClock / 1000);
    
    /* Initialize Button input PB0 */
    // Enable PORTB Clock
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    /* Configure the GPIO_BUTTON pin */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    
    // Turn off LED initially
    BSP_LEDOff(LED);
    ledState = -1;

    while (1)
    {
        // Filter out any noise by setting a time buffer
        if ((millis() - lastDebounceTime) > DEBOUNCE_DELAY)
        {
            buttonState = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0);
            if ((buttonState == BUTTON_ON) ^ (ledState < 0))
            {
                if (buttonState == BUTTON_ON)
                {
                    /* Toggle LED only during OFF->ON transition */
                    BSP_LEDToggle(LED);
                }
                ledState = -ledState;
                lastDebounceTime = millis(); //set the current time
            }
        }

        // Wait 1 ms
        delay(1);
    }
}
