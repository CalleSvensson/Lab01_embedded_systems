#include <avr/io.h>
#include <util/delay.h>

#include "serial.h"


#define FOSC 16000000  // Clock speed
#define BAUD 38400    // Baud rate
#define MYUBRR  ((FOSC / 16) / BAUD) -1  //  Calculating baud rate register setting 

void uart_init(void) 
{
    UBRR0L = (uint8_t)(MYUBRR & 0xFF); // write to lower byte
    UBRR0H = (uint8_t)(MYUBRR >> 8);// write to higher byte
    UCSR0C = 0x06;  // Set to 8N1
    UCSR0B |= (1 << RXEN0) | (1 << TXEN0); // enable the transmitter(TX) and receiver(RX)
}

void uart_putchar(char chr)
{
    if (chr == '\r') // Check if the char is a new line
    {
        while (!(UCSR0A & (1 << UDRE0))); // Wait for empty transmit buffer
        UDR0 = '\r';
        while (!(UCSR0A & (1 << UDRE0)));
        UDR0 = '\n';
    }
    else
    {
        while (!(UCSR0A & (1 << UDRE0)));
        UDR0 = chr;  // Send char
    }
}

void uart_putstr(const char* str)
{
    int i = 0;
    while (str[i] != 0)  // Check for the end of the String
    {
        uart_putchar(str[i]);  // Send each char 
        i++;
    }    
}

char uart_getchar(void)
{
    while (!(UCSR0A & (1 << RXC0)));    // Wait for data to be received
	return UDR0; // return input value
}

void uart_echo(void)
{
    char c = uart_getchar();  // Gets input char
    uart_putchar(c);  // Prints input char
}
