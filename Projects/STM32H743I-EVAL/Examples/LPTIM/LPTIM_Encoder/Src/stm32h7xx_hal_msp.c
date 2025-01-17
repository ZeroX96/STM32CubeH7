/**
  ******************************************************************************
  * @file    LPTIM/LPTIM_Encoder/Src/stm32h7xx_hal_msp.c
  * @author  MCD Application Team
  * @brief   HAL MSP module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/** @addtogroup STM32H7xx_HAL_Examples
  * @{
  */

/** @defgroup ADC_DMA_Transfer
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup HAL_MSP_Private_Functions
  * @{
  */

/**
* @brief  LPTIM MSP Init
* @param  hlptim : LPTIM handle
* @retval None
*/
void HAL_LPTIM_MspInit(LPTIM_HandleTypeDef *hlptim)
{

  GPIO_InitTypeDef       GPIO_InitStructure;

  /* Enable the GPIOD, GPIOE, GPIOH  clock */
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();

  /* Enable LPTIM clock */
  __HAL_RCC_LPTIM1_CLK_ENABLE();
  /* Select APB1 as LPTIM1 clock source */
  __HAL_RCC_LPTIM1_CONFIG(RCC_LPTIM1CLKSOURCE_D2PCLK1);

  /* Configure PH5 and PH6 IOs in output push-pull mode to drive external signals */
  GPIO_InitStructure.Pin = GPIO_PIN_5|GPIO_PIN_6 ;
  GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStructure.Pull = GPIO_PULLUP;
  GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  HAL_GPIO_Init(GPIOH, &GPIO_InitStructure);

  /* Configure PD12 and PE1 for LPTIM1 input1 and input2 */
  GPIO_InitStructure.Pin       = GPIO_PIN_12;
  GPIO_InitStructure.Mode      = GPIO_MODE_AF_PP;
  GPIO_InitStructure.Pull      = GPIO_NOPULL;
  GPIO_InitStructure.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStructure.Alternate = GPIO_AF1_LPTIM1;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStructure);

  GPIO_InitStructure.Pin       = GPIO_PIN_1;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStructure);
}


/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
