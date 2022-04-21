/*
 * sensor.h
 *
 * Created: 21-04-2022 11:37:30
 *  Author: saivi
 */ 


#ifndef SENSOR_H_INCLUDED
#define SENSOR_H_INCLUDED
#include <avr/io.h>
#include<util/delay.h>

#define seat_sensor!(PIND &(1<<PD3))
#define heater_set (PIND &(1<<PD4))
#define heater_clear PORTD&=~(1<<PD4)
#define led_set PORTD|=(1<<PD2)
#define led_clear PORTD &=~(1<<PD2)

void seat_sensing();


#endif // SENSOR_H_INCLUDED
