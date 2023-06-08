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

 #define led 9
 #define Potenciometro A0

 void setup(){
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(Potenciometro,INPUT);
  }

void loop(){
 encender();
}

void encender(){
  int valor = analogRead(Potenciometro);
  int mapeo = map(valor,0,1023,0,255);
  analogWrite(led,mapeo);    
    }
    
