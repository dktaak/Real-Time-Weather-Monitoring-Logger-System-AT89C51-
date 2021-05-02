#include"header.h"
sbit R0=P1^0;

void main()
{
//	u8 sw;
	u8 result;
	lcd_init();
	while(1){
	//sw=keyscan();
		result=math();
	lcd_integer(result);
//	if((sw>=0)&&(sw<=9))
//	 lcd_data(sw+48);
//	else
//	 lcd_data(sw);
  }
}