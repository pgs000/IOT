#include <Keypad.h>
#include <Servo.h>

const byte ROWS = 4; // quatro linhas
const byte COLS = 4; // quatro colunas

char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {3, 4, 5, 6}; // pinos das linhas
byte colPins[COLS] = {7, 8, 9, 10}; // pinos das colunas

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
Servo myServo;

const String correctPassword = "1237"; // Senha correta
String inputPassword = ""; // Senha digitada pelo usuário

const int piezoPin = 12; // Pino para o piezo

void setup() {
  myServo.attach(11); // Conecta o servo no pino 11
  myServo.write(90); // Inicializa o servo na posição 0
  pinMode(piezoPin, OUTPUT); // Configura o pino do piezo como saída
  Serial.begin(6000); // Inicia a comunicação serial para depuração
}

void loop() {
  char key = keypad.getKey(); // Captura a tecla pressionada

  if (key) {
    if (key == '#') { // Finaliza a entrada da senha ao pressionar '#'
      Serial.print("Senha digitada: "); // Para depuração
      Serial.println(inputPassword); // Mostra a senha digitada
      if (inputPassword == correctPassword) {
        tocarPiezo(); // Toca o piezo quando a senha estiver correta
        delay(100); // Pausa por 5 segundos
        myServo.write(360); // Gira 360° se a senha estiver correta
        delay(6000); // Espera 6 segundos
      } else if (inputPassword.length() == correctPassword.length()) {
        tocarPiezo(); // Toca o piezo mesmo se a senha estiver incorreta
        delay(100); // Pausa por 6 segundos
        myServo.write(360); // Gira 180° para senhas de 4 dígitos incorretas
        delay(6000); // Espera 6 segundos
      }
      myServo.write(90); // Retorna o servo para a posição inicial
      inputPassword = ""; // Reseta a senha digitada
    } else {
      inputPassword += key; // Adiciona a tecla pressionada à senha
    }
  }
}

// Função para tocar o piezo
void tocarPiezo() {
  tone(piezoPin, 1000, 500); // Toca uma frequência de 1000Hz por 500ms
}
