/*	Author: Tinghui Song
 *  Partner(s) Name: none
 *	Lab Section:24
 *	Assignment: Lab #2  Exercise #4
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif	

int main(void) {
	//inputs
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0x00; PORTC = 0xFF;
	//outputs
	DDRD = 0xFF; PORTD = 0x00;
	//variables
	unsigned char weight;
	unsigned char seat0 = 0x00;
	unsigned char seat1 = 0x00;
	unsigned char seat2 = 0x00;
	unsigned char tempD = 0x00;

    	while (1) {
		seat0 = PINA;
		seat1 = PINB;
		seat2 = PINC;
		weight = seat0 + seat1 + seat2;

		if((weight) > 0x8C) { 
			tempD = tempD | 0x01; 
		}
		else {
			tempD = tempD & 0xFE; 
		}

		if(((seat0 - seat2) > 0x50 ||(seat2 - seat0) > 0x50)) { 
			tempD = tempD | 0x02; 
		}
		else {
			tempD = tempD & 0xFD; 
		}
		tempD = (tempD & 0x03) | ((weight >> 3) << 1); 
		PORTD = tempD;
    	}

	return 0;
}


