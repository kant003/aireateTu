#include <HTTPClient.h>
#include <WiFi.h>

const String url = "https://api.thingspeak.com/update?api_key=";
const String API = "F0XGD8NQHGOKTJDJ"

int t ; 
int h; 
int co2;

void setup() {

}

void loop() {

  

}

String obtenerUrl(float t, float h, int co2) {
  return (url + API + "&Temperatura=" + t + "&Humedad=" + h + "&CO2=" + co2);
}

int insertarDatos(String url) {
    HTTPClient client;
    
    client.begin(url.c_str());
    int httpResponseCode = client.GET();
    client.end();

    return httpResponseCode > 0;
}
