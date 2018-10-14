/************************************************************
*															*
*	HASAN EREN KESKIN										*
*	ELECTRICAL AND ELECTRONICS ENGINEERING STUDENT			*
*	herenkeskin@gmail.com									*
*	http://herenkeskin.com									*
*															*
*	I2C Library Functions									*
*	Versiyon: 0.1 											*
*															*
*	V0.1 - 14.10.2018										*
*															*
************************************************************/
#ifndef I2C_H
#define I2C_H

#include "System_Config.h"

/* Functions Prototypes */
void I2C1_GPIO_Setup(void);
void I2C1_Init(void);
void I2C1_Start_Condition(void);
void I2C1_Stop_Condition(void);
uint8_t I2C1_ReadData(uint8_t slave_address, uint8_t device_register, uint16_t * data);


#endif
