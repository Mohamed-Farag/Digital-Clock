/*
 * Timer.c
 *
 * Created: 10/01/2020 11:41:51 PM
 *  Author: Mohamed Farag
 */ 
/*
XTA/L = 1MHZ   => Tmachine cycle = 1 micro sec
prescalar 1:64 =>  Tclock = 64 * 1 = 64 micro second
1sec /64 micro sec  = 15625 clock cycles = 0x3D09  clock cycles

65536 - 15625 = C35B
50011 = ?



*/

#include "Timer.h"

extern void timer0_init (void)
{
	// 195
	OCR0 = 125;        //  ( fire every 10 ms )
	TIMSK |= 0x02;     // enable interrupt
	TCNT0 =0;          // clear counter
	
	
	TCCR0 = 0x8B;      // 0b10001011    ,  Normal port operation, OC0 disconnected, 64 prescalar , CTC , Top = OCR0
}

extern void timer1_init (void)
{
	OCR1A = 12500;        // ( fire every 1000 ms )
	//OCR1A = 15625;
	TIMSK |= (1<<4);	 // enable interrupt
	TCNT1 = 0;			 // clear counter
	TCCR1A = 0x08;       // Normal port operation, OC1A/OC1B disconnected. ,  
	TCCR1B = 0x0B;       // 64 prescalar  , CTC , Top = OCR1A
}


/*
extern void Timer_init(void)
{
	
	TCNT1H = 0xC3;
	TCNT1L = 0x5B;
	
	TCCR1A = 0x00;    // Normal mode
	TCCR1B = 0x03;    // Normal mode ,, 64 prescalar 
	TIMSK  = 0x04;    // 
	
}
*/