#include <avr\io.h>
#include "internetESP.h"


void USART_init()
{
    // Set baud rate
    UBRR0H = BAUD_PRESCALER >> 8;
    UBRR0L = BAUD_PRESCALER;

    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); // 8-bit data, 1 stop bit

    UCSR0B = (1 << RXEN0) | (1 << TXEN0);

    UCSR0B |= (1 << RXCIE0);
}

// debug
void USART_TransmitPolling(uint8_t DataType)
{
  while ((UCSR0A & (1 << UDRE0)) == 0);
  UDR0 = DataType;
}

// Envia uma string
void USART_Transmit_String(const char* str) {
    while (*str) {
        USART_TransmitPolling(*str++);
    }
}