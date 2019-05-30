#include "rtc.h"


char time[10],date[10] ;

void RTC_Init(RTC_HandleTypeDef hrtc,RTC_TimeTypeDef sTime,RTC_DateTypeDef sDate){
	sTime.Hours   			 = 	HOUR ; 
	sTime.Minutes 			 = 	MINUTE ;
	sTime.Seconds 			 =  SECOND;
	sTime.DayLightSaving =  RTC_DAYLIGHTSAVING_NONE;
	sTime.StoreOperation =  RTC_STOREOPERATION_RESET;
	
	HAL_RTC_SetTime(&hrtc,&sTime,RTC_FORMAT_BIN);
	
	sDate.Date			= DATE;
	sDate.Month			= MONTH;
	sDate.WeekDay   = RTC_WEEKDAY_SATURDAY;
	sDate.Year			= YEAR;
	HAL_RTC_SetDate(&hrtc,&sDate,RTC_FORMAT_BIN);
	
	HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR1, 0x32F2);

}

void ReadTimeNDate(RTC_HandleTypeDef hrtc){
	RTC_DateTypeDef gDate;
	RTC_TimeTypeDef gTime;
	
	HAL_RTC_GetTime(&hrtc,&gTime,RTC_FORMAT_BIN);
	HAL_RTC_GetDate(&hrtc,&gDate,RTC_FORMAT_BIN);
	
	
sprintf((char*)time,"%02d:%02d:%02d",gTime.Hours, gTime.Minutes, gTime.Seconds);
sprintf((char*)date,"%02d-%02d-%2d",gDate.Date, gDate.Month, 2000 + gDate.Year);


}
