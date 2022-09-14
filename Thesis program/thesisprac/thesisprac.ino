void setup() {
Serial.begin(9600);
}
void loop() {
Serial.println("L"); //turn on the LED
delay(8000);
Serial.println("H");//turn off the LED
delay(8000);
}
