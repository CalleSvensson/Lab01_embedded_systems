#include <avr/io.h>
#include <util/delay.h>

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include "serial.h"
#include "led.h"


void main(void) 
{
    char input_string[10];
    led_init();
    uart_init();
    //led_blink(); 
   while (1)
   {

       //uart_echo();
       uart_getstr(input_string);
       uart_led_hander(input_string);
       //uart_putstr(input_string);
        /*uart_putchar('c');
        _delay_ms(500);
        uart_putchar('\n');
        _delay_ms(500);*/
        //uart_putstr("hej calle\n");
       //uart_putstr("ON\r\n");
       //_delay_ms(500);
       //uart_putstr("OFF\r\n");
       //_delay_ms(500);
    }
}
