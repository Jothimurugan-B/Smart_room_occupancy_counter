#include<lpc21xx.h>

#include"i2c.h"
#include"delay.h"
#include "eeprom.h"
#include "lcd.h"

#define IR1 1
#define IR2 2
#define LED1 1<<14
#define LED2 1<<15
#define LED3 1<<16

typedef unsigned char u8;
typedef signed   char s8;

unsigned char count=0;

int main()
{
	
	IODIR0|=LED1|LED2|LED3; //select p0.14,p0.15 and p0.16 as OP for LED

	 lcd_init();
	 init_i2c();

	count=i2c_eeprom_read(0X50,0X00);

	 delay_ms(100);

	while(1)

	{
	    lcd_cmd(0x80);
	  lcd_str("count=");
	 lcd_integer(count);

  	if(((IOPIN0>>0)&1)==0) //checking entry
	   {	
	     delay_ms(200);

		   if(count>10)
		count=0;
		  count++;
		
		  while(((IOPIN0>>0)&1)==0);	  
	   }

		if(((IOPIN0>>1)&1)==0) //checking exit
		  {
		    delay_ms(200);
			 if(count<0)
			 count=0;

			count--;

			while(((IOPIN0>>1)&1)==0);
		  }

	 i2c_eeprom_write(0X50,0X00,count);

	/***LIGHT BLINKING CODE***/

		if(count==0)
           IOSET0|=LED1|LED2|LED3;

		else if((count>0 )&& (count<=2))
		{
		  IOCLR0|=LED1;
			IOSET0|=LED2|LED3;
		}
			
		else if((count>2) && (count<=4))
		{
			IOCLR0|=LED1|LED2;
			IOSET0|=LED3;
		}
			
		else if(count>=5)
			IOCLR0|=LED1|LED2|LED3;

	}

}

