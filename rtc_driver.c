#include"header.h"
//#include"DS1307.h"


void rtc_set_time(u8 hr,u8 min,u8 sec,u8 format)
{
	if(format == time_format_24hrs)
		hr=(hr&(~(1<<6)));
	else{
	  hr=hr|(1<<6);
	  hr=(format == time_format_12hrs_AM)?(hr&~(1<<5)):(hr|(1<<5));
		}

	i2c_byte_write_frame(0xD0,0x2,hr);//set hr
	i2c_byte_write_frame(0xD0,0x1,min);//set min
	i2c_byte_write_frame(0xD0,0x0,sec);//set sec
}

void rtc_read_time(u8 *time)
{
	u8 h,m,s;
	h=i2c_byte_read_frame(0xD0,0x2);//reading hr in hexadecimal
	m=i2c_byte_read_frame(0xD0,0x1);////reading min in hexadecimal
	s=i2c_byte_read_frame(0xD0,0x0);//reading sec in hexadecimal
	
	if(((h>>6)&1)!=0){
	if(((h>>5)&1) == time_format_12hrs_AM){
		time[9]='A';
   	} 
	else
	  time[9]='P';
  }
	else
		time[9]='\0';
	h=h&(~(1<<6));
	h=h&(~(1<<5));
	
	time[0]=(h/16)+48;//higher byte
	time[1]=(h%16)+48;//lower byte
	time[2]=':';
	
	time[3]=(m/16)+48;//higher byte
  time[4]=(m%16)+48;//lower byte
	time[5]=':';
	
	time[6]=(s/16)+48;//higher byte
	time[7]=(s%16)+48;//lower byte
	time[8]=' ';
	time[10]='\0';	
}
void rtc_set_date(u8 dt,u8 mn,u8 yr){
	i2c_byte_write_frame(0xD0,0x4,dt);//set hr
	i2c_byte_write_frame(0xD0,0x5,mn);//set min
	i2c_byte_write_frame(0xD0,0x6,yr);//set sec
	
}


//void rtc_read_date(u8 *time)
//{
//	u8 d,m,y;
//	d=i2c_byte_read_frame(0xD0,0x4);//reading day in hexadecimal
//	m=i2c_byte_read_frame(0xD0,0x5);////reading month in hexadecimal
//	y=i2c_byte_read_frame(0xD0,0x6);//reading year in hexadecimal
//	
//	time[0]=(d/16)+48;//higher byte
//	time[1]=(d%16)+48;//lower byte
//	time[2]='/';
//	
//	time[3]=(m/16)+48;//higher byte
//  time[4]=(m%16)+48;//lower byte
//	time[5]='/';
//	
//	time[6]=(y/16)+48;//higher byte
//	time[7]=(y%16)+48;//lower byte
//	time[8]='\0';	
//}

//void rtc_set_day(u8 day){
//	i2c_byte_write_frame(0xD0,0x3,day);//set day
//}
//u8 rtc_read_day(){
//	u8 d;
//	d=i2c_byte_read_frame(0xD0,0x3);//set day
//	return d;
//}