/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __BSP_LED_H
#define __BSP_LED_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f10x_gpio.h"

typedef enum 
{
    LED1 = 0,
} Led_TypeDef;

#define LEDn                             1

#define LED1_PIN                         GPIO_Pin_13
#define LED1_GPIO_PORT                   GPIOC
#define LED1_GPIO_CLK                    RCC_APB2Periph_GPIOC


void BSP_LEDInit(Led_TypeDef LEDx);
void BSP_LEDOn(Led_TypeDef LEDx);
void BSP_LEDOff(Led_TypeDef LEDx);
void BSP_LEDToggle(Led_TypeDef LEDx);

#ifdef __cplusplus
}
#endif

#endif /* __BSP_LED_H */
