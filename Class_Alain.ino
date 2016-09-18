#include "ClassAlain.cpp"

//-------------------------------------------------------------------
// attention si class sans paramètres pas myClassAlain().....
ClassAlain myClassAlain;

unsigned long T1=0;
unsigned long Scan=0;

void setup(){

Serial.begin(9600);
T1=millis();

}

void loop(){
delay(1000);
Scan=myClassAlain.TpsScan(T1);
Serial.println(Scan);

}
