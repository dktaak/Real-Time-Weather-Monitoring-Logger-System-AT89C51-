/*lcd program*/

#include"header.h"
sbit led0=P3^7;
sbit led1=P1^6;
sbit led2=P1^5;
//sbit led3=P1^4;
sbit sw1=P3^4;
sbit sw2=P3^3;
sbit sw3=P3^2;
sbit sw4=P3^1;

////void main(){
////u8 i;
////	while(1){
////	for(i=0;i<4;)
////		{
////			if(sw1==0){
////			while(sw1==0)
////			 P1=(P1|0xf0)&(~(0x10<<i));
////			i++;
////			}
////		}

////}	
//}


/*
void main(){
	
	while(1){
		P1=(P1&0x0f)&(0xf0|P3);
}
*/
/*
void main(){
	
	while(1){
   while(sw1==0&&sw2==0)		
		led0=1;
	 led0=0;
	}
}
*/

void main(){
	u8 k;
	//blink led till sw is pressed
	while(1){
//		if(sw1==0){
			led0=~led0;
			for(k=0;k<20;k++)
			  timer_delay_50ms();
//		}
//		else
//			led0=1;
	}
}


/*
void main(){
	while(1){
	  while(sw==1);
		led0=~led0;
		while(sw==0);
		
	}
}
*/
/*
void main()
{
	while(1){
	  while(sw==1);
		while(sw==0);
		led0=~led0;
}}
*/
/*
void main(){
	
	while(1){
		if(sw==0)
			led0=0;
		else
			led0=1;
	}
}
*/