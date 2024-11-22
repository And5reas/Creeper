#ifndef LASER_H

#define laserPin 5 // PB5

#define CONFIG_TCCR1A 0 // Normal
#define CONFIG_TCCR1B 0b00000100 // CS12 = prescaler 256

void laserCtl_init();
void laserCtl_stop();

#endif