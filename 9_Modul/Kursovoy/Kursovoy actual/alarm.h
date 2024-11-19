#ifndef ALARM
#define ALARM

#include "Arduino.h"
#include "pitches.h"
#include "RTClib.h"

class AlarmClock {
    const int _pin;
    bool _status;
    unsigned long _previousMillis;
    int _timeDelay;
    bool _condition;
    bool worked;
    unsigned long _hour;
    unsigned long _minute;

    void speaker();
    bool timeAlarmControl();
    bool timeWorkControl(RTC_DS1307& rtc);

  public:
    AlarmClock(int pin);
    void begin();
    void setTimeDelay(int timeDelay);
    void setTimeAlarm(String timeStart);
    void timeControl(RTC_DS1307& rtc);
    void enabled();
    void disabled();
    bool condition();
};

#endif
