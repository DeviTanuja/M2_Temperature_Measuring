/*
 * lcdprogram.c
 *
 * Created: 21-04-2022 11:32:55
 *  Author: saivi
 */ 
#include"lcdprogram.h"
#include"temperaturevariation.h"

void InitADC()
{
	ADMUX=(1<<REFS0);
	ADCSRA=(1<<ADEN)|(7<<ADPS0);
}

uint16_t ReadADC(uint8_t ch)
{
	ADMUX&=0xf8;
	ch=ch&0b00000111;
	ADMUX|=ch;
	ADCSRA|=(1<<ADSC);
	while(!(ADCSRA & (1<<ADIF)));
	ADCSRA|=(1<<ADIF);
	return(ADC);
}

void timer_initialization(void){
	TIMER1_FAST_PWM; //setting timer1 for PWM
	TIMER_PRESCALER_AS_64; //8 prescalar
	PWM_OUTPUT_PIN; //Setting PB1 as output pin

}

void PWM_out(uint16_t ADC_value){
	char cond[20];
	char intial[]="SEAT-Temperature";

	if(ADC_value>0 && ADC_value<=200){

		OCR1A = 190; //20% duty cycle
		cond[0] = '2';
		cond[1] = '0';
		cond[2] = 223;
		cond[3] = 'C';
		cond[4] = ' ';
		cond[5] = '\0';
		LCD_String(intial);
		LCD_Command(0xC0);
		LCD_String(cond);
		_delay_ms(2);
	}
	else if((ADC_value>=210) && (ADC_value<=500)){

		OCR1A = 450; //40% duty cycle
		cond[0] = '2';
		cond[1] = '5';
		cond [2] = 223;
		cond[3] = 'C';
		cond[4] = ' ';
		cond[5] = '\0';
		LCD_String(intial);
		LCD_Command(0xC0);
		LCD_String(cond);
		_delay_ms(2);
	}
	else if((ADC_value>=501) && (ADC_value<=700)){

		OCR1A = 675;//70% duty cycle
		cond[0] = '2';
		cond[1] = '9';
		cond[2] = 223;
		cond[3] = 'C';
		cond[4] = ' ';
		cond[5] = '\0';
		LCD_String(intial);
		LCD_Command(0xC0);
		LCD_String(cond);
		_delay_ms(2);
	}
	else if((ADC_value>=701) && (ADC_value<=1024)){

		OCR1A = 1010; //95% duty cycle
		cond[0] = '3';
		cond[1] = '3';
		cond[2] = 223;
		cond[3] = 'C';
		cond[4] = ' ';
		cond[5] = '\0';
		LCD_String(intial);
		LCD_Command(0xC0);
		LCD_String(cond);
		_delay_ms(2);
	}
	else{
		OCR1A = 0; //0% output
		cond[0] = 'O';
		cond[1] = 'F';
		cond[2] = 'F';
		cond[3] = ' 0';
		cond[4] = 223;
		cond[5] = ' c';
		cond[6] = ' ';
		cond[7] = '\0';
		LCD_String(intial);
		LCD_Command(0xC0);
		LCD_String(cond);
		_delay_ms(2);
	}

}
