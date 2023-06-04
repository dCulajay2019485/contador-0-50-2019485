 /*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de electronica digital y reparación de computadoras I
 * Nombre: Diego Alejandro Culajay Gonzalez
 * Carnet: 2019485
 * Proyecto: Uso de interrupciones externas - Bimestre III
*/

#define botonRising 2
#define botonFalling 3
#define encender(pin)   digitalWrite(pin,HIGH)
#define apagar(pin)     digitalWrite(pin,LOW)

void funcion_ISR_rising(void);
void funcion_ISR_falling(void);

volatile static bool F_print = false;
volatile static unsigned char i=0; 

void setup() {
  pines(); 
  attachInterrupt(digitalPinToInterrupt(botonRising),funcion_ISR_rising,RISING);
  attachInterrupt(digitalPinToInterrupt(botonFalling),funcion_ISR_falling,FALLING);
}
void loop() {
if (F_print){
  F_print = false; 
Serial.println(i);
  conteo();
}}

void pines(void){
  pinMode(botonRising,OUTPUT);
  pinMode(botonFalling,OUTPUT);
  for(int i=4; i<18;i++){
    pinMode(i,OUTPUT);
    }
  }
void conteo(){
  if(i==0){
  encender(4),encender(5),encender(6),encender(7),encender(8),encender(9),apagar(10);
  encender(11),encender(12),encender(13),encender(14),encender(15),encender(16),apagar(17);}
  if(i==1){
  encender(4),encender(5),encender(6),encender(7),encender(8),encender(9),apagar(10);
  apagar(11),encender(12),encender(13),apagar(14),apagar(15),apagar(16),apagar(17);}//1
  if(i==2){
  encender(4),encender(5),encender(6),encender(7),encender(8),encender(9),apagar(10);
  encender(11),encender(12),apagar(13),encender(14),encender(15),apagar(16),encender(17);}//2
  if(i==3){
  encender(4),encender(5),encender(6),encender(7),encender(8),encender(9),apagar(10);
  encender(11),encender(12),encender(13),encender(14),apagar(15),apagar(16),encender(17);}//3
  if(i==4){
  encender(4),encender(5),encender(6),encender(7),encender(8),encender(9),apagar(10);
  apagar(11),encender(12),encender(13),apagar(14),apagar(15),encender(16),encender(17);}//4
  if(i==5){
  encender(4),encender(5),encender(6),encender(7),encender(8),encender(9),apagar(10);
  encender(11),apagar(12),encender(13),encender(14),apagar(15),encender(16),encender(17);}//5
  if(i==6){
  encender(4),encender(5),encender(6),encender(7),encender(8),encender(9),apagar(10);
  apagar(11),apagar(12),encender(13),encender(14),encender(15),encender(16),encender(17);}//6
  if(i==7){
  encender(4),encender(5),encender(6),encender(7),encender(8),encender(9),apagar(10);
  encender(11),encender(12),encender(13),apagar(14),apagar(15),apagar(16),apagar(17);}//7
  if(i==8){
  encender(4),encender(5),encender(6),encender(7),encender(8),encender(9),apagar(10);
  encender(11),encender(12),encender(13),encender(14),encender(15),encender(16),encender(17);}//8
  if(i==9){
  encender(4),encender(5),encender(6),encender(7),encender(8),encender(9),apagar(10);
  encender(11),encender(12),encender(13),apagar(14),apagar(15),encender(16),encender(17);}//9
  if(i==10){
  apagar(4),encender(5),encender(6),apagar(7),apagar(8),apagar(9),apagar(10);
  encender(11),encender(12),encender(13),encender(14),encender(15),encender(16),apagar(17);}
  if(i==11){
  apagar(4),encender(5),encender(6),apagar(7),apagar(8),apagar(9),apagar(10);
  apagar(11),encender(12),encender(13),apagar(14),apagar(15),apagar(16),apagar(17);}//1
  if(i==12){
  apagar(4),encender(5),encender(6),apagar(7),apagar(8),apagar(9),apagar(10);
  encender(11),encender(12),apagar(13),encender(14),encender(15),apagar(16),encender(17);}//2
  if(i==13){
  apagar(4),encender(5),encender(6),apagar(7),apagar(8),apagar(9),apagar(10);
  encender(11),encender(12),encender(13),encender(14),apagar(15),apagar(16),encender(17);}//3
  if(i==14){
  apagar(4),encender(5),encender(6),apagar(7),apagar(8),apagar(9),apagar(10);
    apagar(11),encender(12),encender(13),apagar(14),apagar(15),encender(16),encender(17);}//4
  if(i==15){
  apagar(4),encender(5),encender(6),apagar(7),apagar(8),apagar(9),apagar(10);
  encender(11),apagar(12),encender(13),encender(14),apagar(15),encender(16),encender(17);}//5
  if(i==16){
  apagar(4),encender(5),encender(6),apagar(7),apagar(8),apagar(9),apagar(10);
  apagar(11),apagar(12),encender(13),encender(14),encender(15),encender(16),encender(17);}//6
  if(i==17){
  apagar(4),encender(5),encender(6),apagar(7),apagar(8),apagar(9),apagar(10);
  encender(11),encender(12),encender(13),apagar(14),apagar(15),apagar(16),apagar(17);}//7
  if(i==18){
  apagar(4),encender(5),encender(6),apagar(7),apagar(8),apagar(9),apagar(10);
  encender(11),encender(12),encender(13),encender(14),encender(15),encender(16),encender(17);}//8
  if(i==19){
  apagar(4),encender(5),encender(6),apagar(7),apagar(8),apagar(9),apagar(10);
  encender(11),encender(12),encender(13),apagar(14),apagar(15),encender(16),encender(17);}//9
  if(i==20){
  encender(4),encender(5),apagar(6),encender(7),encender(8),apagar(9),encender(10);//2
  encender(11),encender(12),encender(13),encender(14),encender(15),encender(16),apagar(17);}
  if(i==21){
  encender(4),encender(5),apagar(6),encender(7),encender(8),apagar(9),encender(10);//2
  apagar(11),encender(12),encender(13),apagar(14),apagar(15),apagar(16),apagar(17);}//1
  if(i==22){
  encender(4),encender(5),apagar(6),encender(7),encender(8),apagar(9),encender(10);//2
  encender(11),encender(12),apagar(13),encender(14),encender(15),apagar(16),encender(17);}//2
  if(i==23){
  encender(4),encender(5),apagar(6),encender(7),encender(8),apagar(9),encender(10);//2
  encender(11),encender(12),encender(13),encender(14),apagar(15),apagar(16),encender(17);}//3
  if(i==24){
  encender(4),encender(5),apagar(6),encender(7),encender(8),apagar(9),encender(10);//2
  apagar(11),encender(12),encender(13),apagar(14),apagar(15),encender(16),encender(17);}//4
  if(i==25){
  encender(4),encender(5),apagar(6),encender(7),encender(8),apagar(9),encender(10);//2
  encender(11),apagar(12),encender(13),encender(14),apagar(15),encender(16),encender(17);}//5
  if(i==26){
  encender(4),encender(5),apagar(6),encender(7),encender(8),apagar(9),encender(10);//2
  apagar(11),apagar(12),encender(13),encender(14),encender(15),encender(16),encender(17);}//6
  if(i==27){
  encender(4),encender(5),apagar(6),encender(7),encender(8),apagar(9),encender(10);//2
  encender(11),encender(12),encender(13),apagar(14),apagar(15),apagar(16),apagar(17);}//7
  if(i==28){
  encender(4),encender(5),apagar(6),encender(7),encender(8),apagar(9),encender(10);//2
  encender(11),encender(12),encender(13),encender(14),encender(15),encender(16),encender(17);}//8
  if(i==29){
  encender(4),encender(5),apagar(6),encender(7),encender(8),apagar(9),encender(10);//2
  encender(11),encender(12),encender(13),apagar(14),apagar(15),encender(16),encender(17);}//9
  if(i==30){
  encender(4),encender(5),encender(6),encender(7),apagar(8),apagar(9),encender(10);//3
  encender(11),encender(12),encender(13),encender(14),encender(15),encender(16),apagar(17);}
  if(i==31){
  encender(4),encender(5),encender(6),encender(7),apagar(8),apagar(9),encender(10);//3
  apagar(11),encender(12),encender(13),apagar(14),apagar(15),apagar(16),apagar(17);}//1
  if(i==32){
  encender(4),encender(5),encender(6),encender(7),apagar(8),apagar(9),encender(10);//3
  encender(11),encender(12),apagar(13),encender(14),encender(15),apagar(16),encender(17);}//2
  if(i==33){
  encender(4),encender(5),encender(6),encender(7),apagar(8),apagar(9),encender(10);//3
  encender(11),encender(12),encender(13),encender(14),apagar(15),apagar(16),encender(17);}//3
  if(i==34){
  encender(4),encender(5),encender(6),encender(7),apagar(8),apagar(9),encender(10);//3
  apagar(11),encender(12),encender(13),apagar(14),apagar(15),encender(16),encender(17);}//4
  if(i==35){
  encender(4),encender(5),encender(6),encender(7),apagar(8),apagar(9),encender(10);//3
  encender(11),apagar(12),encender(13),encender(14),apagar(15),encender(16),encender(17);}//5
  if(i==36){
  encender(4),encender(5),encender(6),encender(7),apagar(8),apagar(9),encender(10);//3
  apagar(11),apagar(12),encender(13),encender(14),encender(15),encender(16),encender(17);}//6
  if(i==37){
  encender(4),encender(5),encender(6),encender(7),apagar(8),apagar(9),encender(10);//3
  encender(11),encender(12),encender(13),apagar(14),apagar(15),apagar(16),apagar(17);}//7
  if(i==38){
  encender(4),encender(5),encender(6),encender(7),apagar(8),apagar(9),encender(10);//3
  encender(11),encender(12),encender(13),encender(14),encender(15),encender(16),encender(17);}//8
  if(i==39){
  encender(4),encender(5),encender(6),encender(7),apagar(8),apagar(9),encender(10);//3
  encender(11),encender(12),encender(13),apagar(14),apagar(15),encender(16),encender(17);}//9
  if(i==40){
  apagar(4),encender(5),encender(6),apagar(7),apagar(8),encender(9),encender(10);//4
  encender(11),encender(12),encender(13),encender(14),encender(15),encender(16),apagar(17);}
  if(i==41){
  apagar(4),encender(5),encender(6),apagar(7),apagar(8),encender(9),encender(10);//4
  apagar(11),encender(12),encender(13),apagar(14),apagar(15),apagar(16),apagar(17);}//1
  if(i==42){
  apagar(4),encender(5),encender(6),apagar(7),apagar(8),encender(9),encender(10);//4
  encender(11),encender(12),apagar(13),encender(14),encender(15),apagar(16),encender(17);}//2
  if(i==43){
  apagar(4),encender(5),encender(6),apagar(7),apagar(8),encender(9),encender(10);//4
  encender(11),encender(12),encender(13),encender(14),apagar(15),apagar(16),encender(17);}//3
  if(i==44){
  apagar(4),encender(5),encender(6),apagar(7),apagar(8),encender(9),encender(10);//4
  apagar(11),encender(12),encender(13),apagar(14),apagar(15),encender(16),encender(17);}//4
  if(i==45){
  apagar(4),encender(5),encender(6),apagar(7),apagar(8),encender(9),encender(10);//4
  encender(11),apagar(12),encender(13),encender(14),apagar(15),encender(16),encender(17);}//5
  if(i==46){
  apagar(4),encender(5),encender(6),apagar(7),apagar(8),encender(9),encender(10);//4
  apagar(11),apagar(12),encender(13),encender(14),encender(15),encender(16),encender(17);}//6
  if(i==47){
  apagar(4),encender(5),encender(6),apagar(7),apagar(8),encender(9),encender(10);//4
  encender(11),encender(12),encender(13),apagar(14),apagar(15),apagar(16),apagar(17);}//7
  if(i==48){
  apagar(4),encender(5),encender(6),apagar(7),apagar(8),encender(9),encender(10);//4
  encender(11),encender(12),encender(13),encender(14),encender(15),encender(16),encender(17);}//8
  if(i==49){
  apagar(4),encender(5),encender(6),apagar(7),apagar(8),encender(9),encender(10);//4
  encender(11),encender(12),encender(13),apagar(14),apagar(15),encender(16),encender(17);}//9
  if(i==50){
  encender(4),apagar(5),encender(6),encender(7),apagar(8),encender(9),encender(10);//5
  encender(11),encender(12),encender(13),encender(14),encender(15),encender(16),apagar(17);}
  }
  void funcion_ISR_rising(void){
F_print = true;
  i++;
 if (i>50){
  i=0;} }
void funcion_ISR_falling(void){
 F_print = true; 
  i--;
if (i>=255){
  i=50;}}
