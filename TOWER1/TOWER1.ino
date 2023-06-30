 #include <Wire.h>
 const int ledPin = 13; 

 int motorRight1 = 2;       // Ворота
int motorRight2 = 4;
int enableRight = 3;

int motorSpeed = 80;

 int incomingByte;
    void setup() {
      pinMode (motorRight1, OUTPUT);
  pinMode (motorRight2, OUTPUT);
  pinMode (enableRight, OUTPUT);
      pinMode(ledPin, OUTPUT);
 Serial.begin(9600); /* begin serial comm. */
 Wire.begin(); /* join i2c bus as master */
 Serial.println("I am I2C Master");
 analogWrite(enableRight, motorSpeed);
}
void loop() {

  if (Serial.available() > 0)
{

incomingByte = Serial.read();

if (incomingByte == 'C')
{
digitalWrite(ledPin, LOW);

Wire.beginTransmission(8); /* begin with device address 8 */
 Wire.write("1");  /* sends hello string */
 Wire.endTransmission();    /* stop transmitting */
 digitalWrite (motorRight1, LOW);
  digitalWrite (motorRight2, HIGH);
  delay(4000);
  digitalWrite (motorRight1, LOW);
  digitalWrite (motorRight2, LOW);

}

if (incomingByte == 'O')
{
digitalWrite(ledPin, HIGH);

Wire.beginTransmission(8); /* begin with device address 8 */
 Wire.write("2");  /* sends hello string */
 Wire.endTransmission();    /* stop transmitting */
 digitalWrite (motorRight1, HIGH);
  digitalWrite (motorRight2, LOW);
  delay(4000);
  digitalWrite (motorRight1, LOW);
  digitalWrite (motorRight2, LOW);
  /* request & read data of size 9 from slave */
}
}


Wire.requestFrom(8, 1);
 while(Wire.available()){
    char c = Wire.read();/* read data received from slave */
  
    Serial.println(c);
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
 }
 
      
   
  
 

 
}
