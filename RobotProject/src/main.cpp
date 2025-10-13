#include <Arduino.h>
#include <turnRight.h>
// put function declarations here:
int myFunction(int, int);

void setup() {
  setupTurnRight();
}

void loop() {
  // put your main code here, to run repeatedly:
    turnRight(60); // поворот на 60 градусов
  delay(5000);   // подождать для следующей команды
}
