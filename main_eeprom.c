#include"header.h"
extern delay(u16);
void main()
{
	u8 d[5]={'D','I','N','E','S'};
	u8 temp,i;u16 mr=0x0000;
	uart_init(9600);
	lcd_init();

	i2c_byte_write_frame(0xA0,0x00,0x00,d);
	delay(10);
	for(i=0;i<5;i++){
	temp = i2c_byte_read_at24c512(0xA0,mr++);
	uart_tx(temp);
	}

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