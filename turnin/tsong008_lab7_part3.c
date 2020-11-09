/*	Author: Tinghui Song
 *  Partner(s) Name: 
 *	Lab Section: 24
 *	Assignment: Lab #7  Exercise #3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *
 *	Demo URL: https://drive.google.com/file/d/18DKZmszKyzGdX5qrrQEztJ_MU9WqEqSc/view?usp=sharing
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif


void ADC_init(){
	ADCSRA |= (1 << ADEN) | ( 1 << ADSC) | ( 1 << ADATE);
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRD = 0xFF; PORTD = 0x00;

    /* Insert your solution below */
	ADC_init();

	unsigned short x;
	
	
	//Max 0x31C;
	//Min 0x067;
	//Max/2 = 0x18E;
   	while (1) {
		x = ADC;
		if ( x >= 0x18E){
			PORTB = 0x01;
		}
		else{
			PORTB = 0x00;
		}
  	}
    	return 1;
}
