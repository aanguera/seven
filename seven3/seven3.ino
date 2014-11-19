/*************************************************************************************
**                                                                                  **
**             Aquest programa visualitza de forma sequancial el nom Toni           **
**             es basa en el programa de visualitzacio de numeros                   **
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
const int seg_a = 2;
const int seg_b = 3;
const int seg_c = 4;
const int seg_d = 7;
const int seg_e = 8;
const int seg_f = 12;
const int seg_g = 13;

// Assigno el polsador al port entrada D5
const int buttonPin = 5;

const char segmentPins[7] = { seg_a,seg_b,seg_c,seg_d,seg_e,seg_f,seg_g};

const byte numLeds[10] = {
  //DP GFEDCBA  Ordre dels segments
  B01111000,  // Representa la lletra "t"
  B00111111,  // Representa la lletra "O"
  B01010100,  // Representa la lletra "n"
  B00110000,  // Representa la lletra "i"
};

//******  Includes  ******************************************************************
void setup() {
  
  // Configura els pins com a sortides
  for(int i = 0; i < 7; i++)
    {
      pinMode( segmentPins[i], OUTPUT); 
    }  

}


//******  Loop  **********************************************************************
void loop() {
  
  boolean isBitSet;          // Assigna 1 o 0 a cada segment del seven segment
  
  // representa els numeros del 0 al 9
  for(int lletra = 0; lletra < 4; lletra++)
  {
    for(int segment = 0; segment < 7; segment++)
    {
      isBitSet = bitRead(numLeds[lletra], segment);
      if (ledOn == LOW) isBitSet = ! isBitSet; // Cas anode comu, inverteix sortida
      digitalWrite( segmentPins[segment], isBitSet); 
    }
  delay(1000);
  shutDown();
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

