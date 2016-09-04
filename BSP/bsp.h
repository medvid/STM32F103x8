#ifndef __BSP_H
#define __BSP_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "bsp_led.h"
#include "bsp_usart.h"

void BSP_CounterInit(void);

uint32_t micros(void);
uint32_t millis(void);
void delay(uint32_t ms);

#ifdef __cplusplus
}
#endif

#endif /* __BSP_H */
