#ifndef INTERNET_ESP_H

#define FREC_CPU 16000000UL

#define USART_BAUDRATE 9600
#define BAUD_PRESCALER ((FREC_CPU / 16 / USART_BAUDRATE) - 1)

void USART_init();
void USART_TransmitPolling(uint8_t DataType);

#endif