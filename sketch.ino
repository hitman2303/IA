#include <Servo.h>

Servo servoMaceta;
const int PIN_SERVO = 9;

void setup() {
  // Inicializa la velocidad del puerto serie a 9600 baudios
  Serial.begin(9600);
  servoMaceta.attach(PIN_SERVO);
  servoMaceta.write(0); // Posición inicial para la fase Semilla
}

void loop() {
  if (Serial.available() > 0) {
    // Lee el ángulo transmitido desde IdArduino.enviar()
    String lectura = Serial.readStringUntil('\n');
    lectura.trim();
    
    int angulo = lectura.toInt();
    
    // Asigna la posición mecánica al servomotor según la fase detectada
    if (angulo >= 0 && angulo <= 180) {
      servoMaceta.write(angulo);
    }
  }
}