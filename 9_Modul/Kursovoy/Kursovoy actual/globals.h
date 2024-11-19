#ifndef GLOBALS_H
#define GLOBALS_H

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "RTClib.h"
#include "lcd.h"
#include "button.h"
#include "pirsensor.h"
#include "alarm.h"

// Константы
#define I2C_ADDR 0x27
#define LCD_COLUMNS 20
#define LCD_LINES 4

#define Y_PIN 26
#define X_PIN 27
#define SEL_PIN 39

// Глобальные переменные
extern int lastX;
extern int lastY;
extern int ledNight;
extern int ledDay;
extern int ledOn;

extern ButtonHandler button1;
extern ButtonHandler button2;
extern ButtonHandler buttonJostik;

extern int cursorLocation;
extern int stroka;
extern unsigned long previousMillis;
extern int hours[2];
extern int minutes[2];
extern int seconds[2];
extern int month[2];
extern int day[2];
extern int year[4];

extern RTC_DS1307 rtc;
extern LiquidCrystal_I2C lcd;
extern ConrolLCD controlLCD;
extern bool startmenu;

extern const int inputPirPin;
extern Pirsensor pirSensorNight;
extern Pirsensor pirSensorDay;
extern int timeDelayPirDay;
extern int timeDelayPirNight;
extern bool condition;
extern String rangeTimeNight[2];
extern String rangeTimeDay[2];

extern int speakerPin;
extern bool workedAlarm;
extern AlarmClock alarmClock;
extern int timeDelayAlarm;

#endif // GLOBALS_H
