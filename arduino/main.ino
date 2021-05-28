#include <HTTPClient.h>
#include <WiFi.h>
#include <DHT.h>

#define CO2PIN 34
#define DHTPIN 4
#define DHTTYPE DHT11

const char* ssid = "Cebem_21";
const char* password = "Cebem2010";
const String api = "https://aireatetu.herokuapp.com/api/";
int MQ;

DHT sensor(DHTPIN, DHTTYPE);

int insertarDatos(float temp, float humd, int co2);
int getCO2Level();
float getHumidity();
float getTemp();
void connectToWifi(const char* ssid, const char* password);

void setup() {
    Serial.begin(9600);
    sensor.begin();
    connectToWifi(ssid, password);
}

void connectToWifi(const char* ssid, const char* password) {
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);

    Serial.print("Connecting to...\t");
    Serial.println(ssid);
    while (WiFi.status() != WL_CONNECTED) {
        delay(200);
        Serial.print("..");
    }
    Serial.println("\nConnected!");
}

int insertarDatos(float temp, float humd, int co2) {
    HTTPClient client;
    String path = api + "insertarDatos?temp=" + temp + "&humd=" + humd + "&co2=" + co2;

    client.begin(path.c_str());
    int httpResponseCode = client.GET();
    client.end();

    return httpResponseCode > 0;
}

int getCO2Level() {
  return analogRead(34);
}

float getTemp() {
  return sensor.readTemperature();
}

float getHumidity() {
  return sensor.readHumidity();
}

void loop() {
  int ppm = getCO2Level();
  float temp = getTemp();
  float humd = getHumidity();

  if (insertarDatos(temp, humd, ppm)) {
    Serial.println("Successful GET petition!");
  } else {;
    Serial.println("Error sending GET petition!");
  }
  delay(60000);
}
