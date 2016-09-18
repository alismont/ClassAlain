#include "ClassAlain.cpp"
#include "TimerOne.h"

//-------------------------------------------------------------------
// attention si class sans paramètres pas myClassAlain().....
ClassAlain myClassAlain;

unsigned long T1=0;
unsigned long Scan=0;

boolean TDN[10];
int Presc[10];
int Accu[10];
boolean Cond[10];

int LED13=13;
int var=0;
int PIN38=38;

//---------------------------------
void setup(){

pinMode(LED13, OUTPUT); 
pinMode(PIN38, INPUT);

Serial.begin(9600);

    Timer1.initialize(100000);         // initialize timer1
  //Timer1.setPeriod(100);
  Timer1.attachInterrupt(callback);

  //--prescelection tempo---10=1sec
  Presc[1]=50;Accu[1]=0;
  var=1;
  Presc[2]=10;Accu[2]=0;
T1=millis();

}
//---------------------------------
void loop(){

switch (var) {
    case 1:
      Cond[1]=true;
        if(TDN[1])
        {
        var=2;
        Cond[1]=false;Accu[1]=0;
        digitalWrite(LED13,HIGH);
        }
      break;
    case 2:
      Cond[1]=true;
        if(TDN[1])
        {
        var=1;
        Cond[1]=false;Accu[1]=0;
        digitalWrite(LED13,LOW);
        }      
      break;
  }
  
 //----- input 38 tempo led13----- 
  if(digitalRead(PIN38))
  {
   Cond[2]=true;

        if(TDN[2])
        {
                digitalWrite(LED13,LOW);
        }
  } 
  else{
    Cond[2]=false;Accu[2]=0; 
  }
  
 //---gestion tempo---- 
TDN[1]=myClassAlain.Ton(Presc[1],Cond[1],Accu[1]);
TDN[2]=myClassAlain.Ton(Presc[2],Cond[2],Accu[2]);

Scan=myClassAlain.TpsScan(T1);
Serial.println(var);

}
//---------------------------------
//--------- interrupts-------------
void callback() {
    if(Cond[1]){
        Accu[1]=Accu[1]+1;
    }
    if(Cond[2]){
        Accu[2]=Accu[2]+1;
    }
}
