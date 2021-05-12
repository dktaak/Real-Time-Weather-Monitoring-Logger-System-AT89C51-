#include "header.h"

int main()
{
  u32 temp;s8 r[12];
	lcd_init();
	lcd_cmd(0xc);
	rtc_set_time(0x11,0x58,0x40,0);//hr,min,sec
	i2c_byte_set_ds1621();
	delay(1000);
	
	lcd_string(" Shree Ganesh Namah");

	while(1)
	{
			rtc_read_time(r);
			lcd_cmd(0xc0);
			lcd_string(r);
			temp=i2c_byte_read_ds1621();
				lcd_cmd(0xcb);
		    lcd_string("TEMP=");
				lcd_int(temp);
			temp=read_adc(0,0);
		  conv_float(adc_vtg,r);
        lcd_cmd(0x94);
				lcd_string("POT=");
		    lcd_string(r);
			temp=read_adc(0,1);
				conv_float(adc_vtg,r);
				lcd_cmd(0x9f);
				lcd_string("LDR=");
        lcd_string(r);
	}
}
u8 conv_int(s16 n,s8* a)
{
	s8 i=0,k=0,j=0,temp=0;
//static u8 a[10];
	if(n==0)
	{
		a[i]=48;
		++i;
		goto l1;
	}
	if(n<0){
		n=-n;
		a[i++]='-';
		k++;
	}
	while(n)
	{
		a[i++]=(n%10)+48;
		n=n/10;
	}
	for(j=i-1;k<j;k++,j--)
	{
		temp=a[j];
		a[j]=a[k];
		a[k]=temp;
	}	
	l1:
	a[i]='\0';
	return i+1;
}
u8 conv_float(float f,u8* a){
	u8 ip,dp;u8 i=0;
	if(f<0){
		f=-f;
		a[i]='-';
	}
	ip=f;
	conv_int(ip,a);
	while(a[i++]);
	i--;
	a[i++]='.';
	dp=(f-ip)*100;
	conv_int(dp,a+i++);
	if(dp%10==0)
	{
		a[i++]=48;
	  a[i]='\0';
	}
	return i+1;
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


