	while(1)
	{
		
		for(j=0,i=0,u=0,addr=0x0000;j<20;j++)
		{
			addr=(j*30);
//			if((j*30)%240==0)
//				addr+=16;
			
			uart_int(j);uart_tx(' ');
			uart_int(addr);uart_tx(' ');
			

			
			rtc_read_time(r);
			uart_tx(' ');
			
			temp=i2c_byte_read_ds1621();
			uart_tx('\0');
			conv_int(temp,r+11);
			while(r[11+i++]);
			r[--i]=' ';
			temp=read_adc(0,0);
			u=i+1;
//			conv_float(adc_vtg,r+u);
//			i=0;
//			while(r[u+i]);
//			r[--i]=' ';
//			u=u+i+1;
////			temp=read_adc(0,1);
//			delay(100);
//			i=conv_float(adc_per,r+u+1);
//		  u=u+1+i;
			r[u]='s';

			delay(100);
			
			for(i=0;;i++)
			{
				if(r[i]=='s')
					break;
				uart_tx(r[i]);
			}
			uart_tx_string("\r\n");
			
			i2c_byte_write_at24c512(0xA0,addr,r);
			delay(10);
			
			start=j;					
		}
		
		flag=1;
  }
