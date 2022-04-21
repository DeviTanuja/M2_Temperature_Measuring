/*
 * sensor.c
 *
 * Created: 21-04-2022 11:33:46
 *  Author: saivi
 */ 
#include "sensor.h"

void seat_sensing(){
	DDRD|=(1<<PD2); //Set D2= 1
	DDRD&=~(1<<PD3); //Clear bit
	PORTD|=(1<<PD3); //Set bit
	DDRD&=~(1<<PD4); //Clear bit
	PORTD|=(1<<PD4); //Set bit
}

