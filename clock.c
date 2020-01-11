/*
 * clock.c
 *
 * Created: 10/01/2020 09:34:10 PM
 *  Author: Mohamed Farag
 */ 
# define F_CPU  1000000UL
#include <avr/io.h>
//#include <avr/interrupt.h>
#include <util/delay.h>
#include "clock.h"
#include "state.h"

static unsigned char Hours = 0;
static unsigned char Miniutes = 0;



extern void clock_Update(void)
{

	if (Miniutes == 59 && Hours == 23)
	{
		Miniutes = 0;
		Hours = 0;
	}
	
	else if (Miniutes == 59)
	{
		Miniutes = 0;
		Hours++;
	}
	else
	{
		Miniutes++;
	}	
}

extern void Increment(unsigned char state)
{
	switch(state)
	{
		case Set_Hours_State:
			if (Hours == 23)
			{
				Hours = 0;
			}	
			else
			{
				Hours++;
			}
		    break;
			
		case Set_Miniutes_State:
			if (Miniutes == 59)
			{
				Miniutes = 0;
			}
			else
			{
				Miniutes++;
			}
			break;
		default:
			break;
	}
}

extern void Decrement(unsigned char state)
{
	switch(state)
	{
		case Set_Hours_State:
			if (Hours == 0)
			{
				Hours = 23;
			}
			else
			{
				Hours--;
			}
			break;
		
		case Set_Miniutes_State:
			if (Miniutes == 0)
			{
				Miniutes = 59;
			}
			else
			{
				Miniutes--;
			}
			break;
		default:
			break;
	}
}


extern unsigned char clock_Get_Minutes(void)
{
	return Miniutes;
}

extern unsigned char clock_Get_Hours(void)
{
	return Hours;
}