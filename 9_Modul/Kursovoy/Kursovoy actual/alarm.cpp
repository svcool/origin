#include "alarm.h"

const int tone1 = NOTE_B4;  // 1319 Гц
const int tone2 = NOTE_E5;  // 1568 Гц
const int tone3 = NOTE_G5;  // 1568 Гц
const int tone4 = NOTE_A5;  // 987 Гц
//*************************************************************************************
void AlarmClock::speaker() {
  for (int i = 0; i < 5; i++) {  
    tone(_pin, tone1, 300);  
    delay(100);  
    tone(_pin, tone2, 300);  
    delay(100);  
    tone(_pin, tone3, 300);  
    delay(100);  
    tone(_pin, tone4, 300);  
    delay(100);  
  }
  noTone(_pin);  
}
//*************************************************************************************
bool AlarmClock::timeAlarmControl() {
  unsigned long currentMillis = millis();
  bool st = false;
  if (currentMillis - _previousMillis >= _timeDelay) {
    _previousMillis = 0;
    st = true;
  }
  return st;
}
//*************************************************************************************
bool AlarmClock::timeWorkControl(RTC_DS1307& rtc) {
  DateTime now = rtc.now(); 
  int currentHour = now.hour();
  int currentMinute = now.minute();
  int currentsecond = now.second();
  if (currentHour == _hour && currentMinute == _minute && currentsecond < 9) {
    return true; 
  }
  return false;
}
//*************************************************************************************
AlarmClock::AlarmClock(int pin): _pin(pin) {}
//*************************************************************************************
void AlarmClock::begin() {
  pinMode(_pin, INPUT);
}
//*************************************************************************************
void AlarmClock::setTimeDelay(int timeDelay) {
  _timeDelay = timeDelay;
}
//*************************************************************************************
void AlarmClock::setTimeAlarm(String timeStart) {
  _hour = timeStart.substring(0, 2).toInt();
  _minute = timeStart.substring(3, 5).toInt();
}
//*************************************************************************************
void AlarmClock::timeControl(RTC_DS1307& rtc) {
  if (_condition) {
    if (timeWorkControl(rtc) && !worked) { 
      _previousMillis = millis();
      worked = true;
    }
    if (worked) {
      speaker();
    }
    if (timeAlarmControl() && !timeWorkControl(rtc)) {
      worked = false;
    }
  }
}
//*************************************************************************************
void AlarmClock::enabled() {
  _condition = true;
}
//*************************************************************************************
void AlarmClock::disabled() {
  _condition = false;
}
//*************************************************************************************
bool AlarmClock::condition() {
  return _condition;
}
//*************************************************************************************
