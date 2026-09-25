/*
 * main.c
 *
 * Created: 9/25/2026 12:59:47 PM
 *  Author: K R Amarnath
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRB |= (1 << PB4);   // PB4 (Arduino Pin 12) = OUTPUT (Relay)
    DDRD &= ~(1 << PD2);  // PD2 (Arduino Pin 2)  = INPUT  (IR Sensor)

    while (1)
    {
        // Read Pin 2 (PD2). Most IR sensors output LOW (0) when detecting an object.
        if (!(PIND & (1 << PD2))) 
        {
            PORTB |= (1 << PB4);   // Pin 12 HIGH -> Relay ON
        }
        else 
        {
            PORTB &= ~(1 << PB4);  // Pin 12 LOW  -> Relay OFF
        }
    }
}