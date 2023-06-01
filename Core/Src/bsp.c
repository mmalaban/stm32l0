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
#include "stm32l0xx_hal_uart.h"
#include "bsp.h"

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

/* typedef -----------------------------------------------------------*/


/* Private define ------------------------------------------------------------*/


/* Private macro -------------------------------------------------------------*/


/* Private variables ---------------------------------------------------------*/


/* External variables ---------------------------------------------------------*/
extern UART_HandleTypeDef huart2; // the current definition of this variable is in main.c

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
  * @name   BSP_Led()
  * @brief  Turns on LED, Nucleo-L031K6 only has one LED. Needs to be extended to other boards
  *
  * @param  file: description of parameter
  * @param  line: description of parameter
  * @retval <name_of_retval>:  description of return value
  */
#if defined(STM32L031xx) && defined(NUCLEOL031K6)
void BSP_Led(BSP_LED_OnOff OnOff)
#endif
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
 #if defined(STM32L031xx) && defined(NUCLEOL031K6)
void BSP_LED_Toggle()
#endif
{
    HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin);
}


/**
  * @brief  description of the function
  *
  * @param  file: description of parameter
  * @param  line: description of parameter
  * @retval <name_of_retval>:  description of return value
  */
void BSP_DebugPrint(int num_args, const char *format, ...)
{
  va_list args;
#ifdef DEBUG
  char buffer[50];
  char line_ending[] = "\r\n";
  uint16_t len;

  va_start(args, format);
  len = snprintf(buffer, sizeof buffer, format, va_arg(args, int));
  va_end(args);

  strcat(buffer, line_ending);
  len += sizeof line_ending;

  #ifdef HAL_UART_MODULE_ENABLED
    HAL_UART_Transmit(&huart2, (uint8_t *)buffer, len, 100);
    return;
  #endif /* HAL_UART_MODULE_ENABLED */
#else
  (void)num_args;
  (void)format;
  (void)args;
#endif /* DEBUG */
}
