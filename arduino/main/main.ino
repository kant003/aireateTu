#include <DHT.h>
#include <HTTPClient.h>
#include <LiquidCrystal_I2C.h>
#include <WiFi.h>

#define CO2PIN 34
#define DHTPIN 4
#define DHTTYPE DHT11
#define GREENLED 14
#define YELLOWLED 27
#define REDLED 26

const char* ssid = "Cebem_21";
const char* password = "Cebem2010";
const String api = "https://aireatetu.herokuapp.com/api/";
const String apiThing = "https://api.thingspeak.com/update?api_key=";
const String key = "F0XGD8NQHGOKTJDJ";
String mac = "";

LiquidCrystal_I2C lcd(0x27, 20, 4);
DHT sensor(DHTPIN, DHTTYPE);

int insertData(float temp, float humd, int co2, String mac);
void showOnLCD(float temp, float humd, float ppm, String mac);
void connectToWifi(const char* ssid, const char* password);
int getPPM();
float getHumidity();
float getTemp();
void turnHighPPMLEDS();
void turnLowPPMLEDS();
void turnMediumPPMLEDS();
void turnOffLEDS();

void setup() {
    Serial.begin(9600);
    sensor.begin();
    lcd.init();
    lcd.backlight();
    connectToWifi(ssid, password);

    pinMode(GREENLED, OUTPUT);
    pinMode(YELLOWLED, OUTPUT);
    pinMode(REDLED, OUTPUT);
}

void loop() {
    int ppm = getPPM();
    float temp = getTemp();
    float humd = getHumidity();

    showOnLCD(temp, humd, ppm, mac);

    if (insertData(temp, humd, ppm, mac)) {
        Serial.println("Successful GET petition!");
    } else {
        Serial.println("Error sending GET petition!");
    }

    delay(30000);
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
    mac = WiFi.macAddress();
    Serial.println("\nConnected!");
}

int insertData(float temp, float humd, int co2, String mac) {
    HTTPClient client;
    String path = api + "insertarDatos?temp=" + temp + "&humd=" + humd + "&co2=" + co2 + "&mac=" + mac;
    String pathThingSpeak = apiThing + key + "&Temperatura=" + temp + "&Humedad=" + humd + "&CO2=" + co2;

    client.begin(path.c_str());
    int apiResponseCode = client.GET();
    client.end();

    client.begin(pathThingSpeak.c_str());
    int apiThingResponse = client.GET();
    client.end();

    return apiResponseCode > 0 && apiThingResponse > 0;
}

int getPPM() {
    return analogRead(34);
}

float getTemp() {
    return sensor.readTemperature();
}

float getHumidity() {
    return sensor.readHumidity();
}

void showOnLCD(float temp, float humd, float ppm, String mac) {
    lcd.setCursor(0, 0);
    lcd.print("PPM: ");
    lcd.print(ppm);
    lcd.setCursor(0, 1);
    lcd.print("HUMD: ");
    lcd.print(humd);
    lcd.print("%");
    lcd.setCursor(0, 2);
    lcd.print("TEMP: ");
    lcd.print(temp);
    lcd.setCursor(0, 3);
    lcd.print(mac);
}

void turnHighPPMLEDS() {
    digitalWrite(GREENLED, LOW);
    digitalWrite(YELLOWLED, LOW);
    digitalWrite(REDLED, HIGH);
}

void turnMediumPPMLEDS() {
    digitalWrite(GREENLED, LOW);
    digitalWrite(YELLOWLED, HIGH);
    digitalWrite(REDLED, LOW);
}

void turnLowPPMLEDS() {
    digitalWrite(GREENLED, HIGH);
    digitalWrite(YELLOWLED, LOW);
    digitalWrite(REDLED, LOW);
}

void turnOffLEDS() {
    digitalWrite(GREENLED, LOW);
    digitalWrite(YELLOWLED, LOW);
    digitalWrite(REDLED, LOW);
}
