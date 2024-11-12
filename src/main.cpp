#include "motorCtl.c"
#include "internetESP.c"
#include <util\delay.h>

int main(void)
{
  USART_Start();

  setup_PINs();
  setupPWM_Servo();

  while (1)
  {
    showVersion();
    _delay_ms(1000);
  }
  

  return 0;
}