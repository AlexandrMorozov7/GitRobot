#include <Arduino.h>
#include <turnRight.h>
#include <turnLeft.h>
#include <moveForward.h>
// put function declarations here:
//int myFunction(int, int);

void setup() {
  setupMoveForward();


  setupTurnRight();


  setupTurnLeft();
}

void loop() {  
    moveForwardDistance(0.6); // робот проедет заданное расстояние
  delay(5000); // Дать роботу немного времени до следующей команды
    turnRight(60); // поворот на 60 градусов
  delay(5000);   // подождать для следующей команды
    turnLeft(60);
  delay(5000);
}
