#include<reg51.h>
#include<intrins.h>
#include"header.h"

sbit SDA=P2^4;
sbit SCL=P2^3;

void i2c_start(void)
{
	SCL=1;
	SDA=1;
	SDA=0;
}
void i2c_stop(void)
{
	SCL=0;
	SDA=0;
	SCL=1;
	SDA=1;
}
void i2c_write(u8 byte)
{
	s8 i;
	
	for(i=7;i>=0;i--)
	{
		SCL=0;
		SDA=((byte>>i)&1);
		SCL=1;
	}
}
u8 i2c_read(void)
{
	u8 temp=0;
	s8 i;
	
	for(i=7;i>=0;i--)
	{
		SCL=1;
		if(SDA==1)
		temp=temp|(1<<i);
		SCL=0;
	}
	return temp;
}
bit i2c_ack(void)
{
	SCL=0;
	SDA=1;
	SCL=1;
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	if(SDA==0)
	{
		SCL=0;//FOR NEXT OPERATION
		return 0;
	}
	else
	{
		SCL=0;
		return 1;
	}
}

void i2c_noack(void)
{
	SCL=0;
	SDA=1;
	SCL=1;
}
