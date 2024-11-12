#include <avr/interrupt.h>
#include <util/delay.h>
#include <motorCtl.c>

int main(void)
{
  setup_PINs();
  setupPWM_Servo();

  while (1)
  {
    
  }
  

  return 0;
}