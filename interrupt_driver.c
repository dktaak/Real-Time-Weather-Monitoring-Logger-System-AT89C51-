#include"header.h"

extern s8 start;
extern bit flag;

void int0_enable(void)
{
	EA=EX0=1;
	IT0=1;//edge triggered
}

void int0_handler(void) interrupt 0
{
	u8 i,j;u8 tp;s8 q[5];
	u16 addr=0x0;
		uart_tx_string("\r\n\r\n");
		for(i=0,j=0,addr=0x0000;j<7;j++)
		{
			addr=(start*30);
//			if((j*30)%240==0)
//				addr+=16;
//			conv_int(j+1,q);uart_tx_string(q);
//			if(j+1<10)
//				uart_tx(' ');
////		  uart_tx(' ');

			for(i=0;i<30;i++)
			{
			tp=i2c_byte_read_at24c512(0xA0,addr+i);
				if(tp=='s')
					break;
				uart_tx(tp);
			}
			uart_tx_string("\r\n");
		start--;
		if((start<0)&&(flag==1))
			start=7;
		else if((start<0)&&(flag==0))
			break;
		}
					uart_tx_string("\r\n");
}
//			for(i=0;q[i];i++)
//				q[i]=i2c_byte_read_at24c512(0xA0,addr+i);
//      i--;
//			uart_tx_string(q);uart_tx(' ');
//			
//			 o.tmp=i2c_byte_read_at24c512(0xA0,addr+i++);
//			 conv_int(o.tmp,q);
//			uart_tx_string(q);uart_tx(' ');
//			if(o.tmp<10&&o.tmp>-10)
//				uart_tx(' ');
//			 
//			 o.pot=i2c_byte_read_at24c512(0xA0,addr+i++);
//			 o.pot=(o.pot<<8)|(i2c_byte_read_at24c512(0xA0,addr+i++));
//			 conv_float(adc_vtg,q);
//			uart_tx_string(q);uart_tx(' ');
//				
//			 o.ldr=i2c_byte_read_at24c512(0xA0,addr+i++);
//			 o.ldr=(o.ldr<<8)|(i2c_byte_read_at24c512(0xA0,addr+i++));
//			 conv_float(adc_per,q);
//			 uart_tx_string(q);
//				
//			uart_tx_string("\r\n");
//			
//}


//void int0_disable(void)
//{
//	EA=EX0=0;
//	//IT0=1;//no matter
//}
//	led=~led;
//	lcd_string("SW pressed");
//	delay(1000);
//	lcd_cmd(0x1);
//}


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
//extern u8 arr[20];
//extern bit flag;//declare single bit_
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
