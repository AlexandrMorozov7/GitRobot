#include <Arduino.h>
#include <turnRight.h>
<<<<<<< HEAD
#include <turnLeft.h>
#include <moveForward.h>
#include <encoderUtils.h>
=======
>>>>>>> parent of 4fd923d (Реализовано демо движения по т-и.)
// put function declarations here:
int myFunction(int, int);

void setup() {
<<<<<<< HEAD
  setupEncoder();


  setupMoveForward();


=======
>>>>>>> parent of 4fd923d (Реализовано демо движения по т-и.)
  setupTurnRight();
}

void loop() {
<<<<<<< HEAD
     moveForwardDistance(0.6);
  // delay(5000);
  // put your main code here, to run repeatedly:
    turnRight(180); // поворот на 60 градусов
  //  delay(5000);   // подождать для следующей команды
    turnLeft(60);
  //  delay(5000);
=======
  // put your main code here, to run repeatedly:
    turnRight(60); // поворот на 60 градусов
  delay(5000);   // подождать для следующей команды
>>>>>>> parent of 4fd923d (Реализовано демо движения по т-и.)
}
