// incluir a biblioteca
 
#include <AccelStepper.h>
// conversão de gramas para steps
// 360º = 1024
// 180º = 512
// 90º = 256
// 60º = 170
// 45º = 128

// variavel para controlar as voltas do motor
#define voltas 1024 // Removido o '='
// criando objeto para controlar o motor
AccelStepper motor(AccelStepper::FULL4WIRE, 8, 10);

void setup() {
  // definir a velocidade máxima do motor
  motor.setMaxSpeed(1000);
  // definir aceleração máxima do motor
  motor.setAcceleration(100);
}

void loop() {
  // habilitar as portas de controle do motor no arduino 
  motor.run();
  // fazer o motor se movimentar a 360º/1024 passos 
  motor.moveTo(voltas); // Alterado para 'voltas'
  // girar a sentido contrario 
  motor.moveTo(-motor.currentPosition());
  delay(1000);
  
}
