/*
 * Display.h
 *
 * Created: 10/01/2020 09:46:30 PM
 *  Author: Mohamed Farag
 */ 


#ifndef DISPLAY_H_
#define DISPLAY_H_

# define F_CPU  1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "state.h"
# define COUNTS  250

extern void Disp_init(void);
extern void Disp_Update(unsigned char flag);
extern void Disp_Blink_Hours(void);
extern void Disp_Blink_Miniutes(void);





#endif /* DISPLAY_H_ */