/*
 * flysky_ibus.h
 *
 *  Created on: Feb 4, 2021
 *      Author: mokhwasomssi
 */


#ifndef __IBUS_H__
#define __IBUS_H__


#include <stdbool.h>
#include <stdint.h>
#include "stm32f4xx_hal.h"  // Adjust if you use a different STM32 series




/* User configuration */
extern UART_HandleTypeDef huart1;
#define IBUS_UART				(&huart1)
#define IBUS_USER_CHANNELS		6		// Use 6 channels




/* Defines */
#define IBUS_LENGTH				0x20	// 32 bytes
#define IBUS_COMMAND40			0x40	// Command to set servo or motor speed is always 0x40
#define IBUS_MAX_CHANNLES		14


/* Main Functions */
void ibus_init();
bool ibus_read(uint16_t* ibus_data);


/* Sub Functions */
bool ibus_is_valid();
bool ibus_checksum();
void ibus_update(uint16_t* ibus_data);
void ibus_soft_failsafe(uint16_t* ibus_data, uint8_t fail_safe_max);
void ibus_reset_failsafe();



#endif /* __IBUS_H__ */
