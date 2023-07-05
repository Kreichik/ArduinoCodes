#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

void setup() {
  servo1.attach(9);   // Подключите первый сервопривод к пину 9
  servo2.attach(12);  // Подключите второй сервопривод к пину 10
  servo3.attach(5);  // Подключите третий сервопривод к пину 11
  servo4.attach(4);  // Подключите четвертый сервопривод к пину 12
  servo1.write(0);
  delay(500);
  servo2.write(60);
  delay(500);
  servo3.write(180);
  delay(500);
  servo4.write(60);
  delay(3000);
}

void loop() {
  // Управление первым сервоприводом
  for (int angle = 0; angle <= 90; angle += 1) {
    servo1.write(angle);
    delay(15);
  }
  delay(1000);
  for (int angle = 60; angle >= 0; angle -= 1) {
    servo2.write(angle);
    delay(15);
  }
  delay(1000);

  // Управление третьим сервоприводом

  for (int angle = 180; angle >= 90; angle -= 1) {
    servo3.write(angle);
    delay(15);
  }

  
  
  delay(1000);
for (int angle = 60; angle <= 180; angle += 1) {
    servo4.write(angle);
    delay(15);
  }

  delay(1000);
  
  // Управление вторым сервоприводом
  for (int angle = 0; angle <= 60; angle += 1) {
    servo2.write(angle);
    delay(15);
  }
  delay(1000);

  for (int angle = 90; angle >= 0; angle -= 1) {
    servo1.write(angle);
    delay(15);
  }

delay(1000);
  // Управление четвертым сервоприводом
  
  for (int angle = 180; angle >= 60; angle -= 1) {
    servo4.write(angle);
    delay(15);
  }

  delay(1000);

  for (int angle = 90; angle <= 180; angle += 1) {
    servo3.write(angle);
    delay(15);
  }
}
