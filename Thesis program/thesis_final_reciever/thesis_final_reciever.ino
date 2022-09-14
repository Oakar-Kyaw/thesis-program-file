#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x3F, 16, 2);
int RelayPin = 7;
int RelayPin1 = 8;
char msg = ' '; //contains the message from arduino sender
const int led = 13;
int servoPin = 3;
const int buzzer=5;
Servo Servo1;
int fan=4;
int i=0;//led at pin 13
void setup() {
 lcd.init();
lcd.begin(16,2);
lcd.backlight();
lcd.setCursor(1,0);
lcd.print("LED, Servo and fan are on");
delay(8000);
lcd.clear();
lcd.setCursor(1,0);
lcd.print("LED, Servo and fan are off");
lcd.clear();

Serial.begin(9600);//Remember that the baud must be the same on both arduinos
Servo1.attach(servoPin);
pinMode(fan,OUTPUT);
pinMode(buzzer,OUTPUT);
pinMode(RelayPin, OUTPUT);
pinMode(RelayPin1, OUTPUT);
Servo1.write(0);
}
void loop() {
while(Serial.available() ) {
           msg=Serial.read();
           if(msg=='A') {
               digitalWrite(RelayPin,HIGH);
               digitalWrite(RelayPin1,LOW);
               
               Servo1.write(0);
          Serial.println("Led is on");
          digitalWrite(fan,LOW);
          noTone(buzzer);
           }
           if(msg=='B') {
                digitalWrite(RelayPin,LOW);
                 digitalWrite(RelayPin1,LOW);
            Servo1.write(0);
           digitalWrite(fan,LOW);
           noTone(buzzer);
           Serial.println(" Led is off");
           
           }
           if(msg=='C'){
            digitalWrite(RelayPin,LOW);
             digitalWrite(RelayPin1,HIGH);
             Servo1.write(0);
            digitalWrite(fan,HIGH);
            noTone(buzzer);
            Serial.println("Fan is on");
          
           }
            if(msg=='D'){
            digitalWrite(RelayPin,LOW);
             digitalWrite(RelayPin1,LOW);

            Servo1.write(0);
            digitalWrite(fan,LOW);
            noTone(buzzer);
            Serial.println("Fan is off");
}
 if(msg=='E'){
            digitalWrite(RelayPin,LOW);
             digitalWrite(RelayPin1,LOW);

            Servo1.write(90);
            digitalWrite(fan,LOW);
            noTone(buzzer);
            Serial.println("door is on");
 }
 if(msg=='F'){
            digitalWrite(RelayPin,LOW);
             digitalWrite(RelayPin1,LOW);

            Servo1.write(0);
            digitalWrite(fan,LOW);
            noTone(buzzer);
            Serial.println("door is off");
}
 if(msg=='G'){
            digitalWrite(RelayPin,HIGH);
             digitalWrite(RelayPin1,HIGH);

            Servo1.write(90);
            digitalWrite(fan,HIGH);
            tone(buzzer, 3000);
            Serial.println("All are on");
}
if(msg=='H'){
            digitalWrite(RelayPin,LOW); 
            digitalWrite(RelayPin1,LOW);

            Servo1.write(0);
            digitalWrite(fan,LOW);
            noTone(buzzer);
            Serial.println("All are off");
}
if(msg=='I'){
            digitalWrite(RelayPin,LOW);
             digitalWrite(RelayPin1,LOW);

            Servo1.write(0);
            digitalWrite(fan,LOW);
            tone(buzzer, 3000);
            Serial.println("buzzer is on");
}
if(msg=='J'){
            digitalWrite(RelayPin,LOW);
             digitalWrite(RelayPin1,LOW);

            Servo1.write(0);
            digitalWrite(fan,LOW);
            noTone(buzzer);
            Serial.println("buzzer is off");
}
if(msg=='K'){
  

            digitalWrite(RelayPin,LOW);
             digitalWrite(RelayPin1,LOW);

            Servo1.write(0);
            digitalWrite(fan,LOW);
            tone(buzzer,5000);
            Serial.println("buzzer is on");
            delay(1000);
         noTone(buzzer);
   
   }
}
}
