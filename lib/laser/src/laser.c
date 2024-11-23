#include <avr/io.h>
#include "laser.h"

/**
 * @brief Inicializa o controle do laser.
 * 
 * Esta função configura o pino do laser como saída, inicializa o temporizador
 * com a configuração de prescaler definida e ativa o pino do laser para iniciar 
 * a operação do controle. O temporizador é configurado para começar a contar
 * a partir de zero.
 */
void laserCtl_init() {
    // Inicializa os pinos de controle do laser como saída
    DDRB |= (1 << laserPin); /**< Configura o pino laserPin como saída */

    // Configura o temporizador com o valor de prescaler definido
    TCCR1A = 0; /**< Configura o registrador TCCR1A para o modo normal */
    TCCR1B = CONFIG_TCCR1B; /**< Configura o registrador TCCR1B com o prescaler de 256 */

    // Ativa o laser, configurando o pino para nível lógico alto
    PORTB |= (1 << laserPin); /**< Configura o pino laserPin como nível lógico alto (laser ligado) */

    // Inicializa o contador do temporizador
    TCNT1 = 0; /**< Zera o contador do temporizador para iniciar a contagem a partir de 0 */
}

/**
 * @brief Para o controle do laser.
 * 
 * Esta função desativa o temporizador e desliga o laser, colocando o pino de controle
 * em nível lógico baixo, interrompendo a operação do laser.
 */
void laserCtl_stop() {
    // Desativa o temporizador, interrompendo qualquer contagem
    TCCR1B = 0; /**< Desliga o temporizador desabilitando o prescaler e o controle de contagem */

    // Zera o contador do temporizador
    TCNT1 = 0; /**< Zera o contador do temporizador */

    // Desliga o laser, colocando o pino de controle em nível lógico baixo
    PORTB &= ~(1 << laserPin); /**< Configura o pino laserPin para nível lógico baixo (laser desligado) */
}
