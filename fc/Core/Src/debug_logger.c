/*
 * debug_logger.c
 *
 *  Created on: Apr 9, 2025
 *      Author: arshd
 */


#include "debug_logger.h"
#include "usbd_cdc_if.h"
#include "motor_control.h"
#include "stm32f4xx_hal.h"

#include <stdio.h>
#include <string.h>

#define DEBUG_FLIGHT_MANAGER 1
#define USB_TX_BUFFER_SIZE 256

static char usb_tx_buffer[USB_TX_BUFFER_SIZE];

void debug_log_status(float throttle, float roll, float pitch, float yaw,
                      float roll_est, float pitch_est,
                      float roll_pid, float pitch_pid, float yaw_pid,
                      uint16_t pwm1, uint16_t pwm2, uint16_t pwm3, uint16_t pwm4)
{
#if DEBUG_FLIGHT_MANAGER
    static uint32_t last_debug_time = 0;
    if (HAL_GetTick() - last_debug_time >= 100) // Every 100ms
    {
        snprintf(usb_tx_buffer, sizeof(usb_tx_buffer),
                 "THR_RC: %4.0f  ROLL_RC: %4.0f  PITCH_RC: %4.0f  YAW_RC: %4.0f | R_EST: %+6.2f  P_EST: %+6.2f\r\n",
                 throttle, roll, pitch, yaw,
                 roll_est, pitch_est);
        CDC_Transmit_FS((uint8_t*)usb_tx_buffer, strlen(usb_tx_buffer));

        snprintf(usb_tx_buffer, sizeof(usb_tx_buffer),
                 "PID_R: %+6.2f  PID_P: %+6.2f  PID_Y: %+6.2f | PWM: %4u %4u %4u %4u\r\n\r\n",
                 roll_pid, pitch_pid, yaw_pid,
                 pwm1, pwm2, pwm3, pwm4);
        CDC_Transmit_FS((uint8_t*)usb_tx_buffer, strlen(usb_tx_buffer));

        last_debug_time = HAL_GetTick();
    }
#endif
}

void debug_motor_test_sequence(void)
{
#if DEBUG_FLIGHT_MANAGER
    const uint16_t spin_pwm = 1200;
    const uint16_t off_pwm = 1000;
    const uint32_t spin_time_ms = 2000;
    const uint32_t wait_time_ms = 1000;

    struct {
        const char* name;
        const char* pin;
        uint8_t motor;
    } motors[4] = {
        { "Motor 1", "PA6 (TIM3_CH1)", 1 },
        { "Motor 2", "PA7 (TIM3_CH2)", 2 },
        { "Motor 3", "PB0 (TIM3_CH3)", 3 },
        { "Motor 4", "PB1 (TIM3_CH4)", 4 },
    };

    for (int i = 0; i < 4; i++) {
        snprintf(usb_tx_buffer, sizeof(usb_tx_buffer),
                 "[Motor Test] Spinning %s | Pin: %s | PWM: %u\r\n",
                 motors[i].name, motors[i].pin, spin_pwm);
        CDC_Transmit_FS((uint8_t*)usb_tx_buffer, strlen(usb_tx_buffer));

        switch (motors[i].motor) {
            case 1: motor_control_write(spin_pwm, off_pwm, off_pwm, off_pwm); break;
            case 2: motor_control_write(off_pwm, spin_pwm, off_pwm, off_pwm); break;
            case 3: motor_control_write(off_pwm, off_pwm, spin_pwm, off_pwm); break;
            case 4: motor_control_write(off_pwm, off_pwm, off_pwm, spin_pwm); break;
        }

        uint32_t start = HAL_GetTick();
        while (HAL_GetTick() - start < spin_time_ms);

        motor_control_write(off_pwm, off_pwm, off_pwm, off_pwm);

        uint32_t wait = HAL_GetTick();
        while (HAL_GetTick() - wait < wait_time_ms);
    }
#endif
}
