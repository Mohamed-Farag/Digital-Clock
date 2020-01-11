/*
 * state.c
 *
 * Created: 11/01/2020 03:24:47 AM
 *  Author: Mohamed Farag
 */ 

#include "state.h"


unsigned char state = Normal_State;

void sw_init(void)
{
		/*------- To initiate interrupt -------*/

		sei();              /* Enable Global Interrupt */
		
		DDRD   = 0x00;		/* PORTD is Input  */
		PORTD  = 0x0C;		/* To use Pull Up Resistor on PD2 and PD3 */  
		GICR   = 0xE0;      /* Local Enable of INT0 , INT1 and INT2 */
		MCUCR  = 0x0A;      /* Falling Edge for INT0 and INT1*/
		MCUCSR = 0x00;		/* Falling Edge for INT2 */
		GIFR   = 0xE0;	    /* clear flag of INT0 , INT1 and INT2 */
		
}


unsigned char state_update(void)
{
	switch (state)
	{
		case Normal_State:
			state = Set_Hours_State;
			break;
			
		case Set_Hours_State:
			state = Set_Miniutes_State;
			break;
		case Set_Miniutes_State:
			state = Normal_State;
			break;
			
		default:
			state = Normal_State;	
			break;
	}
	
	return state;
	
}

