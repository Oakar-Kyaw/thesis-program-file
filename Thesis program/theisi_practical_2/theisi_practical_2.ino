#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x3F, 16, 2);
char msg = ' '; //contains the message from arduino sender
const int led = 13;
int servoPin = 3;
Servo Servo1;
int fan=4;//led at pin 13
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
pinMode(led,OUTPUT);
Servo1.attach(servoPin);
pinMode(fan,OUTPUT);
}
void loop() {
while(Serial.available() ) {
           msg=Serial.read();
           if(msg=='H') {
               digitalWrite(led,HIGH);
          Servo1.write(90);
          Serial.println("Led and servo and fan are on");
          digitalWrite(fan,HIGH);
          delay(8000);
           }
           if(msg=='L') {
                digitalWrite(led,LOW);
           Servo1.write(0);
           digitalWrite(fan,LOW);
           Serial.println(" Led and servo and fan are off");
           delay(8000);
           }
}
}
