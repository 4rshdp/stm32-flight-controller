/*
 * flight_manager.c
 *
 *  Created on: Mar 31, 2025
 *      Author: arshd
 */

#include "usbd_cdc_if.h"
#include "flight_manager.h"
#include "motor_control.h"
#include "flysky.h"
#include "mpu6050.h"
#include "imu_fusion.h"
#include "pid.h"
#include "debug_logger.h"

#include <math.h>
#include <string.h>

static bool armed = false;

// PID controllers
static PIDController pid_roll_angle, pid_roll_rate;
static PIDController pid_pitch_angle, pid_pitch_rate;
static PIDController pid_yaw_rate;

// Kalman outputs (now static)
static float roll_estimate_deg = 0.0f;
static float pitch_estimate_deg = 0.0f;

// Sample time and limits
#define SAMPLE_DT 0.004f           // 4ms
#define ANGLE_MAX_DEG  30.0f
#define YAW_MAX_DPS    90.0f

void flight_manager_init(void)
{
    // Roll
    pid_init(&pid_roll_angle, 4.0f, 0.0f, 0.0f);
    pid_init(&pid_roll_rate, 0.1f, 0.0f, 0.01f);

    // Pitch
    pid_init(&pid_pitch_angle, 4.0f, 0.0f, 0.0f);
    pid_init(&pid_pitch_rate, 0.1f, 0.0f, 0.01f);

    // Yaw (rate mode only)
    pid_init(&pid_yaw_rate, 0.2f, 0.0f, 0.01f);
}

void flight_manager_update(void)
{
    // === Sensor Fusion (Kalman) ===
    imu_fusion_update(Gx, Gy, Gz, Ax, Ay, Az, SAMPLE_DT,
                      &roll_estimate_deg, &pitch_estimate_deg);

    // === RC Input (PWM: 1000–2000) ===
    float rc_throttle = get_throttle();
    float rc_roll     = get_roll();
    float rc_pitch    = get_pitch();
    float rc_yaw      = get_yaw();
    float rc_sw1      = get_sw1();

    // === Arming Logic ===
    if (rc_sw1  > 1500) {
        armed = true;
    } else {
        armed = false;
    }

    // === Map RC to target angles/rates ===
    float roll_target_deg   = ((rc_roll - 1500) / 500.0f) * ANGLE_MAX_DEG;
    float pitch_target_deg  = ((rc_pitch - 1500) / 500.0f) * ANGLE_MAX_DEG;
    float yaw_target_rate   = ((rc_yaw - 1500) / 500.0f) * YAW_MAX_DPS;

    // === Angle PID (outer loop) ===
    float roll_error_angle  = roll_target_deg - roll_estimate_deg;
    float pitch_error_angle = pitch_target_deg - pitch_estimate_deg;

    float desired_roll_rate  = pid_compute(&pid_roll_angle, roll_error_angle, SAMPLE_DT);
    float desired_pitch_rate = pid_compute(&pid_pitch_angle, pitch_error_angle, SAMPLE_DT);

    // === Rate PID (inner loop) ===
    float roll_rate_error  = desired_roll_rate - Gx;
    float pitch_rate_error = desired_pitch_rate - Gy;
    float yaw_rate_error   = yaw_target_rate - Gz;

    float roll_output  = pid_compute(&pid_roll_rate, roll_rate_error, SAMPLE_DT);
    float pitch_output = pid_compute(&pid_pitch_rate, pitch_rate_error, SAMPLE_DT);
    float yaw_output   = pid_compute(&pid_yaw_rate, yaw_rate_error, SAMPLE_DT);

    // === Safety: Throttle Cutoff or Disarmed ===
    if (!armed || rc_throttle < 1050) {
        motor_control_write(1000, 1000, 1000, 1000);

        // Reset PIDs
        pid_reset(&pid_roll_angle);
        pid_reset(&pid_roll_rate);
        pid_reset(&pid_pitch_angle);
        pid_reset(&pid_pitch_rate);
        pid_reset(&pid_yaw_rate);

        return; // Exit early
    }

    // === Motor Mixing ===
    float m1 = rc_throttle - roll_output - pitch_output - yaw_output;
    float m2 = rc_throttle + roll_output - pitch_output + yaw_output;
    float m3 = rc_throttle + roll_output + pitch_output - yaw_output;
    float m4 = rc_throttle - roll_output + pitch_output + yaw_output;

    // Clamp to PWM range
    uint16_t pwm1 = (uint16_t)fminf(fmaxf(m1, 1000), 2000);
    uint16_t pwm2 = (uint16_t)fminf(fmaxf(m2, 1000), 2000);
    uint16_t pwm3 = (uint16_t)fminf(fmaxf(m3, 1000), 2000);
    uint16_t pwm4 = (uint16_t)fminf(fmaxf(m4, 1000), 2000);

    /**
     * @brief Remapped motor outputs to match physical ESC soldering.
     *
     * Motor layout (Betaflight-style X configuration):
     * - M1 (Back Right)  -> PA6  -> pwm3
     * - M2 (Front Right) -> PA7  -> pwm2
     * - M3 (Back Left)   -> PB0  -> pwm4
     * - M4 (Front Left)  -> PB1  -> pwm1
     * \todo Add a config file later for motor management, debug and other configurations.
     */
    motor_control_write(pwm3, pwm2, pwm4, pwm1);


//    debug_log_status(rc_throttle, rc_roll, rc_pitch, rc_yaw,
//                         roll_estimate_deg, pitch_estimate_deg,
//                         roll_output, pitch_output, yaw_output,
//                         pwm1, pwm2, pwm3, pwm4);


    debug_motor_test_sequence();




}
