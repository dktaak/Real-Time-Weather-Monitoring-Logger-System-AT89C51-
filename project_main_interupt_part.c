#include "header.h"
s8 start=0;bit flag=0;
int main()
{
	s8 i,j,u;u8 tp;
	u16 addr=0x0;s8 r[30];s16 temp;
	uart_init(9600);
	//int0_enable();
	rtc_set_time(0x11,0x58,0x40,0);//hr,min,sec
	i2c_byte_set_ds1621();
	delay(1000);
	
	while(1)
	{
		
		for(j=0,addr=0x0000;j<8;j++)
		{
		
			addr=(j*30);
//			if((j*30)%240==0)
//				addr+=16;
			
//			uart_int(j);uart_tx(' ');
//			uart_int(addr);uart_tx(' ');

			i=u=0;
			rtc_read_time(r);
			r[10]=' ';
			temp=i2c_byte_read_ds1621();
			uart_tx('\0');
			i=conv_int(temp,r+11);
		  u+=11+i;
			r[u]=' ';
			temp=read_adc(0,0);
			i=conv_float(adc_vtg,r+u+1);
		   u+=i;
			r[u]=' ';
			temp=read_adc(0,1);
			i=conv_float(adc_per,r+u+1);
		  u=u+1+i;
			r[u]='s';
			r[29]='s';
			for(i=0;;i++)
			{
				if(r[i]=='s')
					break;
				uart_tx(r[i]);
			}
			uart_tx_string("\r\n");
			
			i2c_byte_write_at24c512(0xA0,addr,r);
			delay(1000);
			
			start=j;					
		}
		flag=1;
  }
}

//				lcd_cmd(0x80);
//				lcd_string(&o.time);
//				lcd_cmd(0x8b);
//				lcd_string("temp=");
//			  lcd_int(o.tmp);
//				lcd_cmd(0xc0);
//				lcd_string("POT=");
//				lcd_float(adc_vtg);
//				lcd_cmd(0xca);
//				lcd_string("LDR=");
//				lcd_float(adc_per);


