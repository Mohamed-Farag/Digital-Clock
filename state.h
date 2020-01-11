/*
 * state.h
 *
 * Created: 11/01/2020 03:24:35 AM
 *  Author: Mohamed Farag
 */ 


#ifndef STATE_H_
#define STATE_H_
# define F_CPU  1000000UL

#define	Normal_State         0
#define	Set_Hours_State      1
#define	Set_Miniutes_State   2

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>



void sw_init(void);
unsigned char state_update(void);






#endif /* STATE_H_ */