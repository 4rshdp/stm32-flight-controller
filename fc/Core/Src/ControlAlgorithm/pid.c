/*
 * pid.c
 *
 *  Created on: Mar 31, 2025
 *      Author: arshd
 */


#include "pid.h"

void pid_init(PIDController *pid, float kp, float ki, float kd)
{
    pid->kp = kp;
    pid->ki = ki;
    pid->kd = kd;
    pid->prev_error = 0.0f;
    pid->integral = 0.0f;
}

float pid_compute(PIDController *pid, float error, float dt)
{
    pid->integral += error * dt;

    // Anti-windup (optional)
    if (pid->integral > 400) pid->integral = 400;
    else if (pid->integral < -400) pid->integral = -400;

    float derivative = (error - pid->prev_error) / dt;
    pid->prev_error = error;

    float output = pid->kp * error + pid->ki * pid->integral + pid->kd * derivative;

    // Clamp output (optional)
    if (output > 400) output = 400;
    else if (output < -400) output = -400;

    return output;
}

void pid_reset(PIDController *pid)
{
    pid->prev_error = 0.0f;
    pid->integral = 0.0f;
}

