/**
  ******************************************************************************
  * @file           : bsp.c
  * @brief          : 
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32l0xx_hal_gpio.h"
#include "bsp.h"

/* typedef -----------------------------------------------------------*/


/* Private define ------------------------------------------------------------*/


/* Private macro -------------------------------------------------------------*/


/* Private variables ---------------------------------------------------------*/


/* Private function prototypes -----------------------------------------------*/


/**
  * @brief  description of the function
  *         
  * @param  file: description of parameter
  * @param  line: description of parameter
  * @retval <name_of_retval>:  description of return value
  */
void BSP_Init()
{

}


/**
  * @brief  description of the function
  *
  * @param  file: description of parameter
  * @param  line: description of parameter
  * @retval <name_of_retval>:  description of return value
  */
void BSP_Led(BSP_LED_OnOff OnOff)
{
    switch(OnOff)
    {
        case BSP_LED_OFF:
            HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_RESET);
            break;
        case BSP_LED_ON:
            HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_SET);
            break;
        default:
            /* do nothing */
            break;
    }
}


/**
  * @brief  description of the function
  *
  * @param  file: description of parameter
  * @param  line: description of parameter
  * @retval <name_of_retval>:  description of return value
  */
void BSP_LED_Toggle()
{
    HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin);
}
