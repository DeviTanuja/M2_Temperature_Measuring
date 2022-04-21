/*
 * main.c
 *
 * Created: 4/21/2022 11:29:18 AM
 *  Author: DeviTanuja
 */ 


#include <avr/io.h>
#include <util/delay.h>
#include "sensor.h"
#include "temperaturevariation.h"
#include "lcdprogram.h"
int main()
{
	seat_sensing();
	InitADC();
	timer_initialization();
	lcd_initialization();			/* Initialization of LCD*/

	uint16_t temperature_var;

	while(1)
	{
		if(seat_sensor)
		{
			PORTD|=(1<<PD4);
			if(heater_set){
				led_set;
				_delay_ms(200);
				lcd_off();
				temperature_var=ReadADC(2);
				PWM_out(temperature_var);

			}
			else
			{
				led_clear;
				_delay_ms(200);
				heater_clear;
				_delay_ms(200);
				lcd_off();
			}
		}
		else{
			led_clear;
			_delay_ms(200);
			heater_clear;
			_delay_ms(200);
			lcd_off();
		}
	}
	return 0;
}
