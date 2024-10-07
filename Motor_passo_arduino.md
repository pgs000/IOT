# Projeto de Controle de Motor de Passo com Arduino

# Introdução

Este projeto utiliza um motor de passo controlado por um Arduino e a biblioteca
AccelStepper para movimentar o motor em passos específicos. O motor é programado 
para girar 360 graus e, em seguida, retornar à posição inicial, demonstrando um 
controle básico de movimento.

# Componentes Usados

1 Arduino Uno

1 Motor de Passo

4 Drivers de Motor (para conexão)

Jumpers Macho-Macho

# Montagem do Circuito
![Imagem do Circuito](motor_passo_arduino.png)

# Explicação do Código

 Incluir a biblioteca
#include <AccelStepper.h>

 Conversão de gramas para steps
 360° = 1024
 180° = 512
 90° = 256
 60° = 170
 45° = 128

 Variável para controlar as voltas do motor
#define voltas 1024

Criando o objeto para controlar o motor
AccelStepper motor(AccelStepper::FULL4WIRE, 8, 10, 9, 11);

void setup() {
     Definir a velocidade máxima do motor
    motor.setMaxSpeed(1000);
     Definir a aceleração máxima do motor
    motor.setAcceleration(100);
}

void loop() {
     Habilitar as portas de controle do motor no Arduino
    motor.run();
     Fazer o motor se movimentar a 360° (1024 passos)
    motor.moveTo(voltas);
     Girar em sentido contrário
    motor.moveTo(-motor.currentPosition());
    delay(1000);
}
Definição das Variáveis
voltas: Número de passos necessários para o motor completar uma volta de 360 graus (1024 passos).
motor: Objeto da classe AccelStepper para controlar o motor.

Funções Principais
setup(): Configura a velocidade e a aceleração máximas do motor para garantir um movimento suave.
loop(): Executa continuamente, ativando o motor, movendo-o 360 graus e retornando à posição inicial após um atraso de 1 segundo.
Esse projeto demonstra um controle simples de um motor de passo, que pode ser expandido para aplicações mais complexas, como robótica ou sistemas automatizados.



