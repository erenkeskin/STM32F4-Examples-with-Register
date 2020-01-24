#ifndef _FLASH_H
#define _FLASH_H

#include <stdbool.h>
#include <stdint.h>

typedef uint32_t size_t;

#if !defined(FLASH_SECTOR_COUNT)
	#define FLASH_SECTOR_COUNT 12
#endif

#define FLASH_RETURN_SUCCESS        0
#define FLASH_RETURN_FAILED         1
#define FLASH_RETURN_NO_PERMISSION -1

#define FLASH_WaitWhileBusy() { while (FLASH->SR & FLASH_SR_BSY){} }

size_t FLASH_SectorSize(uint8_t sector);
bool FLASH_Unlock(void);
void FLASH_Lock(void);
bool FLASH_Erase(unsigned long sector);
void FLASH_Write(uint32_t address, uint8_t data);
bool FLASH_WriteBuffer(uint32_t address, const uint8_t *dataBuffer, size_t size);
bool FLASH_Read(uint32_t address, uint8_t *buffer, size_t size);

#endif /* FLASH_H */