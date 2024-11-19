#include <Arduino.h>
#include "menegmentStepEngine.h"

MenegmentStepEngine::MenegmentStepEngine(const int dirPin, const int stepPin):
  _dirPin(dirPin), _stepPin(stepPin) {
  pinMode(_stepPin, OUTPUT); //������ ��� ������
  pinMode(_dirPin, OUTPUT);
}

void MenegmentStepEngine::setSpeed(bool rotation, int speed_time) {
  _rotation = rotation;
  _speed_time = speed_time;
}

void MenegmentStepEngine::setStep(int stepsPerRevolution) {
  _stepsPerRevolution = stepsPerRevolution;
}

void MenegmentStepEngine::start() {
  digitalWrite(_dirPin, _rotation); //��������������� �����������
  for (int x = 0; x < _stepsPerRevolution; x++) // ������� ������� ���������
  {
    digitalWrite(_stepPin, HIGH);
    delayMicroseconds(_speed_time);
    digitalWrite(_stepPin, LOW);
    delayMicroseconds(_speed_time);
  }

}