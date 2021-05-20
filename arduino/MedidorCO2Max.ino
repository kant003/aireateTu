int obtenerNivelCO2(){
return analogRead(A0);
}

int MQ;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
MQ = analogRead(A0);
Serial.println(MQ);
delay(500)
} 