#include <Wire.h>
 const int ledPin = 10;

 int motorRight1 = 2;       // Ворота
int motorRight2 = 4;
int enableRight = 3;
#define PIN_TRIG 12
#define PIN_ECHO 11
int motorSpeed = 90;
int i = 0;
 int incomingByte;
void setup() {
      pinMode(PIN_TRIG, OUTPUT);
pinMode(PIN_ECHO, INPUT);
pinMode (motorRight1, OUTPUT);
  pinMode (motorRight2, OUTPUT);
  pinMode (enableRight, OUTPUT);
   analogWrite(enableRight, motorSpeed);
  pinMode(ledPin, OUTPUT);
 Wire.begin(8);                /* join i2c bus with address 8 */
 Wire.onReceive(receiveEvent); /* register receive event */
 Wire.onRequest(requestEvent); /* register request event */
 Serial.begin(9600);           /* start serial comm. */
 Serial.println("I am I2C Slave");

}
void loop() {

}
// function that executes whenever data is received from master
void receiveEvent(int howMany) {
  
 while (0 <Wire.available()) {
    char c = Wire.read();      /* receive byte as a character */
    if (c == '2'){
    Serial.print(c);
    digitalWrite(ledPin, HIGH);
    digitalWrite (motorRight1, HIGH);
  digitalWrite (motorRight2, LOW);
  delay(4000);
  digitalWrite (motorRight1, LOW);
  digitalWrite (motorRight2, LOW);
  while (i!=10){
  digitalWrite(PIN_TRIG, LOW);
  delay(100);
  digitalWrite(PIN_TRIG, HIGH);
delay(100);
i = i + 1;
}
i = 0;
 }
    else if(c =='1'){
      Serial.print(c);
    digitalWrite(ledPin, LOW);
    digitalWrite (motorRight1, LOW);
  digitalWrite (motorRight2, HIGH);
  delay(4000);
  digitalWrite (motorRight1, LOW);
  digitalWrite (motorRight2, LOW);
  while (i!=10){
  digitalWrite(PIN_TRIG, LOW);
  delay(100);
  digitalWrite(PIN_TRIG, HIGH);
delay(100);
i = i + 1;
}
i = 0;
    }
/* print the character */
  }
 Serial.println();             /* to newline */
}
// function that executes whenever data is requested from master
void requestEvent() {
 if (Serial.available() > 0)
{

incomingByte = Serial.read();

if (incomingByte == 'C')
{
  
digitalWrite(ledPin, LOW);
digitalWrite (motorRight1, LOW);
  digitalWrite (motorRight2, HIGH);
  Wire.write("1");
  delay(4000);
  digitalWrite (motorRight1, LOW);
  digitalWrite (motorRight2, LOW);
  while (i!=10){
  digitalWrite(PIN_TRIG, LOW);
  delay(100);
  digitalWrite(PIN_TRIG, HIGH);
delay(100);
i = i + 1;
}
i = 0;
   /* sends hello string */


}

if (incomingByte == 'O')
{
 
digitalWrite(ledPin, HIGH);
Wire.write("2"); 
open_gates();
  while (i!=10){
  digitalWrite(PIN_TRIG, LOW);
  delay(100);
  digitalWrite(PIN_TRIG, HIGH);
delay(100);
i = i + 1;
}
i = 0;
  /* sends hello string */

}
}
}


void open_gates(){
  digitalWrite (motorRight1, HIGH);
  digitalWrite (motorRight2, LOW);
   
  delay(4000);
  digitalWrite (motorRight1, LOW);
  digitalWrite (motorRight2, LOW);
}
