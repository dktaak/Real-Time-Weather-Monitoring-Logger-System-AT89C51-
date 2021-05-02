#include"header.h"
#include<intrins.h>
//void timer_delay_1ms(void){
//	
//  TMOD=0X1;//0000 0001=>TIMER0 MODE 1
//	TL0=0x18+2+13;//65536-1000=>645536(1MS=1000us)(12CLK=1 COUNT SWITCH=1mc)
//	TH0=0XFC;
//	TR0=1;
//	while(TF0==0);//2 extra mc to chk for fail condition
//	TR0=0;
//	_nop_();
//	TF0=0;

//}
void timer_delay_50ms(void){
	
  TMOD=0X1;//0000 0001=>TIMER0 MODE 1
	TL0=0xc8+2+13;//65536-1000=>645536(1MS=1000us)(12CLK=1 COUNT SWITCH=1mc)
	TH0=0X38;
	TR0=1;
	while(TF0==0);//2 extra mc to chk for fail condition
	TR0=0;
	TF0=0;
  _nop_();
}
//sbit c0=P3^4;
//void counter0(void){
//	unsigned int temp;
//  TMOD=0X5;//0000 0001=>counter0 MODE 1
//	TL0=0x0;//65536-1000=>645536(1MS=1000us)(12CLK=1 COUNT SWITCH=1mc)
//	TH0=0X0;
//	TR0=1;
//	while(TF0==0)//2 extra mc to chk for fail condition
//	{
//		temp=TH0*256+TL0;
//		lcd_cmd(0x1);
//		lcd_int(temp);
//		while(c0==1);
//	  while(c0==0);
//	}
//	TR0=0;
//	TF0=0;
//}
//sbit c1=P3^5;
//void counter1(void){
//	unsigned int temp;
//  TMOD=0X50;//0000 0001=>counter0 MODE 1
//	TL1=0x0;//65536-1000=>645536(1MS=1000us)(12CLK=1 COUNT SWITCH=1mc)
//	TH1=0X0;
//	TR1=1;
//	while(TF1==0)//2 extra mc to chk for fail condition
//	{
//		temp=TH1*256+TL1;
//		lcd_cmd(0x1);
//		lcd_int(temp);
//		while(c1==1);
//		while(c1==0);
//	}
//	TR1=0;
//	TF1=0;
//}