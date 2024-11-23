#include <avr/io.h>
#include "vidas.h"

/**
 * @brief Atualiza o estado das vidas com base nas entradas.
 * 
 * Esta função verifica os estados das portas de entrada (PINC e PIND) e altera o 
 * estado das portas de saída (PORTC e PORTD) para refletir a mudança nas "vidas".
 * 
 * Caso o botão associado à variável 'max' (PINC) esteja pressionado, o estado das 
 * "vidas" é alterado conforme o mapeamento das portas de controle.
 */
void updateLife() {
    // Verifica se o botão máximo ('max') foi pressionado
    if (PINC & (1 << max)) {
        // Desliga o LED correspondente à vida máxima
        PORTC &= ~(1 << max);
        // Liga o LED correspondente à vida intermediária
        PORTD |= (1 << mid);
    } else
    // Caso o botão intermediário ('mid') seja pressionado
    if (PIND & (1 << mid)) {
        // Desliga o LED correspondente à vida intermediária
        PORTD &= ~(1 << mid);
        // Liga o LED correspondente à vida baixa
        PORTD |= (1 << low);
    } else {
        // Caso contrário, desliga o LED correspondente à vida baixa
        PORTD &= ~(1 << low);
    }
}

/**
 * @brief Inicializa as portas de entrada e saída para o controle das "vidas".
 * 
 * Esta função configura as direções das portas para as variáveis que representam
 * os LEDs (PORTC, PORTD) e o controle da bomba (PORTB). 
 * Os pinos são configurados como saída para permitir controle dos LEDs e a bomba.
 */
void vidas_init() {
    // Configura os pinos 'mid' e 'low' no PORTD como saída
    DDRD |= (1 << mid) | (1 << low);
    // Configura o pino 'max' no PORTC como saída
    DDRC |= (1 << max);
    // Configura o pino 'bomba' no PORTB como saída
    DDRB |= (1 << bomba);
    // Liga o LED correspondente à vida máxima ao inicializar
    PORTC |= (1 << max);
}

/**
 * @brief Ativa a bomba.
 * 
 * Esta função ativa o pino da bomba, configurando o valor do pino correspondente
 * em PORTB para '1'. Pode ser usado para simular uma ação de "morte" ou falha
 * no sistema de vidas.
 */
void die() {
    // Liga a bomba (porta 'bomba' no PORTB)
    PORTB |= (1 << bomba);
}

/**
 * @brief Desativa a bomba.
 * 
 * Esta função desativa o pino da bomba, configurando o valor do pino correspondente
 * em PORTB para '0'. Pode ser usado para simular a recuperação ou "sobrevivência"
 * no sistema de vidas.
 */
void survive() {
    // Desliga a bomba (porta 'bomba' no PORTB)
    PORTB &= ~(1 << bomba);
}
