#pragma once
extern volatile unsigned long pulseCount;
void encoderISR();
void setupEncoder();
unsigned long calculatePulsesDistance(float distance_m);
unsigned long calculatePulsesAngle(float angle);
