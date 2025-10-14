#include <Arduino.h>
#include <turnRight.h>
#include <turnLeft.h>
#include <moveForward.h>
#include <encoderUtils.h>
// put function declarations here:
//int myFunction(int, int);

void setup() {
  setupEncoder();


  setupMoveForward();


  setupTurnRight();


  setupTurnLeft();
}

void loop() {
     moveForwardDistance(0.6);
  // delay(5000);
  // put your main code here, to run repeatedly:
    turnRight(180); // поворот на 60 градусов
  //  delay(5000);   // подождать для следующей команды
    turnLeft(60);
  //  delay(5000);
}
