#ifndef __RTC__
#define __RTC__

#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_rtc.h"
#include "stdio.h"

#define HOUR 					00
#define MINUTE				16
#define SECOND				10

#define DATE					21
#define MONTH					((uint8_t)0x05)		// May
#define YEAR					19								// 2019
#define WEEKDAY				((uint8_t)0x06)		// Saturday

void RTC_Init(RTC_HandleTypeDef hrtc,RTC_TimeTypeDef sTime,RTC_DateTypeDef sDate);
void ReadTimeNDate(RTC_HandleTypeDef hrtc);
#endif
