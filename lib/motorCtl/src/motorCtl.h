#ifndef MOTOR_CTL_H

#define MOTOR1CTL_SPEED 255
#define MOTOR2CTL_SPEED 255

#define MOTOR1CTL_DIR 1
#define MOTOR2CTL_DIR 2

#define SERVOMOTOR_DIR 3

#define CONFIG_TCCR2A 0b10000011
#define CONFIG_TCCR2B 0b00000100

void setPWM_servo(char SERVO_DEG);
void setup_PINs();
void setupPWM_Servo();
void motorCtl(char mode);

#endif