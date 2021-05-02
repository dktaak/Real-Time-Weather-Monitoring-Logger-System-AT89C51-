#include"header.h"
extern void delay(unsigned short int ms);
sbit R0=P1^0;
sbit R1=P1^1;
sbit R2=P1^2;
sbit R3=P1^3;
sbit C0=P1^4;
sbit C1=P1^5;
sbit C2=P1^6;
sbit C3=P1^7;
u8 row=0,col=0;
code key[4][4]={7,8,9,'/',4,5,6,'*',1,2,3,'-','#',0,'=','+'};

   u8 keyscan(void){
		 
		 R0=R1=R2=R3=0;
     C0=C1=C2=C3=1;
while((C0&C1&C2&C3)==1);//waiting for key to press
  delay(30);//to avoid key bouncing
		 
	/*row 0 chked*/
	R0=0;R1=R2=R3=1;
	if((C0&C1&C2&C3)==0){
		row=0;
		goto colcheck;
	}
		/*row 1 chked*/
	R1=0;R0=R2=R3=1;
	if((C0&C1&C2&C3)==0){
		row=1;
		goto colcheck;
	}
		/*row 2 chked*/
	R2=0;R0=R1=R3=1;
	if((C0&C1&C2&C3)==0){
		row=2;
		goto colcheck;
	}
			/*row 3 chked*/
	R3=0;R0=R1=R2=1;
	if((C0&C1&C2&C3)==0){
		row=3;
		goto colcheck;
	}
	colcheck:
		if(C0==0)
			col=0;
		else if(C1==0)
			col=1;
		else if(C2==0)
			col=2;
		else if(C3==0)
			col=3;
	while((C0&C1&C2&C3)==0);//waiting for key to release
	return (key[row][col]); 
}
	 
u8 math(void){
	u8 a[4],i;
	for(i=0;i<4;i++){
		a[i]=keyscan();
	if((a[i]>=0)&&(a[i]<=9))
	  lcd_data(a[i]+48);
	else
	  lcd_data(a[i]);
	if(a[i]==('='))
		break;
	else if(a[i]==('#')){
		lcd_cmd(0x1);
		return 0;
	}	
}
	switch(a[1]){
		case '/':
			a[0]=(a[0]/a[2]);break;
		case '*':
			a[0]=(a[0]*a[2]);break;
		case '+':
			a[0]=(a[0]+a[2]);break;
		case '-':
			a[0]=(a[0]-a[2]);break;
	} 
	return a[0];
}
