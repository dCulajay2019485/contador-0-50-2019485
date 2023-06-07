/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Perito en electonica
 * Quinto perito
 * EB5AM 
 * Taller de electronica digital y reparacion de computadoras
 * Nombre: Diego Alejandro Culajay Gonzalez
*/

#include <DallasTemperature.h>
#include <OneWire.h>
#include <Ticker.h>

#define boton 3

volatile static bool estado;

void Temperatura(void);
void Boton(void);

OneWire ourWire(2);
DallasTemperature sensor(&ourWire);
Ticker accionTemperatura(Temperatura,3000);
Ticker accionBoton(Boton,6000);


void setup() {
  Serial.begin(9600);
  pinMode(boton,INPUT);
  sensor.begin();
  accionTemperatura.start();
  accionBoton.start();
  Serial.println("Midiendo temperatura");
}

void loop() {
accionTemperatura.update();
accionBoton.update();
}
 void Boton(void){
  estado = digitalRead(boton);
  if(estado == HIGH){
  Serial.println("Boton activo");}
  if(estado == LOW){
    Serial.println("boton innactivo");
    }
  }

void Temperatura(void){
 sensor.requestTemperatures();
 float temp= sensor.getTempCByIndex(0);
 Serial.print("////////");
 Serial.print("temperatura es:");
 Serial.print(temp);
 Serial.print("C");
 Serial.println("////////");
}
