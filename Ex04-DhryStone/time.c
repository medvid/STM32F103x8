#include "stm32f10x.h"

long timeval = 0;


/*----------------------------------------------------------------------------
  TIM1 Update Interrupt executes each 10ms @ 72 MHz CPU Clock
 *----------------------------------------------------------------------------*/
void TIM1_UP_IRQHandler(void)
{
    /* UIF set? */
    if (TIM_GetFlagStatus(TIM1, TIM_SR_UIF) == SET)
    {
        timeval++;

        /* clear UIF flag */
        TIM_ClearFlag(TIM1, TIM_SR_UIF);
    }
}


/*----------------------------------------------------------------------------
  Setup the TIM1 Interrupt
 *----------------------------------------------------------------------------*/
void TIM_Init(void)
{
    TIM_TimeBaseInitTypeDef TIM_InitStructure;
    
    /* enable clock for TIM1    */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
    
    /* set prescaler = 10KHz, auto-reload = 10 ms  */
    TIM_InitStructure.TIM_Prescaler = SystemCoreClock / 10000 - 1;
    TIM_InitStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_InitStructure.TIM_Period = 100 - 1;
    TIM_InitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_InitStructure.TIM_RepetitionCounter = 0;

    TIM_TimeBaseInit(TIM1, &TIM_InitStructure);
    
    TIM_ITConfig(TIM1, TIM_DIER_UIE, ENABLE);

    /* TIM1 Interrupt enable  */
    NVIC_EnableIRQ(TIM1_UP_IRQn);

    /* timer enable */
    TIM_Cmd(TIM1, ENABLE);                          
}
