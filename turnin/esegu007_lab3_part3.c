/*	Author: Edward Segura
 *  Partner(s) Name: 
 *	Lab Section: 21
 *	Assignment: Lab 3  Exercise 1
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
	DDRA = 0X00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
    /* Insert your solution below */
    unsigned char tmpA = 0x00;
    unsigned char tmpC = 0x00;
    while (1) {
    	tmpA = PINA;
    	unsigned char num = tmpA & 0x0F;
    	tmpC = 0x3F;
    	if(num < 13){
    		tmpC = tmpC & 0xFE;
    		if(num < 10){
    			tmpC = tmpC & 0xFC;
    			if(num < 7){
    				tmpC = tmpC & 0xF8;
    				if(num < 5){
    					tmpC = 0x70;
    					if(num < 3){
    						tmpC = tmpC & 0xE0;
    						if(num == 0){
    							tmpC = tmpC & 0xC0;
    						}
    					}
    				}
    			}
    		}
    	}
    	if((tmpA & 0x70) == 0x30){
    		tmpC = tmpC | 0x80;
    	}
    	PORTC = tmpC;
    }
    return 1;
}
