#include "System_Config.h"

#define HIGH		1
#define LOW			0

int a = 0;

void GPIO_Init(GPIO_TypeDef * GPIOx, uint8_t GPIO_Pin);
void GPIO_Write(GPIO_TypeDef * GPIOx, uint8_t GPIO_Pin, uint8_t State);

/*
	(Reference Manual 7.2 - Page: 218/1749)
	The timer clock frequencies are automatically set by hardware. There are two cases:
		1. If the APB prescaler is 1, the timer clock frequencies are set to the same frequency as
		that of the APB domain to which the timers are connected.
		2. Otherwise, they are set to twice (×2) the frequency of the APB domain to which the
		timers are connected.

	APB1 Bus max 42 MHz
	Timer7 Clock max 84 MHz
*/
void TIM7_Init(void)
{
	RCC->APB1ENR 	|= (1 << 5);    // Activate Timer 7 Clock (42 Mhz * 2)
	
	TIM7->CR1 		 = 0;           // Clear Control Register
	TIM7->CR1 		|= (1 << 7);    // Auto-Reloaded Selected
	
	/*
		Period = 1 / Frequency
		t = (1 / f)
		fCK_PSC / ( (PRESCALER + 1) * (AUTO-RELOADED-VALUE + 1) ) = 1 Hz
		
		This calculation gives us to 1 second timer interrupt
	*/
	TIM7->PSC 		 = 41999;
	TIM7->ARR 		 = 1999;
	
	TIM7->DIER 		 = 0;						// Clear DMA/Interrupt Enable Register
	TIM7->DIER 		|= (1 << 8);		// UDE: Update DMA request enable
	TIM7->DIER 		|= (1 << 0);		// UIE: Update interrupt enable
	
	NVIC->ISER[1]  = (1 << 23);  	// Activate Tımer7 Global Interrupt in NVIC
	
	TIM7->CR1 		|= (1 << 0);		// Counter Enable
}

void TIM7_IRQHandler()
{
		TIM7->SR = 0;
		if(a % 2)
		{
			GPIO_Write(GPIOD, 12, HIGH);
		} else {
			GPIO_Write(GPIOD, 12, LOW);
		}
		a++;
}

int main(void)
{
	System_Clock_Config();
	RCC->AHB1ENR 		|=  (1 << 3);			// GPIOD Peripheral clock enable
	
	GPIO_Init(GPIOD, 12);
	TIM7_Init();
	
	while(1);
	
	return 0;
}

void GPIO_Init(GPIO_TypeDef * GPIOx, uint8_t GPIO_Pin)
{
	GPIOx->MODER 		|=  (1 << (2 * GPIO_Pin));		// GPIO Pin 12
	
	// Output State
	GPIOx->OSPEEDR 	|=  (3 << (2 * GPIO_Pin));		// Output Speed - Very High Mode
	GPIOx->OTYPER 	&= ~(1 << (1 * GPIO_Pin));		// Output Type = Push-pull
	GPIOx->PUPDR 		&= ~(3 << (2 * GPIO_Pin));		// Pull-up/down Mode = No pull up/down
}
 
void GPIO_Write(GPIO_TypeDef * GPIOx, uint8_t GPIO_Pin, uint8_t State)
{
	if(State == 1)
	{
		GPIOx->ODR |= (1 << GPIO_Pin);
	} else if(State == 0) {
		GPIOx->ODR &= ~(3 << GPIO_Pin);
	} else {
		GPIOx->ODR &= ~(3 << GPIO_Pin);
	}
}