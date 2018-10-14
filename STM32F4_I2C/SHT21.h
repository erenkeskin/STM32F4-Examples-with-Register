/************************************************************
*															*
*	HASAN EREN KESKIN										*
*	ELECTRICAL AND ELECTRONICS ENGINEERING STUDENT			*
*	herenkeskin@gmail.com									*
*	http://herenkeskin.com									*
*															*
*	SHT21 Libraries 									*
*	Versiyon: 0.1 											*
*															*
*	V0.1 - 14.10.2018										*
*															*
************************************************************/
#ifndef SHT21_H
#define SHT21_H

#include <stdint.h>

// Sensor Registers
#define SHT21_I2C_ADDRESS															0x40		// 1000 000
#define SHT21_I2C_ADDRESS_WRITE												0x80		// 1000 0000
#define SHT21_I2C_ADDRESS_READ												0x81		// 1000 0001

#define SHT21_TRIGGER_T_MEASUREMENT_HOLD_MASTER				0xE3		// 1110 0011
#define SHT21_TRIGGER_T_MEASUREMENT_NO_HOLD_MASTER		0xF3		// 1111 0011
#define SHT21_TRIGGER_RH_MEASUREMENT_HOLD_MASTER			0xE5		// 1110 0101
#define SHT21_TRIGGER_RH_MEASUREMENT_NO_HOLD_MASTER		0xF5		// 1111 0101
#define SHT21_WRITE_USER_REGISTER											0xE6		// 1110 0110
#define SHT21_READ_USER_REGISTER											0xE7		// 1110 0111
#define SHT21_SOFT_RESET															0xFE		// 1111 1110

void 	SHT21_Init(void);
void 	SHT21_ReadData(void);
float SHT21_GetTemperature(void);
float SHT21_GetHumidity(void);

#endif
