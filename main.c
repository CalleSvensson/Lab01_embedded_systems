#include <avr/io.h>
#include <util/delay.h>

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include "serial.h"

#define REDLED PB3;
 
void ledblink()
{
    DDRB |= (1 << PB3); // set pin 11 on Arduino board to output
    DDRB |= (1 << PB2); // set pin 10 on Arduino board to output
    DDRB |= (1 << PB1); // set pin 9 on Arduino board to output

    while (true)
    {
        PORTB |= (1 << PB3);// set pin 11 on Arduino board to HIGH
        _delay_ms(500);
        PORTB &= ~(1 << PB3);// set pin 11 on Arduino board to LOW
        _delay_ms(500);        
        PORTB |= (1 << PB2);// set pin 10 on Arduino board to HIGH
        _delay_ms(500);
        PORTB &= ~(1 << PB2);// set pin 10 on Arduino board to LOW
        _delay_ms(500);        
        PORTB |= (1 << PB1);// set pin 9 on Arduino board to HIGH
        _delay_ms(500);
        PORTB &= ~(1 << PB1);// set pin 9 on Arduino board to LOW
        _delay_ms(500);
    }
}
void main(void) {
    //ledblink();
    uart_init();

   while (1)
   {
       uart_echo();
        /*uart_putchar('c');
        _delay_ms(500);
        uart_putchar('\n');
        _delay_ms(500);*/
        //uart_putstr("hej calle \n");
        //_delay_ms(500);
    }
}
