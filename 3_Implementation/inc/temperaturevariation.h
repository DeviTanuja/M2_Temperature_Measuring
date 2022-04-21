/*
 * temperaturevariation.h
 *
 * Created: 21-04-2022 11:39:46
 *  Author: saivi
 */ 

#ifndef TEMPERATUREVARIATION_H_INCLUDED
#define TEMPERATUREVARIATION_H_INCLUDED
#include <avr/io.h>			/* Include AVR std. library file */
#include <util/delay.h>			/* Include Delay header file */

#define LCD_Dir  DDRB			/* Define LCD data port direction */
#define LCD_Port PORTB			/* Define LCD data port */
#define RS PB2				/* Define Register Select pin */
#define EN PB3 				/* Define Enable signal pin */

void LCD_Command( unsigned char cmnd );
void LCD_Char( unsigned char data );
void lcd_initialization (void);
void LCD_String (char *str);
void LCD_String_xy (char row, char pos, char *str);
void lcd_off();


#endif // TEMPERATUREVARIATION_H_INCLUDED
