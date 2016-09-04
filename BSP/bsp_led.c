#include "bsp_led.h"

GPIO_TypeDef* LED_PORT[LEDn] = {LED1_GPIO_PORT};
const uint16_t LED_PIN[LEDn] = {LED1_PIN};
const uint32_t LED_CLK[LEDn] = {LED1_GPIO_CLK};

/**
  * @brief  Configures LED GPIO.
  * @retval None
  */
void BSP_LEDInit(Led_TypeDef Led)
{
    GPIO_InitTypeDef  GPIO_InitStructure;

    /* Enable the GPIO_LED Clock */
    RCC_APB2PeriphClockCmd(LED_CLK[Led], ENABLE);

    /* Configure the GPIO_LED pin */
    GPIO_InitStructure.GPIO_Pin = LED_PIN[Led];
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

    GPIO_Init(LED_PORT[Led], &GPIO_InitStructure);
}

/**
  * @brief  Turns selected LED On.
  * @retval None
  */
void BSP_LEDOn(Led_TypeDef Led)
{
    LED_PORT[Led]->BRR = LED_PIN[Led];
}

/**
  * @brief  Turns selected LED Off.
  * @retval None
  */
void BSP_LEDOff(Led_TypeDef Led)
{
    LED_PORT[Led]->BSRR = LED_PIN[Led];
}

/**
  * @brief  Toggles the selected LED.
  * @retval None
  */
void BSP_LEDToggle(Led_TypeDef Led)
{
    LED_PORT[Led]->ODR ^= LED_PIN[Led];
}
