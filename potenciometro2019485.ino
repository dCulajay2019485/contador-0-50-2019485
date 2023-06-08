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
int Potenciometro = A0; //Declaramos la entradas analógicas A0
int Led = 9;  //Declaramos el pin digital 9 como salidas digitales PWM
int valor=0; //creamos una variable valor de tipo entero para almacenar los valores de las lecturas analógicas

void setup ()
{ 
 pinMode(LEDR,OUTPUT); 
}

void loop()
{
int valor = analogRead(Potenciometro); // lee el valor del potenciómetro
analogWrite(Led, valor/4); 
}
