/*	Author: Tinghui Song
 *  Partner(s) Name: 
 *	Lab Section: 24
 *	Assignment: Lab #7  Exercise #4
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *
 *	Demo URL: 
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
		if ( x >= 0x2B5) {
			PORTB = 0xFF;
		}
		else if ( x >= 0x25E){
			PORTB = 0x7F;
		}
		else if ( x >= 0x208){
			PORTB = 0x3F;
		}
		else if ( x >= 0x1B1){
			PORTB = 0x1F;
		}
		else if ( x >= 0x15A){
			PORTB = 0x0F;
		}
		else if ( x >= 0x104){
			PORTB = 0x07;
		}
		else if ( x >= 0x0AD){
			PORTB = 0x03;
		}
		else if ( x >= 0x057){
			PORTB = 0x01;
		}
		else{
			PORTB = 0x00;
		}
  	}
    	return 1;
}
