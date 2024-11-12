#ifndef INTERNET_ESP_H

#define FREC_CPU 16000000UL

#define USART_BAUDRATE 9600
#define BAUD_PRESCALER ((FREC_CPU / (USART_BAUDRATE * 16UL)) - 1)

#define ASYNCHRONOUS 0b0000000

#define DISABLE     0b000000
#define EVEN_PARITY 0b100000
#define ODD_PARITY  0b110000
#define PARITY_MODE DISABLE

#define ONE_BIT  0b0000
#define TWO_BIT  0b1000
#define STOP_BIT ONE_BIT

#define FIVE_BIT  0b000
#define SIX_BIT   0b010
#define SEVEN_BIT 0b100
#define EIGHT_BIT 0b110
#define DATA_BIT  EIGHT_BIT

void USART_Start();
void USART_TransmitPolling(uint8_t DataType);
void testing();
void showVersion();
void setMode();
void showWifi();
void wifiLogin();

#endif