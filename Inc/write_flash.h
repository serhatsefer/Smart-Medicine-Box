#ifndef STM32_FLASH_WRITE
#define STM32_FLASH_WRITE

#include "stm32f4xx.h"

void FLASH_WRITE(uint32_t Flash_Address,uint32_t Flash_Data);
uint32_t FLASH_READ(uint32_t Flash_Address);

#endif
