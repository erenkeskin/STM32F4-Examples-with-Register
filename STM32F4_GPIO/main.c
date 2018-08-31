#include "System_Config.h"

/*
typedef struct
{
  __IO uint32_t MODER;
  __IO uint32_t OTYPER;
  __IO uint32_t OSPEEDR;
  __IO uint32_t PUPDR;
  __IO uint32_t IDR;
  __IO uint32_t ODR;
  __IO uint32_t BSRR;
  __IO uint32_t LCKR;
  __IO uint32_t AFR[2];
} GPIO_TypeDef;
*/

#define HIGH		1
#define LOW			0

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

int main(void)
{
	System_Clock_Config();
	
	//RCC->AHB1ENR |= 0x0000003F; 		// GPIO A, B, C, D, E and F clock enable

	RCC->AHB1ENR 		|=  (1 << 3);			// GPIOD Peripheral clock enable
	
	GPIO_Init(GPIOD, 12);
	
	while (1)
	{
		GPIO_Write(GPIOD, 12, HIGH);
		Delay_Ms(1000);						// 1 second
		
		GPIO_Write(GPIOD, 12, LOW);
		Delay_Ms(1000);						// 1 second
	}
	
	return 0;
}
