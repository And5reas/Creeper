#ifndef MOTOR_CTL_H

#define MOTOR1CTL_DIR_E 0 // PB0
#define MOTOR1CTL_DIR_D 7 // PD7

#define MOTOR2CTL_DIR_E 5 // PD5
#define MOTOR2CTL_DIR_D 6 // PD6

#define SERVOMOTOR_DIR 3  // PB3

#define CONFIG_TCCR2A 0b10100011 // COM2A1 | COM2B1 | WGM21 | WGM20 = Clear OC2A and OC2B on compare + Fast PWM
#define CONFIG_TCCR2B 0b00000100 // CS22 = prescaler 64

void motorCtl_init();
void PWM_motors_init();
void motorCtl_setSpeed(char speed);
void alt_ServoAng(char SERVO_DEG); // SERVO_DEG = MAX: 100 (180deg), MIN: 33 (0deg)
void motorCtl(char mode); // mode = I: stop, F: forward, T: backward, E: left, D: right
void USART_Transmit_String(const char* str);

#endif