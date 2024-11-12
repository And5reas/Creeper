#include <motorCtl.h>
#include <avr/io.h>

void setup_PINs(){
    DDRB |= (1 << MOTOR1CTL_DIR) | (1 << MOTOR2CTL_DIR) | (1 << SERVOMOTOR_DIR);
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
    
}