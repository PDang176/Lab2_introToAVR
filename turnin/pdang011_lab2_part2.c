/*	Author: Patrick Dang
 *	Partner(s) Name: 
 *	Lab Section: 028
 *	Assignment: Lab #2  Exercise #2
 *	Exercise Description: [optional - include for your own benefit]
 *      PortA's pins 3 to 0 indicate a separate parking space
 *      PORTC is a binary representation of the number of available spaces given in PORTA
 *      
 *      Inputs: PA0, PA1, PA2, PA3 (1 = car parked)
 *      Outputs: PORTC (binary number of cars parked)
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
    DDRC = 0xFF; PORTC = 0x00;

    unsigned char cntavail = 0x00; // The number of parking spaces available
    /* Insert your solution below */
    while (1) {
	// Check Pins
	if((PINA & 0x01) == 0x00){
		cntavail++;	
	}
	if((PINA & 0x02) == 0x00){
		cntavail++;
	}
	if((PINA & 0x04) == 0x00){
		cntavail++;
	}
	if((PINA & 0x08) == 0x00){
		cntavail++;
	}
	// Write to output
	PORTC = cntavail;
	// Reset cntavail
	cntavail = 0x00;
    }
    return 0;
}
