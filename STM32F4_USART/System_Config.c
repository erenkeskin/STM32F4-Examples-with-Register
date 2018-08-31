/********************************************************
*                                                      	*
* HASAN EREN KESKIN                                    	*
* ELECTRICAL AND ELECTRONICS ENGINEERING STUDENT       	*
* herenkeskin@gmail.com                                	*
* http://herenkeskin.com                            		*
*                                                      	*
* System Configration Functions                        	*
* Versiyon: 0.1																					*
*																												*
*	V0.1 - 31.08.2018																			*
*                                                      	*
********************************************************/

#include "System_Config.h"

uint32_t multiplier;
 
void Delay_Us(uint32_t microseconds)
{
    microseconds = microseconds * CLOCK_DIVIDER - 10;
    while (microseconds--);
}

void Delay_Ms(uint32_t milliseconds) 
{
    milliseconds = 1000 * (milliseconds * CLOCK_DIVIDER - 10);
    while (milliseconds--);
}

void System_Clock_Config(void)
{	
	
	// Prescaler Configrations
	RCC->CFGR |= (5 << 10);							// APB1 Prescaler = 4
	RCC->CFGR |= (4 << 13);							// APB2 Prescaler = 2
  
	RCC->CR 	|= (1 << 16);          		// HSE Clock Enable - HSEON
  while(!(RCC->CR & 0x00020000));			// Wait until HSE Clock Ready - HSERDY
	
	// PLL Configrations
  RCC->PLLCFGR = 0;										// Clear all PLLCFGR register
	RCC->PLLCFGR 	|=  (8 		<<  0);			// PLLM = 8;
	RCC->PLLCFGR 	|=  (336 	<<  6);			// PLLN = 336;
	RCC->PLLCFGR 	&= ~(3 		<< 16);			// PLLP = 2; // For 2, Write 0
	RCC->PLLCFGR 	|=  (1 		<< 22);			// HSE Oscillator clock select as PLL
	RCC->PLLCFGR 	|=  (7 		<< 24);			// PLLQ = 7;
  
	RCC->CR 			|=  (1 		<< 24);   	// PLL Clock Enable - PLLON
  while(!(RCC->CR & 0x02000000)); 		// Wait until PLL Clock Ready - PLLRDY
	
	// Flash Configrations
  FLASH->ACR = 0;											// Clear all ACR register (Access Control Register)
  FLASH->ACR 		|= (5 <<  0);      		// Latency - 5 Wait State
  FLASH->ACR 		|= (1 <<  9);       	// Instruction Cache Enable
  FLASH->ACR 		|= (1 << 10);       	// Data Cache Enable
  
	RCC->CFGR 		|= (2 <<  0);     		// PLL Selected as System Clock
  while((RCC->CFGR & 0x0F) != 0x0A); 	// Wait PLL On

}
