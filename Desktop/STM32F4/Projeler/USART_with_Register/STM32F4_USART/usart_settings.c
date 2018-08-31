#include "USART.h"

int main(void)
{
	
	System_Clock_Config();
	USART1_Init(115200);
	
	while(1)
	{
		USART1_WriteString("Eren Keskin\r\n");
		Delay_Ms(1000);
	}
	
	return 0;
}
