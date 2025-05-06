/*
 * motor_control.h
 *
 *  Created on: Apr 8, 2025
 *      Author: arshd
 */

#ifndef INC_FLIGHT_MOTOR_CONTROL_H_
#define INC_FLIGHT_MOTOR_CONTROL_H_

#include <stdint.h>

void motor_control_write(uint16_t m1, uint16_t m2, uint16_t m3, uint16_t m4);

#endif /* INC_FLIGHT_MOTOR_CONTROL_H_ */
