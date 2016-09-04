#include <stdio.h>
#include "stm32f10x.h"
#include "bsp.h"
#include "config.h"

#define MESSAGE1   "STM32 Medium Density" 
#define MESSAGE2   " Device running on  " 
#define MESSAGE3   " STM3F103C8T6       "

USART_InitTypeDef USART_InitStructure;

void USART_Configuration()
{
    /* USARTx configured as follow:
        - BaudRate = 115200 baud  
        - Word Length = 8 Bits
        - One Stop Bit
        - No parity
        - Hardware flow control disabled (RTS and CTS signals)
        - Receive and transmit enabled
    */
    USART_InitStructure.USART_BaudRate = 115200;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
}

int main(void)
{
    BSP_LEDInit(LED);
  
    // Init cycle counter
    BSP_CounterInit();

    // SysTick
    SysTick_Config(SystemCoreClock / 1000);

    USART_Configuration();

    BSP_COMInit(COM, &USART_InitStructure);

    /* Turn on LED */
    BSP_LEDOn(LED);

    printf("\n\r %s", MESSAGE1);
    printf(" %s", MESSAGE2);
    printf(" %s\n\r", MESSAGE3);

    /* Infinite loop */
    while (1)
    {
        BSP_LEDOn(LED);
        delay(1000);
        BSP_LEDOff(LED);
        delay(1000);
    }
}
