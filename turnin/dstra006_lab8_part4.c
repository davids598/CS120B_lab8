/*	Author: David Strathman
 *  Partner(s) Name:
 *	Lab Section:
 *	Assignment: Lab #8  Exercise #4
 *	Exercise Description: [optional - include for your own benefit]
 *
 *  Link to Vid: https://youtu.be/hC2bUaqfC8M
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#define MAX 0x01FB
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif
unsigned short x = 0;
unsigned short one_light = MAX / 8;
void ADC_init() {
  ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF; //A is input
    DDRB = 0xFF; PORTB = 0x00; //Set both to outputs
    DDRD = 0xFF; PORTD = 0x00; //Set both to outputs
    /* Insert your solution below */
    ADC_init();
    while (1) {
      x = ADC;
      if (x >= 7 * one_light) {
        PORTB = 0xFF;
      }
      else if (x >= 6 * one_light) {
        PORTB = 0x7F;
      }
      else if (x >= 5 * one_light) {
        PORTB = 0x3F;
      }
      else if (x >= 4 * one_light) {
        PORTB = 0x1F;
      }
      else if (x >= 3 * one_light) {
        PORTB = 0x0F;
      }
      else if (x >= 2 * one_light) {
        PORTB = 0x07;
      }
      else if (x >= 1 * one_light) {
        PORTB = 0x03;
      }
      else {
        PORTB = 0x01;
      }
    }
    return 1;
}
