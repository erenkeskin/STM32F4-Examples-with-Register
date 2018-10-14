#include "System_Config.h"
#include "USART.h"
#include "I2C.h"
#include "SHT21.h"

// -----------------------------------------------------------------------------

int main(void)
{
	System_Clock_Config();
	SysTick_Init();
	
	SHT21_Init();	
	USART1_Init(115200);
	
	uint8_t ekran[100] = {0};
	
	float sicaklik = 0;
	float nem = 0;
	
	
	while(1)
	{
		sicaklik = SHT21_GetTemperature();
		nem = SHT21_GetHumidity();
		
		sprintf(ekran, "Sicaklik = %f\r\nNem = %f\r\n-----------------\r\n", sicaklik, nem);
		
		USART1_WriteString(ekran);
		
		Delay(1000000);
	}
	
	return 0;
}
