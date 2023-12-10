/**
  ******************************************************************************
  * @file           : 
  * @brief          : 
  ******************************************************************************
  * @attention
  *
  * Copyright (c) .
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef INC_BSP_H_
#define INC_BSP_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "bsp_cfg.h"

/* Exported types ------------------------------------------------------------*/
typedef enum
{
    BSP_LED_OFF = 0u,
    BSP_LED_ON
} BSP_LED_OnOff;


/* Exported constants --------------------------------------------------------*/


/* Exported macro ------------------------------------------------------------*/
#define BSP_STM32L0

/* Exported functions prototypes ---------------------------------------------*/
void BSP_Init(void);

#if defined(STM32L031xx) && defined(NUCLEOL031K6)
void BSP_Led(BSP_LED_OnOff OnOff);
#endif

#if defined(STM32L031xx) && defined(NUCLEOL031K6)
void BSP_LED_Toggle(void);
#endif


#ifdef DEBUG
#if defined(STM32L031xx) && defined(NUCLEOL031K6)
void BSP_DebugPrint(const char *format, ...);
#endif
#endif
/* Private defines -----------------------------------------------------------*/


#ifdef __cplusplus
}
#endif

#endif /* INC_BSP_H_ */
