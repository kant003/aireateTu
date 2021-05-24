// Definición de variables
int ledNivelBajo = 2;
int ledNivelMedio = 3;
int ledNivelAlto = 4;
//Varible auxiliar
int espera = 300;

void setup() {
  // Declaracion de salidas
  pinMode(ledNivelBajo, OUTPUT);
  pinMode(ledNivelMedio, OUTPUT);
  pinMode(ledNivelAlto, OUTPUT);
  

}

void loop() {
  // Codigo de testeo
 delay(espera);
 setCalidadBaja();
 delay(espera);
 setCalidadMedia();
 delay(espera);
 setCalidadAlta();
 delay(espera);
 apagarLeds();
}


// FUNCIONES

void setCalidadAlta(){
  digitalWrite(ledNivelBajo, LOW);
  digitalWrite(ledNivelMedio, LOW);
  digitalWrite(ledNivelAlto, HIGH);
}

void setCalidadMedia(){
  digitalWrite(ledNivelBajo, LOW);
  digitalWrite(ledNivelMedio, HIGH);
  digitalWrite(ledNivelAlto, LOW);
}

void setCalidadBaja(){
  digitalWrite(ledNivelBajo, HIGH);
  digitalWrite(ledNivelMedio, LOW);
  digitalWrite(ledNivelAlto, LOW);
}

void apagarLeds(){
  digitalWrite(ledNivelBajo, LOW);
  digitalWrite(ledNivelMedio, LOW);
  digitalWrite(ledNivelAlto, LOW);
}
