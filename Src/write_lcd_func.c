#include "write_lcd_func.h"
#include "ssd1306.h"
#include "esp8266.h"
#include <string.h>

char cache_ssid[100];
extern char* ip_buf,*ssid;

void send_intro_lcd(void){
		ssd1306_Init();
		ssd1306_Fill(Black);
    ssd1306_SetCursor(20, 0);
    ssd1306_WriteString("Gebze Technical", Font_7x10, White);
		ssd1306_SetCursor(20, 10);
    ssd1306_WriteString("University", Font_7x10, White);
		ssd1306_SetCursor(20, 30);
    ssd1306_WriteString("Electronics", Font_7x10, White);
		ssd1306_SetCursor(20, 40);
    ssd1306_WriteString("Engineering", Font_7x10, White);
		ssd1306_UpdateScreen();
		HAL_Delay(1000);
		
		ssd1306_Fill(Black);
		ssd1306_SetCursor(20, 0);
    ssd1306_WriteString("Embedded System", Font_7x10, White);
		ssd1306_SetCursor(20, 10);
    ssd1306_WriteString("Design", Font_7x10, White);
		ssd1306_SetCursor(10, 25);
		ssd1306_WriteString("The Final Project", Font_7x10, White);
		ssd1306_SetCursor(20, 40);
    ssd1306_WriteString("- 2019 -", Font_7x10, White);
		ssd1306_UpdateScreen();
		HAL_Delay(1000);
		ssd1306_Fill(Black);
		ssd1306_SetCursor(20, 30);
    ssd1306_WriteString("Initializing...", Font_7x10, White);
		ssd1306_UpdateScreen();
		strcat(cache_ssid,ssid);
	}

	
void send_connected_lcd(void)
{
	
		ssd1306_Fill(Black);
		ssd1306_SetCursor(10, 10);
		ssd1306_WriteString("Connected To", Font_7x10, White);
		ssd1306_SetCursor(10, 20);
		ssd1306_WriteString("WIFI!", Font_7x10, White);
		ssd1306_SetCursor(10, 30);
		ssd1306_WriteString("Can Connect To", Font_7x10, White);
		ssd1306_SetCursor(10, 40);
		ssd1306_WriteString("Device With", Font_7x10, White);
		ssd1306_SetCursor(10, 50);
		ssd1306_WriteString("AP Or Stat. Mode", Font_7x10, White);
		ssd1306_UpdateScreen();
	
}

void send_not_connected_lcd(void)
{

		ssd1306_Fill(Black);
		ssd1306_SetCursor(10, 10);
		ssd1306_WriteString("Not Connected", Font_7x10, White);
		ssd1306_SetCursor(15, 20);
		ssd1306_WriteString("To WIFI!", Font_7x10, White);
		ssd1306_SetCursor(10, 30);
		ssd1306_WriteString("Can Connect To", Font_7x10, White);
		ssd1306_SetCursor(15, 40);
		ssd1306_WriteString("Device With", Font_7x10, White);
		ssd1306_SetCursor(15, 50);
		ssd1306_WriteString("Only AP Mode", Font_7x10, White);
		ssd1306_UpdateScreen();
	
}

void send_ready_lcd(char*ip)
{
		extern int status_wifi;
	
		ssd1306_Fill(Black);
		ssd1306_SetCursor(10, 10);
    ssd1306_WriteString("Device Is Ready!", Font_7x10, White);
		ssd1306_SetCursor(10, 30);
		ssd1306_WriteString("WIFI:", Font_7x10, White);
		ssd1306_SetCursor(50, 30);

		if (status_wifi == 1){
		ssd1306_WriteString(cache_ssid, Font_7x10, White);
		ssd1306_SetCursor(5, 50);	
		ssd1306_WriteString("IP:", Font_7x10, White);
	  ssd1306_SetCursor(25, 50);
		ssd1306_WriteString(ip, Font_7x10, White);
		}
		else
		{
		ssd1306_WriteString("Not Connect", Font_7x10, White);
		ssd1306_SetCursor(10, 50);
		ssd1306_WriteString("Mode:AP", Font_7x10, White);
		}
		ssd1306_UpdateScreen();
}


void send_wifi_disconnected(void)
{
		ssd1306_Fill(Black);
		ssd1306_SetCursor(20, 10);
    ssd1306_WriteString("WIFI WAS", Font_7x10, White);
		ssd1306_SetCursor(35,20);
    ssd1306_WriteString("DISCONNECTED!", Font_7x10, White);
		ssd1306_SetCursor(20, 40);
    ssd1306_WriteString("Trying To", Font_7x10, White);
		ssd1306_SetCursor(35, 50);
    ssd1306_WriteString("Reconnect", Font_7x10, White);
		ssd1306_UpdateScreen();
	
}

void send_medicine_info(char*medicine,char*time,char*section){
		ssd1306_Fill(Black);
		ssd1306_SetCursor(5, 5);
    ssd1306_WriteString("Time Is UP!", Font_7x10, White);
		ssd1306_SetCursor(5,20);
		ssd1306_WriteString("Medicine:", Font_7x10, White);
		ssd1306_SetCursor(70,20);
		ssd1306_WriteString(medicine, Font_7x10, White);
		ssd1306_SetCursor(5, 35);
		ssd1306_WriteString("Time:", Font_7x10, White);
		ssd1306_SetCursor(40,35);
		ssd1306_WriteString(time, Font_7x10, White);
		ssd1306_SetCursor(5, 50);
		ssd1306_WriteString("Section:", Font_7x10, White);
		ssd1306_SetCursor(60,50);
		ssd1306_WriteString(section, Font_7x10, White);
		ssd1306_UpdateScreen();
		
		
}

