/*
 * interruptc.c
 *
 * Created: 13/01/2020 01:54:34 ص
 *  Author: Mohamed Farag
 */ 
# define F_CPU  1000000UL

#include "interrupt.h"

unsigned char count_50ms = 0;
unsigned char sec = 0;
unsigned char Button_pressed = 0;

extern unsigned char state;


ISR (INT0_vect)				// Set Button			
{
	TCNT0 =0;				// clear counter
	count_50ms = 0;
	Button_pressed = 1;
}


ISR (TIMER0_COMP_vect)		//each 50ms increment the timer
{
	
	if ( ((PIND & 0x04) == 0x00) && (count_50ms == 4) && (Button_pressed == 1) )
	{
				
		state = state_update();
		count_50ms = 0;
		Button_pressed = 0;	
	}
	
	count_50ms++;

}

ISR (INT1_vect)				// increment switch
{
	/*
	// For Test interrupt 
	PORTA = 0xFF;
	PORTB = 0b11111110;
	_delay_ms(2000);
	*/
	
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