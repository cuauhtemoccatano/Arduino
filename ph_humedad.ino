#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Librerías para sensores
#include <DFRobot_PH.h>
#include <SimpleDHT.h>

// Definición de pines
#define PH_SENSOR_PIN A0  // Pin analógico para el sensor de pH
#define DHT_SENSOR_PIN 2   // Pin digital para el sensor de humedad del suelo

// Inicialización de objetos
DFRobot_PH ph;
SimpleDHT dht;

void setup() {
  Serial.begin(9600);
  
  // Inicialización del sensor de pH
  if (ph.begin(PH_SENSOR_PIN, 2) == 0) {
    Serial.println("Sensor de pH inicializado correctamente");
  } else {
    Serial.println("Error al inicializar el sensor de pH");
  }
  
  // Inicialización del sensor de humedad del suelo
  Serial.println("Sensor de humedad del suelo inicializado correctamente");
}

void loop() {
  // Lectura promediada del sensor de pH
  float pHValue = 0;
  for (int i = 0; i < 10; ++i) {
    pHValue += ph.readPH();
    delay(500);
  }
  pHValue /= 10;
  Serial.print("pH: ");
  Serial.println(pHValue);

  // Lectura del sensor de humedad del suelo
  byte temperature = 0;
  byte humidity = 0;
  if (dht.read(DHT_SENSOR_PIN, &temperature, &humidity, NULL) == SimpleDHTErrSuccess) {
    Serial.print("Temperatura: ");
    Serial.print(temperature);
    Serial.print("°C, Humedad: ");
    Serial.println(humidity);
  } else {
    Serial.println("Error al leer el sensor de humedad del suelo");
  }

  delay(1000);  // Puedes ajustar el intervalo de lectura según tus necesidades
}
