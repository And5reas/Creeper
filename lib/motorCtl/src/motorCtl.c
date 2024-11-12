#include <motorCtl.h>
#include <avr/io.h>

void setup_PINs(){
    DDRB |= (1 << MOTOR2CTL_DIR_D) 
         |  (1 << SERVOMOTOR_DIR);

    DDRD |= (1 << MOTOR1CTL_DIR_E)
         |  (1 << MOTOR1CTL_DIR_D)
         |  (1 << MOTOR2CTL_DIR_E);
}

void setPWM_servo(char SERVO_DEG) {
    OCR2A = SERVO_DEG;
}

void setupPWM_Servo() {
    // Set up the PWM timer
    TCCR2A = CONFIG_TCCR2A;
    TCCR2B = CONFIG_TCCR2B;
    setPWM_servo(85);
}

void motorCtl(char mode) {
    switch (mode)
    {
    case 0:
        PORTD |=  (1 << MOTOR1CTL_DIR_D);
        PORTD &= ~(1 << MOTOR1CTL_DIR_E);
        break;
    case 1:
        PORTD &= ~(1 << MOTOR1CTL_DIR_D);
        PORTD |=  (1 << MOTOR1CTL_DIR_E);
        break;
    case 2:
        PORTD |=  (1 << MOTOR2CTL_DIR_E);
        PORTB &= ~(1 << MOTOR2CTL_DIR_D);
        break;
    case 3:
        PORTD &= ~(1 << MOTOR2CTL_DIR_E);
        PORTB |=  (1 << MOTOR2CTL_DIR_D);
        break;
    case 4:
        PORTD |=  (1 << MOTOR1CTL_DIR_D);
        PORTB |=  (1 << MOTOR2CTL_DIR_D);
    default:
        PORTD  = 0;
        PORTB  = 0;
        break;
    }
}