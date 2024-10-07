# Projeto de Monitoramento de Umidade do Solo
# Introdução
Este projeto foi desenvolvido no Tinkercad, como parte da disciplina de Internet
das Coisas (IoT), com o objetivo de criar um protótipo que monitora a umidade do
solo utilizando um sensor analógico. O sistema é projetado para ler e classificar 
os níveis de umidade, fornecendo feedback sobre as condições do solo.
O sensor de umidade é utilizado para medir a resistência elétrica do solo,
permitindo a identificação de três estados: solo seco, solo ideal e solo úmido.
Os dados são enviados para o monitor serial, permitindo a visualização em tempo real.

# Componentes Usados
1 Arduino Uno

1 Placa de Ensaio

1 Sensor de Umidade do Solo

1 Resistor de 10kΩ (opcional, dependendo do sensor)

3 Jumpers Macho-Macho

# Montagem do Circuito
![Imagem do Circuito](sensor_umidade.png)

# Explicação do Código

 Biblioteca para conexão serial do sensor
#include <SoftwareSerial.h>

 Variável do sensor
int sensor = A0;  Pino onde o sensor está conectado

void setup() {
   Definir o sensor como entrada
  pinMode(sensor, INPUT);
  
   Inicializando a comunicação serial
  Serial.begin(9600);
}

void loop() {
   Guardar o valor lido pelo sensor
  int umidade = analogRead(sensor);
  
   Imprimindo o valor lido
  Serial.print("Umidade do solo: ");  
  Serial.println(umidade);
  
   Classificação da umidade do solo
  if (umidade >= 0 && umidade <= 300) {
    Serial.println("Solo seco");
  } else if (umidade > 300 && umidade <= 500) {
    Serial.println("Solo ideal");
  } else if (umidade > 500) {
    Serial.println("Solo úmido");
  }

  delay(10000); // Espera 10 segundos antes da próxima leitura
}
Descrição do Código
Importação da Biblioteca:

A biblioteca SoftwareSerial é importada para permitir comunicação serial, embora neste projeto não seja estritamente necessária, podendo ser utilizada para outros sensores que requeiram uma comunicação diferente.
Definição do Pino do Sensor:

O pino analógico A0 é designado para a leitura do sensor de umidade do solo.
Função setup():

Define o pino do sensor como entrada e inicia a comunicação serial a uma taxa de 9600 bps.
Função loop():

Lê o valor de umidade do solo usando analogRead(sensor).
Imprime o valor lido e classifica a umidade do solo em três estados:
Solo seco (0 a 300)
Solo ideal (301 a 500)
Solo úmido (acima de 500)
Aguarda 10 segundos antes de repetir o ciclo.
