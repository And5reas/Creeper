#include <avr\io.h>
#include "internetESP.h"

void USART_Start()
{
    // Set baud rate
    UBRR0H = BAUD_PRESCALER >> 8;
    UBRR0L = BAUD_PRESCALER;

    UCSR0C = ASYNCHRONOUS | PARITY_MODE | STOP_BIT | DATA_BIT;

    UCSR0B = (1 << RXEN0) | (1 << TXEN0);
}

void USART_TransmitPolling(uint8_t DataType)
{
  while ((UCSR0A & (1 << UDRE0)) == 0);
  UDR0 = DataType;
}

void testing() 
{
    USART_TransmitPolling('A');
    USART_TransmitPolling('T');
}

void showVersion()
{
    USART_TransmitPolling('A');
    USART_TransmitPolling('T');
    USART_TransmitPolling('+');
    USART_TransmitPolling('G');
    USART_TransmitPolling('M');
    USART_TransmitPolling('R');
}

void setMode()
{
    USART_TransmitPolling('A');
    USART_TransmitPolling('T');
    USART_TransmitPolling('+');
    USART_TransmitPolling('C');
    USART_TransmitPolling('W');
    USART_TransmitPolling('M');
    USART_TransmitPolling('O');
    USART_TransmitPolling('D');
    USART_TransmitPolling('E');
    USART_TransmitPolling('=');
    USART_TransmitPolling('3');
}

void showWifi()
{
    USART_TransmitPolling('A');
    USART_TransmitPolling('T');
    USART_TransmitPolling('+');
    USART_TransmitPolling('C');
    USART_TransmitPolling('W');
    USART_TransmitPolling('L');
    USART_TransmitPolling('A');
    USART_TransmitPolling('P');
}

void wifiLogin()
{
    USART_TransmitPolling('A');
    USART_TransmitPolling('T');
    USART_TransmitPolling('+');
    USART_TransmitPolling('C');
    USART_TransmitPolling('W');
    USART_TransmitPolling('L');
    USART_TransmitPolling('A');
    USART_TransmitPolling('P');
    USART_TransmitPolling('=');
    USART_TransmitPolling('"');
    // nome da rede
    USART_TransmitPolling('"');
    USART_TransmitPolling(',');
    USART_TransmitPolling('"');
    // senha da rede
    USART_TransmitPolling('"');
}