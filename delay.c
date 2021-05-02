/*delay.h*/
void delay(unsigned short int ms)
{
unsigned char ch;
	for(;ms>1;ms--)
	{
		for(ch=100;ch>2;ch--);
		ch++;
	}
	for(ch=97;ch>0;ch--);
	ch=4;
	while(--ch);
}
/*
/////////by manu sir
typedef unsigned short int u16;
typedef unsigned char u8;
void delay(u16 ms)
{
	u8 i;
	for(;ms>0;ms--)
	{
	for(i=250;i>0;i--);
		for(i=247;i>0;i--);
	}
}
*/