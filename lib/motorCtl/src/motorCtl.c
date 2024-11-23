#include <avr/io.h>
#include "motorCtl.h"

/**
 * @brief Inicializa os pinos de controle dos motores e do servo motor.
 * 
 * Esta função configura os pinos de direção dos motores como saída, além de configurar
 * o pino do servo motor para o controle de movimento. O objetivo é preparar os pinos
 * para controle de direção de movimento e sinal PWM.
 */
void motorCtl_init() {
    // Configura os pinos de controle do motor 1 e o servo motor como saída
    DDRB |= (1 << MOTOR1CTL_DIR_E)   /**< Configura o pino MOTOR1CTL_DIR_E como saída */
         |  (1 << SERVOMOTOR_DIR);   /**< Configura o pino SERVOMOTOR_DIR como saída */

    // Configura os pinos de controle dos motores 1 e 2 como saída
    DDRD |= (1 << MOTOR1CTL_DIR_D)   /**< Configura o pino MOTOR1CTL_DIR_D como saída */
         |  (1 << MOTOR2CTL_DIR_E)   /**< Configura o pino MOTOR2CTL_DIR_E como saída */
         |  (1 << MOTOR2CTL_DIR_D);  /**< Configura o pino MOTOR2CTL_DIR_D como saída */
}

/**
 * @brief Inicializa o controle PWM dos motores e do servo motor.
 * 
 * Esta função configura os temporizadores para gerar os sinais PWM necessários
 * para o controle de velocidade dos motores e do servo motor. O servo motor é
 * inicialmente posicionado a cerca de 90 graus.
 */
void PWM_motors_init() {
    // Configura o temporizador para o controle PWM do servo motor
    TCCR2A = CONFIG_TCCR2A; /**< Configura o registrador TCCR2A para modo Fast PWM */
    TCCR2B = CONFIG_TCCR2B; /**< Configura o registrador TCCR2B com prescaler 128 */

    // Define o ângulo inicial do servo motor (aproximadamente 90 graus)
    alt_ServoAng(124); /**< Define o ângulo do servo motor para 90 graus */

    // Ativa a interrupção do temporizador para o canal OC2B
    TIMSK2 |= (1 << OCIE2B); /**< Habilita a interrupção do temporizador para OC2B */

    // Define a velocidade máxima dos motores (ciclo de trabalho máximo do PWM)
    motorCtl_setSpeed(255); /**< Define a velocidade máxima dos motores */
}

/**
 * @brief Define a velocidade dos motores.
 * 
 * Esta função define o ciclo de trabalho do PWM para controlar a velocidade
 * dos motores. O valor de `speed` define a largura do pulso PWM, com valores
 * possíveis de 0 (velocidade mínima) a 255 (velocidade máxima).
 * 
 * @param speed Valor de velocidade (0 a 255) para o controle PWM do motor.
 */
void motorCtl_setSpeed(char speed) {
    OCR2B = speed; /**< Define o valor de OCR2B para controlar a largura do pulso PWM */
}

/**
 * @brief Ajusta o ângulo do servo motor.
 * 
 * Esta função ajusta o valor de OCR2A, que controla o sinal PWM para o servo motor,
 * permitindo que ele mude sua posição de acordo com o valor de ângulo fornecido.
 * 
 * @param SERVO_DEG Valor de ângulo para o servo motor. O valor varia de 33 (0º) a 100 (180º).
 */
void alt_ServoAng(char SERVO_DEG) {
    OCR2A = SERVO_DEG; /**< Define o valor de OCR2A para ajustar a posição do servo motor */
}

/**
 * @brief Controla o movimento dos motores.
 * 
 * Esta função controla o modo de operação dos motores, permitindo que o robô
 * se mova para frente, para trás, vire para a esquerda ou para a direita. A
 * função altera os pinos de controle dos motores para definir a direção de movimento.
 * 
 * @param mode O modo de operação dos motores. As opções são:
 *             - 'F' para ir para frente (forward)
 *             - 'T' para ir para trás (backward)
 *             - 'E' para virar para a esquerda (left)
 *             - 'D' para virar para a direita (right)
 *             - Qualquer outro valor para parar os motores (stop)
 */
void motorCtl(char mode) {
    switch (mode) {
    case 'F':
        // Mover para frente
        PORTD ^= (1 << MOTOR1CTL_DIR_D); /**< Inverte o sentido de rotação do motor 1 */
        PORTD ^= (1 << MOTOR2CTL_DIR_D); /**< Inverte o sentido de rotação do motor 2 */
        break;
    case 'T':
        // Mover para trás
        PORTB ^= (1 << MOTOR1CTL_DIR_E); /**< Inverte a direção do motor 1 */
        PORTD ^= (1 << MOTOR2CTL_DIR_E); /**< Inverte a direção do motor 2 */
        break;
    case 'E':
        // Virar para a esquerda
        PORTB ^= (1 << MOTOR1CTL_DIR_E); /**< Inverte a direção do motor 1 */
        PORTD ^= (1 << MOTOR2CTL_DIR_D); /**< Inverte a direção do motor 2 */
        break;
    case 'D':
        // Virar para a direita
        PORTD ^= (1 << MOTOR1CTL_DIR_D); /**< Inverte a direção do motor 1 */
        PORTD ^= (1 << MOTOR2CTL_DIR_E); /**< Inverte a direção do motor 2 */
        break;
    default:
        // Parar os motores
        PORTB &= ~(1 << MOTOR1CTL_DIR_E); /**< Desativa o motor 1 */
        PORTD &= ~(1 << MOTOR2CTL_DIR_E); /**< Desativa o motor 2 */
        PORTD &= ~(1 << MOTOR1CTL_DIR_D); /**< Desativa o motor 1 */
        PORTD &= ~(1 << MOTOR2CTL_DIR_D); /**< Desativa o motor 2 */
    }
}
