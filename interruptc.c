﻿/*
 * interruptc.c
 *
 * Created: 13/01/2020 01:54:34 AM
 *  Author: Mohamed Farag
 */ 
# define F_CPU  1000000UL

#include "interrupt.h"

unsigned char count_10ms = 0;
unsigned char sec = 0;
unsigned char Button_pressed = 0;

extern unsigned char state;


ISR (INT0_vect)				// Set Button			
{
	TCNT0 =0;				// clear counter
	count_10ms = 0;
	Button_pressed = 1;
}


ISR (TIMER0_COMP_vect)		//each 10ms increment the timer
{
	
	if ( ((PIND & 0x04) == 0x00) && (count_10ms == 20) && (Button_pressed == 1) )
	{
				
		state = state_update();
		count_10ms = 0;
		Button_pressed = 0;	
	}
	else if ((PIND & 0x04) == 0x00)            // To Ensure that Button still presses over the 200ms 
	{
			count_10ms++;
	}
	
	else
	{
		; /* MISRA */
	}

}

ISR (INT1_vect)				// increment switch
{
	Increment(state);
}


ISR (TIMER1_COMPA_vect)		//each 1 s increment the timer
{	
	sec++;
	if ( (state == Normal_State) && (sec == 60 ))
	{
			sec = 0;
			clock_Update();
	}
	
	/*
	// if You Want To Test as seconds 
	if ( (state == Normal_State) )
	{
		clock_Update();
	}
	*/	
}


ISR (INT2_vect)				// Decrement switch
{
	Decrement(state);
}
