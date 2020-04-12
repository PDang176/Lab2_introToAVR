/*	Author: Patrick Dang
 *	Partner(s) Name: 
 *	Lab Section: 028
 *	Assignment: Lab #2  Exercise #3
 *	Exercise Description: [optional - include for your own benefit]
 *      PortA's pins 3 to 0 indicate a separate parking space
 *      PORTC's pins 3 to 0 is a binary representation of the number of available
 *      spaces given in PORTA
 *      - PC7 also indicates whether or not the parking lot is all full
 *
 *      Inputs: PA0 - PA3 (1 = car parked)
 *      Outputs: PA0 - PA3 (binary number of cars parked), PC7 (1 == full lot)
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
	// Checks if lot is full before writing to output
	if(cntavail == 0x00){
		PORTC = cntavail | 0x80;
	}
	else{
		PORTC = cntavail;
	}
	// Reset cntavail
	cntavail = 0x00;
    }
    return 0;
}
