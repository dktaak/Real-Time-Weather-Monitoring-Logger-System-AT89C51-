#ifndef DS1307_H_
#define DS1307_H_

/*Application configurable items*/

#define ds1307_addr_sec   0x00
#define ds1307_addr_min   0x01
#define ds1307_addr_hour  0x02
#define ds1307_addr_day   0x03
#define ds1307_addr_date  0x04
#define ds1307_addr_month 0x05
#define ds1307_addr_year  0x06

#define time_format_12hrs_AM  0
#define time_format_12hrs_PM  1
#define time_format_24hrs     2

#define ds1307_i2c_address  0x68

#define sunday    1
#define monday    2
#define tuesday   3
#define wednesday 4
#define friday    5
#define thursday  6
#define saturday  7

typedef struct
{
	u8 date;
	u8 year;
	u8 month;
	u8 day;
}rtc_date_t;

typedef struct
{
	u8 sec;
	u8 min;
	u8 hr;
	u8 time_format;
}rtc_time_t;

u8 DS1307_init(void); 

u8 ds1307_set_current_time(rtc_time_t*);
u8 ds1307_get_current_time(rtc_time_t*);

u8 ds1307_set_current_date(rtc_date_t*);
u8 ds1307_get_current_date(rtc_date_t*);

#endif /* DS1307 */