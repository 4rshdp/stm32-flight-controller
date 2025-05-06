/*
 * pid.h
 *
 *  Created on: Mar 31, 2025
 *      Author: arshd
 */

#ifndef INC_CONTROLALGORITHM_PID_H_
#define INC_CONTROLALGORITHM_PID_H_

typedef struct {
    float kp;
    float ki;
    float kd;
    float prev_error;
    float integral;
} PIDController;

void pid_init(PIDController *pid, float kp, float ki, float kd);
float pid_compute(PIDController *pid, float error, float dt);
void pid_reset(PIDController *pid);

#endif /* INC_CONTROLALGORITHM_PID_H_ */
