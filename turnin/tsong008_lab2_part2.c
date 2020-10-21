/*	Author: Tinghui Song
 *  Partner(s) Name: none
 *	Lab Section:24
 *	Assignment: Lab #2  Exercise #2
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
	DDRC = 0xFF; PORTC = 0x00;
	unsigned char Input0 = 0x00;
	unsigned char Input1 = 0x00;
	unsigned char Input2 = 0x00;
	unsigned char Input3 = 0x00;
	unsigned char spaceCnt = 0x00;
	while(1){
		Input0 = PINA & 0x01;
		Input1 = PINA & 0x02;
		Input2 = PINA & 0x04;
		Input3 = PINA & 0x08;
		spaceCnt = 0x04;
		if (Input0==0x01){
			spaceCnt--;
		}
		if (Input1==0x02){
			spaceCnt--;
		}
		if (Input2==0x04){
			spaceCnt--;
		}
		if (Input3==0x08){
			spaceCnt--;
		}
		PORTC = spaceCnt;
	}

	return 0;
}


