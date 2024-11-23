#ifndef INTERNET_ESP_H

#define FREC_CPU 16000000UL /**< @brief Frequência do clock do microcontrolador (16 MHz) */

/**
 * @brief Definição da taxa de baud para comunicação USART.
 * 
 * A taxa de baud define a velocidade de comunicação da USART. Aqui, ela está configurada
 * para 9600 bps (bits por segundo). A taxa de baud é um parâmetro importante para
 * garantir que a comunicação serial seja feita de maneira eficiente.
 */
#define USART_BAUDRATE 9600

/**
 * @brief Cálculo do prescaler para a taxa de baud da USART.
 * 
 * O prescaler é calculado de acordo com a frequência do processador e a taxa de baud
 * desejada. Esse valor será utilizado para configurar o registrador de controle da USART
 * de forma a garantir que a comunicação ocorra na taxa correta.
 * 
 * @note O valor calculado é o que será utilizado no registrador de controle da USART.
 */
#define BAUD_PRESCALER ((FREC_CPU / 16 / USART_BAUDRATE) - 1) /**< @brief Prescaler para a taxa de baud da USART */

/**
 * @brief Inicializa a comunicação USART.
 * 
 * Esta função configura os parâmetros necessários para a comunicação USART, como
 * a taxa de baud, o modo de operação (por exemplo, modo assíncrono) e o controle de
 * interrupções ou flags. A função prepara a USART para transmissão e recepção de dados.
 */
void USART_init();

/**
 * @brief Transmite dados via USART usando polling.
 * 
 * Esta função envia um dado para a USART de forma síncrona, ou seja, ela vai aguardar
 * a disponibilidade do registrador de dados para enviar o próximo byte. Esse método de
 * "polling" garante que os dados sejam transmitidos um de cada vez e sem interrupções.
 * 
 * @param DataType O dado a ser transmitido via USART. Este parâmetro pode ser de qualquer
 * tipo que seja compatível com a USART (por exemplo, `uint8_t` para dados de 1 byte).
 */
void USART_TransmitPolling(uint8_t DataType);

#endif
