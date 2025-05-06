/*
 * debug_logger.h
 *
 *  Created on: Apr 9, 2025
 *      Author: arshd
 */

#ifndef INC_DEBUG_LOGGER_H_
#define INC_DEBUG_LOGGER_H_

#include <stdint.h>
#include <stdbool.h>

void debug_log_status(float throttle, float roll, float pitch, float yaw,
                      float roll_est, float pitch_est,
                      float roll_pid, float pitch_pid, float yaw_pid,
                      uint16_t pwm1, uint16_t pwm2, uint16_t pwm3, uint16_t pwm4);

void debug_motor_test_sequence(void);

#endif /* INC_DEBUG_LOGGER_H_ */
