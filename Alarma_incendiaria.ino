#include <LedControl.h>
#include <Ticker.h>

#define PinDin 2
#define PinCS 4
#define PinClk 5
#define PinGas A0

void Sensor_GAS(void);
const int MatrizAN = 8; 
const int MatrizAL = 8; 
int gas;
int prom;

LedControl MALED = LedControl(PinDin,PinCS,PinClk,1);
Ticker ISR_GAS(Sensor_GAS, 1000);

byte LLAMA[8] = {
B00000000,
B00000000,
B00010000,
B00011000,
B00111000,
B00101100,
B00111100,
B00011000
};
byte LLAMA2[8] = {
B00001000,
B00001000,
B00011000,
B00011000,
B00101100,
B00100110,
B00010100,
B00111110
};
byte ESTRELLA [8] = {
B00011000,
B01000010,
B00100100,
B11111111,
B11111111,
B00100100,
B01000010,
B00011000
};

void setup() {
  MALED.shutdown(0, false); 
  MALED.setIntensity(0, 15); 
  MALED.clearDisplay(0); 
  pinMode(PinGas, INPUT); 
  ISR_GAS.start();
  Serial.begin(9600);
}

void loop() {
 ISR_GAS.update();
  if (prom > 90) {
    ALERTA();
  } else {
    for (int i = 0; i < MatrizAL; i++) {
    MALED.setColumn(0, i, ESTRELLA[i]);
  }
  }
  delay(1000);
}

void Leer(){
  int suma =0;
  for(int i = 0; i < 5; i++){
  gas = map(analogRead(PinGas),0,1023,0,100);
  suma = suma + gas;
  delay(100);
  }
  prom = suma/5;
  Serial.println(gas);
}

void ALERTA() {
  MALED.clearDisplay(0);
for(int t = 0; t<5;t++){
  for (int i = MatrizAL; i > 0; i--) {
    MALED.setColumn(0, i, LLAMA[i]);
  }
  delay(500);
  
  for (int i = MatrizAN; i > 0; i--) {
    MALED.setColumn(0, i, LLAMA2[i]);
  }
  delay(500);
}
}
