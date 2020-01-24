#include "stm32f4xx.h" // Device header
#include "flash.h"
#include <string.h>

//
size_t FLASH_SectorSize(uint8_t sector)
{
    if (sector >= 0 && sector <= 3) {
        return (16 * 1024);
    } else if (sector == 4) {
        return (64 * 1024);
    } else if (sector >= 5 && sector <= 11) {
        return (128 * 1024);
    }

    return 0;
}

//
bool FLASH_Unlock(void)
{
    /* Check if unlock is really needed */
    if (!(FLASH->CR & FLASH_CR_LOCK)) {
        return FLASH_RETURN_SUCCESS;
    }

    /* Write magic unlock sequence */
    FLASH->KEYR = 0x45670123;
    FLASH->KEYR = 0xCDEF89AB;

    /* Check if unlock was successful */
    if (FLASH->CR & FLASH_CR_LOCK) {
        return FLASH_RETURN_FAILED;
    }

    return FLASH_RETURN_SUCCESS;
}

//
void FLASH_Lock(void)
{
    FLASH->CR |= FLASH_CR_LOCK; // FLASH_CR_LOCK = 0x80000000;
}

//
bool FLASH_Erase(unsigned long sector)
{

    if (FLASH_Unlock() == FLASH_RETURN_FAILED) {
        return FLASH_RETURN_NO_PERMISSION;
    }

    FLASH_WaitWhileBusy();

    sector = sector & 0x0F;
    FLASH->CR |= FLASH_CR_SER;			// Sector Erase Flag
    FLASH->CR |= (sector << 3);			// Sector Number to SNB[3:0]
    FLASH->CR |= FLASH_CR_STRT;			// Sector Erase Start	

    FLASH_WaitWhileBusy();
		
    /* Sector erase flag does not clear automatically. */
    FLASH->CR &= ~FLASH_CR_SER;
		
    return FLASH_RETURN_SUCCESS;
}

//
void FLASH_Write(uint32_t address, uint8_t data)
{
    /* Enter flash programming mode */
    FLASH->CR |= FLASH_CR_PG;

    /* Write the data */
    *(uint8_t *)address = data;

    /* Wait for completion */
    FLASH_WaitWhileBusy();

    /* Exit flash programming mode */
    FLASH->CR &= ~FLASH_CR_PG;
}

//
bool FLASH_WriteBuffer(uint32_t address, const uint8_t * dataBuffer, size_t size)
{
		/* Unlock flash for write access */
    if (FLASH_Unlock() == FLASH_RETURN_FAILED) {
        return FLASH_RETURN_NO_PERMISSION;
    }

    /* Wait for any busy flags */
    FLASH_WaitWhileBusy();

    while (size >= sizeof(uint8_t)) {
        FLASH_Write(address, *(const uint8_t *)dataBuffer);
        address += sizeof(uint8_t);
        dataBuffer += sizeof(uint8_t);
        size -= sizeof(uint8_t);
    }

    return FLASH_RETURN_SUCCESS;
}

//
bool FLASH_Read(uint32_t address, uint8_t * buffer, size_t size) 
{
    memcpy(buffer, (uint8_t*) address, size);
    return FLASH_RETURN_SUCCESS;
}