// Программа для езды по линии с двумя датчиками. В отличие от езды с одним датчиком - тут рассматривается три случая. Случай первый - линия находится между
// двумя датчиками, оба датчика показывают, что находятся на против белого. В таком случае робот просто едет вперед. Второй случай - когда линия находится под левым датчиком.
// В таком случае машинка поворачивается и пытается вернуться на линию. В третьем случае - линия находится под правым датчиком, машинка поворачивает налево.
#include <SoftwareSerial.h>
SoftwareSerial HC06(10, 11);
int motorRight1 = 2;       // Правый мотор.
int motorRight2 = 4;
int enableRight = 3;

int motorLeft1 = 6;        // Левый мотор.
int motorLeft2 = 7;
int enableLeft = 5;
int x,y=0;
int control;               // Управление двигателями.
int motorSpeed = 80;
int line_stop = 0;
String status_ok = "OK";
void setup() 
{
pinMode (motorRight1, OUTPUT);
  pinMode (motorRight2, OUTPUT);
  pinMode (enableRight, OUTPUT);

  pinMode (motorLeft1, OUTPUT);
  pinMode (motorLeft2, OUTPUT);
  pinMode (enableLeft, OUTPUT);
HC06.begin(9600);
Serial.begin(9600);
}

void loop() 
{
if(HC06.available() > 0) //When HC06 receive something
  {
     char receive = HC06.read(); //Read from Serial Communication
    if(receive == '1') //If received data is 1, turn on the LED and send back the sensor data
    {
      HC06.println(line_stop);
      }
      if(receive == '2') //If received data is 1, turn on the LED and send back the sensor data
    {
      HC06.println(status_ok);
      
      }
    }
  x = analogRead(A0);
  y = analogRead(A2);
  Serial.print(x);
  Serial.print("   ");
    Serial.println(y);

  if (x < 700 && y < 700)       // оба датчика на белом, машинка едет вперед
  {
    line_stop = 0;
//    Serial.println("Forward");
    rightWheelForward ();
      leftWheelForward ();
  }

  if (x > 700 && y > 700)       // оба датчика на белом, машинка едет вперед
  {
    line_stop = 1;
//    Serial.println("Forward");
    rightWheelForward ();
      leftWheelForward ();
  }
  if (x > 700 && y < 700)       // один датчик на белом, другой на черном
  {
    line_stop = 0;
//    Serial.println("Left");
   
      leftWheelStop ();
      rightWheelForward ();
  }
  if (x < 700 && y > 700)       // один датчик на белом, другой на черном
  {
    line_stop = 0;
//    Serial.println("Right");
    rightWheelStop ();
      leftWheelForward ();
  }
}

void rightWheelForward () {               // Правое колесо вперёд.
  digitalWrite (motorRight1, LOW);
  digitalWrite (motorRight2, HIGH);
  analogWrite(enableRight, motorSpeed);
}

void leftWheelForward () {                // Левое колесо вперёд.
  digitalWrite (motorLeft1, LOW);
  digitalWrite (motorLeft2, HIGH);
  analogWrite(enableLeft, motorSpeed);
}

void rightWheelBack () {                  // Правое колесо назад.
  digitalWrite (motorRight1, HIGH);
  digitalWrite (motorRight2, LOW);
  analogWrite(enableRight, motorSpeed);
}

void leftWheelBack () {                   // Левое колесо назад.
  digitalWrite (motorLeft1, HIGH);
  digitalWrite (motorLeft2, LOW);
  analogWrite(enableLeft, motorSpeed);
}

void rightWheelStop () {                  // Правое колесо остановить.
  digitalWrite (motorRight1, LOW);
  digitalWrite (motorRight2, LOW);
  analogWrite(enableRight, 0);
}

void leftWheelStop () {                   // Левое колесо остановить.
  digitalWrite (motorLeft1, LOW);
  digitalWrite (motorLeft2, LOW);
  analogWrite(enableLeft, 0);
}
