/*************************************************************************************
**                                                                                  **
**             Aquest programa fa un test del display seven segment                 **
**             primer engega i apaga cadascun dels segments i despres               **
**             presenta els numeros del 0 al 9.                                     **
**                                                                                  **
*************************************************************************************/
 
//******  Includes  ******************************************************************



//******  Variables  *****************************************************************

// Cal utilitzar aquests dos parametres si es catode comu
const char ledOn = HIGH;
const char ledOff = LOW;
// Cal utilitzar aquests dos paramtre si es anode comu
//const char ledOn = LOW;
//const char ledOff = HIGH;

// Assignacio de segments a ports de sortida
const int seg_a = 5;
const int seg_b = 3;
const int seg_c = 4;
const int seg_d = 7;
const int seg_e = 8;
const int seg_f = 12;
const int seg_g = 13;

// Assigno el polsador al port entrada D2 per actuar com interrrupcio
const int buttonPin = 2;
// Aquesta variable es global i controla el funcionament
boolean onOff = true;     // Conte l'estat actual pot estar funcionant o parat

const char segmentPins[7] = { seg_a,seg_b,seg_c,seg_d,seg_e,seg_f,seg_g};

const byte numLeds[10] = {
  //DP GFEDCBA  Ordre dels segments
  B00111111,  // Representa el 0
  B00000110,  // Representa el 1
  B01011011,  // Representa el 2
  B01001111,  // Representa el 3
  B01100110,  // Representa el 4
  B01101101,  // Representa el 5
  B01111100,  // Representa el 6
  B00000111,  // Representa el 7
  B01111111,  // Representa el 8
  B01100111,  // Representa el 9
};

void pin0Interrupt(void)
{
  onOff = ! onOff;
  delay(50);
}

//******  Includes  ******************************************************************
void setup() {
  // Configura el pin del polsador com entrada
  pinMode(buttonPin, INPUT);
  attachInterrupt (0, pin0Interrupt, FALLING);
  // Configura els pins com a sortides
  for(int i = 0; i < 7; i++)
    {
      pinMode( segmentPins[i], OUTPUT); 
    }  

}



//******  Loop  **********************************************************************
void loop() {
  
  boolean isBitSet;          // Assigna 1 o 0 a cada segment del seven segment
  
  boolean lastState;         // Darrer estat del pulsador, true vol dir darrer estat pitjat

  
  while (onOff == true) {
    // representa els numeros del 0 al 9
    for(int numero = 0; numero < 10; numero++)
    {
        
      for(int segment = 0; segment < 7; segment++)
      {
        isBitSet = bitRead(numLeds[numero], segment);
        if (ledOn == LOW) isBitSet = ! isBitSet; // Cas anode comu, inverteix sortida
        digitalWrite( segmentPins[segment], isBitSet); 
      }
  
    delay(1000);
    while (onOff == false) {
          delay(1);
      }    
    shutDown();
  
    }
  }
}
  //Aquesta funcio apaga tots elssegments
  void shutDown()
  {
    for(int i = 0; i < 7; i++)
    {
      digitalWrite( segmentPins[i], ledOff); 
    }

  }

