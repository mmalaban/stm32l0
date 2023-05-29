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
void BSP_Led(BSP_LED_OnOff OnOff);
void BSP_LED_Toggle(void);


/* Private defines -----------------------------------------------------------*/


#ifdef __cplusplus
}
#endif

#endif /* INC_BSP_H_ */
