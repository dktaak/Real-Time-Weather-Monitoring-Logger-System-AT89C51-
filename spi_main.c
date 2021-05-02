#include"header.h"
#define adc_vtg (step*adc_value)
#define adc_per (p*adc_value)

//#define adc_per(adc_value) (p*adc_value)

void main()
{
	u16 adc_value;float step=5.0/4095;float p=100.0/4095;
	lcd_init();
	uart_init(9600);
	
	while(1)
	{
		/*channel 0*/
		adc_value=read_adc(0,0);
		lcd_cmd(0xc0);
		lcd_string("POT=");
		lcd_float(adc_vtg);
		lcd_data(' ');
		uart_tx_string("CH0=");
		uart_float(adc_vtg);
		uart_tx_string("\r\n");
		
//		/*channel 1*/
//		adc_value=read_adc(0,1);
////	lcd_cmd(0x1);
//		lcd_string("CH1=");
//		lcd_float(adc_vtg);
////  lcd_data(' ');
//		uart_tx_string("CH1=");
//		uart_float(adc_vtg);
//		uart_tx_string("\r\n");
		
//				/*channel 2*/
//		adc_value=read_adc(1,0);
//  	lcd_cmd(0xc0);
//		lcd_string("CH2=");
//		lcd_float(adc_per);
//    lcd_data(' ');
//		uart_tx_string("CH2=");
//		uart_float(adc_per);
//		uart_tx_string("\r\n");
//		
//				/*channel 3*/
//		adc_value=read_adc(1,1);
////	lcd_cmd(0x1);
//		lcd_string("CH3=");
//		lcd_float(adc_per);
////  lcd_data(' ');
//		uart_tx_string("CH3=");
//		uart_float(adc_per);
//		uart_tx_string("\r\n\r\n");
	}
	
}