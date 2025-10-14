#include <Arduino.h>
#include <moveForward.h>
#include <encoderUtils.h>
// Пины моторов
#define IN1 27
#define IN2 26
#define IN3 25
#define IN4 33

// Пин энкодера
#define ENCODER_PIN 34

const float WHEEL_DIAMETER = 0.07; // метры
const int SLOTS = 20;              // количество отверстий (импульсов на один оборот)



// Инициализация пинов и прерываний энкодера
void setupMoveForward() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENCODER_PIN, INPUT);


  Serial.begin(115200);
}

// Расчёт, сколько импульсов нужно для заданного расстояния
unsigned long calculatePulses1(float distance_m) {
  float wheelCircumference = PI * WHEEL_DIAMETER; // длина окружности колеса
  float revolutions = distance_m / wheelCircumference;
  return revolutions * SLOTS;
}

// Основная функция: проехать distance_m метров вперёд
void moveForwardDistance(float distance_m) {
  pulseCount = 0;

  unsigned long targetPulses = calculatePulses1(distance_m);

  Serial.print("Заданное расстояние: ");
  Serial.print(distance_m);
  Serial.print(" м, импульсов для прохождения: ");
  Serial.println(targetPulses);

  // Оба мотора вперёд
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  while (pulseCount < targetPulses) {
    Serial.print("Текущий счётчик импульсов: ");
    Serial.println(pulseCount);
    delay(10);
  }

  // Остановить моторы
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(5000);
  Serial.println("Движение завершено.");
}
