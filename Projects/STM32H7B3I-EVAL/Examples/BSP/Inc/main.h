/**
  ******************************************************************************
  * @file    BSP/Inc/main.h
  * @author  MCD Application Team
  * @brief   Header for main.c module for Cortex-M7.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

/* Includes ------------------------------------------------------------------*/
#include "stdio.h"
#include "string.h"
#include "stm32h7xx_hal.h"
#include "stm32h7b3i_eval.h"
#include "stm32h7b3i_eval_lcd.h"
#include "stm32h7b3i_eval_sd.h"
#include "stm32h7b3i_eval_eeprom.h"
#include "stm32h7b3i_eval_nor.h"
#include "stm32h7b3i_eval_sram.h"
#include "stm32h7b3i_eval_sdram.h"
#include "stm32h7b3i_eval_io.h"
#include "stm32h7b3i_eval_ts.h"
#include "stm32h7b3i_eval_audio.h"
#include "stm32h7b3i_eval_ospi.h"
#include "stm32h7b3i_eval_camera.h"
#include "stm32_lcd.h"

/* Exported types ------------------------------------------------------------*/
typedef struct
{
  void   (*DemoFunc)(void);
  uint8_t DemoName[50];
  uint32_t DemoIndex;
}BSP_DemoTypedef;

typedef enum {
  AUDIO_ERROR_NONE = 0,
  AUDIO_ERROR_NOTREADY,
  AUDIO_ERROR_IO,
  AUDIO_ERROR_EOF,
}AUDIO_ErrorTypeDef;

typedef enum {
  TS_ACT_NONE = 0,
  TS_ACT_FREQ_DOWN,
  TS_ACT_FREQ_UP,
  TS_ACT_VOLUME_DOWN,
  TS_ACT_VOLUME_UP,
  TS_ACT_PAUSE = 0xFE
}TS_ActionTypeDef;

/* Exported variables --------------------------------------------------------*/
extern const unsigned char stlogo[];
extern __IO uint32_t ButtonState;
extern uint32_t SdmmcTest;
extern uint32_t CameraTest;
extern uint32_t AudioUpdate;
extern uint16_t PlayBuffer[];
extern uint32_t AudioInstance;
extern uint32_t TSInterruptTest;
extern TS_Init_t hTS;
extern TS_ActionTypeDef ts_action;
extern uint8_t FreqStr[];
extern uint32_t PauseEnabledStatus;
extern TS_State_t  TS_State;
/* Exported constants --------------------------------------------------------*/
/* LCD Frame Buffer address */
#define LCD_FRAME_BUFFER                  0xD0000000 /* LCD Frame buffer of size 800x480 in ARGB8888 */
/* Camera Frame Buffer address */
#define CAMERA_FRAME_BUFFER               0xD0400000
/* SDRAM write address */
#define SDRAM_WRITE_READ_ADDR             CAMERA_FRAME_BUFFER
#define SDRAM_WRITE_READ_ADDR_OFFSET ((uint32_t)0x0800)

/* SD definitions */
#define SD_DMA_MODE      0U
#define SD_IT_MODE       1U
#define SD_POLLING_MODE  2U

/* AUDIO definitions */
#define AUDIO_BUFFER_SIZE            8192

/* Exported macro ------------------------------------------------------------*/
#define COUNT_OF_EXAMPLE(x)    (sizeof(x)/sizeof(BSP_DemoTypedef))

/* Exported functions ------------------------------------------------------- */
void LCD_demo (void);
void Touchscreen_demo1(void);
void Touchscreen_demo2(void);
void Touchscreen_demo3(void);
void POTENTIOMETER_demo (void);
void EEPROM_demo (void);
void AudioPlay_demo (void);
void OSPI_demo (void);
void SD_DMA_demo(void);
void SD_IT_demo(void);
void SD_POLLING_demo(void);
void NOR_demo (void);
void SRAM_demo (void);
void SDRAM_demo(void);
void Camera_demo(void);
void REC_SingleBuff_demo(void);
void REC_MultiBuff_demo(void);
void REC_AnalogMicRecord_demo(void);
uint8_t TouchScreen_GetTouchPosition(void);
void Touchscreen_DrawBackground_Circles(uint8_t state);
uint8_t CheckForUserInput(void);
uint8_t AUDIO_Process(void);

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
