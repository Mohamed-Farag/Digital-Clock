/*
 * clock.h
 *
 * Created: 10/01/2020 09:34:30 PM
 *  Author: Mohamed Farag
 */ 


#ifndef CLOCK_H_
#define CLOCK_H_

extern void clock_Update(void);
extern void Increment(unsigned char state);
extern void Decrement(unsigned char state);
extern unsigned char clock_Get_Minutes(void);
extern unsigned char clock_Get_Hours(void);


#endif /* CLOCK_H_ */