// biblioteca para conexão serial do sensor
#include <SoftwareSerial.h>

// variável do sensor
int sensor = A0;

// pinos dos LEDs
const int ledVermelho = 11; // LED para solo seco
const int ledVerde = 10;    // LED para solo ideal
const int ledAzul = 9;      // LED para solo úmido

void setup() {
  // definir o sensor como entrada
  pinMode(sensor, INPUT);
  
  // configurar os pinos dos LEDs como saída
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAzul, OUTPUT);
  
  // iniciando o monitor serial
  Serial.begin(9600);
}

void loop() {
  // guardar o valor lido pelo sensor
  int umidade = analogRead(sensor);
  
  // Exibir a umidade do solo
  Serial.print("Umidade do solo: ");
  Serial.println(umidade);
  
  // Verificar a umidade e acender o LED correspondente
  if (umidade < 300) {
    Serial.println("Solo seco");
    digitalWrite(ledVermelho, HIGH); // acende o LED vermelho
    digitalWrite(ledVerde, LOW);      // apaga o LED verde
    digitalWrite(ledAzul, LOW);       // apaga o LED azul
  } else if (umidade >= 300 && umidade <= 500) {
    Serial.println("Solo ideal");
    digitalWrite(ledVermelho, LOW);    // apaga o LED vermelho
    digitalWrite(ledVerde, HIGH);      // acende o LED verde
    digitalWrite(ledAzul, LOW);         // apaga o LED azul
  } else {
    Serial.println("Solo úmido");
    digitalWrite(ledVermelho, LOW);     // apaga o LED vermelho
    digitalWrite(ledVerde, LOW);        // apaga o LED verde
    digitalWrite(ledAzul, HIGH);        // acende o LED azul
  }

  delay(5000); // espera 5 segundos
}
