#include "button.h"
//*************************************************************************************
ButtonHandler::ButtonHandler(int pin, int lastButton, bool stateButton)
    : _pin(pin), _lastButton(lastButton), _stateButton(stateButton) {
}
//*************************************************************************************
void ButtonHandler::begin(int state) {
  digitalWrite(_pin, state);// без параметров state=HIGH
  pinMode(_pin, INPUT); 
}
//*************************************************************************************
// Функция для получения состояния кнопки
bool ButtonHandler::handleButton() {
  int currentState = digitalRead(_pin);
  // Устранение дребезга
  if (_lastButton != currentState) {
    delay(10);
    currentState = digitalRead(_pin);
  }
  // Переключение состояния кнопки
  if (_lastButton == HIGH && currentState == LOW) {
    _stateButton = !_stateButton;
  }
  // Обновление предыдущего состояния
  _lastButton = currentState;
  return _stateButton;
}
//*************************************************************************************
void ButtonHandler::setResetButton() {
  _stateButton = false;
}
//*************************************************************************************