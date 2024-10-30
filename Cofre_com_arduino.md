# Projeto: Trava de Segurança com Teclado e Servo Motor

Este projeto é uma trava de segurança eletrônica que utiliza um teclado matricial 4x4 e um servo motor, acionados através de uma senha. Ao inserir a senha correta, o servo motor gira e o piezo emite um som, indicando que a trava foi desbloqueada. Caso a senha esteja incorreta, o piezo ainda emite um som, mas o servo não realiza a ação completa. O projeto é desenvolvido para ser executado em um microcontrolador Arduino.

# Componentes Necessários

- Arduino Uno (ou outro compatível)
- Teclado matricial 4x4
- Servo motor
- Buzzer Piezo
- Fios de conexão

# Biblioteca Utilizada

- **Keypad**: Para o controle do teclado matricial, disponível na **Arduino IDE**.

# Montagem do Circuito

- **Teclado Matricial**: Conecte as linhas e colunas do teclado aos pinos digitais especificados no código.
- **Servo Motor**: Conecte o servo ao pino 11.
- **Buzzer Piezo**: Conecte o piezo ao pino 12.
- **Ligação com o Arduino**: Utilize os pinos digitais 3, 4, 5, 6 para as linhas do teclado e os pinos 7, 8, 9, 10 para as colunas.

*(Adicione aqui uma imagem do diagrama esquemático para facilitar a montagem)*

# Código do Projeto

Aqui está o código completo para o controle da trava:

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

const String correctPassword = "1537"; // Senha correta
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
        delay(100); // Pausa de 100 ms
        myServo.write(360); // Gira 360° se a senha estiver correta
        delay(6000); // Espera 6 segundos
      } else if (inputPassword.length() == correctPassword.length()) {
        tocarPiezo(); // Toca o piezo mesmo se a senha estiver incorreta
        delay(100); // Pausa de 100 ms
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

# Explicação do Código
Configuração do Teclado e Servo Motor:

O teclado é configurado para capturar entradas de um teclado 4x4, e o servo motor é posicionado inicialmente em 90°.
Funcionamento do Sistema de Senha:

O usuário insere a senha e finaliza a entrada ao pressionar #.
Caso a senha esteja correta (1537 por padrão), o piezo toca e o servo gira 360°, simbolizando o desbloqueio da trava.
Se a senha estiver incorreta, o piezo ainda toca, mas o servo não realiza o movimento completo.
Função tocarPiezo:

Emite um som de 1000Hz por 500 ms sempre que a senha é confirmada, correta ou incorreta.
Configuração e Ajustes
Senha: A senha padrão é "1537". Para alterá-la, basta modificar a variável correctPassword.
Pinos: Verifique as conexões dos pinos do teclado, servo e piezo para garantir que estejam de acordo com as especificações do código.
Contribuições
Sinta-se à vontade para fazer um fork do repositório e enviar melhorias. Qualquer contribuição é bem-vinda!

# Licença
Este projeto é licenciado sob a Licença MIT - veja o arquivo LICENSE para mais detalhes.

# Imagens do Projeto
