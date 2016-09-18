/******************************************************************
 Created with PROGRAMINO IDE for Arduino - 18.09.2016 03:37:37
 Project     :interrupts
 Libraries   :
 Author      :
 Description :
******************************************************************/

#include "TimerOne.h"
int Cpt=0;
//----------------
void setup()
{

Serial.begin(9600);

    Timer1.initialize(100000);         // initialize timer1
  //Timer1.setPeriod(100);
  Timer1.attachInterrupt(callback);
}
//---------------
void loop()
{

  Serial.println(Cpt);  

}

//--------- interrupts-----------
void callback() {
Cpt=Cpt+1;
}