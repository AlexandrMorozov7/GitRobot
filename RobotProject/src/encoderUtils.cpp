#include "encoderUtils.h"
#include <Arduino.h>

#define ENCODER_PIN 34
const float WHEEL_DIAMETER = 0.07;
const float TRACK_WIDTH = 0.13;
const int SLOTS = 20;

volatile unsigned long pulseCount = 0;

void IRAM_ATTR encoderISR() {
  pulseCount++;
}

void setupEncoder() {
  pinMode(ENCODER_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(ENCODER_PIN), encoderISR, RISING);
  Serial.begin(115200);
}

unsigned long calculatePulsesDistance(float distance_m) {
  float wheelCircumference = PI * WHEEL_DIAMETER;
  float revolutions = distance_m / wheelCircumference;
  return revolutions * SLOTS;
}

unsigned long calculatePulsesAngle(float angle) {
  float robotCircumference = PI * TRACK_WIDTH;
  float arcLength = robotCircumference * (angle / 360.0);
  float revolutions = arcLength / (PI * WHEEL_DIAMETER);
  return revolutions * SLOTS;
}
