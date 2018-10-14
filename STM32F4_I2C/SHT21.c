/************************************************************
*															*
*	HASAN EREN KESKIN										*
*	ELECTRICAL AND ELECTRONICS ENGINEERING STUDENT			*
*	herenkeskin@gmail.com									*
*	http://herenkeskin.com									*
*															*
*	SHT21 Library Functions									*
*	Versiyon: 0.1 											*
*															*
*	V0.1 - 14.10.2018										*
*															*
************************************************************/
#include "I2C.h"
#include "SHT21.h"

// -----------------------------------------------------------------------------

void SHT21_Init(void)
{
	I2C1_Init();
}

// -----------------------------------------------------------------------------

float SHT21_GetTemperature(void)
{
	uint16_t temperature_raw_data = 0;
	float temperature_data = 0;
	
  I2C1_ReadData(SHT21_I2C_ADDRESS, SHT21_TRIGGER_T_MEASUREMENT_HOLD_MASTER, &temperature_raw_data);
	
	temperature_data = (-46.85 + 175.72 / 65536.0 * (float)(temperature_raw_data));
	
	return temperature_data;
}

// -----------------------------------------------------------------------------

float SHT21_GetHumidity(void)
{
	uint16_t humidity_raw_data = 0;
	float humidity_data = 0;
	
	I2C1_ReadData(SHT21_I2C_ADDRESS, SHT21_TRIGGER_RH_MEASUREMENT_HOLD_MASTER, &humidity_raw_data);
	
	humidity_data = (-6.0 + 125.0 / 65536.0 * (float)(humidity_raw_data));
	
	return humidity_data;
}
