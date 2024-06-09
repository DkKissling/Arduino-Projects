#include <IRremote.h>

int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); // Iniciar receptor IR
}

void loop() {
  if (irrecv.decode(&results)) {
    unsigned int value = results.value;
    switch (value) {
      case 0xFD08F7: // Código para el botón 1
        Serial.println("Botón 1 presionado");
        break;
      case 0xFD8877: // Código para el botón 2
        Serial.println("Botón 2 presionado");
        break;
      // Agrega más casos para otros botones
      default:
        Serial.println("Código IR desconocido");
    }
    irrecv.resume(); // Recibir siguiente valor
  }
}

