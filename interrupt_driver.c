#include"header.h"
extern void delay(u16);
//sbit led=P1^7;

void int0_enable(void)
{
	EA=EX0=1;
	IT0=1;//edge triggered
}
void int0_disable(void)
{
	EA=EX0=0;
	//IT0=1;//no matter
}


void int0_handler(void) interrupt 0
{
	u16 mr=0x0000;u8 time[12];u8 i;
	while(mr<200){
	for(i=0;i<10;i++){
	time[i] = i2c_byte_read_at24c512(0xA0,mr++);
	}
	time[i]='\0';
	uart_tx_string(time);
	uart_tx_string("\r\n");
}
	
	
//	led=~led;
//	lcd_string("SW pressed");
//	delay(1000);
//	lcd_cmd(0x1);
}


//void int0_handler(void) interrupt 0
//{
//	u8 a[15];
//	uart_rx_string(a,15);
//	lcd_string(a);
//}


/////////////////////////////////////////////////////////////

//void timer0_enable()
//{
//	TMOD=0x1;
//	TH0=0x3c;
//	TL0=0XB0;
//	EA=ET0=1;
//	TR0=1;
//}

//void timer0_handler(void) interrupt 1
//{
//  static char i;
//  TR0=0;
//	
//	i++;
//	if(i==20)
//	{
//		led=~led;
//		i=0;
//	}
//	TH0=0x3c;
//	TL0=0XB0;
//	TR0=1;
//}

////////////////////////////////////////////////////////
/*
void uart_interrupt_enable(void)
{
	ES=EA=1;
}
//void uart_interrupt_disable(void)
//{
//	ES=EA=0;
//}
extern u8 arr[20];
extern bit flag;//declare single bit_
//extern u8 i;

void uart_handler(void) interrupt 4//auto called by cpu; no need to declare prototype of isr
{
		//only x code_ here
		static u8 i=0;
		if(RI==1)//chking for any uart _interrupt
		{
			RI=0;//imp
			arr[i]=SBUF;
			uart_tx(arr[i]);
			i++;
			if((arr[i-1]==Enter_key))
			{
				arr[i-1]=0;
				i=0;
				flag=1;
			}
		else if((i==19))
			{
				i=0;
				arr[19]='\0';
				flag=1;
			}
		}
}
*/