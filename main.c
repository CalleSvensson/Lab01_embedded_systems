#include <avr/io.h>
#include <util/delay.h>

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include "serial.h"

void main(void) {
	DDRB |= (1 << PB3); // set pin 11 on Arduino board to output

	while (true) {
		PORTB |= (1 << PB3);// set pin 11 on Arduino board to HIGH
		_delay_ms(500);
		PORTB &= ~(1 << PB3);// set pin 11 on Arduino board to LOW
		_delay_ms(500);
	}

}
