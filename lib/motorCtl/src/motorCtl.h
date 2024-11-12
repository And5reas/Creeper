#ifndef MOTOR_CTL_H

#define MOTOR1CTL_SPEED 255
#define MOTOR2CTL_SPEED 255

#define MOTOR1CTL_DIR_E 5
#define MOTOR1CTL_DIR_D 6

#define MOTOR2CTL_DIR_E 7
#define MOTOR2CTL_DIR_D 0

#define SERVOMOTOR_DIR 3

#define CONFIG_TCCR2A 0b10000011
#define CONFIG_TCCR2B 0b00000100

void setPWM_servo(char SERVO_DEG);
void setup_PINs();
void setupPWM_Servo();
void motorCtl(char mode);

#endif