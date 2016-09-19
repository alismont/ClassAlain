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

char octetReception;
char caractereReception;
char octetReceptionProc;
char caractereReceptionProc;
String chaineReception, Tram;
String chaineReceptionProc, TramProc;
boolean Processing=true;

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
  Presc[2]=30;Accu[2]=0;
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

AffProcessing();

Scan=myClassAlain.TpsScan(T1);
//Serial.println(var);

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
//---------------------------------
void AffProcessing() {
  while (Serial.available() > 0) { 
  
     octetReceptionProc = Serial.read(); // lit le 1er octet de la file d'attente
if (octetReceptionProc == '/') {
        if (chaineReceptionProc.substring(0, 2) == " ")  {

      chaineReceptionProc = "";
      //delay(1); // pause
    }
    else {
      caractereReceptionProc = char(octetReceptionProc);
      chaineReceptionProc = chaineReceptionProc + caractereReceptionProc;
      //delay(1);
    }
  }
  }
  
  if (Processing) {
    //dtostrf( F8[IndexDebugProc], 5, 3, charVal);
    //TramProc = charVal;
    //TramProc = TramProc + "/";
    
        
    Serial.print("var= ");
    Serial.print(var);
    Serial.print("/");
    
    Serial.print("Accu1= ");
    Serial.print(Accu[1]);
    Serial.print("/"); 
   
       Serial.print("Accu2= ");
    Serial.print(Accu[2]);
    Serial.print("/");  
    
        Serial.println();
        }
        }