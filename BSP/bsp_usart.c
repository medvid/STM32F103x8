#include "bsp_usart.h"

USART_TypeDef* COM_USART[COMn] = {COM1_USART, COM2_USART, COM3_USART}; 
GPIO_TypeDef* COM_TX_PORT[COMn] = {COM1_TX_GPIO_PORT, COM2_TX_GPIO_PORT, COM3_TX_GPIO_PORT};
GPIO_TypeDef* COM_RX_PORT[COMn] = {COM1_RX_GPIO_PORT, COM2_RX_GPIO_PORT, COM3_RX_GPIO_PORT};
const uint32_t COM_USART_CLK[COMn] = {COM1_CLK, COM2_CLK, COM3_CLK};
const uint32_t COM_TX_PORT_CLK[COMn] = {COM1_TX_GPIO_CLK, COM2_TX_GPIO_CLK, COM3_TX_GPIO_CLK};
const uint32_t COM_RX_PORT_CLK[COMn] = {COM1_RX_GPIO_CLK, COM2_RX_GPIO_CLK, COM3_RX_GPIO_CLK};
const uint16_t COM_TX_PIN[COMn] = {COM1_TX_PIN, COM2_TX_PIN, COM3_TX_PIN};
const uint16_t COM_RX_PIN[COMn] = {COM1_RX_PIN, COM2_RX_PIN, COM3_RX_PIN};


/**
  * @brief  Configures COM port.
  * @param  COM: Specifies the COM port to be configured.
  *   This parameter can be one of following parameters:    
  *     @arg COM1
  *     @arg COM2
  *     @arg COM3
  * @param  USART_InitStruct: pointer to a USART_InitTypeDef structure that
  *   contains the configuration information for the specified USART peripheral.
  * @retval None
  */
void BSP_COMInit(COM_TypeDef COMx, USART_InitTypeDef* USART_InitStruct)
{
    GPIO_InitTypeDef GPIO_InitStructure;
	
    assert_param(COMx < COMn);

    /* Enable GPIO clock */
    RCC_APB2PeriphClockCmd(COM_TX_PORT_CLK[COMx] | COM_RX_PORT_CLK[COMx] | RCC_APB2Periph_AFIO, ENABLE);

    /* Enable USART clock */
    switch (COMx)
    {
    case COM1:
        RCC_APB2PeriphClockCmd(COM_USART_CLK[COMx], ENABLE);
        break;
    case COM2:
    case COM3:
        RCC_APB1PeriphClockCmd(COM_USART_CLK[COMx], ENABLE);
        break;
    }

    /* Configure USART Tx as alternate function push-pull */
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Pin = COM_TX_PIN[COMx];
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(COM_TX_PORT[COMx], &GPIO_InitStructure);

    /* Configure USART Rx as input floating */
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_InitStructure.GPIO_Pin = COM_RX_PIN[COMx];
    GPIO_Init(COM_RX_PORT[COMx], &GPIO_InitStructure);

    /* USART configuration */
    USART_Init(COM_USART[COMx], USART_InitStruct);
    
    /* Enable USART */
    USART_Cmd(COM_USART[COMx], ENABLE);
}

int BSP_PutChar(COM_TypeDef COMx, int ch)
{
    while(USART_GetFlagStatus(COM_USART[COMx], USART_FLAG_TXE) == RESET)
    {}

    USART_SendData(COM_USART[COMx], (uint8_t) ch);

    return ch;
}

int BSP_GetChar(COM_TypeDef COMx)
{
    while(USART_GetFlagStatus(COM_USART[COMx], USART_SR_RXNE) == RESET)
    {}

    return USART_ReceiveData(COM_USART[COMx]);
}

FlagStatus BSP_CheckChar(COM_TypeDef COMx)
{
    return USART_GetFlagStatus(COM_USART[COMx], USART_SR_RXNE);
}
