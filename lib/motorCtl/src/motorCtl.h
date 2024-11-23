#ifndef MOTOR_CTL_H

/**
 * @brief Definições dos pinos de controle do motor 1.
 * 
 * O pino `MOTOR1CTL_DIR_E` (PB0) é utilizado para controlar a direção do motor 1.
 * O pino `MOTOR1CTL_DIR_D` (PD7) é utilizado para controlar o sentido da rotação
 * do motor 1, permitindo a movimentação em frente ou para trás.
 */
#define MOTOR1CTL_DIR_E 0 // PB0
#define MOTOR1CTL_DIR_D 7 // PD7

/**
 * @brief Definições dos pinos de controle do motor 2.
 * 
 * O pino `MOTOR2CTL_DIR_E` (PD5) é utilizado para controlar a direção do motor 2.
 * O pino `MOTOR2CTL_DIR_D` (PD6) é utilizado para controlar o sentido da rotação
 * do motor 2, permitindo a movimentação em frente ou para trás.
 */
#define MOTOR2CTL_DIR_E 5 // PD5
#define MOTOR2CTL_DIR_D 6 // PD6

/**
 * @brief Definição do pino de controle do servo motor.
 * 
 * O pino `SERVOMOTOR_DIR` (PB3) é utilizado para controlar o movimento do servo motor,
 * ajustando a posição do servo de acordo com o sinal PWM enviado.
 */
#define SERVOMOTOR_DIR 3  // PB3

/**
 * @brief Configuração do registrador TCCR2A para controle PWM.
 * 
 * A configuração `0b10100011` define o modo de operação para o temporizador 2, com
 * a configuração de **Fast PWM**. Isso permite a geração de sinais PWM para controle
 * de velocidade dos motores e do servo motor, utilizando os pinos de comparação OC2A e OC2B.
 */
#define CONFIG_TCCR2A 0b10100011 // COM2A1 | COM2B1 | WGM21 | WGM20 = Clear OC2A and OC2B on compare + Fast PWM

/**
 * @brief Configuração do registrador TCCR2B para controle PWM.
 * 
 * A configuração `0b00000101` define o prescaler para 128, permitindo uma base de
 * tempo adequada para gerar sinais PWM de alta resolução para controle de velocidade.
 */
#define CONFIG_TCCR2B 0b00000101 // CS22 | CS20 = prescaler 128

/**
 * @brief Inicializa o controle dos motores.
 * 
 * Esta função configura os pinos de controle dos motores como saída e realiza as
 * configurações iniciais para permitir o controle de direção e velocidade dos motores.
 */
void motorCtl_init();

/**
 * @brief Inicializa o PWM dos motores.
 * 
 * Esta função configura o temporizador 2 para gerar sinais PWM necessários para
 * controlar a velocidade dos motores. Ela também ajusta as configurações de controle
 * de PWM, como a frequência e a resolução.
 */
void PWM_motors_init();

/**
 * @brief Define a velocidade dos motores.
 * 
 * Esta função ajusta a velocidade dos motores, enviando um valor de controle PWM
 * correspondente à velocidade desejada. O valor de `speed` determina a largura do
 * pulso PWM que controlará a velocidade de rotação.
 * 
 * @param speed O valor de velocidade, representando o ciclo de trabalho do PWM.
 * Pode ser um valor entre 0 (velocidade mínima) e 255 (velocidade máxima).
 */
void motorCtl_setSpeed(char speed);

/**
 * @brief Ajusta o ângulo do servo motor.
 * 
 * Esta função ajusta a posição do servo motor com base no valor do ângulo fornecido.
 * O valor `SERVO_DEG` define a posição desejada, onde 100 corresponde a 180 graus
 * (posição máxima) e 33 corresponde a 0 grau (posição mínima).
 * 
 * @param SERVO_DEG O valor do ângulo para o servo motor. O valor pode variar de 33 (0º) a 100 (180º).
 */
void alt_ServoAng(char SERVO_DEG); // SERVO_DEG = MAX: 100 (180deg), MIN: 33 (0deg)

/**
 * @brief Controle do modo dos motores.
 * 
 * Esta função permite controlar o modo de operação dos motores. O parâmetro `mode`
 * pode ser utilizado para definir a direção do movimento dos motores, como parar, 
 * mover para frente, para trás, para a esquerda ou para a direita.
 * 
 * @param mode O modo de operação do motor. As opções são:
 *             - 'I' para parar (stop)
 *             - 'F' para mover para frente (forward)
 *             - 'T' para mover para trás (backward)
 *             - 'E' para mover para a esquerda (left)
 *             - 'D' para mover para a direita (right)
 */
void motorCtl(char mode); // mode = I: stop, F: forward, T: backward, E: left, D: right

/**
 * @brief Transmite uma string via USART.
 * 
 * Esta função envia uma sequência de caracteres (string) através da comunicação
 * serial USART. Ela transmite cada caractere da string, utilizando a função de
 * transmissão por polling para garantir que os dados sejam enviados corretamente.
 * 
 * @param str Ponteiro para a string a ser transmitida.
 */
void USART_Transmit_String(const char* str);

#endif
