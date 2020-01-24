#include "stm32f4xx.h"                  // Device header
#include <string.h>
#include "flash.h"

#define APPLICATION_START_ADDRESS 	0x0800C000 	//	(FLASH_BASE+ 48*1024)

typedef void (*pFunction)(void);
void System_clockConfig(void);

const unsigned char app1[] =
{
0x68, 0x06, 0x00, 0x20, 0x0D, 0xC2, 0x00, 0x08, 0x15, 0xC2, 0x00, 0x08,
0x17, 0xC2, 0x00, 0x08, 0x19, 0xC2, 0x00, 0x08, 0x1B, 0xC2, 0x00, 0x08,
0x1D, 0xC2, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0xC2, 0x00, 0x08,
0x21, 0xC2, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x23, 0xC2, 0x00, 0x08,
0xC9, 0xC2, 0x00, 0x08, 0x27, 0xC2, 0x00, 0x08, 0x27, 0xC2, 0x00, 0x08,
0x27, 0xC2, 0x00, 0x08, 0x27, 0xC2, 0x00, 0x08, 0x27, 0xC2, 0x00, 0x08,
0x27, 0xC2, 0x00, 0x08, 0x27, 0xC2, 0x00, 0x08, 0x27, 0xC2, 0x00, 0x08,
0x27, 0xC2, 0x00, 0x08, 0x27, 0xC2, 0x00, 0x08, 0x27, 0xC2, 0x00, 0x08,
0x27, 0xC2, 0x00, 0x08, 0x27, 0xC2, 0x00, 0x08, 0x27, 0xC2, 0x00, 0x08,
0x27, 0xC2, 0x00, 0x08, 0x27, 0xC2, 0x00, 0x08, 0x27, 0xC2, 0x00, 0x08,
0x27, 0xC2, 0x00, 0x08, 0x27, 0xC2, 0x00, 0x08, 0x27, 0xC2, 0x00, 0x08,
0x27, 0xC2, 0x00, 0x08, 0x27, 0xC2, 0x00, 0x08, 0x27, 0xC2, 0x00, 0x08,
0x27, 0xC2, 0x00, 0x08, 0x27, 0xC2, 0x00, 0x08, 0x27, 0xC2, 0x00, 0x08,
0x27, 0xC2, 0x00, 0x08, 0x27, 0xC2, 0x00, 0x08, 0x27, 0xC2, 0x00, 0x08,
0x27, 0xC2, 0x00, 0x08, 0x27, 0xC2, 0x00, 0x08, 0x27, 0xC2, 0x00, 0x08,
0x27, 0xC2, 0x00, 0x08, 0x27, 0xC2, 0x00, 0x08, 0x27, 0xC2, 0x00, 0x08,
0x27, 0xC2, 0x00, 0x08, 0x27, 0xC2, 0x00, 0x08, 0x27, 0xC2, 0x00, 0x08,
0x27, 0xC2, 0x00, 0x08, 0x27, 0xC2, 0x00, 0x08, 0x27, 0xC2, 0x00, 0x08,
0x27, 0xC2, 0x00, 0x08, 0x27, 0xC2, 0x00, 0x08, 0x27, 0xC2, 0x00, 0x08,
0x27, 0xC2, 0x00, 0x08, 0x27, 0xC2, 0x00, 0x08, 0x27, 0xC2, 0x00, 0x08,
0x27, 0xC2, 0x00, 0x08, 0x27, 0xC2, 0x00, 0x08, 0x27, 0xC2, 0x00, 0x08,
0x27, 0xC2, 0x00, 0x08, 0x27, 0xC2, 0x00, 0x08, 0x27, 0xC2, 0x00, 0x08,
0x27, 0xC2, 0x00, 0x08, 0x27, 0xC2, 0x00, 0x08, 0x27, 0xC2, 0x00, 0x08,
0x27, 0xC2, 0x00, 0x08, 0x27, 0xC2, 0x00, 0x08, 0x27, 0xC2, 0x00, 0x08,
0x27, 0xC2, 0x00, 0x08, 0x27, 0xC2, 0x00, 0x08, 0x27, 0xC2, 0x00, 0x08,
0x27, 0xC2, 0x00, 0x08, 0x27, 0xC2, 0x00, 0x08, 0x27, 0xC2, 0x00, 0x08,
0x27, 0xC2, 0x00, 0x08, 0x27, 0xC2, 0x00, 0x08, 0x27, 0xC2, 0x00, 0x08,
0x27, 0xC2, 0x00, 0x08, 0x27, 0xC2, 0x00, 0x08, 0x27, 0xC2, 0x00, 0x08,
0x27, 0xC2, 0x00, 0x08, 0x27, 0xC2, 0x00, 0x08, 0x27, 0xC2, 0x00, 0x08,
0x27, 0xC2, 0x00, 0x08, 0x27, 0xC2, 0x00, 0x08, 0x27, 0xC2, 0x00, 0x08,
0x27, 0xC2, 0x00, 0x08, 0x27, 0xC2, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00,
0x27, 0xC2, 0x00, 0x08, 0x27, 0xC2, 0x00, 0x08, 0x00, 0xF0, 0x02, 0xF8,
0x00, 0xF0, 0x2E, 0xF8, 0x0A, 0xA0, 0x90, 0xE8, 0x00, 0x0C, 0x82, 0x44,
0x83, 0x44, 0xAA, 0xF1, 0x01, 0x07, 0xDA, 0x45, 0x01, 0xD1, 0x00, 0xF0,
0x23, 0xF8, 0xAF, 0xF2, 0x09, 0x0E, 0xBA, 0xE8, 0x0F, 0x00, 0x13, 0xF0,
0x01, 0x0F, 0x18, 0xBF, 0xFB, 0x1A, 0x43, 0xF0, 0x01, 0x03, 0x18, 0x47,
0xD8, 0x02, 0x00, 0x00, 0xE8, 0x02, 0x00, 0x00, 0x00, 0x23, 0x00, 0x24,
0x00, 0x25, 0x00, 0x26, 0x10, 0x3A, 0x28, 0xBF, 0x78, 0xC1, 0xFB, 0xD8,
0x52, 0x07, 0x28, 0xBF, 0x30, 0xC1, 0x48, 0xBF, 0x0B, 0x60, 0x70, 0x47,
0x1F, 0xB5, 0x00, 0xF0, 0x49, 0xF9, 0x1F, 0xBD, 0x10, 0xB5, 0x10, 0xBD,
0x00, 0xF0, 0x31, 0xF8, 0x11, 0x46, 0xFF, 0xF7, 0xF5, 0xFF, 0x00, 0xF0,
0xFD, 0xF8, 0x00, 0xF0, 0x4F, 0xF8, 0x03, 0xB4, 0xFF, 0xF7, 0xF2, 0xFF,
0x03, 0xBC, 0x00, 0xF0, 0x57, 0xF8, 0x00, 0x00, 0x09, 0x48, 0x80, 0x47,
0x09, 0x48, 0x00, 0x47, 0xFE, 0xE7, 0xFE, 0xE7, 0xFE, 0xE7, 0xFE, 0xE7,
0xFE, 0xE7, 0xFE, 0xE7, 0xFE, 0xE7, 0xFE, 0xE7, 0xFE, 0xE7, 0xFE, 0xE7,
0x04, 0x48, 0x05, 0x49, 0x05, 0x4A, 0x06, 0x4B, 0x70, 0x47, 0x00, 0x00,
0x09, 0xC3, 0x00, 0x08, 0x89, 0xC1, 0x00, 0x08, 0x68, 0x00, 0x00, 0x20,
0x68, 0x06, 0x00, 0x20, 0x68, 0x02, 0x00, 0x20, 0x68, 0x02, 0x00, 0x20,
0x70, 0x47, 0x70, 0x47, 0x70, 0x47, 0x75, 0x46, 0x00, 0xF0, 0x2C, 0xF8,
0xAE, 0x46, 0x05, 0x00, 0x69, 0x46, 0x53, 0x46, 0x20, 0xF0, 0x07, 0x00,
0x85, 0x46, 0x18, 0xB0, 0x20, 0xB5, 0xFF, 0xF7, 0xDD, 0xFF, 0xBD, 0xE8,
0x20, 0x40, 0x4F, 0xF0, 0x00, 0x06, 0x4F, 0xF0, 0x00, 0x07, 0x4F, 0xF0,
0x00, 0x08, 0x4F, 0xF0, 0x00, 0x0B, 0xAC, 0x46, 0xAC, 0xE8, 0xC0, 0x09,
0xAC, 0xE8, 0xC0, 0x09, 0xAC, 0xE8, 0xC0, 0x09, 0xAC, 0xE8, 0xC0, 0x09,
0x21, 0xF0, 0x07, 0x01, 0x8D, 0x46, 0x70, 0x47, 0x10, 0xB5, 0x04, 0x46,
0xAF, 0xF3, 0x00, 0x80, 0x20, 0x46, 0xBD, 0xE8, 0x10, 0x40, 0xFF, 0xF7,
0xA8, 0xBF, 0x00, 0x00, 0x00, 0x48, 0x70, 0x47, 0x00, 0x00, 0x00, 0x20,
0x01, 0x49, 0x18, 0x20, 0xAB, 0xBE, 0xFE, 0xE7, 0x26, 0x00, 0x02, 0x00,
0x70, 0x47, 0x00, 0x00, 0x6A, 0x48, 0x01, 0x68, 0x11, 0xB1, 0x01, 0x68,
0x01, 0x39, 0x01, 0x60, 0x70, 0x47, 0x00, 0xBF, 0x09, 0x48, 0x0A, 0x4A,
0x00, 0x21, 0x01, 0x60, 0x42, 0x60, 0x81, 0x60, 0x01, 0x68, 0x41, 0xF0,
0x04, 0x01, 0x01, 0x60, 0x01, 0x68, 0x41, 0xF0, 0x02, 0x01, 0x01, 0x60,
0x01, 0x68, 0x41, 0xF0, 0x01, 0x01, 0x01, 0x60, 0x70, 0x47, 0x00, 0xBF,
0x10, 0xE0, 0x00, 0xE0, 0x41, 0x90, 0x02, 0x00, 0x10, 0xB5, 0x0E, 0x48,
0x0E, 0x4C, 0xD0, 0xF8, 0x80, 0x10, 0x41, 0xF4, 0x70, 0x01, 0xC0, 0xF8,
0x80, 0x10, 0x35, 0x49, 0x0A, 0x68, 0x42, 0xF0, 0x01, 0x02, 0x0A, 0x60,
0x00, 0x22, 0x8A, 0x60, 0x0B, 0x68, 0x23, 0x40, 0x0B, 0x60, 0x07, 0x4B,
0x4B, 0x60, 0x0B, 0x68, 0x23, 0xF4, 0x80, 0x23, 0x0B, 0x60, 0xCA, 0x60,
0x04, 0x49, 0x01, 0x60, 0x10, 0xBD, 0x00, 0xBF, 0x08, 0xED, 0x00, 0xE0,
0xFF, 0xFF, 0xF6, 0xFE, 0x10, 0x30, 0x00, 0x24, 0x00, 0xC0, 0x00, 0x08,
0x26, 0x48, 0x81, 0x68, 0x41, 0xF4, 0xA0, 0x51, 0x81, 0x60, 0x81, 0x68,
0x41, 0xF4, 0x00, 0x41, 0x81, 0x60, 0x01, 0x68, 0x41, 0xF4, 0x80, 0x31,
0x01, 0x60, 0x01, 0x68, 0x11, 0xF4, 0x00, 0x3F, 0xFB, 0xD0, 0x00, 0x21,
0x41, 0x60, 0x41, 0x68, 0x41, 0xF0, 0x08, 0x01, 0x41, 0x60, 0x41, 0x68,
0x41, 0xF4, 0xA8, 0x41, 0x41, 0x60, 0x41, 0x68, 0x21, 0xF4, 0x40, 0x31,
0x41, 0x60, 0x41, 0x68, 0x41, 0xF4, 0x80, 0x01, 0x41, 0x60, 0x41, 0x68,
0x41, 0xF0, 0xE0, 0x61, 0x41, 0x60, 0x01, 0x68, 0x41, 0xF0, 0x80, 0x71,
0x01, 0x60, 0x01, 0x68, 0x11, 0xF0, 0x00, 0x7F, 0xFB, 0xD0, 0x00, 0x21,
0xC0, 0xF8, 0x00, 0x14, 0xD0, 0xF8, 0x00, 0x14, 0x41, 0xF0, 0x05, 0x01,
0xC0, 0xF8, 0x00, 0x14, 0xD0, 0xF8, 0x00, 0x14, 0x41, 0xF4, 0x00, 0x71,
0xC0, 0xF8, 0x00, 0x14, 0xD0, 0xF8, 0x00, 0x14, 0x41, 0xF4, 0x80, 0x61,
0xC0, 0xF8, 0x00, 0x14, 0x81, 0x68, 0x41, 0xF0, 0x02, 0x01, 0x81, 0x60,
0x81, 0x68, 0x01, 0xF0, 0x0F, 0x01, 0x0A, 0x29, 0xFA, 0xD1, 0x70, 0x47,
0x00, 0x38, 0x02, 0x40, 0x80, 0xB5, 0xFF, 0xF7, 0xAD, 0xFF, 0xFF, 0xF7,
0x6D, 0xFF, 0x1A, 0x48, 0x4F, 0xF4, 0x7A, 0x7C, 0x4F, 0xF4, 0xFA, 0x73,
0x01, 0x68, 0x41, 0xF0, 0x08, 0x01, 0x01, 0x60, 0x16, 0x49, 0xD1, 0xF8,
0x00, 0x2C, 0x22, 0xF0, 0x7F, 0x42, 0xC1, 0xF8, 0x00, 0x2C, 0xD1, 0xF8,
0x00, 0x2C, 0x42, 0xF0, 0xAA, 0x42, 0xC1, 0xF8, 0x00, 0x2C, 0x02, 0x68,
0x42, 0xF0, 0x01, 0x02, 0x02, 0x60, 0x08, 0x68, 0x20, 0xF0, 0x03, 0x00,
0x08, 0x60, 0x08, 0x68, 0x08, 0x60, 0x0C, 0x48, 0x0C, 0x49, 0x02, 0x68,
0x42, 0xF4, 0x00, 0x42, 0x02, 0x60, 0xC1, 0xF8, 0x00, 0xC0, 0x0A, 0x68,
0x00, 0x2A, 0xFC, 0xD1, 0x02, 0x68, 0x22, 0xF4, 0x00, 0x42, 0x02, 0x60,
0x0B, 0x60, 0x0A, 0x68, 0x00, 0x2A, 0xFC, 0xD1, 0xED, 0xE7, 0x00, 0xBF,
0x30, 0x38, 0x02, 0x40, 0x00, 0x00, 0x02, 0x40, 0x14, 0x0C, 0x02, 0x40,
0x60, 0x00, 0x00, 0x20, 0xF1, 0xEE, 0x10, 0x0A, 0x4F, 0xF6, 0xFF, 0x71,
0xC0, 0xF2, 0xC0, 0x31, 0x20, 0xEA, 0x01, 0x00, 0x40, 0xF0, 0x40, 0x70,
0xE1, 0xEE, 0x10, 0x0A, 0x70, 0x47, 0x00, 0x00, 0xA4, 0xC4, 0x00, 0x08,
0x00, 0x00, 0x00, 0x20, 0x68, 0x06, 0x00, 0x00, 0xC4, 0xC1, 0x00, 0x08,
};

const unsigned char app2[] =
{
0x68, 0x06, 0x00, 0x20, 0x0D, 0x82, 0x01, 0x08, 0x15, 0x82, 0x01, 0x08,
0x17, 0x82, 0x01, 0x08, 0x19, 0x82, 0x01, 0x08, 0x1B, 0x82, 0x01, 0x08,
0x1D, 0x82, 0x01, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x82, 0x01, 0x08,
0x21, 0x82, 0x01, 0x08, 0x00, 0x00, 0x00, 0x00, 0x23, 0x82, 0x01, 0x08,
0xC9, 0x82, 0x01, 0x08, 0x27, 0x82, 0x01, 0x08, 0x27, 0x82, 0x01, 0x08,
0x27, 0x82, 0x01, 0x08, 0x27, 0x82, 0x01, 0x08, 0x27, 0x82, 0x01, 0x08,
0x27, 0x82, 0x01, 0x08, 0x27, 0x82, 0x01, 0x08, 0x27, 0x82, 0x01, 0x08,
0x27, 0x82, 0x01, 0x08, 0x27, 0x82, 0x01, 0x08, 0x27, 0x82, 0x01, 0x08,
0x27, 0x82, 0x01, 0x08, 0x27, 0x82, 0x01, 0x08, 0x27, 0x82, 0x01, 0x08,
0x27, 0x82, 0x01, 0x08, 0x27, 0x82, 0x01, 0x08, 0x27, 0x82, 0x01, 0x08,
0x27, 0x82, 0x01, 0x08, 0x27, 0x82, 0x01, 0x08, 0x27, 0x82, 0x01, 0x08,
0x27, 0x82, 0x01, 0x08, 0x27, 0x82, 0x01, 0x08, 0x27, 0x82, 0x01, 0x08,
0x27, 0x82, 0x01, 0x08, 0x27, 0x82, 0x01, 0x08, 0x27, 0x82, 0x01, 0x08,
0x27, 0x82, 0x01, 0x08, 0x27, 0x82, 0x01, 0x08, 0x27, 0x82, 0x01, 0x08,
0x27, 0x82, 0x01, 0x08, 0x27, 0x82, 0x01, 0x08, 0x27, 0x82, 0x01, 0x08,
0x27, 0x82, 0x01, 0x08, 0x27, 0x82, 0x01, 0x08, 0x27, 0x82, 0x01, 0x08,
0x27, 0x82, 0x01, 0x08, 0x27, 0x82, 0x01, 0x08, 0x27, 0x82, 0x01, 0x08,
0x27, 0x82, 0x01, 0x08, 0x27, 0x82, 0x01, 0x08, 0x27, 0x82, 0x01, 0x08,
0x27, 0x82, 0x01, 0x08, 0x27, 0x82, 0x01, 0x08, 0x27, 0x82, 0x01, 0x08,
0x27, 0x82, 0x01, 0x08, 0x27, 0x82, 0x01, 0x08, 0x27, 0x82, 0x01, 0x08,
0x27, 0x82, 0x01, 0x08, 0x27, 0x82, 0x01, 0x08, 0x27, 0x82, 0x01, 0x08,
0x27, 0x82, 0x01, 0x08, 0x27, 0x82, 0x01, 0x08, 0x27, 0x82, 0x01, 0x08,
0x27, 0x82, 0x01, 0x08, 0x27, 0x82, 0x01, 0x08, 0x27, 0x82, 0x01, 0x08,
0x27, 0x82, 0x01, 0x08, 0x27, 0x82, 0x01, 0x08, 0x27, 0x82, 0x01, 0x08,
0x27, 0x82, 0x01, 0x08, 0x27, 0x82, 0x01, 0x08, 0x27, 0x82, 0x01, 0x08,
0x27, 0x82, 0x01, 0x08, 0x27, 0x82, 0x01, 0x08, 0x27, 0x82, 0x01, 0x08,
0x27, 0x82, 0x01, 0x08, 0x27, 0x82, 0x01, 0x08, 0x27, 0x82, 0x01, 0x08,
0x27, 0x82, 0x01, 0x08, 0x27, 0x82, 0x01, 0x08, 0x27, 0x82, 0x01, 0x08,
0x27, 0x82, 0x01, 0x08, 0x27, 0x82, 0x01, 0x08, 0x27, 0x82, 0x01, 0x08,
0x27, 0x82, 0x01, 0x08, 0x27, 0x82, 0x01, 0x08, 0x27, 0x82, 0x01, 0x08,
0x27, 0x82, 0x01, 0x08, 0x27, 0x82, 0x01, 0x08, 0x00, 0x00, 0x00, 0x00,
0x27, 0x82, 0x01, 0x08, 0x27, 0x82, 0x01, 0x08, 0x00, 0xF0, 0x02, 0xF8,
0x00, 0xF0, 0x2E, 0xF8, 0x0A, 0xA0, 0x90, 0xE8, 0x00, 0x0C, 0x82, 0x44,
0x83, 0x44, 0xAA, 0xF1, 0x01, 0x07, 0xDA, 0x45, 0x01, 0xD1, 0x00, 0xF0,
0x23, 0xF8, 0xAF, 0xF2, 0x09, 0x0E, 0xBA, 0xE8, 0x0F, 0x00, 0x13, 0xF0,
0x01, 0x0F, 0x18, 0xBF, 0xFB, 0x1A, 0x43, 0xF0, 0x01, 0x03, 0x18, 0x47,
0xD8, 0x02, 0x00, 0x00, 0xE8, 0x02, 0x00, 0x00, 0x00, 0x23, 0x00, 0x24,
0x00, 0x25, 0x00, 0x26, 0x10, 0x3A, 0x28, 0xBF, 0x78, 0xC1, 0xFB, 0xD8,
0x52, 0x07, 0x28, 0xBF, 0x30, 0xC1, 0x48, 0xBF, 0x0B, 0x60, 0x70, 0x47,
0x1F, 0xB5, 0x00, 0xF0, 0x49, 0xF9, 0x1F, 0xBD, 0x10, 0xB5, 0x10, 0xBD,
0x00, 0xF0, 0x31, 0xF8, 0x11, 0x46, 0xFF, 0xF7, 0xF5, 0xFF, 0x00, 0xF0,
0xFD, 0xF8, 0x00, 0xF0, 0x4F, 0xF8, 0x03, 0xB4, 0xFF, 0xF7, 0xF2, 0xFF,
0x03, 0xBC, 0x00, 0xF0, 0x57, 0xF8, 0x00, 0x00, 0x09, 0x48, 0x80, 0x47,
0x09, 0x48, 0x00, 0x47, 0xFE, 0xE7, 0xFE, 0xE7, 0xFE, 0xE7, 0xFE, 0xE7,
0xFE, 0xE7, 0xFE, 0xE7, 0xFE, 0xE7, 0xFE, 0xE7, 0xFE, 0xE7, 0xFE, 0xE7,
0x04, 0x48, 0x05, 0x49, 0x05, 0x4A, 0x06, 0x4B, 0x70, 0x47, 0x00, 0x00,
0x09, 0x83, 0x01, 0x08, 0x89, 0x81, 0x01, 0x08, 0x68, 0x00, 0x00, 0x20,
0x68, 0x06, 0x00, 0x20, 0x68, 0x02, 0x00, 0x20, 0x68, 0x02, 0x00, 0x20,
0x70, 0x47, 0x70, 0x47, 0x70, 0x47, 0x75, 0x46, 0x00, 0xF0, 0x2C, 0xF8,
0xAE, 0x46, 0x05, 0x00, 0x69, 0x46, 0x53, 0x46, 0x20, 0xF0, 0x07, 0x00,
0x85, 0x46, 0x18, 0xB0, 0x20, 0xB5, 0xFF, 0xF7, 0xDD, 0xFF, 0xBD, 0xE8,
0x20, 0x40, 0x4F, 0xF0, 0x00, 0x06, 0x4F, 0xF0, 0x00, 0x07, 0x4F, 0xF0,
0x00, 0x08, 0x4F, 0xF0, 0x00, 0x0B, 0xAC, 0x46, 0xAC, 0xE8, 0xC0, 0x09,
0xAC, 0xE8, 0xC0, 0x09, 0xAC, 0xE8, 0xC0, 0x09, 0xAC, 0xE8, 0xC0, 0x09,
0x21, 0xF0, 0x07, 0x01, 0x8D, 0x46, 0x70, 0x47, 0x10, 0xB5, 0x04, 0x46,
0xAF, 0xF3, 0x00, 0x80, 0x20, 0x46, 0xBD, 0xE8, 0x10, 0x40, 0xFF, 0xF7,
0xA8, 0xBF, 0x00, 0x00, 0x00, 0x48, 0x70, 0x47, 0x00, 0x00, 0x00, 0x20,
0x01, 0x49, 0x18, 0x20, 0xAB, 0xBE, 0xFE, 0xE7, 0x26, 0x00, 0x02, 0x00,
0x70, 0x47, 0x00, 0x00, 0x6A, 0x48, 0x01, 0x68, 0x11, 0xB1, 0x01, 0x68,
0x01, 0x39, 0x01, 0x60, 0x70, 0x47, 0x00, 0xBF, 0x09, 0x48, 0x0A, 0x4A,
0x00, 0x21, 0x01, 0x60, 0x42, 0x60, 0x81, 0x60, 0x01, 0x68, 0x41, 0xF0,
0x04, 0x01, 0x01, 0x60, 0x01, 0x68, 0x41, 0xF0, 0x02, 0x01, 0x01, 0x60,
0x01, 0x68, 0x41, 0xF0, 0x01, 0x01, 0x01, 0x60, 0x70, 0x47, 0x00, 0xBF,
0x10, 0xE0, 0x00, 0xE0, 0x41, 0x90, 0x02, 0x00, 0x10, 0xB5, 0x0E, 0x48,
0x0E, 0x4C, 0xD0, 0xF8, 0x80, 0x10, 0x41, 0xF4, 0x70, 0x01, 0xC0, 0xF8,
0x80, 0x10, 0x35, 0x49, 0x0A, 0x68, 0x42, 0xF0, 0x01, 0x02, 0x0A, 0x60,
0x00, 0x22, 0x8A, 0x60, 0x0B, 0x68, 0x23, 0x40, 0x0B, 0x60, 0x07, 0x4B,
0x4B, 0x60, 0x0B, 0x68, 0x23, 0xF4, 0x80, 0x23, 0x0B, 0x60, 0xCA, 0x60,
0x04, 0x49, 0x01, 0x60, 0x10, 0xBD, 0x00, 0xBF, 0x08, 0xED, 0x00, 0xE0,
0xFF, 0xFF, 0xF6, 0xFE, 0x10, 0x30, 0x00, 0x24, 0x00, 0xC0, 0x00, 0x08,
0x26, 0x48, 0x81, 0x68, 0x41, 0xF4, 0xA0, 0x51, 0x81, 0x60, 0x81, 0x68,
0x41, 0xF4, 0x00, 0x41, 0x81, 0x60, 0x01, 0x68, 0x41, 0xF4, 0x80, 0x31,
0x01, 0x60, 0x01, 0x68, 0x11, 0xF4, 0x00, 0x3F, 0xFB, 0xD0, 0x00, 0x21,
0x41, 0x60, 0x41, 0x68, 0x41, 0xF0, 0x08, 0x01, 0x41, 0x60, 0x41, 0x68,
0x41, 0xF4, 0xA8, 0x41, 0x41, 0x60, 0x41, 0x68, 0x21, 0xF4, 0x40, 0x31,
0x41, 0x60, 0x41, 0x68, 0x41, 0xF4, 0x80, 0x01, 0x41, 0x60, 0x41, 0x68,
0x41, 0xF0, 0xE0, 0x61, 0x41, 0x60, 0x01, 0x68, 0x41, 0xF0, 0x80, 0x71,
0x01, 0x60, 0x01, 0x68, 0x11, 0xF0, 0x00, 0x7F, 0xFB, 0xD0, 0x00, 0x21,
0xC0, 0xF8, 0x00, 0x14, 0xD0, 0xF8, 0x00, 0x14, 0x41, 0xF0, 0x05, 0x01,
0xC0, 0xF8, 0x00, 0x14, 0xD0, 0xF8, 0x00, 0x14, 0x41, 0xF4, 0x00, 0x71,
0xC0, 0xF8, 0x00, 0x14, 0xD0, 0xF8, 0x00, 0x14, 0x41, 0xF4, 0x80, 0x61,
0xC0, 0xF8, 0x00, 0x14, 0x81, 0x68, 0x41, 0xF0, 0x02, 0x01, 0x81, 0x60,
0x81, 0x68, 0x01, 0xF0, 0x0F, 0x01, 0x0A, 0x29, 0xFA, 0xD1, 0x70, 0x47,
0x00, 0x38, 0x02, 0x40, 0x80, 0xB5, 0xFF, 0xF7, 0xAD, 0xFF, 0xFF, 0xF7,
0x6D, 0xFF, 0x1A, 0x48, 0x4F, 0xF4, 0x7A, 0x7C, 0x4F, 0xF4, 0xFA, 0x73,
0x01, 0x68, 0x41, 0xF0, 0x08, 0x01, 0x01, 0x60, 0x16, 0x49, 0xD1, 0xF8,
0x00, 0x2C, 0x22, 0xF0, 0x7F, 0x42, 0xC1, 0xF8, 0x00, 0x2C, 0xD1, 0xF8,
0x00, 0x2C, 0x42, 0xF0, 0xAA, 0x42, 0xC1, 0xF8, 0x00, 0x2C, 0x02, 0x68,
0x42, 0xF0, 0x01, 0x02, 0x02, 0x60, 0x08, 0x68, 0x20, 0xF0, 0x03, 0x00,
0x08, 0x60, 0x08, 0x68, 0x08, 0x60, 0x0C, 0x48, 0x0C, 0x49, 0x02, 0x68,
0x42, 0xF4, 0x00, 0x52, 0x02, 0x60, 0xC1, 0xF8, 0x00, 0xC0, 0x0A, 0x68,
0x00, 0x2A, 0xFC, 0xD1, 0x02, 0x68, 0x22, 0xF4, 0x00, 0x52, 0x02, 0x60,
0x0B, 0x60, 0x0A, 0x68, 0x00, 0x2A, 0xFC, 0xD1, 0xED, 0xE7, 0x00, 0xBF,
0x30, 0x38, 0x02, 0x40, 0x00, 0x00, 0x02, 0x40, 0x14, 0x0C, 0x02, 0x40,
0x60, 0x00, 0x00, 0x20, 0xF1, 0xEE, 0x10, 0x0A, 0x4F, 0xF6, 0xFF, 0x71,
0xC0, 0xF2, 0xC0, 0x31, 0x20, 0xEA, 0x01, 0x00, 0x40, 0xF0, 0x40, 0x70,
0xE1, 0xEE, 0x10, 0x0A, 0x70, 0x47, 0x00, 0x00, 0xA4, 0x84, 0x01, 0x08,
0x00, 0x00, 0x00, 0x20, 0x68, 0x06, 0x00, 0x00, 0xC4, 0x81, 0x01, 0x08,
};



#define sizeOfArray(array)	sizeof(array) / sizeof(array[0])
#define clearArray(array)		memset(array, 0, sizeof(array))
	
int main(void) 
{
	
	System_clockConfig();
	
	//uint8_t readData[sizeOfArray(app1)];
	
	FLASH_Unlock();	
	FLASH_Erase(3);
	
	// Button
	RCC->AHB1ENR |= (1 << 0);
	GPIOA->MODER &= 0xFFFFFFFC;
	GPIOA->MODER |= 0x00000000;
	
	if (GPIOA->IDR & 0x00000001) {
		FLASH_WriteBuffer(APPLICATION_START_ADDRESS, app2, sizeOfArray(app2));
		//FLASH_Read(APPLICATION_START_ADDRESS, readData, sizeOfArray(app2));
	} else {
		FLASH_WriteBuffer(APPLICATION_START_ADDRESS, app1, sizeOfArray(app1));
		//FLASH_Read(APPLICATION_START_ADDRESS, readData, sizeOfArray(app1));
	}
	
	FLASH_Lock();
	
	pFunction Jump_To_Application = *( (pFunction*) (APPLICATION_START_ADDRESS + 4) );
	
	__set_CONTROL(0);
	
	SysTick->CTRL = 0;
	
	SCB->VTOR = APPLICATION_START_ADDRESS;
	__set_MSP( *( (uint32_t*) APPLICATION_START_ADDRESS ) );
	Jump_To_Application();
	
	return 0;
}

void System_clockConfig(void)
{	
	
	// Prescaler Configrations
	RCC->CFGR 	|= (5 << 10);					// APB1 Prescaler = 4
	RCC->CFGR 	|= (4 << 13);					// APB2 Prescaler = 2

	RCC->CR 	|= (1 << 16);						// HSE Clock Enable - HSEON
	while(!(RCC->CR & 0x00020000));		// Wait until HSE Clock Ready - HSERDY

	// PLL Configrations
	RCC->PLLCFGR = 0;									// Clear all PLLCFGR register
	RCC->PLLCFGR |=  (8		<<  0);			// PLLM = 8;
	RCC->PLLCFGR |=  (336 	<<  6);		// PLLN = 336;
	RCC->PLLCFGR &= ~(3 	<< 16);			// PLLP = 2; // For 2, Write 0
	RCC->PLLCFGR |=  (1 	<< 22);			// HSE Oscillator clock select as PLL
	RCC->PLLCFGR |=  (7 	<< 24);			// PLLQ = 7;

	RCC->CR 		|=  (1 		<< 24); 		// PLL Clock Enable - PLLON
	while(!(RCC->CR & 0x02000000)); 	// Wait until PLL Clock Ready - PLLRDY

	// Flash Configrations
	FLASH->ACR = 0;										// Clear all ACR register (Access Control Register)
	FLASH->ACR 		|= (5 <<  0); 			// Latency - 5 Wait State
	FLASH->ACR 		|= (1 <<  9);				// Instruction Cache Enable
	FLASH->ACR 		|= (1 << 10);				// Data Cache Enable

	RCC->CFGR 		|= (2 <<  0);				// PLL Selected as System Clock
	while((RCC->CFGR & 0x0F) != 0x0A); // Wait PLL On

}    