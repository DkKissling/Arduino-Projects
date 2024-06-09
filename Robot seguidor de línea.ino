#define MOTOR_IZQUIERDO_1 2
#define MOTOR_IZQUIERDO_2 3
#define MOTOR_DERECHO_1 4
#define MOTOR_DERECHO_2 5

#define SENSOR_IZQUIERDO A0
#define SENSOR_DERECHO A1

void setup() {
  pinMode(MOTOR_IZQUIERDO_1, OUTPUT);
  pinMode(MOTOR_IZQUIERDO_2, OUTPUT);
  pinMode(MOTOR_DERECHO_1, OUTPUT);
  pinMode(MOTOR_DERECHO_2, OUTPUT);
}

void loop() {
  int sensorIzquierdo = analogRead(SENSOR_IZQUIERDO);
  int sensorDerecho = analogRead(SENSOR_DERECHO);

  if (sensorIzquierdo < 500 && sensorDerecho < 500) {
    avanzar();
  } else if (sensorIzquierdo < 500 && sensorDerecho >= 500) {
    girarIzquierda();
  } else if (sensorIzquierdo >= 500 && sensorDerecho < 500) {
    girarDerecha();
  } else {
    detenerse();
  }
}

void avanzar() {
  digitalWrite(MOTOR_IZQUIERDO_1, HIGH);
  digitalWrite(MOTOR_IZQUIERDO_2, LOW);
  digitalWrite(MOTOR_DERECHO_1, HIGH);
  digitalWrite(MOTOR_DERECHO_2, LOW);
}

void girarIzquierda() {
  digitalWrite(MOTOR_IZQUIERDO_1, LOW);
  digitalWrite(MOTOR_IZQUIERDO_2, HIGH);
  digitalWrite(MOTOR_DERECHO_1, HIGH);
  digitalWrite(MOTOR_DERECHO_2, LOW);
}

void girarDerecha() {
  digitalWrite(MOTOR_IZQUIERDO_1, HIGH);
  digitalWrite(MOTOR_IZQUIERDO_2, LOW);
  digitalWrite(MOTOR_DERECHO_1, LOW);
  digitalWrite(MOTOR_DERECHO_2, HIGH);
}

void detenerse() {
  digitalWrite(MOTOR_IZQUIERDO_1, LOW);
  digitalWrite(MOTOR_IZQUIERDO_2, LOW);
  digitalWrite(MOTOR_DERECHO_1, LOW);
  digitalWrite(MOTOR_DERECHO_2, LOW);
}

