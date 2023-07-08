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
int motorSpeed = 100;
int line_stop = 0;
String status_ok = "OK";
bool actionPerformed = false;

void setup() 
{
pinMode (motorRight1, OUTPUT);
  pinMode (motorRight2, OUTPUT);
  pinMode (enableRight, OUTPUT);

  pinMode (motorLeft1, OUTPUT);
  pinMode (motorLeft2, OUTPUT);
  pinMode (enableLeft, OUTPUT);
HC06.begin(9600);
}

void loop() 
{
  if (!actionPerformed) {
  delay(43000);
  rightWheelForward(120);
  leftWheelForward (170);
  delay(2000);
  rightWheelStop();
  leftWheelStop();
  
}
}
void rightWheelForward (int motorSpeed) {               // Правое колесо вперёд.
  digitalWrite (motorRight1, LOW);
  digitalWrite (motorRight2, HIGH);
  analogWrite(enableRight, motorSpeed);
}

void leftWheelForward (int motorSpeed)  {                // Левое колесо вперёд.
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
