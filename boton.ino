int pulsador=0;

void setup() {
  pinMode(12, OUTPUT);
  pinMode(8, INPUT);
}

void loop() {
  if (digitalRead(8) == HIGH) {
    digitalWrite(12, HIGH);
  }
  else {
    digitalWrite(12, LOW);
  }
}
