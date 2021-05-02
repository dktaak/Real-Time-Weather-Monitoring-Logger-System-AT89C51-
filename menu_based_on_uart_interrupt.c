#include"header.h"

u8 arr[20],s1[20];
bit flag=0;
void main(){
	u8 temp,op,*p;
	uart_init(9600);
	uart_interrupt_enable();
	
	while(1){
		uart_tx_string("Menu\r\n------------------------\r\n");
	  uart_tx_string("a)strcmp\r\nb)strstr\r\nc)strcat\r\nd)strchar\r\n");
		
		while(flag==0); 
		if(flag==1){
			flag=0;
		op=arr[0];			
	  }
		if(op>=97&&op<=100){
		uart_tx_string("Enter string 1: ");
		
		while(flag==0);
	  if(flag==1){
			flag=0;
		mystrcpy(s1,arr);	
	  }
		
	uart_tx_string("Enter string 2: ");

	while(flag==0);
	if(flag==1){
		flag=0;
		uart_tx_string("Result : ");
		switch(op){
			case 'a':
					temp=mystrcmp(s1,arr);
					if(temp==0){
						uart_tx_string("Same");
					}
					else
						uart_tx_string("Diff");
					break;
			case 'b':
					temp=mystrstr(s1,arr);
					if(temp==1){
						uart_tx_string("sub string found");
					}
					else
						uart_tx_string("sub string not found");
					break;
			case 'c':
					p=mystrcat(s1,arr);
			    uart_tx_string(p);
					break;
			case 'd':
					p=mystrchr(s1,arr[0]);
					if(*p==arr[0]){
						uart_tx_string("Char found");
					}
					else
						uart_tx_string("Char not found");
					break;
					}
		//uart_interrupt_disable();
	}
   }
	uart_tx_string("\r\n");
  }
}