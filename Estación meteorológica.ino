#include <DHT.h>
#include <BMP180.h>

#define DHTPIN 2
#define DHTTYPE DHT22
#define WIND_SENSOR_PIN 3

DHT dht(DHTPIN, DHTTYPE);
BMP180 bmp;

void setup() {
  Serial.begin(9600);
  dht.begin();
  if (!bmp.begin()) {
    Serial.println("Error al iniciar el sensor BMP180");
  }
  pinMode(WIND_SENSOR_PIN, INPUT);
}

void loop() {
  delay(2000); // Espera 2 segundos entre mediciones

  // Leer humedad y temperatura
  float humedad = dht.readHumidity();
  float temperatura = dht.readTemperature();

  // Leer presión atmosférica
  float presion = bmp.readPressure() / 100; // Convertir a hPa

  // Leer velocidad del viento
  int rpm = obtenerRPM(WIND_SENSOR_PIN);
  float velocidadViento = rpm / 1.492; // Ajusta el factor de conversión según tu anemómetro

  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.print(" °C, Humedad: ");
  Serial.print(humedad);
  Serial.print(" %, Presión: ");
  Serial.print(presion);
  Serial.print(" hPa, Velocidad del viento: ");
  Serial.print(velocidadViento);
  Serial.println(" km/h");
}

int obtenerRPM(int pin) {
  int revoluciones = 0;
 

