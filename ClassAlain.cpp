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
    //-- scan
    int i;
    unsigned long T1SetUp=0;
    unsigned long cycleTime = 0;
    unsigned long CyclePrescedent = 0;
    unsigned long Cycle = 0;
    
    //--tempo
    int Presc;
    int Accu;
    boolean DN_Bit;
    boolean TT_Bit;
    boolean Condition;
    
 ClassAlain() {  //the constructor
 
 }
 //----- fonction calcul du scanning-------------
    unsigned long TpsScan(unsigned long _T1SetUp){

  cycleTime = millis() - _T1SetUp;
  Cycle = cycleTime - CyclePrescedent;
  CyclePrescedent = cycleTime;
  
    return Cycle;
}
 //----- fonction Tempo TON-------------
  
 boolean Ton(int _Presc,boolean _Condition,int _Accu){
    boolean _DN_Bit;
    boolean _TT_Bit;
    boolean _CptT;
    
    //_Presc=Presc;
    //_Accu=Accu;
    //_Condition=Condition;
    //_DN_Bit=DN_Bit;
    //_TT_Bit=TT_Bit;
    
//--code--    
if (_Condition) {
    _CptT = true;
  }
  else {
    _Accu =  0.0;
    _DN_Bit =  0.0;
    _CptT = false;
  }
  if (_Accu >= _Presc) { // présélection de 600 donc 60 secondes
    _DN_Bit =  1.0;   // bit down
    _Accu = _Presc;
  }

  return _DN_Bit; 

}

};
