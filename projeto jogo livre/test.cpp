#include <TouchScreen.h>
#include <Elegoo_GFX.h>
#include <Elegoo_TFTLCD.h>

//definição de pinos analógicos
#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0
#define LCD_RESET A4

//definição das cores
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

//pinos analógicos
#define YP A2  
#define XM A3 
//pinos digitais
#define YM 8   
#define XP 9   

//uso de livrarias
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 400);
Elegoo_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

void setup{
	tft.reset();
	tft.begin(0x9341);
	tft.fillScreen(WHITE);
	tft.setRotation(1);
	
	Serial.begin(9600);

	tft.setCursor(60, 110);
	tft.setTextColor(BLACK);
	tft.setTextSize(5);
	tft.println("Test");
}

//fim do setup inicial



