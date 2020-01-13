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
#include "interrupt.h"


unsigned char state =Normal_State;        /* global variable in this file only */


int main(void)
{
	timer0_init();
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





