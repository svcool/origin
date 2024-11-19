#include "TimeFunctions.h"
//****************************************************************************
void adjustClock() {
    int hour, minute, second;
    sscanf(subMenuClock[1].data.c_str(), "%02d:%02d:%02d", &hour, &minute, &second);
    DateTime now = rtc.now();
    rtc.adjust(DateTime(now.year(), now.month(), now.day(), hour, minute, second));
}
//****************************************************************************
void adjustDate() {
    int year, month, day;
    sscanf(subMenuClock[0].data.c_str(), "%02d.%02d.%04d", &day, &month, &year);
    DateTime now = rtc.now();
    rtc.adjust(DateTime(year, month, day, now.hour(), now.minute(), now.second()));
}
//****************************************************************************
void initialStartParametr() {
rangeTimeNight[0] = subMenuNightLight[0].data.substring(0, 5);
rangeTimeNight[1] = subMenuNightLight[0].data.substring(8,13); 
rangeTimeDay[0] = subMenuDayLight[0].data.substring(0, 5);
rangeTimeDay[1] = subMenuDayLight[0].data.substring(8,13);

timeDelayPirNight = subMenuNightLight[1].data.toInt()*10;
timeDelayPirDay = subMenuDayLight[1].data.toInt()*10;
timeDelayAlarm = subMenuBuzzer[1].data.toInt()*10;
controlLCD.setApplyDataMenu(false);
}
//****************************************************************************
void updateTime() {
   DateTime now = rtc.now(); // Получаем врем с модуля RTC
  lcd.setCursor(0, 2);
  lcd.print(String(now.year()) + "/");
  lcd.print(String(now.month()) + "/");
  lcd.print(String(now.day()) + " ");
  // Формат HH:MM:SS
  lcd.print(String(now.hour()) + ":");
  if (now.minute() < 10) lcd.print("0");
  lcd.print(String(now.minute()) + ":");
  if (now.second() < 10) lcd.print("0");
  lcd.print(now.second());
}
//****************************************************************************