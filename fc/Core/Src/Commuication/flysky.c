/*
 * flysky.c
 *
 *  Created on: Feb 6, 2025
 *      Author: arshd
 */


#include "flysky.h"
#include <stdio.h>

// Define the public channel variables.
uint16_t roll      = 0;
uint16_t pitch     = 0;
uint16_t throttle  = 0;
uint16_t yaw       = 0;
uint16_t sw1       = 0;

void flysky_update(const uint16_t *data)
{
    // Map the raw IBUS data to the corresponding channels.
    roll      = data[0];  // Channel 1: Roll
    pitch     = data[1];  // Channel 2: Pitch
    throttle  = data[2];  // Channel 3: Throttle
    yaw       = data[3];  // Channel 4: Yaw
    sw1       = data[4];  // Channel 5: Switch 1
}

void flysky_process(uint16_t *ibus_data)
{
    // Read raw IBUS data.
    ibus_read(ibus_data);

    // Apply a soft failsafe with a threshold (for example, 50).
    ibus_soft_failsafe(ibus_data, 100);

    // Update the FlySky channel values.
    flysky_update(ibus_data);

}

/* Getter functions */

uint16_t get_roll(void)
{
    return roll;
}

uint16_t get_pitch(void)
{
    return pitch;
}

uint16_t get_throttle(void)
{
    return throttle;
}

uint16_t get_yaw(void)
{
    return yaw;
}

uint16_t get_sw1(void)
{
    return sw1;
}
