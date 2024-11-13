#include "motorCtl.c"
#include "internetESP.c"
#include <util\delay.h>

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// you can enable debug logging to Serial at 115200
//#define REMOTEXY__DEBUGLOG    

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__ESP8266_HARDSERIAL_POINT


// RemoteXY connection settings 
#define REMOTEXY_SERIAL Serial
#define REMOTEXY_SERIAL_SPEED 9600
#define REMOTEXY_WIFI_SSID "Vinicius"
#define REMOTEXY_WIFI_PASSWORD "101202303"
#define REMOTEXY_SERVER_PORT 6377

#include <RemoteXY.h>

// RemoteXY GUI configuration  
#pragma pack(push, 1)  
uint8_t RemoteXY_CONF[] =   // 69 bytes
  { 255,4,0,0,0,62,0,19,0,0,0,82,101,109,111,116,101,88,89,0,
  31,2,106,200,200,84,1,1,3,0,5,206,19,143,143,26,23,34,34,0,
  2,26,31,1,42,52,57,57,121,30,24,24,0,5,31,0,1,65,50,57,
  57,161,31,24,24,0,2,31,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  int8_t joystick_x; // from -100 to 100
  int8_t joystick_y; // from -100 to 100
  uint8_t Laser; // =1 if button pressed, else =0
  uint8_t Detonador; // =1 if button pressed, else =0

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0

} RemoteXY;   
#pragma pack(pop)
 
/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

unsigned char MotorDireita[2] = {MOTOR1CTL_DIR_D, MOTOR1CTL_DIR_E};
unsigned char MotorEsquerda[2] = {MOTOR2CTL_DIR_D, MOTOR2CTL_DIR_E};

void laser()
{
  if(RemoteXY.Laser == 1)
  {
    PORTB |= (1 << PB5);
  }
  else
  {
    PORTB &= ~(1 << PB5);
  }
}

void direcao(unsigned char * motor, int v)
{
  if(v > 100) v = 100;

  if(v < -100) v = -100;

  if(v == 0) v = 0;

  motorCtl(v);
}
int main(void)
{
  RemoteXY_Init();
  USART_Start();

  setup_PINs();
  setupPWM_Servo();

  while (1)
  {
    RemoteXY_Handler();
    direcao(MotorDireita, RemoteXY.joystick_y - RemoteXY.joystick_x);
    direcao(MotorEsquerda, RemoteXY.joystick_y + RemoteXY.joystick_x);
    showVersion();
    laser();
    _delay_ms(1000);
  }
  

  return 0;
}