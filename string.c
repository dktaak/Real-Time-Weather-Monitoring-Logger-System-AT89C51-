#include"header.h"
void mystrcpy(u8 *p,u8 *q){
	while(*q){
		*p=*q;
		p++;q++;
	}
	*p=*q;
}

u8 mystrcmp(u8 *s1,u8 *s2){
	
		while(*s1==*s2){
			s1++;s2++;
			if((*s1=='\0')||(*s2=='\0'))
				break;
		}
		return (*s1-*s2);
} 
u8* mystrchr(u8 *s,u8 ch)
{
	u8 i=0;
	while(s[i]){
		if(ch==s[i])
			return (s+i);
		i++;
	}
	return 0;
}
u8 mystrstr(u8 *s1,u8 *s2)
{
	u8 i=0,*p;
    while(*s1){
	   p=mystrchr(s1,*s2);
			if(p==0)
			 return 0;
			else
				s1=p;
	   while(*s2){
			 if(*p==s2[i])
			 {
				 p++;i++;
			 }
			 else
				 break;
			 
			 if(s2[i]=='\0')
				 return 1;
	 }
		 i=0;
}
		return 0;
}

u8* mystrcat(u8 *s1,u8 *s2)
{
	u8*p=s1;
	while(*s1)
		s1++;
	while(*s2)
	{
		*s1++=*s2++;
	}
	*s1=*s2;
	return p;
}