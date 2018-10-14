#include "I2C.h"

/* Functions Prototypes */
void I2C1_GPIO_Setup(void)
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;	// Enable clock for GPIOB

	GPIOB->AFR[1] |= (4 << 0); 				// P8 => AF4
	GPIOB->AFR[1] |= (4 << 4); 				// P9 => AF4
	
	GPIOB->MODER 	|= (2 << (2 * 8)); 	// AF: PB8 => I2C1_SCL
	GPIOB->MODER 	|= (2 << (2 * 9)); 	// AF: PB9 => I2C1_SDA
	
	GPIOB->OTYPER |= (1 << (1 * 8)); 	// PB8 - Open Drain
	GPIOB->OTYPER |= (1 << (1 * 9)); 	// PB9 - Open Drain
}

// -----------------------------------------------------------------------------

void I2C1_Init(void)
{
	I2C1_GPIO_Setup();
	
  // Initialize I2C1 Peripheral 
  RCC->APB1ENR  |= (1 << 21);       // Enable clock for I2C1 
	
	I2C1->CR1 	&= ~(1 <<  0);				// Peripheral Disable
	I2C1->CR1 	|=  (1 << 15);				// Software reset I2C1 - I2C1_CR1_SWRST
	I2C1->CR1 	&= ~(1 << 15);				// Out of reset - I2C1_CR1_SWRST
	
	// For CR2, CCR and TRISE registers calculations
	// http://tath.eu/projects/stm32/stm32-I2C1-calculating-clock-control-register/
	I2C1->CR2		= 42;       					// Peripheral clock is 42 MHz - APB1 Bus Speed
	I2C1->CCR		= 210;       					// Standard mode, 100kHz clock
	I2C1->TRISE = 43;        					// Maximum Rise Time
	
  I2C1->CR1 	|=  (1 <<  0);				// Peripheral Enable
	
}

// -----------------------------------------------------------------------------

void I2C1_Start_Condition(void)
{
	I2C1->CR1 |= (1 << 8);                    // Generate start for data send - I2C1_CR1_START
	while (!(I2C1->SR1 & I2C_SR1_SB));        // Wait until start flag is set 
}

// -----------------------------------------------------------------------------

void I2C1_Stop_Condition(void)
{
	I2C1->CR1 |= (1 << 9);										// Generate stop after data received  - I2C1_CR1_STOP
	while ((I2C1->SR1 & I2C_SR1_STOPF));    	// Wait until stop flag is clear 
}

// -----------------------------------------------------------------------------

uint8_t I2C1_ReadData(uint8_t slave_address, uint8_t device_register, uint16_t * data) 
{
    uint8_t ack = 0;
	
		while (I2C1->SR2 & I2C_SR2_BUSY);				// Wait until bus not busy
	
		I2C1_Start_Condition();									// Generate Start Condition

		I2C1->DR = (slave_address << 1);        // Write Slave Address + Write Bit
		while (!(I2C1->SR1 & I2C_SR1_ADDR));		// Wait until address flag is set
		ack = I2C1->SR2;                        // Get Acknowledge and clear address flag

		while (!(I2C1->SR1 & I2C_SR1_TXE));			// Wait until data register empty
		I2C1->DR = device_register;             // Write register address
		ack = I2C1->SR2;                        // Get Acknowledge and clear address flag

		while (!(I2C1->SR1 & I2C_SR1_TXE));			// Wait until data register empty
		while (!(I2C1->SR1 & I2C_SR1_BTF));			// Wait until byte transfer finished
	
	 // ==================================================================================
    
    I2C1_Start_Condition();									// Generate Start Condition
    
		I2C1->DR = ((slave_address << 1) | 1);	// Write Slave Address + Read Bit

    while (!(I2C1->SR1 & I2C_SR1_ADDR));		// Wait until address flag is set
    I2C1->CR1 &= ~(I2C_CR1_ACK);						// Disable Acknowledge
    ack = I2C1->SR2;                        // Get Acknowledge and clear address flag
	
    while(!(I2C1->SR1 & I2C_SR1_RXNE));    	// Wait until RXNE flag is set
    
		// Normally
		//*data++ = I2C1->DR;                     // Read data from DR register
		
		// For SHT21
		*data++ = ((I2C1->DR) << 8);
    *data++ += I2C1->DR;
		
		I2C1_Stop_Condition();										// Generate Stop Condition

    return ack;
}
