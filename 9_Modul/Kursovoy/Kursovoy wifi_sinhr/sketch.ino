#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "RTClib.h"
#include "wifi.h"
//#include "TimeLib.h"
String addressTime = "http://worldtimeapi.org/api/timezone/Europe/Moscow";

unsigned long lastUpdateTime = 0; // Переменная для хранения времени последнего обновления
const unsigned long updateInterval = 3600000; // Интервал обновления в миллисекундах (1 час)

WifiSettings wifi;
ServerTimeHttp serverTime(addressTime);

RTC_DS1307 rtc; //RTC модуль
LiquidCrystal_I2C lcd(0x27, 16, 4); // Адрес дисплея и его размеры(I2C)


void updateTime() {
  DateTime now = rtc.now(); // Получаем врем с модуля RTC
  lcd.setCursor(0, 0);
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


void setup() {
  Serial.begin(115200);
  wifi.connectWifi();
  serverTime.begin();

  Wire.begin();// Start I2C communication
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    abort();
  }
  lcd.init();

  rtc.adjust(DateTime(2023, 3, 15, 14, 30, 0)); // установка не актуальной даты и времени

  serverTime.requestHttp(); // запрос времени с сайта
  DateTime date_time = serverTime.handleReceivedMessage(); // получение времени 
  rtc.adjust(date_time); //синхронизация
}

void loop() {
  updateTime(); // обновление экрана
  unsigned long currentMillis = millis(); 
  // Обновление каждый час
  if (currentMillis - lastUpdateTime >= updateInterval) {
    updateTime();
    serverTime.requestHttp();
    DateTime date_time = serverTime.handleReceivedMessage(); 
    rtc.adjust(date_time); // Обновляем время в RTC 
    lastUpdateTime = currentMillis; 
  }

}
