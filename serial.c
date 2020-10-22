#include <avr/io.h>
#include <util/delay.h>

#include "serial.h"



#define FOSC 16000000  // Clock speed
#define BAUD 38400    // Baud rate
#define MYUBRR  ((FOSC / 16) / BAUD) -1  //  Calculating baud rate register setting 

void uart_init(void) 
{
    /*Set baud rate */
    UBRR0H = (unsigned char)(MYUBRR >> 8);
    UBRR0L = (unsigned char)MYUBRR;
    UCSR0C = (3 << UCSZ00); // 1 stop bit, 8bit data
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
        while (!(UCSR0A & (1 << UDRE0)));
        UDR0 = chr;  // Send char

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


void uart_getstr(char* str) 
{
    int i = 0;
    char c;
    while ((i < 10) && (c!='\n')) 
    {
        c = uart_getchar(); // receive char from uart     
        str[i++] = tolower(c);// Add character to string/ char array
    }

    str[i] = 0;  // reset char array
}

void uart_led_hander(char* str)
{
    if (strcmp(str, "on\r\n") == 0)
    {
        led_on();
    }
    else if (strcmp(str, "off\r\n") == 0)
    {
        led_off();
    }
    else if (strcmp(str, "red\r\n") == 0)
    {
        red_led();
    }
    else if (strcmp(str, "blue\r\n") == 0)
    {
        blue_led();
    }
    else if (strcmp(str, "green\r\n") == 0)
    {
        green_led();
    }
    else
    {
        uart_putstr("Invalid command\n");
    }
}
