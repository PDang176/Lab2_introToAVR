/*	Author: Patrick Dang
 *	Partner(s) Name: 
 *	Lab Section: 028
 *	Assignment: Lab #2  Exercise #4
 *	Exercise Description: [optional - include for your own benefit]
 *	PORTS A, B, C are 8-bit weight sensors for 3 seats in a ride (0-255 kg)
 *	
 *	PD0 is set to 1 if the total passenger weight is over 140kg
 *	PD1 is set to 1 if the difference between PORTA and PORTC is over 80kg
 *	PD7 to PD2 is the approximated weight of the 3 seats
 *
 *	Inputs: PORTA, PORTB, PORTC (binary value of weight)
 *	Outputs: PD0 (PORTA + PORTB + PORTC > 140), PD1 (|PORTA - PORTC| > 80),
 *		 PD7 to PD2 (PORTA + PORTB + PORTC)
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
    DDRB = 0x00; PORTB = 0xFF;
    DDRC = 0x00; PORTC = 0xFF;
    DDRD = 0xFF; PORTD = 0x00;

    unsigned char totalWeight = 0x00;
    unsigned char overWeight = 0x00;
    unsigned char unbalanced = 0x00;
    /* Insert your solution below */
    while (1) {
	    totalWeight = PINA + PINB + PINC;
	    if(totalWeight > 140){
		overWeight = 0x01;
	    }
	    if(PINA - PINC < -80 || PINA - PINC > 80){
		unbalanced = 0x02;
	    }
	    totalWeight = totalWeight & 0xFC;
	    
	    PORTD = totalWeight & overWeight & unbalanced;
    }
    return 0;
}
