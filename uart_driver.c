/*uart intialisation and transmission*/
#include"header.h"

//u8 dec_to_bcd(u8 x){
//	u8 m,n;
//	m=x/10;
//	n=x%10;
//	x=((m<<4)|n);
//	return x;
//}
void uart_init(u16 baud)
{
	SCON=0X50;
	TMOD|=0X20;
	switch(baud)
	{
	case 7200:TH1=252;break;
	case 9600:TH1=253;break;
	case 14400:TH1=254;break;
	case 28800:TH1=255;break;
	case 57600:
	  TH1=255;PCON |=(1<<7);break;
  }
	TR1=1;
}

void uart_tx(u8 ch)
{
SBUF=ch;
while(TI==0);
TI=0;
}

//u8 uart_rx(void)
//{
//while(RI==0);
//	RI=0;
//return SBUF;
//}

void uart_tx_string(u8 *str)
{
	while(*str)
	{
//		if(*str>='0'&&*str<='9')
//			uart_tx(*str48);
		//else
		uart_tx(*str);
		str++;
	}
}

//void uart_rx_string(u8 *ptr,u8 max_len)
//{
//	u8 i;RI=0;
//	for(i=0;i<max_len;i++)
//	{
//		while(RI==0);
//		RI=0;//imp
//		ptr[i]=SBUF;
//		uart_tx(ptr[i]);
//	  if(ptr[i]==Enter_key){
//			ptr[i]='\0';
//		  break;
//		}
//	}
//	ptr[i]='\0';
//}
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


//void uart_int(s16 n)
//{
//	s8 i=0,a[10];
//	if(n<0){
//		uart_tx('-');
//		n=-n;
//	}
//	if(n==0)
//		uart_tx(48);
//	while(n)
//	{
//		a[i]=(n%10)+48;
//		n=n/10;
//		i++;
//	}
//	for(--i;i>=0;i--)
//	{
//		uart_tx(a[i]);
//	}	
//}
//void uart_float(float f){
//	long int ip,dp;
//	if(f<0){
//		uart_tx('-');
//		f=-f;
//	}
//	ip=f;
//	dp=(f-ip)*100;
//	uart_int(ip);
//	uart_tx('.');
//	uart_int(dp);
//	if(dp==0)
//	uart_tx(48);
//}
//void uart_tx_integer(u8 n)
//{
//	s8 i=0,j,a[3]={0,0,0};
//	while(n)
//	{
//		a[i]=(n%10)+48;
//		n=n/10;
//		i++;
//	}
//	for(j=i-1;j>=0;j--)
//	{
//		uart_tx(a[j]);
//	}	
//}
//void uart_rx_time(u8 *d)
//{
//uart_rx_string(d,10);

//d[0]=(((d[0]%48)<<4)|(d[1]%48));
//d[1]=(((d[3]%48)<<4)|(d[4]%48));
//d[2]=(((d[6]%48)<<4)|(d[7]%48));

//	if(d[9]=='A')
//	  d[3]=0;
//	else
//		d[3]=1;
//	
//	 d[4]='\0';
//}

//void uart_rx_date(u8 *d)
//{
//uart_rx_string(d,8);

//d[0]=(((d[0]%48)<<4)|(d[1]%48));
//d[1]=(((d[3]%48)<<4)|(d[4]%48));
//d[2]=(((d[6]%48)<<4)|(d[7]%48));
//   
//	 d[4]='\0';
//}