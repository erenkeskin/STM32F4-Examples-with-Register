/******************************************************
*																											*
*	HASAN EREN KESKIN																		*
*	ELECTRICAL AND ELECTRONICS ENGINEERING STUDENT			*
*	herenkeskin@gmail.com																*
*	http://herenkeskin.com															*
*																											*
*	System Configration Functions												*
*	Versiyon: 0.1 																			*
*																											*
*	V0.1 - 31.08.2018																		*
*																											*
******************************************************/

#ifndef SYSTEM_CONFIG_H
#define SYSTEM_CONFIG_H
	
#include <stm32f4xx.h>
#include "stm32f4xx_hal_conf.h"            // Keil::Device:STM32Cube HAL:Common

// System Clocks
#define CPU_PLL_CLOCK			168000000		// 168 MHz
#define APB1_CLOCK				42000000		//  42 MHz
#define APB2_CLOCK				84000000		//  84 MHz

// While loop takes 4 cycle
// For 1 us delay, we need to divide with 4M
#define CLOCK_DIVIDER			(CPU_PLL_CLOCK / 4000000)

void Delay_Us(uint32_t microseconds);
void Delay_Ms(uint32_t milliseconds);
void System_Clock_Config(void);

#endif	// SYSTEM_CONFIG_H
