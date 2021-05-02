#include"header.h"
#include"DS1307.h"

u8 arr[12];
void main()
{
u8 time[12];
lcd_init();
//lcd_cmd(0x0c);
uart_init(9600);

//i2c_detect();
//	uart_tx_string("\r\nEnter Date Format(18/07/93)\r\n");
//  uart_rx_date(arr);
//  rtc_set_date(arr[0],arr[1],arr[2]);//date,mn,yr
	
	
//uart_tx_string("\r\nEnter Time Format(11;07;59 A/P)\r\n");
//uart_rx_time(arr);

//rtc_set_time(arr[0],arr[1],arr[2],arr[3]);//hr,min,sec
//uart_tx_string("\r\n");
//rtc_set_time(0x11,0x23,0x40,0);//hr,min,sec
//delay(100);

//rtc_set_date(0x18,0x07,0x93);
//rtc_set_day(friday);
//uart_tx_string("\r\n  Time        Date\r\n");
//while(1){

//rtc_read_time(time);
//lcd_cmd(0x80);
//lcd_string("Time ");
//lcd_string(time);
//uart_tx_string("\r\n");
//	
//uart_tx_string(time);
//uart_tx_string("  ");
//	
//rtc_read_date(time);
//lcd_cmd(0xC0);
//lcd_string("Date ");
//lcd_string(time);
////uart_tx_string("\r\n");
//	
//uart_tx_string(time);
//uart_tx_string("\r\n");
//	
//d=rtc_read_day();
//lcd_string(" ");
//uart_tx_string(" ");
//switch(d){
//case 1: lcd_string("SUN");
//        uart_tx_string("SUN");break;
//case 2: lcd_string("MON");
//		uart_tx_string("MON");break;
//case 3: lcd_string("TUE");
//		uart_tx_string("TUE");break;
//case 4: lcd_string("WED");
//		uart_tx_string("WED");break;
//case 5: lcd_string("THU");
//		uart_tx_string("THU");break;
//case 6: lcd_string("FRI");
//		uart_tx_string("FRI");break;
//case 7: lcd_string("SAT");
//		uart_tx_string("SAT");break;
//}
//}
}