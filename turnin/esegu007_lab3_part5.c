/*	Author: Edward Segura
 *  Partner(s) Name: 
 *	Lab Section: 21
 *	Assignment: Lab 3  Exercise 5
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
    /* Insert DDR and PORT initializations */
	DDRB = 0xFE; PORTB = 0x01;
	DDRD = 0x00; PORTD = 0xFF;
    /* Insert your solution below */
    unsigned char tmpB = 0x00;
    unsigned short weight = 0x000;
    while (1) {
    	weight = PIND << 1;
    	weight = weight | PINB;
    	tmpB = 0x00;
    	if(weight >= 70){
    		tmpB = 0x02;
    	}
    	if(weight < 70 && weight > 5){
    		tmpB = 0x04;
    	}
    	PORTB = tmpB;
    }
    return 1;
}
