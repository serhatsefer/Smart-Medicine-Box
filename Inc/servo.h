#ifndef SERVO
#define SERVO

#include "stm32f4xx_hal.h"

#define CLOSE_POS			113
#define OPEN_POS			25



void initServo(TIM_HandleTypeDef htim,int a);
void openCover(TIM_HandleTypeDef htim,int a);
void closeCover(TIM_HandleTypeDef htim,int a);





#endif
