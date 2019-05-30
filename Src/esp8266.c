/*************************************  ESP8266 Kütüphanesi ************************************
 *                                     -> SOURCE FILE <-
 *
 *
 * 
 *		
 *
 *     ESP_Init() Fonksiyonu ESP8266'yi Hazirlar Ve WIFI Agina Baglanir.
 *     clear_rcvbuffer() Fonksiyonu Rx_Buffer'i Temizler.
 *     ESP_Read() Fonksiyonu Gelen HTTP Istegini Okur Ve Gelen Istege Göre LED yakar.
 *
 **/


// -- Gerekli Kütüphaneler Ve Degiskenler Eklendi. ---

#include "esp8266.h"

// --- Baglanilacak WIFI Aginin SSID Ve Sifresi ---
const char* ssid="Lenovo K6";
const char* pass="19962009";

// --- Daha Sonra Kullanilacak Degiskenler Tanimlandi. ---
char Rx_Buffer[RX_BUFFER_SIZE],buffer[TX_BUFFER_SIZE],veriuzunluk[4],Parser[RX_BUFFER_SIZE];
char ip_[RX_BUFFER_SIZE],ip_buf[15],medicine[100],time[10],section[5];
uint8_t Rx_data = '\0';
char *htmlcode,*read_ok,*stat,*reset,*login,*successful = "";
char *connection,*ip,*parse = "";
int status_wifi,last,uzunluk,check,Rx_indx= 0;
//-------------------------------------------

extern UART_HandleTypeDef huart2;
extern TIM_HandleTypeDef htim1;


// --- Gelen Datayi Okur Ve Geçici Buffer'a Atar. ---
void HAL_UART_RxCpltCallback(UART_HandleTypeDef*huart)
{	
	if (huart->Instance == USART2)
	{	
	
		if( (Rx_data != '\n') && (Rx_indx < RX_BUFFER_SIZE))
		{	
			Rx_Buffer[Rx_indx++] = Rx_data;
		}
		else
		{
			stat 	 = strstr(Rx_Buffer, "WIFI DISCONNECT");
			reset  = strstr(Rx_Buffer, "/reset HTTP/1.1");
			parse =  strstr(Rx_Buffer,"/send");
			ip = 		 strstr(Rx_Buffer,"STAIP");
			
			if(parse != NULL){
				strcpy(Parser,Rx_Buffer);
			}
			else if(ip != NULL){
				strcpy(ip_,Rx_Buffer);
			}
			
			Rx_Buffer[Rx_indx-1] = '\0';
			Rx_indx = 0;
		}

	}
	HAL_UART_Receive_IT(&huart2, &Rx_data, 1);
}




// --- Rx_Buffer'ini Temizler. ---
void clear_rcvbuffer(void)
{
	memset(Rx_Buffer,0,RX_BUFFER_SIZE);
	Rx_indx = 0;
}

char* Send_ESP(char*data,int delay)
{
	strcpy(buffer,data);
	strcat(buffer,"\r\n");
	uzunluk=strlen(buffer)+1;
	HAL_UART_Transmit_IT(&huart2, (uint8_t*) buffer, uzunluk+1);
	read_ok = strstr(Rx_Buffer, "OK");
	HAL_Delay(delay);
	
	return read_ok;
}

char* Send_ESP_Conc(char*data,int length,int delay)
{
	strcpy(buffer,data);
	sprintf(veriuzunluk, "%d",length);
	strcat(buffer,veriuzunluk);
	strcat(buffer, "\r\n");
	uzunluk = strlen(buffer)+1;
	HAL_UART_Transmit_IT(&huart2, (uint8_t*) buffer, uzunluk);
	read_ok = strstr(Rx_Buffer, "OK");
	HAL_Delay(delay);
	
	return read_ok;
}

char* Send_ESP_Connect(const char* ssid,const char* pass,int delay)
{
			strcpy(buffer, "AT+CWJAP=\"");
			strcat(buffer, ssid);
			strcat(buffer, "\",\"");
			strcat(buffer, pass);
			strcat(buffer, "\"\r\n");
			uzunluk = strlen(buffer);
			HAL_UART_Transmit_IT(&huart2, (uint8_t*) buffer, uzunluk);
			read_ok = strstr(Rx_Buffer, "OK");
			HAL_Delay(delay);
			return read_ok;
}

void Close_Connection(void){
	for (int i = 0 ; i < 5; i++){
		Send_ESP_Conc("AT+CIPCLOSE=",i,1000);
		}
}

char* Get_IP(void)
{
	int i = 0;
	char *p;
	Send_ESP("AT+CIFSR",1000);
	if (i == 0)
	{
		p = strtok(ip_,"\"");
		p = strtok(NULL,"\"");
		printf("IP:%s",p);
		sprintf(ip_buf,"%s",p);
		i = 1;
	}
	
	return ip_buf;
}	

/* ESP8266'yi Hazirlar Ve WIFI Agina Baglar.Eger WIFI SSID Ve Sifresi Daha Önce Tanimlanmamissa 
   ESP8266 HOTSPOT olarak yayin yapar ve kendi web arayüzü üzerinden WIFI'in SSID ve sifresi girilmesi istenir.
*/

	void ESP_Init(void)
{
	
	status_wifi=0;
	HAL_GPIO_WritePin(GPIOA,KirmiziLed1,GPIO_PIN_SET);
	
	
	// *********** ESP8266'yi Resetler. ***********	
	Send_ESP("AT+RST",1000);

	// ************ Otomatik Baglantiyi Devredisi Birak ****************
	while(Send_ESP("AT+CWAUTOCONN=0",1000) == NULL );
	clear_rcvbuffer();
	
	// *********** ESP8266'yi SoftAP + Station Moduna Ayarlar. ***********
	while(Send_ESP("AT+CWMODE=3",500) == NULL );
	clear_rcvbuffer();
	
	// *********** SSID Ve Sifresi Belirtilen WIFI Agina Baglanir. ***********
  // 				WIFI Agina Baglandiginda A Portunun 4.Pinindeki LED Yanar.
	int counter = 0;
	if(ssid != NULL && pass != NULL)
	{
		do
		{
				connection = Send_ESP_Connect(ssid,pass,7000);
	  		counter++;
			if (connection != NULL){
				status_wifi = 1;
				send_connected_lcd();
				HAL_GPIO_WritePin(GPIOA,KirmiziLed1,GPIO_PIN_RESET);
			}
			if (counter == 5){
				status_wifi = 0;
				send_not_connected_lcd();
				HAL_GPIO_WritePin(GPIOA,KirmiziLed1,GPIO_PIN_SET);
			
				break;
			}
		} while (connection == NULL) ;		
	}
	
	clear_rcvbuffer();
	

	
	// *********** ESP8266'nin AP Modunun WIFI Adini Ve Sifresini Ayarlar. ***********
	while(Send_ESP("AT+CWSAP_DEF=\"MedicineBox\",\"testtest\",5,4",500) == NULL);
	clear_rcvbuffer();
	// *********** Baglanilan Agdan Alinan IP Adresini Gösterir. ***********
	Get_IP();
	clear_rcvbuffer();
	// *********** Çoklu Baglantilara Izin Verir. ***********
	while(Send_ESP("AT+CIPMUX=1",500) == NULL);
	clear_rcvbuffer();
	// *********** WIFI Agi Tarafindan ESP8266'ya Verilen IP Adresinin 80.Portuna Server Kurar. ***********
	while(Send_ESP("AT+CIPSERVER=1,80",500) == NULL);
	clear_rcvbuffer();
	// *********** TCP Modunda Maksimum Baglanti Suresini Ayarlar ***********
	while(Send_ESP("AT+CIPSTO=5000",500) == NULL);
	clear_rcvbuffer();
	send_ready_lcd(ip_buf);
	//  *********** LCD'ye Cihazin Hazir Oldugunu Yazdirir. ***********
	
}
	
	// ***************************************************************************

// ESP8266'ye Gelen Verileri Okur.

void ESP_Read(void)
{

	if (parse != NULL)
	{
		check = 1;
		HAL_GPIO_WritePin(GPIOA,KirmiziLed1,GPIO_PIN_SET);
	}


	// eger WIFI baglantisi koptuysa kirmizi ledleri yak ve aga tekrar baglanmaya çalis.
	else if(stat != NULL) {
		
		clear_rcvbuffer();
		status_wifi=0;
		send_wifi_disconnected();
		HAL_GPIO_WritePin(GPIOA,KirmiziLed1,GPIO_PIN_SET);
		ESP_Init();
	}


	 else if(reset != NULL)
	{

		HAL_GPIO_WritePin(GPIOA, BeyazLed1 | BeyazLed2 |  MaviLed1 | MaviLed2 | KirmiziLed2, GPIO_PIN_RESET); 
		uzunluk = strlen(reset_msg);
		Send_ESP_Conc("AT+CIPSEND=0,",uzunluk,100);
		Send_ESP((char*)reset_msg,200);

		while(Send_ESP("AT+CIPCLOSE=5",20) == NULL);
		HAL_Delay(1000);
		NVIC_SystemReset();
	}		

	else if(login != NULL)
	{
		HAL_GPIO_WritePin(GPIOA, BeyazLed2 | MaviLed1 | MaviLed2 | BeyazLed1, GPIO_PIN_RESET); 
		ESP_Login();
	}


			
	if(check == 1){
		char*token;
		//send_intro_lcd();
		uzunluk = strlen(send_msg);
		Send_ESP_Conc("AT+CIPSEND=0,",uzunluk,100);
		Send_ESP((char*)send_msg,200);

		while(Send_ESP("AT+CIPCLOSE=5",20) == NULL);
		HAL_Delay(1000);
		
		token = strtok(Parser,"-");
		token = strtok(NULL,"-");
		printf("%s",token);
		strcpy(medicine,token);
		
		token = strtok(NULL,"-");
		printf("%s",token);
		strcpy(time,token);
		
				
		token = strtok(NULL,"-");
		printf("%s",token);
		strcpy(section,token);
		HAL_Delay(1000);
		send_medicine_info(medicine,time,section);
		check = 0;
		
		if(strncmp(section,"1",1) == 0 ){
			HAL_GPIO_WritePin(GPIOD,GPIO_PIN_11,GPIO_PIN_SET);
			openCover(htim1,1);
			HAL_Delay(1000);
			closeCover(htim1,1);
			HAL_GPIO_WritePin(GPIOD,GPIO_PIN_11,GPIO_PIN_RESET);
		}
		else if (strncmp(section,"2",1) == 0 ){
			openCover(htim1,2);
			HAL_Delay(1000);
			closeCover(htim1,2);
		}
		else if (strncmp(section,"3",1) == 0 ){
			openCover(htim1,3);
			HAL_Delay(1000);
			closeCover(htim1,3);
		}
		// buzzeri calistir.
		for (int i = 0;i<8;i++)
		{
			HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_0);
			HAL_Delay(500);
		}
			HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_0);
			HAL_Delay(1000);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_RESET);
			send_ready_lcd(ip_buf);
	}

//-------------------- ESP_Read() Fonksiyon Sonu --------------------
}

// --- WIFI Agina Baglanmak Icin WIFI SSID Ve Sifresinin Girildigi Bir HTML Arayüzü Olusturur. ---

void ESP_Login(void)
{
	uzunluk = strlen(login_msg);
	
		Send_ESP_Conc("AT+CIPSEND=0,",uzunluk,300);
	
		Send_ESP((char*)login_msg,1000);
	do{
		clear_rcvbuffer();
	}
	while(Send_ESP("AT+CIPCLOSE=5",100) == NULL);
	clear_rcvbuffer();
	// *********** WIFI Agi Tarafindan ESP8266'ya Verilen IP Adresinin 80.Portuna Server Kurar. ***********
	do{
		clear_rcvbuffer();
	}
	while(Send_ESP("AT+CIPSERVER=1,80",500) == NULL);
	clear_rcvbuffer();

}


void ESP_TCP(void){

	htmlcode="\
	GET /writedata.php HTTP/1.0 \r\n\
	Host: esp8266.rf.gd\r\n\
	Accept: */*\r\n\
	Content-Type: application/x-www-form-urlencoded\r\n\
	Content-Length: 32\r\n\r\n\
	?n=ayse&s=yilmaz&m=test2&t=104050\
		";

	Send_ESP("AT+CIPSTART=1,\"TCP\",\"esp8266.rf.gd\",80",100);

	uzunluk = strlen(htmlcode);
	
	Send_ESP_Conc("AT+CIPSEND=1,",uzunluk,10);
	
	Send_ESP(htmlcode,2000);

	Close_Connection();


}



