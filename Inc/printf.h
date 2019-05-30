#ifndef _PRINTF_
#define _PRINTF_

#include <stdio.h>
#include <rt_misc.h>
#include <stdint.h>
#include "stm32f4xx_hal.h"

#pragma import(__use_no_semihosting_swi)

struct __FILE { int handle; };

extern FILE __stdout;
extern FILE __stdin;


int fputc(int ch, FILE *f);
void _sys_exit(int return_code);
#endif
