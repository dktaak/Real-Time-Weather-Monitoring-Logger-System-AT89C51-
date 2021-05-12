#include"header.h"
bit v;u8 a[2]={0,0};
//extern delay(u16);

s8 i2c_byte_read_ds1621(void)
{
	
	u8 sa=0x90;
  u8 temp;
	i2c_start();//restart condition
	i2c_write(sa);//sa+w
	i2c_ack();
	i2c_write(0xAA);//init temp conv
	i2c_ack();

	i2c_start();//restart condition
	i2c_write(sa|0x1);//SA+R
	i2c_ack();
  temp=i2c_read();
	i2c_ack();
	i2c_stop();
	return temp;
}

void i2c_byte_set_ds1621(void)
{
	u8 sa=0x90;

	i2c_start();
	i2c_write(sa);//sa+w
	i2c_ack();
	i2c_write(0xAc);
	i2c_ack();
	i2c_write(0x02);
	i2c_ack();
	
	i2c_start();//restart condition
	i2c_write(sa);//sa+w
	i2c_ack();
	i2c_write(0xEE);//init temp conv
	i2c_ack();
	
	i2c_stop();
}

//void i2c_byte_write_at24c512(u8 sa,u16 mr,u8 *p)
//{
//	i2c_start();
//	i2c_write(sa);	
//	i2c_ack();
//	i2c_write((mr>>8)&0xFF);//first byte address
//	i2c_ack();
//	i2c_write(mr&0xFF);//second byte address
//	i2c_ack();
//	while(*p!='s')
//	{
//	i2c_write(*p);
//	i2c_ack();
//	p++;
//	}
//	i2c_write(*p);
//	i2c_ack();
//	delay(10);
//	i2c_stop();
//}


//u8 i2c_byte_read_at24c512(u8 sa,u16 mr)
//{
//	u8 temp;
//	i2c_start();
//	i2c_write(sa);
//	i2c_ack();
//	i2c_write((mr>>8)&0xFF);//first byte address
//	i2c_ack();
//	i2c_write(mr&0xFF);//second byte address
//	i2c_ack();
//	i2c_start();
//	i2c_write(sa|0x1);
//	i2c_ack();
//	temp=i2c_read();
//	i2c_ack();
//	//i2c_noack();
//	i2c_stop();
//	//delay(10);
//	return temp;
//}

//u8 i2c_byte_read_frame(u8 sa,u8 mrh,u8 mrl)
//{
//	u8 i=0;
//   u8 temp;
//	i2c_start();
//	
//	i2c_write(sa);
//		v=i2c_ack();
//	
//	i2c_write(mrh);
//		v=i2c_ack();
//	
//	i2c_write(mrl);
//		v=i2c_ack();
//	
//	i2c_start();
//	i2c_write(sa|1);//sa+R
//		v=i2c_ack();

//	temp=i2c_read();

//	//temp[5]='\0';
//	i2c_noack();
//	i2c_stop();
//	return temp;
//}
void i2c_byte_write_frame(u8 sa,u8 mr, u8 d)
{
	
			i2c_start();
			i2c_write(sa);
			v=i2c_ack();

			i2c_write(mr);
			v=i2c_ack();

			i2c_write(d);
			v=i2c_ack();
//
			i2c_stop();
}
u8 i2c_byte_read_frame(u8 sa,u8 mr)
{
			u8 temp;
			i2c_start();
			i2c_write(sa);
			v=i2c_ack();

			i2c_write(mr);
			v=i2c_ack();

			i2c_start();
			i2c_write(sa|1);//sa+R
			v=i2c_ack();

			temp=i2c_read();
			i2c_noack();
			i2c_stop();
	delay(10);
			return temp;
}
//void uart_tx_hexa(u8 n){
//		s8 r,i=1;
//		while(n)
//		{
//			r=n%16;
//			if(r>9)
//				a[i]=r+55;
//			else 
//				a[i]=r+48;
//			i--;
//			n=n/16;
//		}
//		for(i=0;i<2;i++)
//		 uart_tx(a[i]);
//}

//void i2c_detect(void){
//	u8 sa,temp;
//	u32 c=0;
////	memset(a,0,sizeof(a));
//	uart_init(9600);
//	uart_tx_string("Device address\r\n");
//	for(sa=0;sa<255;sa++){
//	
//			temp=sa&0xFE;
//		i2c_start();
//	 //i2c_write(sa<<1);
//		i2c_write(temp);
//		//	 uart_tx_integer(sa);
//	 v=i2c_ack();
//		i2c_stop();
//	  if(v==0){
//		  c++;
//			sa++;
//		 uart_tx_string("0x");
//			uart_tx_hexa(temp);
//		  //uart_tx_hexa(sa<<1);
////		 if((sa<<1)==0xD0)
////			uart_tx_string("  RTC");//
////     if((sa<<1)==0xA0)
////			uart_tx_string("  EEPROM");	
////		 uart_tx_string("\r\n");
//	 }	
//  

//   }
//	 uart_tx_string("\r\nTotal devices: "); 
//	 uart_int(c);
// }

