#include <DHT.h>

#define DHTPIN 2     // Pin digital al que está conectado el sensor DHT
#define DHTTYPE DHT11 // Tipo de sensor DHT (DHT11 o DHT22)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(2000); // Espera 2 segundos entre mediciones

  float humedad = dht.readHumidity();
  float temperatura = dht.readTemperature();

  if (isnan(humedad) || isnan(temperatura)) {
    Serial.println("Error al leer el sensor DHT");
    return;
  }

  Serial.print("Humedad: ");
  Serial.print(humedad);
  Serial.print(" %\t");
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C");
}

