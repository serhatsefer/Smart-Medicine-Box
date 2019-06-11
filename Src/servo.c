#include "servo.h"


void initServo(TIM_HandleTypeDef htim,int a)
{	
		switch (a){
		case 1:
			HAL_TIM_PWM_Start(&htim,TIM_CHANNEL_1);	
			break;
		case 2:
			HAL_TIM_PWM_Start(&htim,TIM_CHANNEL_2);	
			break;
		case 3:
			HAL_TIM_PWM_Start(&htim,TIM_CHANNEL_3);	
			break;
		case 4:
			HAL_TIM_PWM_Start(&htim,TIM_CHANNEL_4);	
			break;		
	}
	
}


void openCover(TIM_HandleTypeDef htim,int a)
{
	switch (a){
		case 1:
			htim.Instance->CCR1 = OPEN_POS1;
			break;
		case 2:
			htim.Instance->CCR2 = OPEN_POS2;
			break;
		case 3:
			htim.Instance->CCR3 = OPEN_POS3;
			break;
		case 4:
			htim.Instance->CCR4 = OPEN_POS1;
			break;		
	}
	HAL_Delay(1000);
}




void closeCover(TIM_HandleTypeDef htim,int a)
{
switch (a){
		case 1:
			htim.Instance->CCR1 = CLOSE_POS1;
			break;
		case 2:
			htim.Instance->CCR2 = CLOSE_POS2;
			break;
		case 3:
			htim.Instance->CCR3 = CLOSE_POS3;
			break;
		case 4:
			htim.Instance->CCR4 = CLOSE_POS1;
			break;		
	}
	HAL_Delay(1000);
}
