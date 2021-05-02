#include"header.h"

sbit clk=P1^4;
sbit din=P1^5;
sbit dout=P1^6;
sbit cs=P1^7;



u16 read_adc(bit d1,bit d0)
{
	u16 temp=0x0;
	s8 i;//important signed
	
	cs=0;
	
	clk=0; din=1; clk=1;//start 
	clk=0; din=1; clk=1;//sgl/dfl
	clk=0; din=1; clk=1;//D2;

	clk=0; din=d1; clk=1;//D1
	clk=0; din=d0; clk=1;//D0
	
	/*channel selection*/
	clk=0;clk=1;////analog sampling
	clk=0;clk=1;//null bit_ by slave to master
		
	//reading 12 bits
	for(i=11;i>=0;i--)
	{
		clk=0;
		
		if(dout==1)
			temp=temp|(1<<i);//reading 12 bits
		
		clk=1;
	}
	cs=1;
	return temp;
}