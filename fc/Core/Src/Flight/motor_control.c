/*
 * motor_control.c
 *
 *  Created on: Apr 8, 2025
 *      Author: arshd
 */


#include "motor_control.h"
#include "main.h"
#include "stm32f4xx_hal.h"

extern TIM_HandleTypeDef htim3;


// Directly sets PWM pulse widths to ESCs via TIM3
void motor_control_write(uint16_t m1, uint16_t m2, uint16_t m3, uint16_t m4)
{
    __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, m1);
    __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, m2);
    __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, m3);
    __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, m4);
}
