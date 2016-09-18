/******************************************************************
 Created with PROGRAMINO IDE for Arduino - 14.09.2016 22:06:51
 Project     :
 Libraries   :
 Author      :
 Description :
******************************************************************/
#include <Arduino.h>

    
class ClassAlain {

public:   //public 
    int i;
    unsigned long T1SetUp=0;
    unsigned long cycleTime = 0;
    unsigned long CyclePrescedent = 0;
    unsigned long Cycle = 0;
    
 ClassAlain() {  //the constructor
 
 }
 
    unsigned long TpsScan(unsigned long _T1SetUp){

  cycleTime = millis() - _T1SetUp;
  Cycle = cycleTime - CyclePrescedent;
  CyclePrescedent = cycleTime;
  
    return Cycle;
}

};
