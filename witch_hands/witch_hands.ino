#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;



void setup() {
  servo1.attach(9);  // Подключаем первый сервопривод к пину 9
  servo2.attach(8);  // Подключаем второй сервопривод к пину 8
  servo3.attach(5);  // Подключаем третий сервопривод к пину 5
  servo4.attach(4);  // Подключаем четвертый сервопривод к пину 4
}



void loop() {
  // Управление первой рукой
  servo1.write(0);    // Поворот первого сервопривода в положение 0 градусов
  servo2.write(90);   // Поворот второго сервопривода в положение 90 градусов

  delay(1000);        // Пауза 1 секунда

  servo1.write(90);   // Поворот первого сервопривода в положение 90 градусов
  servo2.write(180);  // Поворот второго сервопривода в положение 180 градусов

  delay(1000);        // Пауза 1 секунда

 
}