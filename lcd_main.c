#include"header.h"
extern void delay(u16);
void main()
{
	lcd_init();
	
	lcd_int(12345678);
	lcd_cmd(0xc0);
	lcd_float(12345.6375);
	
	cgram_init();
	lcd_cmd(0x94);
	while(1){
	lcd_data(0);
		delay(500);
	lcd_cmd(0x94);//94-red line
	lcd_data(1);//D4-4th line
		delay(500);
		lcd_cmd(0x94);
	}
	//while(1);
}