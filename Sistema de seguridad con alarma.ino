#include <Servo.h>

#define PIR_PIN 2
#define BUZZER_PIN 3
#define SERVO_PIN 9

Servo servo;
int estado = LOW;
int valorPIR = 0;

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  servo.attach(SERVO_PIN);
  Serial.begin(9600);
}

void loop() {
  valorPIR = digitalRead(PIR_PIN);
  if (valorPIR == HIGH) {
    if (estado == LOW) {
      Serial.println("Movimiento detectado!");
      estado = HIGH;
      activarAlarma();
    }
  } else {
    estado = LOW;
    desactivarAlarma();
  }
}

void activarAlarma() {
  tone(BUZZER_PIN, 1000); // Emitir sonido de alarma
  servo.write(180); // Mover el servo a la posición de alarma
}

void desactivarAlarma() {
  noTone(BUZZER_PIN); // Detener el sonido de alarma
  servo.write(0); // Mover el servo a la posición de reposo
}

