#include <avr/io.h>
#include "laser.h"

void laserCtl_init() {
    // Initialize laser control pins
    DDRB |= (1 << laserPin);
    TCCR1A = 0;
    TCCR1B = CONFIG_TCCR1B;

    PORTB |= (1 << laserPin);

    TCNT1 = 0;
}

void laserCtl_stop() {
    // Stop laser control
    TCCR1B = 0;
    TCNT1 = 0;
    PORTB &= ~(1 << laserPin);
}