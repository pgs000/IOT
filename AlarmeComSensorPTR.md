# AlarmeComSensorPTR
# Introdução
Este projeto utiliza um sensor PIR conectado ao Arduino para detectar movimento. Quando
um movimento é detectado, um buzzer emite um som e o LED vermelho é desligado. Quando não
há movimento, o LED vermelho é aceso. Esse sistema é útil para alertar sobre a presença de
pessoas em um ambiente.

# Componentes Usados

1 Arduino Uno

1 Sensor PIR

1 Buzzer Piezoelétrico

1 LED Vermelho

1 Resistor de 220 ohms (para o LED)

Jumpers Macho-Macho

# Montagem do Circuito

![Imagem do Circuito](AlarmeComSensorPTR.png)
# Explicação do Código
cpp
Copiar código
int sensorPIR = 3;              Pino conectado ao sensor PIR
int buzzer = 5;                 Pino conectado ao buzzer
int ledVermelho = 7;            Pino do LED vermelho

void setup() {
    pinMode(sensorPIR, INPUT);   Configura o pino do sensor PIR como entrada
    pinMode(buzzer, OUTPUT);      Configura o pino do buzzer como saída
    pinMode(ledVermelho, OUTPUT);  Configura o pino do LED vermelho como saída
    delay(2000);                  Espera 2 segundos para estabilizar o sensor
}

void loop() {
    int detectarPresenca = digitalRead(sensorPIR);  Lê o estado do sensor PIR
    
  if (detectarPresenca == HIGH) {  Verifica se há presença
        tone(buzzer, 264);            Toca um som no buzzer
        digitalWrite(ledVermelho, LOW);  Desliga o LED vermelho
    } else {
        noTone(buzzer);               Desliga o buzzer
        digitalWrite(ledVermelho, HIGH);  Liga o LED vermelho
    }
}
Definição das Variáveis
sensorPIR: Pino conectado ao sensor PIR para detectar movimento.
buzzer: Pino conectado ao buzzer para emitir sons.
ledVermelho: Pino conectado ao LED vermelho.
Funções Principais
setup(): Configura os pinos do sensor PIR, buzzer e LED como entrada ou saída, e aguarda 2 segundos para estabilizar o sensor.
loop(): Verifica continuamente se há movimento. Se houver, toca um som no buzzer e desliga o LED vermelho. Se não houver movimento, desliga o buzzer e acende o LED vermelho.
Este projeto é uma excelente maneira de aprender sobre sensores de movimento e controle de saída em Arduino. Você pode expandi-lo para adicionar mais funcionalidades, como um display ou mais LEDs.
