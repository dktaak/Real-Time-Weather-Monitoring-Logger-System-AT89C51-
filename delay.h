#include<reg51.h>

#define PORT0 0
#define PORT1 1
#define PORT2 2
#define PORT3 3
#define CLEAR 0
#define SET 1
#define Enter_key '\r'
typedef unsigned long int u32;
typedef signed long int s32;
typedef unsigned char u8;
typedef unsigned short int u16;
typedef signed char s8;
typedef signed short int s16;

sbit led=P1^0;
sbit led3=P3^0;
//LCD

extern void lcd_cmd(u8);
extern void lcd_data(u8);
extern void lcd_init(void);
extern void lcd_string(u8 *);

//UART
extern void uart_rx_string(u8*,u8);
extern void uart_tx_string(u8 *str);
extern u8 uart_rx(void);
extern void uart_tx(u8 ch);
extern void uart_init(u16 baud);
extern void uart_interrupt_enable(void);
extern void uart_interrupt_disable(void);

//_interrupt
extern void int0_disable(void);
extern void int0_enable(void);

//timer
extern void timer0_enable(void);

//I2C
extern void i2c_start(void);
extern void i2c_stop(void);
extern void i2c_write(u8);
extern u8 i2c_read(void);
extern bit i2c_ack(void);
extern void i2c_noack(void);
extern u8 i2c_byte_read_frame(u8 ,u8 );
extern void i2c_byte_write_frame(u8 ,u8 , u8);

//rtc
extern void rtc_read(u8*);
extern void rtc_set(u8,u8,u8);