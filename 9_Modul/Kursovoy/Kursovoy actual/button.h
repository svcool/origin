#ifndef BUTTON_H
#define BUTTON_H

#include "Arduino.h"

class ButtonHandler {
    int _lastButton = false;   // Предыдущее состояние кнопки
    bool _stateButton = true; // Текущее состояние кнопки
    int _pin=0;          // Пин подключения кнопки
  public:
    ButtonHandler(int pin, int lastButton = false, bool stateButton = false);

    void begin(int state = HIGH); //иницилизация
    bool handleButton();// Функция для получения состояния кнопки
    void setResetButton();//сброс кнопки
};
#endif