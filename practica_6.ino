 /*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de electronica digital y reparación de computadoras I
 * Nombre: Diego Alejandro Culajay Gonzalez
 * CARNE: 2019485
 * Proyecto: Practica 6
*/
#include <Wire.h>
#include <SPI.h>
#include <SparkFun_ADXL345.h>
#include <LedControl.h>

#define ancho_matriz 8 
#define alto_matriz 8
#define DIN_PIN 12
#define CLK_PIN 11
#define CS_PIN 10

float xg,yg,zg;
float soh;
float tilt;
float Angulo;

const byte desnivelmenos5[8] = {
  B00000000,
  B00000000,
  B11111111,
  B11111101,
  B11111101,
  B11111111,
  B00000000,
  B00000000
};

const byte desnivelmenos4[8] = {
  B00000000,
  B00000000,
  B11111111,
  B11111001,
  B11111001,
  B11111111,
  B00000000,
  B00000000
};

const byte desnivelmenos3[8] = {
  B00000000,
  B00000000,
  B11111111,
  B11111011,
  B11111011,
  B11111111,
  B00000000,
  B00000000
};

const byte desnivelmenos2[8] = {
  B00000000,
  B00000000,
  B11111111,
  B11110011,
  B11110011,
  B11111111,
  B00000000,
  B00000000
  };

const byte desnivelmenos1[8] = {
  B00000000,
  B00000000,
  B11111111,
  B11110111,
  B11110111,
  B11111111,
  B00000000,
  B00000000
  };

const byte centrado[8] = {
  B00000000,
  B00000000,
  B11111111,
  B11100111,
  B11100111,
  B11111111,
  B00000000,
  B00000000};

const byte desnivelmas1[8] = {
  B00000000,
  B00000000,
  B11111111,
  B11101111,
  B11101111,
  B11111111,
  B00000000,
  B00000000};

const byte desnivelmas2[8] = {
  B00000000,
  B00000000,
  B11111111,
  B11001111,
  B11001111,
  B11111111,
  B00000000,
  B00000000
};

const byte desnivelmas3[8] = {
  B00000000,
  B00000000,
  B11111111,
  B11011111,
  B11011111,
  B11111111,
  B00000000,
  B00000000
};

const byte desnivelmas4[8] = {
  B00000000,
  B00000000,
  B11111111,
  B10011111,
  B10011111,
  B11111111,
  B00000000,
  B00000000
};

const byte desnivelmas5[8] = {
  B00000000,
  B00000000,
  B11111111,
  B10111111,
  B10111111,
  B11111111,
  B00000000,
  B00000000
};

//Constructores
LedControl Mtriz_LED_de_Cula = LedControl(DIN_PIN,CLK_PIN,CS_PIN,1);
ADXL345 NIVEL = ADXL345();
void setup() {
   Serial.begin(9600);    
   Mtriz_LED_de_Cula.shutdown(0,false);    
   Mtriz_LED_de_Cula.setIntensity(0,15);  
   Mtriz_LED_de_Cula.clearDisplay(0);   
   NIVEL.powerOn();           
   NIVEL.setRangeSetting(8);       

}

void loop() {
   nivelacion();
   animacion();
   
}

void nivelacion(){
  int sumax = 0;
  int x, y, z;
  NIVEL.readAccel(&x, &y, &z);
     xg = x*0.0039;
     yg = y*0.0039;
     zg = z*0.0039;
     soh = xg/zg;

     tilt = atan(soh)*57.296;
}

void animacion(){
  Serial.println(tilt);
  if((abs(tilt) > 90)){  
    for (int i = alto_matriz; i > 0; i--) {
    Mtriz_LED_de_Cula.setColumn(0, i, desnivelmas5[i]);
      }
    for (int i = alto_matriz; i > 0; i--) {
    Mtriz_LED_de_Cula.setColumn(0, i, desnivelmenos5[i]);
      }
  }
  
  if((tilt < -60) && ( tilt >= -90) ){  
    for (int i = alto_matriz; i > 0; i--) {
    Mtriz_LED_de_Cula.setColumn(0, i, desnivelmenos5[i]);
      }
  }
  
  if((tilt < -45) && (tilt >= -60 )){  
    for (int i = alto_matriz; i > 0; i--) {
    Mtriz_LED_de_Cula.setColumn(0, i, desnivelmenos4[i]);
      }
  }
  if((tilt < -30) && (tilt >= -45 )){  
    for (int i = alto_matriz; i > 0; i--) {
    Mtriz_LED_de_Cula.setColumn(0, i, desnivelmenos3[i]);
      }
  }

  if((tilt < -15) && (tilt >= -30 )){ 
   for (int i = alto_matriz; i > 0; i--) {
    Mtriz_LED_de_Cula.setColumn(0, i, desnivelmenos2[i]);
      }
  }
  
  if((tilt < -5) && (tilt >= -15 )){  //Muy poco Inclinado hacia la izquierda
   for (int i = alto_matriz; i > 0; i--) {
    Mtriz_LED_de_Cula.setColumn(0, i, desnivelmenos1[i]);
      }
  }
  
  if(tilt >= -5 && tilt <= 5){  //Correctamente Nivelado
   for (int i = alto_matriz; i > 0; i--) {
    Mtriz_LED_de_Cula.setColumn(0, i, centrado[i]);
      }
  }

  if((tilt > 5) && (tilt <= 15 )){  //Muy poco inclinado hacia la derecha
   for (int i = alto_matriz; i > 0; i--) {
    Mtriz_LED_de_Cula.setColumn(0, i, desnivelmas1[i]);
      }
  }
  
  if((tilt > 15) && (tilt <= 30 )){  //Poco Inclinado hacia la izquierda
   for (int i = alto_matriz; i > 0; i--) {
    Mtriz_LED_de_Cula.setColumn(0, i, desnivelmas2[i]);
      }
  }

  if((tilt > 30) && (tilt <= 45 )){  //Muy Inclinado hacia la izquierda
   for (int i = alto_matriz; i > 0; i--) {
    Mtriz_LED_de_Cula.setColumn(0, i, desnivelmas3[i]);
      }
  }
  
  if((tilt > 45) && (tilt <= 60 )){  //Demasiado Inclinado hacia la izquierda
   for (int i = alto_matriz; i > 0; i--) {
    Mtriz_LED_de_Cula.setColumn(0, i, desnivelmas4[i]);
      }
  }
  if((tilt > 60) && (tilt <= 90 )){  //No valido
   for (int i = alto_matriz; i > 0; i--) {
    Mtriz_LED_de_Cula.setColumn(0, i, desnivelmas5[i]);
      }
  }
  }
