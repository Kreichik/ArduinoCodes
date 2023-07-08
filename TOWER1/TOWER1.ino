
 const int ledPin = 13; 
int led = 8;
#define PIN_TRIG 12
#define PIN_ECHO 11

 int motorRight1 = 2;       // Ворота
int motorRight2 = 4;
int enableRight = 3;
int i = 0;
int motorSpeed = 120;

 int incomingByte;
    void setup() {
      pinMode(led, OUTPUT);
      pinMode(PIN_TRIG, OUTPUT);
pinMode(PIN_ECHO, INPUT);
      pinMode (motorRight1, OUTPUT);
  pinMode (motorRight2, OUTPUT);
  pinMode (enableRight, OUTPUT);
      pinMode(ledPin, OUTPUT);
 Serial.begin(9600); /* begin serial comm. */
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
 digitalWrite (motorRight1, LOW);
  digitalWrite (motorRight2, HIGH);
  delay(5000);
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

if (incomingByte == 'O')
{
digitalWrite(ledPin, HIGH);
 digitalWrite (motorRight1, HIGH);
  digitalWrite (motorRight2, LOW);
  delay(5000);
  digitalWrite (motorRight1, LOW);
  digitalWrite (motorRight2, LOW);
  /* request & read data of size 9 from slave */
  while (i!=10){
  digitalWrite(PIN_TRIG, LOW);
  delay(100);
  digitalWrite(PIN_TRIG, HIGH);
delay(100);
i = i + 1;
}
i = 0;
}
}


 
}
