#include <DHT.h>

#define DHTPIN 10
#define DHTTYPE DHT11

DHT sensor(DHTPIN, DHTTYPE);


public :
float obtenerTemperatura(){
 return sensor.readTemperature();
}

float obtenerHumedad(){
  return sensor.Humidity();
}


void setup() {
  Serial.begin(9600);
  sensor.begin();
}

void loop() {
 delay(2500);
 sensor.readHumidity();
 sensor.readTemperature();
}