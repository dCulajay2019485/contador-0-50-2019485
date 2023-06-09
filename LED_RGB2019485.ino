/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Perito en electonica
 * Quinto perito
 * EB5AM 
 * Taller de electronica digital y reparacion de computadoras
 * Nombre: Diego Alejandro Culajay Gonzalez
 * Carnet: 2019485
*/

#define RED 3
#define GREEN 5
#define BLUE 6
#define Pot A0
int POTPIN = 0;

void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(Pot,INPUT);
}

void loop() {
  RGB();
}

 void RGB(){
  int valor = analogRead(POTPIN);
  int mapeo = map(valor,0,1203,0,255);
  analogWrite(RED, 174);
  analogWrite(GREEN, 92);
  analogWrite(BLUE, 230);
  delay(valor);
  analogWrite(RED, 255);
  analogWrite(GREEN, 255);
  analogWrite(BLUE, 255);
  delay(valor);
  analogWrite(RED, 0);
  analogWrite(GREEN, 255);
  analogWrite(BLUE, 255);
  delay(valor);
  analogWrite(RED, 189);
  analogWrite(GREEN, 174);
  analogWrite(BLUE, 20);
  delay(valor);
  analogWrite(RED, 255);
  analogWrite(GREEN, 87);
  analogWrite(BLUE, 35);
  delay(valor);
  }
