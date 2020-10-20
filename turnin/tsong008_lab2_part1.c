/*	Author: Tinghui Song
 *  Partner(s) Name: none
 *	Lab Section:24
 *	Assignment: Lab #2  Exercise #1
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
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0xFF;
	unsigned char Input0 = 0x00;
	unsigned char Input1 = 0x00;
	unsigned char tempB = 0x00;
	while(1){
		Input0 = PINA & 0x01;
		Input1 = PINA & 0x02;
		if ((Input1==0x00) && (Input0==0x01)){
			tempB = 0x01;
		}
		else{
			tempB = 0x00;
		}
		PORTB = tempB;
	}

	return 0;
}


