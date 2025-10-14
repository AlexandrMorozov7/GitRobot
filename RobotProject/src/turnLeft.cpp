// turnRight.cpp
#include <Arduino.h>
#include <turnLeft.h>
#include <encoderUtils.h>
// Задаём распиновку L298N
#define IN1 27
#define IN2 26
#define IN3 25
#define IN4 33

// Пин подключения оптопары H2010
#define ENCODER_PIN 34

// Физические параметры — если изменятся, только здесь
const float WHEEL_DIAMETER = 0.07; // диаметр колеса (метры)
const float TRACK_WIDTH = 0.13;     // база между колесами (метры)
const int SLOTS = 20;               // количество прорезей/импульсов на 1 оборот




// Инициализация пинов моторов и энкодера (вызвать в setup)
void setupTurnLeft() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENCODER_PIN, INPUT);



  Serial.begin(115200);
}

// Функция для расчёта количества импульсов
unsigned long calculatePulses2(float angle) {
  // Радиус поворота для полного разворота = половина расстояния между колесами
  float robotCircumference = PI * TRACK_WIDTH;
  // Длина дуги, которую должно пройти колесо при повороте робота на 'angle'
  float arcLength = robotCircumference * (angle / 360.0);
  // Сколько оборотов должно сделать колесо
  float revolutions = arcLength / (PI * WHEEL_DIAMETER);
  // Количество импульсов энкодера на это число оборотов
  return revolutions * SLOTS;
}

// Главная функция поворота (вызвать в main.cpp: turnRight(angle);)
void turnLeft(float angle) {
  pulseCount = 0;  // сбросить счётчик

  unsigned long targetPulses = calculatePulses2(angle);

  Serial.print("Поворот на: ");
  Serial.print(angle);
  Serial.print(" градусов, импульсов для прохождения: ");
  Serial.println(targetPulses);

  // Запуск: левое колесо вперед, правое назад (разворот на месте)
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  // Крутим до достижения нужного количества импульсов
  while (pulseCount < targetPulses) {
    Serial.print("Текущий счётчик импульсов: ");
    Serial.println(pulseCount);
    delay(10);
  }

  // Стоп моторы
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(5000);
  Serial.println("Поворот завершён.");
}
