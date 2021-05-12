#include<reg51.h>
#include<intrins.h>   //For using [_nop_()]
//hello
////#define PORT0 0
////#define PORT1 1
////#define PORT2 2
////#define PORT3 3
////#define CLEAR 0
////#define SET 1
////#define Enter_key '\r'
#define adc_vtg ((5.0/4095)*(temp))
#define adc_per ((100.0/4095)*(temp))
#define time_format_12hrs_AM  0
#define time_format_12hrs_PM  1
#define time_format_24hrs     2


extern void delay(unsigned short int ms);
typedef unsigned long int u32;
typedef signed long int s32;
typedef unsigned char u8;
typedef unsigned short int u16;
typedef signed char s8;
typedef signed short int s16;

struct P
{
	u8 time[11];
	s8 tmp;
	u16 pot;
	u16 ldr;
	u8 stop;
};

//sbit led=P1^0;
//sbit led3=P3^0;
//string 
extern u8  mystrcmp(u8 *s1,u8 *s2);
extern void mystrcpy(u8 *p,u8 *q);
extern u8 mystrstr(u8 *s1,u8 *s2);
extern u8* mystrchr(u8 *s,u8 ch);
extern u8* mystrcat(u8 *s1,u8 *s2);

//keyboard
extern u8 keyscan(void);
extern u8 math(void);
//LCD

extern void lcd_cmd(u8);
extern void lcd_data(u8);
extern void lcd_init(void);
extern void lcd_string(u8 *);
extern void lcd_int(long int n);
extern void lcd_float(float);
extern void cgram_init();

//Timer
extern void timer_delay_1ms(void);
extern void timer_delay_50ms(void);
extern void counter0(void);
extern void counter1(void);

//UART
extern void uart_rx_string(u8*,u8);
extern void uart_tx_string(u8 *str);
extern u8 uart_rx(void);
extern void uart_tx(u8 ch);
extern void uart_init(u16 baud);
extern void uart_interrupt_enable(void);
extern void uart_interrupt_disable(void);
//extern void uart_tx_integer(u8);
extern void uart_int(s16);
extern void uart_float(float f);
extern u8 conv_int(s16 n,u8*);
extern u8 conv_float(float f,u8* a);

//_interrupt
extern void int0_disable(void);
extern void int0_enable(void);
extern void timer0_enable(void);
extern void uart_interrupt_enable(void);
extern void uart_interrupt_disable(void);

//I2C
extern void i2c_start(void);
extern void i2c_stop(void);
extern void i2c_write(u8);
extern u8 i2c_read(void);
extern bit i2c_ack(void);
extern void i2c_noack(void);

extern u8 i2c_byte_read_frame(u8 ,u8 );
extern void i2c_byte_write_frame(u8 ,u8 , u8);
//extern u8 i2c_byte_read_frame(u8 ,u8 ,u8);

extern void i2c_byte_write_at24c512(u8 sa,u16 mr,u8 *);
extern u8 i2c_byte_read_at24c512(u8 sa,u16 mr);
extern s8 i2c_byte_read_ds1621(void);
extern void i2c_byte_set_ds1621(void);
//rtc
extern void rtc_read_time(u8*);
extern void rtc_set_time(u8,u8,u8,u8);
extern void i2c_detect(void);
extern void rtc_read_date(u8*);
extern void rtc_set_date(u8,u8,u8);
extern void rtc_set_day(u8);
extern u8 rtc_read_day(void);
extern void uart_rx_time(u8*);
extern void uart_rx_date(u8*);

//spi
extern u16 read_adc(bit d1,bit d0);