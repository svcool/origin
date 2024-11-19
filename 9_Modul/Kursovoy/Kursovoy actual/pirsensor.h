#ifndef PIR_SENSOR
#define PIR_SENSOR
#include "Arduino.h"
#include "RTClib.h"


class Pirsensor {
    const int _pin = 0; // вход от датчика
    bool _pirState = false; // состояние датчика
    bool _status; //включеное отключеное состояние датчика
    unsigned long _previousMillis = 0;
    int _timeDelay = 0 ;//время задержки
    bool _condition = true;//вкл_откл состояние датчика
    bool worked = false; // сработка логики класса

    unsigned long _startHour;
    unsigned long _startMinute;
    unsigned long _endHour;
    unsigned long _endMinute;
    bool statePir();//проверка сработки датчики
    bool timeWorkControl(RTC_DS1307& rtc);
    bool timeDelayControl();

  public:
    Pirsensor(int pin, int pirState = LOW);
    void begin();
    bool getPirState(); //статус сработки до истечения задержки
    bool timeControl(RTC_DS1307& rtc);
    void setTimeWork(String timeStart, String timeEnd);//время работы датчика
    void setTimeDelay(int timeDelay); //таймер
    void enabled();//включить
    void disabled();//выключить
    bool condition();//вкл_откл состояние датчика
};

#endif