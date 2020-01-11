/*
 * Timer.h
 *
 * Created: 10/01/2020 11:42:05 PM
 *  Author: Mohamed Farag
 */ 


#ifndef TIMER_H_
#define TIMER_H_
# define F_CPU  1000000UL

#include <avr/io.h>

extern void timer0_init (void);
extern void timer1_init (void);




#endif /* TIMER_H_ */