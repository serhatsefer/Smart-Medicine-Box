#ifndef SERVO
#define SERVO

#include "stm32f4xx_hal.h"

#define CLOSE_POS1			110
#define OPEN_POS1				85
	

#define CLOSE_POS2			100
#define OPEN_POS2				75

#define CLOSE_POS3			100
#define OPEN_POS3				75




void initServo(TIM_HandleTypeDef htim,int a);
void openCover(TIM_HandleTypeDef htim,int a);
void closeCover(TIM_HandleTypeDef htim,int a);





#endif
