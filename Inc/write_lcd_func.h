
#ifndef WRITE_LCD_FUNCTIONS
#define WRITE_LCD_FUNCTIONS

#include "ssd1306.h"
#include "esp8266.h"

void send_intro_lcd(void);
void send_connected_lcd(void);
void send_not_connected_lcd(void);
void send_ready_lcd(char*ip);
void send_wifi_disconnected(void);
void send_medicine_info(char*medicine,char*time,char*section);
#endif
