#include "write_flash.h"

void FLASH_WRITE(uint32_t Flash_Address,uint32_t Flash_Data)
{

	HAL_FLASH_Unlock();
	__HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR | FLASH_FLAG_PGAERR | FLASH_FLAG_PGSERR );
	FLASH_Erase_Sector(FLASH_SECTOR_11,VOLTAGE_RANGE_3);
	HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD,Flash_Address,Flash_Data);
	HAL_FLASH_Lock();
}

uint32_t FLASH_READ(uint32_t Flash_Address)
{
	uint32_t data;
	data = *(uint32_t*) Flash_Address;
	return data;
	
}
