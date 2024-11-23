#include <avr/interrupt.h>
#include <util/delay.h>
#include "motorCtl.c"
#include "internetESP.c"
#include "laser.c"
#include "receptor.h"
#include "vidas.c"

// Variáveis voláteis usadas nas interrupções
volatile uint8_t USART_ReceiveBuffer; /**< Buffer de recepção do USART */
volatile uint32_t contador = 0; /**< Contador para controlar o tempo em determinadas operações */

/**
 * @brief Interrupção do temporizador (TIMER2) para controlar os motores.
 * 
 * Esta função é chamada a cada compare match do temporizador TIMER2.
 * Ela controla a direção do motor com base no valor armazenado no buffer de recepção do USART.
 */
ISR(TIMER2_COMPB_vect) {
    motorCtl(USART_ReceiveBuffer); /**< Controla os motores com base no comando recebido via USART */
}

/**
 * @brief Interrupção de recepção de dados do USART.
 * 
 * Esta função é chamada quando dados são recebidos pelo USART.
 * Ela armazena o byte recebido no buffer e executa comandos específicos
 * com base no valor recebido, como iniciar o laser ou realizar ações de vida.
 */
ISR(USART_RX_vect) {
    USART_ReceiveBuffer = UDR0; /**< Armazena o dado recebido no buffer */

    // Comando para inicializar o laser
    if (USART_ReceiveBuffer == 'L' && contador == 0) {
        laserCtl_init(); /**< Inicializa o laser se o comando for 'L' */
    } 
    // Comando para a morte (matar)
    else if (USART_ReceiveBuffer == 'X') {
        die(); /**< Chama a função que trata a morte */
    } 
    // Comando para a sobrevivência
    else if (USART_ReceiveBuffer == 'I') {
        survive(); /**< Chama a função para indicar que o robô sobrevive */
    }
}

/**
 * @brief Função principal do programa.
 * 
 * A função principal inicializa os sistemas do robô, como o controle dos motores,
 * comunicação serial, controle de saúde e laser, e entra no loop principal
 * para monitorar o LDR e controlar os movimentos conforme os dados recebidos.
 */
int main() {
    // Limpa o flag global de interrupção
    cli();

    // Inicializa os pinos de controle dos motores
    motorCtl_init();
    PWM_motors_init();

    // Inicializa a comunicação serial
    USART_init();

    // Inicializa a saúde do robô
    vidas_init();

    // Habilita interrupções globais
    sei();

    // Loop principal
    while(1) {
        // Verifica se o temporizador atingiu o valor de parada para o laser
        if (TCNT1 >= 62499)
            laserCtl_stop(); /**< Para o laser quando o tempo de 1s é atingido */

        // Verifica se o LDR detectou luz (se o pino está em nível lógico alto)
        if (PINC & (1 << ldr)) {
            alt_ServoAng(249); /**< Ajusta o servo motor para a posição correspondente */
            updateLife(); /**< Atualiza a vida do robô com base no LDR */
            while (contador <= 2300000) { /**< Impede qualquer tipo de ação por 5s */
                USART_ReceiveBuffer = 'I'; /**< Envia o comando de sobrevivência */
                contador++; /**< Incrementa o contador */
            }
            alt_ServoAng(124); /**< Retorna o servo motor para a posição inicial */
            contador = 0; /**< Reseta o contador */
        }
    }

    return 0;
}
