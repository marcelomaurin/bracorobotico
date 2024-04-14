#include <Servo.h>

Servo servos[6]; // Cria um array de 6 servos

const int primeiroPinoServo = 2; // Define o primeiro pino onde o primeiro servo será conectado

void setup() {
  Serial.begin(9600); // Inicia a comunicação serial
  for (int i = 0; i < 6; i++) {
    servos[i].attach(primeiroPinoServo + i); // Conecta cada servo a um pino consecutivo
  }
}

void loop() {
  if (Serial.available() > 0) { // Verifica se há pelo menos um byte disponível na porta serial
    String input = Serial.readStringUntil(13); // Lê a linha até encontrar um caractere de retorno de carro (ASCII 13)

    if (input.length() >= 2) { // Verifica se a linha tem pelo menos 2 caracteres
      char servoNum = input.charAt(0); // Obtém o primeiro caractere (número do servo)
      char servoPos = input.charAt(1); // Obtém o segundo caractere (posição do servo)

      int servoIndex = servoNum - '0'; // Converte o número do servo de char para int
      int pos = servoPos - '0'; // Converte a posição do servo de char para int

      if (servoIndex >= 0 && servoIndex < 6 && pos >= 0 && pos <= 180) {
        servos[servoIndex].write(pos); // Define a posição do servo
      }
    }
  }
}
