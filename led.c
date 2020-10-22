#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

#include "led.h"

bool red_on = false;
bool blue_on = false;
bool green_on = false;

void led_init()
{
    DDRB |= (1 << PB3); // set pin 11 on Arduino board to output
    DDRB |= (1 << PB2); // set pin 10 on Arduino board to output
    DDRB |= (1 << PB1); // set pin 9 on Arduino board to output
}

void led_blink()
{
   
    while (1)
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
void red_led() 
{
    red_on = !red_on;
    if (red_on == true)
    {
        PORTB |= (1 << PB3);
        uart_putstr("Red on\n");
    }
    else
    {
        PORTB &= ~(1 << PB3);
        uart_putstr("Red off\n");
    } 
}

void blue_led() 
{
    blue_on = !blue_on;
    if (blue_on == true)
    {
        PORTB |= (1 << PB2);
        uart_putstr("Blue on\n");
    }
    else
    {
        PORTB &= ~(1 << PB2);
        uart_putstr("Blue off\n");
    }
}

void green_led() 
{
    green_on = !green_on;
    if (green_on == true)
    {
        PORTB |= (1 << PB1);
        uart_putstr("Green on\n");
    }
    else
    {
        PORTB &= ~(1 << PB1);
        uart_putstr("Green off\n");
    }
}

void led_on() 
{
    red_on = true;
    blue_on = true;
    green_on = true;
    PORTB |= (1 << PB3);
    PORTB |= (1 << PB2);
    PORTB |= (1 << PB1);
    uart_putstr("All on\n");
}

void led_off() 
{
    red_on = false;
    blue_on = false;
    green_on = false;
    PORTB &= ~(1 << PB3);
    PORTB &= ~(1 << PB2);
    PORTB &= ~(1 << PB1);
    uart_putstr("All off\n");
}

