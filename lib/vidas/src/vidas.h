#ifndef VIDAS_H

/**
 * @brief Definição do pino correspondente à vida intermediária.
 * 
 * Este valor define o pino PD2 (PORTD, pino 2) como o controle do LED
 * ou botão que representa a vida intermediária no sistema.
 */
#define mid 2 // PD2

/**
 * @brief Definição do pino correspondente à vida máxima.
 * 
 * Este valor define o pino PC3 (PORTC, pino 3) como o controle do LED
 * ou botão que representa a vida máxima no sistema.
 */
#define max 3 // PC3

/**
 * @brief Definição do pino correspondente à vida baixa.
 * 
 * Este valor define o pino PD4 (PORTD, pino 4) como o controle do LED
 * ou botão que representa a vida baixa no sistema.
 */
#define low 4 // PD4

/**
 * @brief Definição do pino correspondente ao controle da bomba.
 * 
 * Este valor define o pino PB4 (PORTB, pino 4) como o controle da bomba
 * que pode ser ligada ou desligada para indicar um evento de falha ou sucesso.
 */
#define bomba 4 // PB4

/**
 * @brief Atualiza o estado das "vidas" no sistema.
 * 
 * Esta função altera o estado das "vidas", verificando os valores das entradas
 * e controlando os LEDs ou outros dispositivos conectados aos pinos de saída.
 * 
 * As vidas são representadas por LEDs conectados aos pinos 'max', 'mid' e 'low'.
 * A função vai alternar o estado desses LEDs dependendo das condições verificadas.
 */
void updateLife();

/**
 * @brief Inicializa os pinos de controle das "vidas" e da bomba.
 * 
 * Esta função configura os pinos como saída para os LEDs e o controle da bomba.
 * Ela prepara o sistema de hardware para operação inicial, garantindo que os pinos
 * estejam devidamente configurados para acionar os LEDs e a bomba.
 */
void vidas_init();

/**
 * @brief Ativa a bomba.
 * 
 * Esta função ativa a bomba conectada ao pino PB4. Isso pode ser usado para 
 * indicar um estado de falha ou morte no sistema, ativando um dispositivo de 
 * resposta como um alarme ou outro mecanismo de controle.
 */
void die();

/**
 * @brief Desativa a bomba.
 * 
 * Esta função desativa a bomba conectada ao pino PB4. Ela pode ser usada para 
 * indicar que o sistema está em um estado seguro ou "sobrevivente", desativando 
 * o dispositivo de resposta.
 */
void survive();

#endif
