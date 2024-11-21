#include <avr\io.h>
#include "internetESP.h"

volatile uint8_t USART_ReceiveBuffer;

ISR(USART_RX_vect) {
    USART_ReceiveBuffer = UDR0;
    if (USART_ReceiveBuffer == 'F') {
        
    }
}

void USART_Start()
{
    // Set baud rate
    UBRR0H = BAUD_PRESCALER >> 8;
    UBRR0L = BAUD_PRESCALER;

    UCSR0C = ASYNCHRONOUS | PARITY_MODE | STOP_BIT | DATA_BIT;

    UCSR0B = (1 << RXEN0) | (1 << TXEN0);

    UCSR0B |= (1 << RXCIE0);

    sei();
}

void USART_TransmitPolling(uint8_t DataType)
{
  while ((UCSR0A & (1 << UDRE0)) == 0);
  UDR0 = DataType;
}