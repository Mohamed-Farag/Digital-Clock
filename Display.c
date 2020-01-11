/*
 * Display.c
 *
 * Created: 10/01/2020 09:46:47 PM
 *  Author: Mohamed Farag
 */ 
#include "Display.h"
#include "clock.h"

static unsigned char Hours = 0;
static unsigned char Miniutes = 0;
extern unsigned char state;           // Declaration 

/* we use look up table to handle numbers on 7 segment Display */


static unsigned char LUT[]= {0b0111111,0b0000110,0b1011011,0b1001111,0b1100110,0b1101101,0b1111101,0b0000111,0b1111111,0b1101111};

extern void Disp_init(void)
{
	/*------- To initiate PORTA , PORTB and PORTC -------*/
	DDRA  = 0xFF;		 /* PORTA is Output */
	DDRB  = 0xF0;		 /* From PORTB.4 To PORTB.7 is Output , From PORTB.0 To PORTB.3 is Input  */
	PORTB = 0x04;		 /* To use Pull Up Resistor on PB2 */
	PORTA = LUT[0];		 /* To initiate first 7 segment with zero */
}



extern void Disp_Update(unsigned char flag)
{
	 Miniutes = clock_Get_Minutes();
	 Hours = clock_Get_Hours();
	 
	 
	 if (flag != 1)
	 {
		 
	 
	 /* first digit form left */
	 PORTB = 0xE4;
	 PORTA = LUT[Hours/10];   // tens of Hours
	 _delay_us(500);
	 
	 
	 
	 /* second digit form left */
	 PORTB = 0xD4;
	 PORTA = LUT[Hours%10];   // units of Hours
	 PORTA |= 0x80;
	 _delay_us(500);
	 
	 }
	 if (flag != 2)
	 {
	  /* third digit form left */
	  PORTB = 0xB4;
	  PORTA = LUT[Miniutes/10];   // tens of Miniutes
	  _delay_us(500);	  
	  
	 /* fourth digit form left */
	  PORTB = 0x74;
	  PORTA = LUT[Miniutes%10];   // units of Miniutes
	  _delay_us(500);
	 }
	  
}


extern void Disp_Blink_Hours(void)
{
	unsigned char i = 0;
	unsigned char flag = 0;
	
	for (i = 0 ;i<=COUNTS ; i++)		/* To Generate 0.5 Sec ON */
	{
		Disp_Update(flag);
		if(state != Set_Hours_State)
		{
			return;
		}
	}
	flag = 1;
	for (i = 0 ;i<=COUNTS ; i++)	   /* To Generate 0.5 Sec OFF */
	{
		Disp_Update(flag);
		if(state != Set_Hours_State)
		{
			return;
		}
	}
	
}


extern void Disp_Blink_Miniutes(void)
{
		unsigned char i = 0;
	    unsigned char flag = 0;
		
		for (i = 0 ;i<=COUNTS ; i++)		 /* To Generate 0.5 Sec ON */
		{
			Disp_Update(flag);
			if(state != Set_Miniutes_State)
			{
				return;
			}
		}
		flag = 2;
		for (i = 0 ;i<=COUNTS ; i++)		 /* To Generate 0.5 Sec OFF */
		{
			Disp_Update(flag);
			if(state != Set_Miniutes_State)
			{
				return;
			}
		}
}



