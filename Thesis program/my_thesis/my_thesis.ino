#include <Servo.h> 
int in1=6;
int in2=7;
int in3=8;
int in4=9;
const int buzzer;
int servoPin = 3; 
Servo Servo1;


char msg=' ';

void setup() {
   Servo1.attach(servoPin); 
    Servo1.write(0);
  pinMode(in1,OUTPUT);
 
  pinMode(in2, OUTPUT);
 
  pinMode(in3,OUTPUT);
  digitalWrite(in1,HIGH);
  

  pinMode(in4,OUTPUT);
  digitalWrite(in2,HIGH);
   digitalWrite(in3,HIGH);
    digitalWrite(in4,HIGH);
  Serial.begin(9600);
  
  // put your setup code here, to run once:

}

void loop() {
  while(Serial.available()){
    msg= Serial.read();
    if (msg=='A'){
      digitalWrite(in1, LOW);
      digitalWrite(in2,HIGH);
      digitalWrite(in3,HIGH);
      noTone(buzzer);
      digitalWrite(in4,HIGH);
      Servo1.write(0);

      Serial.println("light is on");
    }
    if (msg=='B'){
      digitalWrite(in1, HIGH);
      digitalWrite(in2,HIGH);
      digitalWrite(in3,HIGH);
      Servo1.write(0);
      noTone(buzzer);
      digitalWrite(in4,HIGH);
      Serial.println("light is off");
    }
    if (msg=='C'){
      digitalWrite(in1, HIGH);
      digitalWrite(in2,LOW);
      digitalWrite(in3,HIGH);
      Servo1.write(0);
      noTone(buzzer);
      digitalWrite(in4,HIGH);
      Serial.println("Fan is on");
    }
    if (msg=='D'){
      digitalWrite(in1,HIGH);
      digitalWrite(in2,HIGH);
      digitalWrite(in3,HIGH);
      Servo1.write(0);
      noTone(buzzer);
      digitalWrite(in4,HIGH);
      Serial.println("Fan is off");
      
    }
     if (msg=='E'){
      digitalWrite(in1, HIGH);
      digitalWrite(in2,HIGH);
      digitalWrite(in3,HIGH);
      digitalWrite(in4,LOW);
      Servo1.write(90);
    
      noTone(buzzer);
      Serial.println("Door is on");
    }
    if (msg=='F'){
      digitalWrite(in1, HIGH);
      digitalWrite(in2,HIGH);
      digitalWrite(in3,HIGH);
      digitalWrite(in4,HIGH);
      Servo1.write(0);
      noTone(buzzer);
   
      Serial.println("Door is off");
    }
     if (msg=='G'){
      digitalWrite(in1, LOW);
      digitalWrite(in2,LOW);
      digitalWrite(in4,LOW);
      Servo1.write(90);

      noTone(buzzer);
      Serial.println("All are on");
      
    }
    if (msg=='H'){
      digitalWrite(in1, HIGH);
      digitalWrite(in2,HIGH);
      digitalWrite(in3,HIGH);
      digitalWrite(in4,HIGH);
      Servo1.write(0);
      noTone(buzzer);
     
      Serial.println("All are off");
    }
    if (msg=='I'){
    
     digitalWrite(in3,LOW);
     
      tone(buzzer,3000);
    
      
      Serial.println("Buzzer is on");
    }
    if (msg=='J'){
      digitalWrite(in3,HIGH);
      noTone(buzzer);
      Serial.println("Buzzer is off");
    }
    
   
    }
  // put your main code here, to run repeatedly:

}
