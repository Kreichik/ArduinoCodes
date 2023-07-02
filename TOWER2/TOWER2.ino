#include <Wire.h>
 const int ledPin = 13;

  int motorRight1 = 2;       // Правый мотор.
int motorRight2 = 4;
int enableRight = 3;

int motorSpeed = 255;
 int incomingByte;
void setup() {
  pinMode (motorRight1, OUTPUT);
  pinMode (motorRight2, OUTPUT);
  pinMode (enableRight, OUTPUT);
  pinMode(ledPin, OUTPUT);
 Wire.begin(8);                /* join i2c bus with address 8 */
 Wire.onReceive(receiveEvent); /* register receive event */
 Wire.onRequest(requestEvent); /* register request event */
 Serial.begin(9600);           /* start serial comm. */
 Serial.println("I am I2C Slave");
 analogWrite(enableRight, motorSpeed);
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
 }
    else if(c =='1'){
      Serial.print(c);
    digitalWrite(ledPin, LOW);
    digitalWrite (motorRight1, LOW);
  digitalWrite (motorRight2, HIGH);
  delay(4000);
  digitalWrite (motorRight1, LOW);
  digitalWrite (motorRight2, LOW);
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
  Wire.write("1");
digitalWrite(ledPin, LOW);
digitalWrite (motorRight1, LOW);
  digitalWrite (motorRight2, HIGH);
  delay(4000);
  digitalWrite (motorRight1, LOW);
  digitalWrite (motorRight2, LOW);
   /* sends hello string */


}

if (incomingByte == 'O')
{
  Wire.write("2"); 
digitalWrite(ledPin, HIGH);
digitalWrite (motorRight1, HIGH);
  digitalWrite (motorRight2, LOW);
  delay(4000);
  digitalWrite (motorRight1, LOW);
  digitalWrite (motorRight2, LOW);
  /* sends hello string */

}
}
}
