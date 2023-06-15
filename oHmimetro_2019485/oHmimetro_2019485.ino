/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Perito en electonica
 * Quinto perito
 * EB5AM 
 * Taller de electronica digital y reparacion de computadoras
 * Nombre: Diego Alejandro Culajay Gonzalez
*/

#include <LiquidCrystal_I2C.h>
#define Resistencia A0
//constructor
LiquidCrystal_I2C Pantalla(0x27,16,2);
float Calcular();

void setup() {
  Pantalla.init(); 
  Pantalla.backlight();
  pinMode(Resistencia, INPUT);
}

void loop() {
 float mostrar = Calcular();
 Pantalla.setCursor(1,0);
 Pantalla.print("Su Resistencia ");
 Pantalla.setCursor(2,1); 
 Pantalla.print(mostrar);
 Pantalla.print(" Ohms"); 
}

float Calcular(){
  float  vout, resultado = 0, R1=0, R2=0;
  float vr = analogRead(Resistencia);
  vout = (vr*5)/1023;
  R1 = (-vout)*(10000);
  R2 = vout-10;
  resultado = R1/R2;
  return resultado; 
  }
