#ifndef LASER_H

/**
 * @brief Definição do pino do laser.
 * 
 * Este valor define o pino PB5 (PORTB, pino 5) como o pino de controle do laser.
 * Ele é utilizado para ativar ou desativar o laser no sistema.
 */
#define laserPin 5 // PB5

/**
 * @brief Configuração do registrador TCCR1A.
 * 
 * Este valor define a configuração do registrador TCCR1A, com o valor 0, que configura o temporizador 
 * no modo normal (sem nenhum modo de comparação de PWM ou outros modos avançados).
 */
#define CONFIG_TCCR1A 0 // Normal

/**
 * @brief Configuração do registrador TCCR1B.
 * 
 * Este valor define a configuração do registrador TCCR1B. O valor `0b00000100` configura o prescaler 
 * do temporizador para 256, o que significa que o temporizador terá uma frequência de contagem mais baixa,
 * o que é útil para controlar eventos que ocorrem com menor frequência.
 */
#define CONFIG_TCCR1B 0b00000100 // CS12 = prescaler 256

/**
 * @brief Inicializa o controle do laser.
 * 
 * Esta função configura o pino do laser e o temporizador para que o controle do laser funcione adequadamente.
 * A função pode configurar o pino como saída e configurar o temporizador com o prescaler adequado para gerar
 * pulsos ou eventos de controle do laser.
 */
void laserCtl_init();

/**
 * @brief Para o controle do laser.
 * 
 * Esta função desativa o laser, interrompendo qualquer pulso ou evento associado ao controle do temporizador.
 * Ela pode ser usada para desligar o laser ou parar sua operação.
 */
void laserCtl_stop();

#endif
