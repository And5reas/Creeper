#include <avr\interrupt.h>
#include <util\delay.h>
#include "motorCtl.c"
#include "internetESP.c"
#include "laser.c"

volatile uint8_t USART_ReceiveBuffer;

ISR(TIMER2_COMPB_vect)
{
    motorCtl(USART_ReceiveBuffer);
}

ISR(USART_RX_vect)
{
    USART_ReceiveBuffer = UDR0;

    if (USART_ReceiveBuffer == 'L') {
        // Initialize the laser timer1
        laserCtl_init();
    }
}

int main() {
    // Cleaning the global interrupt flag
    cli();

    // Initialize the motors control pins
    motorCtl_init();
    PWM_motors_init();
    
    // Initialize the serial communication
    USART_init();

    // Initialize the global interrupt flag
    sei();

    while(1) {
        if (TCNT1 >= 62499)
            laserCtl_stop();
    }

    return 0;
}