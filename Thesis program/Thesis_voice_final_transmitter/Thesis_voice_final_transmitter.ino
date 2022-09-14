  
#include <SoftwareSerial.h>
SoftwareSerial BT(10,11);
String voice;
const int gasPin = A0;
int sensorThres = 400;
int analogSensor = analogRead(gasPin);

void setup() {
  BT.begin(9600);
  Serial.begin(9600);
  pinMode(gasPin, INPUT);
  }
  
  // put your setup code here, to run once:



void loop() {


   
  
  while (BT.available()){
    delay(10);
    char c=BT.read();
    if (c=='#') {
      break;
    }
    voice += c; 
  }
 
  if ( voice.length()>0){
    Serial.println(voice);

   

    if (voice == "Hello"){
      Serial.println("A");
    }
    if (voice == "Fan"){
      Serial.println("B");
    }
    if (voice == "*fan on"){
      Serial.println("C");
    }
    if (voice == "*fan off"){
      Serial.println("D"); 
    }
    if (voice == "*door on"){
      Serial.println("E");
    }
    if (voice == "*door off"){
      Serial.println("F");
    }
    if (voice == "*all on"){
      Serial.println("G");
    }
    if (voice == "*all off"){
      Serial.println("H");
    }
   

    voice="";
  }
   
}

 

  
   
  
