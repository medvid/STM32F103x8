#include <stdio.h>
#include "stm32f10x.h"
#include "bsp.h"
#include "config.h"

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
    USART_Configuration();

    BSP_COMInit(COM, &USART_InitStructure);

    printf("Hello world!\r\n");

    while (1)
    {
        ;
    }
}
