/*
 * Digital_Clock.c
 *
 * Created: 09/01/2020 01:40:42 PM
 * Author : Mohamed Farag
 */ 

# define F_CPU  1000000UL


#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "Display.h"
#include "clock.h"
#include "Timer.h"
#include "state.h"

unsigned char Button_pressed = 0;
unsigned char sec = 0;

static unsigned char state =Normal_State;        /* global variable in this file only */


ISR (INT0_vect)				// Set Button			
{
	
	timer0_init();
	Button_pressed = 1;
	

}


ISR (TIMER0_COMP_vect)		//each 200 increment the timer
{
	
	if ( ((PIND & 0x04) == 0x00) && (Button_pressed == 1) )
	{
				
		state = state_update();
		
		
	//	TCCR0 =0x00;		//	Timer stopped
	}
	
	Button_pressed = 0;
	//  TCNT0 = 0;             //   clear counter
	/*
	// For Test interrupt
	PORTA = 0xFF;
	PORTB = 0b11111101;
	_delay_ms(2000);
	*/
	/*
	if (state != Normal_State)
	{
		clock_Update();
	}
	*/
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

int main(void)
{

	sw_init();  
	timer1_init();       
	Disp_init();
	


    /* Super Loop */
	for(;;) 
    {
		switch(state)
		{
			case Normal_State:
				Disp_Update(0);			
				break;
			
			case Set_Hours_State:
				Disp_Blink_Hours();
				break;
			
			
			case Set_Miniutes_State:
				Disp_Blink_Miniutes();
				break;
			
			
			default:
				break;	
		}
		
		
		
	}
	
		

	
	
	
	
return 0;
}





