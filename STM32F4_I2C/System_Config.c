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
*	V0.2 - 09.09.2018																		*
*																											*
******************************************************/

#include "System_Config.h"

void System_Clock_Config(void)
{	
	
	// Prescaler Configrations
	RCC->CFGR 	|= (5 << 10);			// APB1 Prescaler = 4
	RCC->CFGR 	|= (4 << 13);			// APB2 Prescaler = 2

	RCC->CR 	|= (1 << 16);			// HSE Clock Enable - HSEON
	while(!(RCC->CR & 0x00020000));		// Wait until HSE Clock Ready - HSERDY

	// PLL Configrations
	RCC->PLLCFGR = 0;					// Clear all PLLCFGR register
	RCC->PLLCFGR |=  (8		<<  0);		// PLLM = 8;
	RCC->PLLCFGR |=  (336 	<<  6);		// PLLN = 336;
	RCC->PLLCFGR &= ~(3 	<< 16);		// PLLP = 2; // For 2, Write 0
	RCC->PLLCFGR |=  (1 	<< 22);		// HSE Oscillator clock select as PLL
	RCC->PLLCFGR |=  (7 	<< 24);		// PLLQ = 7;

	RCC->CR 		|=  (1 		<< 24); // PLL Clock Enable - PLLON
	while(!(RCC->CR & 0x02000000)); 	// Wait until PLL Clock Ready - PLLRDY

	// Flash Configrations
	FLASH->ACR = 0;						// Clear all ACR register (Access Control Register)
	FLASH->ACR 		|= (5 <<  0); 		// Latency - 5 Wait State
	FLASH->ACR 		|= (1 <<  9);		// Instruction Cache Enable
	FLASH->ACR 		|= (1 << 10);		// Data Cache Enable

	RCC->CFGR 		|= (2 <<  0);		// PLL Selected as System Clock
	while((RCC->CFGR & 0x0F) != 0x0A); 	// Wait PLL On

}

/* SysTick Configrations */
void SysTick_Init(void)
{
	SysTick->CTRL = 0;									// Close SysTick for configrations
	//SysTick->LOAD = 0x00014821;				// 0.5ms counter
	//SysTick->LOAD = 0x00029041;				// 1ms counter
	SysTick->LOAD = 0x000000A8;					// 1us counter
	SysTick->VAL  = 0;									// SysTick Current Value Register 
	SysTick->CTRL |= (1 << 2);					// Clock source selection, 1 = AHB Source
	SysTick->CTRL |= (1 << 1);					// SysTick exception request enable (SysTick Interrupt)
	SysTick->CTRL |= (1 << 0);					// Counter enable
}

/*
	Systick Handler (Interrupt Function)
*/
__IO uint32_t Delay_Time;
void SysTick_Handler(void)
{
  if(Delay_Time !=0)
	{
		Delay_Time --;
	}
}         

// Microsecond Delay (us)
void Delay(uint32_t time)
{
	Delay_Time = time;
	while(Delay_Time !=0);
}
