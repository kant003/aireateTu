#include <DHT.h>
#include <HTTPClient.h>
#include <WiFi.h>
#include <LiquidCrystal_I2C.h>

#define CO2PIN 34
#define DHTPIN 4
#define DHTTYPE DHT11

const char* ssid = "Cebem_21";
const char* password = "Cebem2010";
const String api = "https://aireatetu.herokuapp.com/api/";
const String apiThing = "https://api.thingspeak.com/update?api_key=";
const String key = "F0XGD8NQHGOKTJDJ";

LiquidCrystal_I2C lcd(0x27, 20, 4);
DHT sensor(DHTPIN, DHTTYPE);

int insertData(float temp, float humd, int co2);
void showOnLCD(float temp, float humd, float ppm);
void connectToWifi(const char* ssid, const char* password);
int getPPM();
float getHumidity();
float getTemp();

void setup() {
    Serial.begin(9600);
    sensor.begin();
    lcd.init();
    lcd.backlight();
    connectToWifi(ssid, password);
}

void loop() {
    int ppm = getPPM();
    float temp = getTemp();
    float humd = getHumidity();

    showOnLCD(temp, humd, ppm);

    if (insertData(temp, humd, ppm)) {
        Serial.println("Successful GET petition!");
    } else {
        Serial.println("Error sending GET petition!");
    }
    delay(60000);
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

int insertData(float temp, float humd, int co2) {
    HTTPClient client;
    String path = api + "insertarDatos?temp=" + temp + "&humd=" + humd + "&co2=" + co2;

    String pathThingSpeak = apiThing + key + "&Temperatura=" + temp + "&Humedad=" + humd + "&CO2=" + co2;

    client.begin(path.c_str());
    int httpResponseCode = client.GET();
    client.end();

    client.begin(pathThingSpeak.c_str());
    int apiThingResponse = client.GET();
    client.end();

    return httpResponseCode > 0 && apiThingResponse > 0;
}

int getPPM() {
    return analogRead(34);
}

void showOnLCD(float temp, float humd, float ppm) {
    lcd.setCursor(0, 0);
    lcd.print("PPM: ");
    lcd.print(ppm);
    lcd.setCursor(0, 1);
    lcd.print("H: ");
    lcd.print(humd);
    lcd.print("%");
    lcd.setCursor(0, 2);
    lcd.print("T: ");
    lcd.print(temp);
}

float getTemp() {
    return sensor.readTemperature();
}

float getHumidity() {
    return sensor.readHumidity();
}
