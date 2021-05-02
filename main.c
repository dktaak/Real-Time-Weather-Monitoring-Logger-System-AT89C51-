#include"header.h"
#define adc_vtg (step*(time[11]))
#define adc_per (p*(time[12]))
extern delay(u16);
//u8 arr[12];
u8 time[17];

void main()
{
	//variable
	u8 c=0,i;u16 mr=0x0000;
  float step=5.0/4095;float p=100.0/4095;
	
	//intialisation
//	lcd_init();
//	lcd_cmd(0x0c);//cursur off
	uart_init(9600);
//	int0_enable();
  rtc_set_time(0x03,0x23,0x40,0);//hr,min,sec
  i2c_byte_set_ds1621();
	
		uart_tx_string("logid  time  POT  LDR  TEMP\r\n");
	
//	while(1)
//	{
//	for(i=1;mr=0x0000,c=0;mr<200;)
//	{
		 // time[0]=1;
			  rtc_read_time(time);
			time[11]=read_adc(0,0);
			time[12]=read_adc(0,1);
			time[13]=i2c_byte_read_ds1621();
			  time[14]='\0';
				
//				lcd_cmd(0x80);
//				lcd_string(time);
//				lcd_cmd(0xc0);
//				lcd_string("POT=");
//				lcd_float(adc_vtg);
//				lcd_cmd(0xca);
//				lcd_string("LDR=");
//				lcd_float(adc_per);
				
//				uart_tx_string(time);uart_tx(' ');
//				uart_float(adc_vtg);uart_tx(' ');
//				uart_float(adc_per);uart_tx(' ');
//				uart_int(time[13]);uart_tx(' ');
//				uart_tx_string(time);
			
//		mr+=c;
				c=i2c_byte_write_at24c512(0xA0,mr,time);
//        
//        uart_tx_string("\r\n");
//				
//				for(i=0;i<c+4;i++){
//				time[i]= i2c_byte_read_at24c512(0xA0,mr++);
//				}
//				time[i]='\0';			
//				
//			uart_tx_string(time);

while(1);
}