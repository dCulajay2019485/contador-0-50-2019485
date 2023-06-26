/*
CENTRO EDUCATIVO TECNICO LABORAL KINAL 
Electronica dispositivos digitales
Taller de electronica 
NOMBRES:
*Diego Alejandro Culajay Gonzalez
*Edgar Emmanuel Galvez Bol
Carnet
*2019485
*2019

*/

#include <Stepper.h>
#include <Servo.h>

#define LDR    A0  
#define ledAzul  2   
#define ledVerde 3   
#define ledRojo  4   
#define PIN1 15  
#define PIN2 16  
#define PIN3 17 
#define PIN4 18  
#define sensorO 12  
#define valido 8   
#define invalido 9  

int resultado_azul, resultado_rojo, resultado_verde;
int resultado;

int tol = 8; 

Stepper Banda(2048,PIN1,PIN2,PIN3,PIN4);   
Servo CuGa;  

void setup() {
  //Comunicacion serial
  Serial.begin(9600);

  pinMode(LDR, INPUT); 
  pinMode(ledAzul, OUTPUT); 
  pinMode(ledVerde, OUTPUT); 
  pinMode(ledRojo, OUTPUT);  
  pinMode(valido, OUTPUT);
  pinMode(invalido, OUTPUT);
  
  digitalWrite(ledAzul, LOW);
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledRojo, LOW);
  
  
  BanTrasn.setSpeed(15);

  CuGa.attach(6);
  CuGa.write(180);  
}

void loop() {
  if(digitalRead(sensorO) == true){  
    BanTrasn.step(-1);
    }
    if(digitalRead(sensorO) == false){   
    color();
    }
}
int color(){
  digitalWrite(ledRojo, HIGH);
  delay(50);
  resultado = analogRead(LDR);
  resultado_rojo = map(resultado, 0,1023,0,255);  
  digitalWrite(ledRojo, LOW);
  delay(50);
  digitalWrite(ledVerde, HIGH);
  delay(50);

  
  resultado = analogRead(LDR);
  resultado_verde = map(resultado, 0,1023,0,255);  
  digitalWrite(ledVerde, LOW);
  delay(50);
  digitalWrite(ledAzul, HIGH);
  delay(50);

  
  resultado = analogRead(LDR);
  resultado_azul = map(resultado, 0,1023,0,255);  
  digitalWrite(ledAzul, LOW);
  delay(50);

  if(resultado_verde > resultado_azul && resultado_verde > resultado_rojo){  
    digitalWrite(valido, HIGH); 
    Serial.println("Verde OK");
    Serial.println("Posicionado");
    BanTrasn.step(-2048);    /
    delay(100);
    Serial.println("Piston");
    CuGa.write(0);  
    delay(500);
    CuGa.write(180);  
    digitalWrite(valido, LOW); 
    }
    else{
      Serial.println("No valido");  
      for(int i = 0; i < 12; i++){
      digitalWrite(invalido, !digitalRead(invalido));
      delay(100);
      }
      BanTrasn.step(-5000);   
      }
  }
