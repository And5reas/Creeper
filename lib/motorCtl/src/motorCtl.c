#include <avr/io.h>
#include "motorCtl.h"

void motorCtl_init(){
    DDRB |= (1 << MOTOR1CTL_DIR_E) 
         |  (1 << SERVOMOTOR_DIR);

    DDRD |= (1 << MOTOR1CTL_DIR_D)
         |  (1 << MOTOR2CTL_DIR_E)
         |  (1 << MOTOR2CTL_DIR_D);
}

void PWM_motors_init() {
    // Set up the servo PWM timer
    TCCR2A = CONFIG_TCCR2A;
    TCCR2B = CONFIG_TCCR2B;
    alt_ServoAng(85); // Aprox 90 degrees

    TIMSK2 |= (1 << OCIE2B);
    motorCtl_setSpeed(255);
}

void motorCtl_setSpeed(char speed) {
    OCR2B = speed;
}

void alt_ServoAng(char SERVO_DEG) {
    OCR2A = SERVO_DEG;
}

void motorCtl(char mode) {
    switch (mode)
    {
    case 'F':
        // Go forward
        PORTD ^= (1 << MOTOR1CTL_DIR_D);
        PORTD ^= (1 << MOTOR2CTL_DIR_D);
        break;
    case 'T':
        // Go backward
        PORTB ^= (1 << MOTOR1CTL_DIR_E);
        PORTD ^= (1 << MOTOR2CTL_DIR_E);
        break;
    case 'E':
        // Turn left
        PORTB ^= (1 << MOTOR1CTL_DIR_E);
        PORTD ^= (1 << MOTOR2CTL_DIR_D);
        break;
    case 'D':
        // Turn right
        PORTD ^= (1 << MOTOR1CTL_DIR_D);
        PORTD ^= (1 << MOTOR2CTL_DIR_E);
        break;
    default:
        // Stop motors
        PORTB &= ~(1 << MOTOR1CTL_DIR_E);
        PORTD &= ~(1 << MOTOR2CTL_DIR_E);
        PORTD &= ~(1 << MOTOR1CTL_DIR_D);
        PORTD &= ~(1 << MOTOR2CTL_DIR_D);
    }
}