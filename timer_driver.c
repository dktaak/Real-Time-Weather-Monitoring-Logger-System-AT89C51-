#include"header.h"
#include<intrins.h>
void timer_delay_1ms(void){
	
  TMOD=0X1;//0000 0001=>TIMER0 MODE 1
	TL0=0x18+2+13;//65536-1000=>645536(1MS=1000us)(12CLK=1 COUNT SWITCH=1mc)
	TH0=0XFC;
	TR0=1;
	while(TF0==0);//2 extra mc to chk for fail condition
	TR0=0;
	TF0=0;
	_nop_;
}
void timer_delay_50ms(void){
	
  TMOD=0X1;//0000 0001=>TIMER0 MODE 1
	TL0=0xc8+2+13;//65536-1000=>645536(1MS=1000us)(12CLK=1 COUNT SWITCH=1mc)
	TH0=0X38;
	TR0=1;
	while(TF0==0);//2 extra mc to chk for fail condition
	TR0=0;
	TF0=0;
	_nop_;
}