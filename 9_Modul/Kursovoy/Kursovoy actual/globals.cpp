#include "globals.h"

// Определения переменных
int lastX = 2048;
int lastY = 2048;
int ledNight = 25;
int ledDay = 32;
int ledOn = LOW;

ButtonHandler button1(39);
ButtonHandler button2(35);
ButtonHandler buttonJostik(34);

int cursorLocation = 0;
int stroka = 0;
unsigned long previousMillis = 0;
int hours[2] = {0, 0};
int minutes[2] = {0, 0};
int seconds[2] = {0, 0};
int month[2] = {0, 0};
int day[2] = {0, 0};
int year[4] = {0, 0, 0, 0};

RTC_DS1307 rtc;
LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLUMNS, LCD_LINES);
ConrolLCD controlLCD(lcd, 20, 4, cursorLocation, stroka);
bool startmenu = false;

const int inputPirPin = 36;
Pirsensor pirSensorNight(inputPirPin);
Pirsensor pirSensorDay(inputPirPin);
int timeDelayPirDay = 5000;
int timeDelayPirNight = 5000;
bool condition = false;
String rangeTimeNight[2];
String rangeTimeDay[2];

int speakerPin = 23;
bool workedAlarm = false;
AlarmClock alarmClock(speakerPin);
int timeDelayAlarm = 5000;
