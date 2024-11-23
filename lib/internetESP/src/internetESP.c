#include <avr/io.h>
#include "internetESP.h"

/**
 * @brief Inicializa a comunicação USART.
 * 
 * Esta função configura a USART para comunicação serial com a taxa de baud
 * especificada pelo cálculo do prescaler. Ela configura os parâmetros necessários
 * para a comunicação, incluindo o formato dos dados (8 bits, 1 bit de parada) e
 * habilita a recepção e transmissão de dados. Também habilita a interrupção de
 * recepção.
 */
void USART_init()
{
    // Configura a taxa de baud
    UBRR0H = BAUD_PRESCALER >> 8; /**< Configura o byte alto do registrador de prescaler */
    UBRR0L = BAUD_PRESCALER;      /**< Configura o byte baixo do registrador de prescaler */

    // Configura a comunicação: 8 bits de dados, 1 bit de parada
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); /**< Configura o formato de quadro de dados (8 bits de dados e 1 bit de parada) */

    // Habilita o receptor e transmissor da USART
    UCSR0B = (1 << RXEN0) | (1 << TXEN0); /**< Habilita o RX (receptor) e TX (transmissor) da USART */

    // Habilita a interrupção de recepção
    UCSR0B |= (1 << RXCIE0); /**< Habilita a interrupção quando o dado for recebido */
}

/**
 * @brief Transmite um byte via USART utilizando polling.
 * 
 * Esta função envia um byte de dados pela USART, esperando até que o registrador
 * de dados esteja pronto para receber o próximo byte. Esse método usa polling, ou
 * seja, verifica periodicamente se a USART está pronta para enviar mais dados.
 * 
 * @param DataType O byte de dados a ser transmitido. O tipo do dado é `uint8_t`,
 * o que representa um valor de 1 byte.
 */
void USART_TransmitPolling(uint8_t DataType)
{
    // Espera até que o registrador de dados esteja pronto para receber um novo byte
    while ((UCSR0A & (1 << UDRE0)) == 0);

    // Transmite o dado
    UDR0 = DataType; /**< Envia o dado através do registrador de dados da USART */
}

/**
 * @brief Transmite uma string via USART.
 * 
 * Esta função envia uma sequência de caracteres (string) pela USART, transmitindo
 * cada caractere um de cada vez, utilizando a função `USART_TransmitPolling` para
 * cada caractere da string.
 * 
 * @param str Ponteiro para a string a ser transmitida. A função continua a transmitir
 * enquanto não encontrar o caractere nulo (`'\0'`), que indica o final da string.
 */
void USART_Transmit_String(const char* str) {
    // Transmite cada caractere da string
    while (*str) {
        USART_TransmitPolling(*str++); /**< Envia o próximo caractere da string */
    }
}
