/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __BSP_USART_H
#define __BSP_USART_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f10x_gpio.h"
#include "stm32f10x_usart.h"

typedef enum 
{
    COM1 = 0,
    COM2 = 1,
    COM3 = 2
} COM_TypeDef;

#define COMn                             3

#define COM1_USART                       USART1
#define COM1_CLK                         RCC_APB2Periph_USART1
#define COM1_TX_PIN                      GPIO_Pin_9
#define COM1_TX_GPIO_PORT                GPIOA
#define COM1_TX_GPIO_CLK                 RCC_APB2Periph_GPIOA
#define COM1_RX_PIN                      GPIO_Pin_10
#define COM1_RX_GPIO_PORT                GPIOA
#define COM1_RX_GPIO_CLK                 RCC_APB2Periph_GPIOA
#define COM1_IRQn                        USART1_IRQn

#define COM2_USART                       USART2
#define COM2_CLK                         RCC_APB1Periph_USART2
#define COM2_TX_PIN                      GPIO_Pin_2
#define COM2_TX_GPIO_PORT                GPIOA
#define COM2_TX_GPIO_CLK                 RCC_APB2Periph_GPIOA
#define COM2_RX_PIN                      GPIO_Pin_3
#define COM2_RX_GPIO_PORT                GPIOA
#define COM2_RX_GPIO_CLK                 RCC_APB2Periph_GPIOA
#define COM2_IRQn                        USART2_IRQn

#define COM3_USART                       USART3
#define COM3_CLK                         RCC_APB1Periph_USART3
#define COM3_TX_PIN                      GPIO_Pin_10
#define COM3_TX_GPIO_PORT                GPIOB
#define COM3_TX_GPIO_CLK                 RCC_APB2Periph_GPIOB
#define COM3_RX_PIN                      GPIO_Pin_11
#define COM3_RX_GPIO_PORT                GPIOB
#define COM3_RX_GPIO_CLK                 RCC_APB2Periph_GPIOB
#define COM3_IRQn                        USART3_IRQn


void BSP_COMInit(COM_TypeDef COMx, USART_InitTypeDef* USART_InitStruct);
int BSP_PutChar(COM_TypeDef COMx, int ch);
int BSP_GetChar(COM_TypeDef COMx);
FlagStatus BSP_CheckChar(COM_TypeDef COMx);

#ifdef __cplusplus
}
#endif

#endif /* __BSP_USART_H */
