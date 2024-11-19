#include "pirsensor.h"
//*************************************************************************************
Pirsensor::Pirsensor(int pin, int pirState): _pin(pin), _pirState(pirState) {}
//*************************************************************************************
void Pirsensor::begin() {
  pinMode(_pin, INPUT);
}
bool Pirsensor::getPirState(){
  return _pirState;
}; 

//*************************************************************************************
bool Pirsensor::statePir() {
  int val = digitalRead(_pin);
  bool st = false;
  if (val == HIGH) // есть сигнал от датчика
  {
    if (!_pirState)
    {
      Serial.println("Motion detected!"); // отправляем сообщение только один раз
      _pirState = !_pirState;
      st = true;
    }
  }
  else
  {
    if (_pirState)
    {
      Serial.println("Motion ended!"); // отправляем сообщение только один раз
      _pirState = !_pirState;
      st = false;
    }
  }
  return st;
}
//*************************************************************************************
bool Pirsensor::timeWorkControl(RTC_DS1307& rtc) {
  DateTime now = rtc.now(); // Получаем врем с модуля RTC
  int currentHour = now.hour();
  int currentMinute = now.minute();
  bool result = false;
  //проверка пределов установленного времени
  bool isIntervalAcrossMidnight = _startHour > _endHour;
  
 if (isIntervalAcrossMidnight) {
  // Интервал времени пересекает полночь
  result = (currentHour >= _startHour || currentHour <= _endHour) &&
           ((currentHour == _startHour && currentMinute >= _startMinute) ||
            (currentHour == _endHour && currentMinute <= _endMinute) ||
            ((currentHour > _startHour || currentHour < _endHour) && currentHour != _startHour && currentHour != _endHour));
} else {
  // Интервал времени не пересекает полночь
  result = (currentHour >= _startHour && currentHour <= _endHour) &&
           ((currentHour == _startHour && currentMinute >= _startMinute) ||
            (currentHour == _endHour && currentMinute <= _endMinute) ||
            (currentHour > _startHour && currentHour < _endHour));           
}
  return result;
}
//*************************************************************************************
bool Pirsensor::timeControl(RTC_DS1307& rtc) {
  if (!_condition) {
    return false;
  }

  if (!worked && timeWorkControl(rtc)) {
    if (statePir()) {
      worked = true;
      _previousMillis = millis();
    }
  }
  if (worked && timeDelayControl()) {
    worked = false;
  }

  return worked;
}
//*************************************************************************************
void Pirsensor::setTimeWork(String timeStart, String timeEnd) {
  // Извлекаем часы и минуты
  int startHour = timeStart.substring(0, 2).toInt();
  int startMinute = timeStart.substring(3, 5).toInt();

  // Извлекаем часы и минуты
  int endHour = timeEnd.substring(0, 2).toInt();
  int endMinute = timeEnd.substring(3, 5).toInt();

  _startHour = startHour;
  _startMinute = startMinute;
  _endHour = endHour;
  _endMinute = endMinute;
}
//*************************************************************************************
void Pirsensor::setTimeDelay(int timeDelay) {
  _timeDelay = timeDelay;
}

bool Pirsensor::timeDelayControl() {
  unsigned long currentMillis = millis();
  bool st = false;
  // Проверяем, прошло ли заданное время
  if (currentMillis - _previousMillis >= _timeDelay) {
    _previousMillis = 0;
    st = true;
  }
  return st;
}
//*************************************************************************************
void Pirsensor::enabled() {
  _condition = true;
}
//*************************************************************************************
void Pirsensor::disabled() {
  _condition = false;
}
//*************************************************************************************
bool Pirsensor::condition() {
  return _condition;
}
//*************************************************************************************