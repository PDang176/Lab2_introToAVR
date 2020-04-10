/*	Author: Patrick Dang
 *	Partner(s) Name: 
 *	Lab Section: 028
 *	Assignment: Lab #2  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *	Garage open at night -- Garage door sensor connects to PA0 (1 == open)
 *	- A light sensor connects to PA1 (1 == light detected)
 *	
 *	Problem: Write a program that illuminates an LED connected to PB0 (1 == on)
 *		 if the garage door is open at night (There is no light: PA1 == 0)
 *	
 *	2 Inputs: PA0 (garage door sensor) and PA1 (light sensor)
 *	1 Output: PB0 (LED, 1 when PA1 = 0 && PA0 = 1)
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
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;

    unsigned char tmpA = 0x00; // Temporary variable to read both PA0 and PA1
    unsigned char tmpB = 0x00; // Temporary variable to write to PB0
    /* Insert your solution below */
    while (1) {
	// Read Input
    	tmpA = (PINA & 0x01) | (~(PINA) & 0x02);

	// If PA1 is 0 and PA0 is 1 set PB0(tmpB) to 1
	if(tmpA == 0x03){
		tmpB = (tmpB & 0xFE) | 0x01;
	}
	else{
		tmpB = (tmpB & 0xFE) | 0x00;
	}
	// Write to output
	PORTB = tmpB;
    }
    return 0;
}
