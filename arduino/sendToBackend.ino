#include <HTTPClient.h>
#include <WiFi.h>

const char* ssid = "";
const char* password = "";
const String api = "https://aireatetu.herokuapp.com/api/";

int insertarDatos(float temp, float humd, float co2);
void connectToWifi(const char* ssid, const char* password);

void setup() {
    Serial.begin(9600);

    connectToWifi(ssid, password);
    if (insertarDatos(32, 32, 32)) {
      Serial.println("Successful GET petition!");
    }
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

int insertarDatos(float temp, float humd, float co2) {
    HTTPClient client;
    String path = api + "insertarDatos?temp=" + temp + "&humd=" + humd + "&co2=" + co2;

    client.begin(path.c_str());
    int httpResponseCode = client.GET();
    client.end();

    return httpResponseCode > 0;
}

void loop() {

}
