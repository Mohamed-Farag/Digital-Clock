/*
 * interrupt.h
 *
 * Created: 13/01/2020 01:54:50 ص
 *  Author: LENOVO
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "state.h"
#include "clock.h"

ISR (INT0_vect);
ISR (TIMER0_COMP_vect);
ISR (INT1_vect);
ISR (TIMER1_COMPA_vect);
ISR (INT2_vect);


#endif /* INTERRUPT_H_ */