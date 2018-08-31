/************************************************************
*															*
*	HASAN EREN KESKIN										*
*	ELECTRICAL AND ELECTRONICS ENGINEERING STUDENT			*
*	herenkeskin@gmail.com									*
*	http://herenkeskin.com									*
*															*
*	USART Library											*
*	Versiyon: 0.1 											*
*															*
*	V0.1 - 31.08.2018										*
*															*
************************************************************/
 
#ifndef USART_H
#define USART_H

/*
	
	STM32F4 USART Library with register based
	
	This document is tested with FTDI232 USB to TTL Converter
	
	Connection
	---------------------------
	
	Board TX 	-----> FTDI232 RX
	Board RX  	-----> FTDI232 TX
	Board GND 	-----> FTDI232 GND
	
	For USART1 Communication:
		- Used pins are PB6 and PB7
		- PA9 and PA10 not used for FTDI communication on Discovery Board.
			Because, these pins also used on USB communication with connected
			Capacitor. This is the reason why used PB6 and PB7 for USART1.
			
	Features
	---------------------------
	- Other USARTs functions will add
	
*/
	
#include "System_Config.h"

void 	USART1_Init(uint32_t BAUDRATE);
void 	USART1_WriteChar(uint8_t character);
void	USART1_WriteString(uint8_t * string);

#endif	// USART_H
