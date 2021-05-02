#include"header.h"
extern delay(u16);
void main()
{
	u8 tx_ch;
	u8 temp='E';
	uart_init(9600);
	lcd_init();
	lcd_data('y');
	tx_ch=uart_rx();
	uart_tx(tx_ch);//loopback
	i2c_byte_write_frame(0xA0,0x2,tx_ch);
	delay(10);
	uart_tx_string("\r\npress any key\r\n");
	uart_rx();
	temp = i2c_byte_read_frame(0xA0,0x2);
		uart_tx_string("\r\n");
	uart_tx(temp);
	while(1);
}















/*
void main()
{	
	unsigned long int count=0;
	int0_enable();
	uart_init(9600);
	
	lcd_init();

	while(1)
	{
		count++;
		uart_tx_string("Vector\r\n");
	}
}
*/

/*
u8 arr[13];//13th bit_ for \0
           //global bec can be accessible in driver also
bit_ flag=0;//declare single bit_
u8 i;
void main()
{
  uart_init(9600);
	
	
	lcd_init();
	while(1)
	{
		uart_interrupt_enable();
		if(flag==1)
		{
			lcd_cmd(0x1);//clear lcd
		  lcd_string(arr);//print lcd rcved string
		  uart_tx_string(arr);//loopback
	    flag=0;//to make non bloking after 1st string print
		}
		//optional code_
	}
}

*/