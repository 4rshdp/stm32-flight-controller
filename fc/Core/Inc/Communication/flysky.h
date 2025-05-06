/*
 * flysky.h
 *
 *  Created on: Feb 6, 2025
 *      Author: arshd
 */

#ifndef INC_FLYSKY_H_
#define INC_FLYSKY_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>
#include <ibus.h>



// Public variables that hold the RC channel values
extern uint16_t roll;      // Channel 1: Roll
extern uint16_t pitch;     // Channel 2: Pitch
extern uint16_t throttle;  // Channel 3: Throttle
extern uint16_t yaw;       // Channel 4: Yaw
extern uint16_t sw1;       // Channel 5: Switch 1

/**
 * @brief  Update the FlySky channels with the raw IBUS data.
 * @param  data: pointer to the array holding the raw IBUS channel data.
 */
void flysky_update(const uint16_t *data);

/**
 * @brief  Process the IBUS data and format a status string.
 *         This function reads the raw IBUS data, applies a soft failsafe,
 *         updates the FlySky channel values, and writes a formatted string
 *         into the provided USB transmit buffer.
 * @param  ibus_data: pointer to an array where raw IBUS data is stored.
 * @param  usb_tx_buffer: pointer to a character buffer for the status string.
 * @param  buf_size: size of the USB transmit buffer.
 */
void flysky_process(uint16_t *ibus_data);

/* Getter functions for each channel: */

/**
 * @brief  Get the current roll value.
 * @retval Roll channel value.
 */
uint16_t get_roll(void);

/**
 * @brief  Get the current pitch value.
 * @retval Pitch channel value.
 */
uint16_t get_pitch(void);

/**
 * @brief  Get the current throttle value.
 * @retval Throttle channel value.
 */
uint16_t get_throttle(void);

/**
 * @brief  Get the current yaw value.
 * @retval Yaw channel value.
 */
uint16_t get_yaw(void);

/**
 * @brief  Get the current switch 1 value.
 * @retval Switch 1 channel value.
 */
uint16_t get_sw1(void);

#ifdef __cplusplus
}
#endif

#endif /* INC_FLYSKY_H_ */
