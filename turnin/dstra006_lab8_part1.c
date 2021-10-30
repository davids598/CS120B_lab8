/*	Author: David Strathman
 *  Partner(s) Name:
 *	Lab Section:
 *	Assignment: Lab #8  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *  Link to Vid:
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif
unsigned short x = 0;
void ADC_init() {
  ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0x00; //A is input
    DDRB = 0xFF; PORTB = 0x00; //Set both to outputs
    DDRD = 0xFF; PORTD = 0x00; //Set both to outputs
    /* Insert your solution below */
    ADC_init();
    while (1) {
      x = ADC;
      PORTB = (char)x;
      PORTD = (char)(x >> 4);
    }
    return 1;
}
