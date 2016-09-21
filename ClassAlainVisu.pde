
import processing.serial.*;

Serial  myPort;

PFont myFont;     // The display font
String inString;  // Input string from serial port
int lf = 10;      // ASCII linefeed 
String t=":";
String[] tag = new String[110];

String TramEcriture="";
int value = 0;

//-----------------------------------------------------------------------------------
void setup() { // fonction d'initialisation ex�cut�e 1 fois au d�marrage

  colorMode(RGB, 255, 255, 255); // fixe format couleur R G B pour fill, stroke, etc...
  fill(0, 0, 255); // couleur remplissage RGB
  stroke (0, 0, 0); // couleur pourtour RGB
  rectMode(CORNER); // origine rectangle : CORNER = coin sup gauche | CENTER : centre 
  imageMode(CORNER); // origine image : CORNER = coin sup gauche | CENTER : centre
  //strokeWeight(0); // largeur pourtour
  frameRate(30);// Images par seconde

  size(1000, 1057); // ouvre une fen�tre xpixels  x ypixels
  background(0, 0, 0); // couleur fond fenetre

  // --- initialisation des objets et fonctionnalit�s utilis�es --- 

  //------------- initialisation port serie ---- 
  println(Serial.list());  
  myPort = new Serial(this, Serial.list()[1], 9600); 
  
  myPort.bufferUntil('\n'); 

  myPort.clear();
}
//------------------------------------------------
void  draw() { 
  
  if (inString != null) {
    String[] q = splitTokens(inString, "/");
    tag[0]=q[0];//
        tag[1]=q[1];//
                tag[2]=q[2];//
    tag[3]=q[3];// 
    tag[4]=q[4];//
        tag[5]=q[5];// 
  }

  AffichageTags(tag);
  
    fill(255);
  rect(25, 125, 50, 50);
} 


//=================================================================================================Affichage
void AffichageTags(String[] tags) {  // This function also does not return a value
  background(0);

  if (tags[0] != null) {
    //image(img, 0, 0); 
    fill(250, 226, 5);
    textSize(20);

    text(tags[0], 26, 35);
    text(tags[1], 26, 55);
    text(tags[2], 26, 75);
    text(tags[3], 200, 35);
    text(tags[4], 200, 55);
    text(tags[5], 200, 75);
  }
}
//***********************************

void serialEvent(Serial p) { 
  inString = p.readString();
  //print(inString);
} 

void mouseClicked() {
  println(mouseX); println(mouseY);
  if (mouseX >= 26 & mouseX<=75 & mouseY>=126 & mouseY <=173) {
    myPort.write("OK/");
  }
  
}