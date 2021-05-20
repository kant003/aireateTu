#include <LiquidCrystal.h>

(rs, en, d4, d5, d6, d7)
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup() {
  lcd.begin(20,4);
}

int MostrarValores() {

  int sen1=analogRead(A0);
  float sen2=analogRead(A1)*(5.0 / 1023.0);
  float sen3=analogRead(A2)*(100.0 / 1023.0);
 //CO2
  lcd.setCursor(0,0);
  lcd.print("CO2: ");
  lcd.print(sen1);
  lcd.print("   ");
  //Humedad
  lcd.setCursor(11,1);  
  lcd.print("Humedad: ");
  lcd.print(sen2);
  lcd.print("%");
  //Temperatura
  lcd.setCursor(0,2);
  lcd.print("Temperatura:");
  lcd.print(sen3); 
  lcd.print(" 337C  ");
  
  
  
  delay(200);
  
}
