#include"header.h"

#define lcd_port P0
extern delay(u16);
sbit RS=P2^0;
sbit RW=P2^1;
sbit EN=P2^2;

void lcd_cmd(u8 cmd)
{
	lcd_port=cmd;
	RS=0;
	RW=0;
	EN=1;
	delay(2);
	EN=0;
}
void lcd_data(u8 ch)
{
	lcd_port=ch;
	RS=1;
	RW=0;
	EN=1;
	delay(2);
	EN=0;
}
void lcd_init(void)
{
	lcd_cmd(0x02);//cursur move to home position
  lcd_cmd(0x38);//8 bit_ mode
	lcd_cmd(0x0E);//cursur on
	lcd_cmd(0x01);
}
void lcd_string(s8 *p)
{
	while(*p!='\0')
	{
//		if((*p)==Enter_key)
//			{
//			lcd_cmd(0xc0);
//				p++;
//		  }
		lcd_data(*p);
		p++;
	}
	
}

void lcd_int(signed long int n){
	signed long int i=0,a[16];
	if(n<0){
		lcd_data('-');
		n=-n;
	}
	if(n==0)
		lcd_data(48);
	while(n){
		a[i]=n%10;
		i++;
		n=n/10;
	}
	for(i=i-1;i>=0;i--){
		lcd_data(a[i]+48);
	}
}

void lcd_float(float f){
	long int ip,dp;
	if(f<0){
		lcd_data('-');
		f=-f;
	}
	ip=f;
	dp=(f-ip)*100;
	lcd_int(ip);
	lcd_data('.');
	lcd_int(dp);
}
//hello