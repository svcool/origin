
#include "globals.h"
#include "keyboard.h"
#include "TimeFunctions.h"
//#include "wifi.h"

void setup() {
//wifi
  // wifi.connectWifi();
  // serverTime.begin();
  // serverTime.requestHttp(); // запрос времени с сайта
  // DateTime date_time = serverTime.handleReceivedMessage(); // получение времени 
  // rtc.adjust(date_time); //синхронизация
  
  //джостик
  pinMode(Y_PIN, INPUT);
  pinMode(X_PIN, INPUT);
  buttonJostik.begin();
  //lcd
  Wire.begin();// Start I2C communication
  lcd.backlight();//включить подстветку
  lcd.init();
  lcd.clear();
  lcd.home();
  lcd.print("********************");
  Serial.begin(115200);
  lcd.setCursor(0, 1);
  lcd.print("Hello!");
  lcd.setCursor(0, 3);
  lcd.print("Press the joystick");


  //RTC модуль
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    abort();
  }
  //кнопки
  button1.begin();
  button2.begin();


  //LCD
  digitalWrite(ledDay, LOW);
  digitalWrite(ledNight, LOW);
  pinMode(ledDay, OUTPUT); //дневная подсветка
  pinMode(ledNight, OUTPUT); //ночная подстветка

  //датчик движения
  pirSensorNight.begin();
  pirSensorDay.begin();
  //Будильник
  alarmClock.begin();

  initialStartParametr();
}
//******************************************************
void loop() {
  
if(controlLCD.getApplyDataMenu()){ // проверка на изменение данных для дальнейших иницилизации
initialStartParametr();
}
  // Serial.println(subMenuClock[0].data);
  // Serial.println(subMenuClock[1].data);

if(controlLCD.getApplyClockMenu()){ // проверка на изменение данных для дальнейших иницилизации
adjustClock();
controlLCD.setApplyClockMenu(false);
}

if(controlLCD.getApplyDateMenu()){ // проверка на изменение данных для дальнейших иницилизации
adjustDate();
controlLCD.setApplyDateMenu(false);
}

// if(controlLCD.getApplyWifiMenu()){ // проверка на изменение данных для дальнейших иницилизации
// wifi.setSsid(subMenuNetwork[0].data.c_str()); 
// wifi.setPass(subMenuNetwork[1].data.c_str());
// wifi.connectWifi();
// controlLCD.setApplyWifiMenu(false);
// }

  if (controlLCD.getStartWindow()) {
    updateTime(); //отображение времени и даты на экране
  }
  //*******логика кнопок***********************
  button1.setResetButton();
  button2.setResetButton();
  buttonJostik.setResetButton();
  if (button1.handleButton()) {
    ledOn = !ledOn;
    digitalWrite(32, ledOn);
  }
  if (button2.handleButton()) {
    ledOn = !ledOn;
    digitalWrite(32, ledOn);
  }
  //*********логика LCD и управления меню*****************
  char keypressed = kpd.getKey();
  unsigned long currentMillis = millis();
  if (controlLCD.timeOfWork() || controlLCD.periodOfWork()
      || controlLCD.timeM() || controlLCD.dateM()) {
    timeDelayError(previousMillis, currentMillis); //задержка для отображения ошибки
  }
  if (controlLCD.getenterMenu() && controlLCD.keyboardEnabled()) {
    if (keypressed != NO_KEY) {
      processKeyInput(keypressed);
    }
  }

  //джостик
  int x = analogRead(X_PIN);  // считываем значение оси X
  int y = analogRead(Y_PIN);  // считываем значение оси Y
  if (x != lastX) { // если значение оси X изменилось
    delay(200);
    controlLCD.moveCursor(x);
  }
  if (y != lastY) { // если значение оси Y изменилось
    delay(200);
    controlLCD.moveLine(y); // проверка нажатия и смещение
  }
  //кнопка джостика
  if (buttonJostik.handleButton()) {
    //первый старт меню
    if (controlLCD.getStartWindow()) {
      controlLCD.displayMenu();// отображение меню
      controlLCD.changeCursor();// курсор выбора
    }
    else {
      controlLCD.selectMenuItem();
    }
  }

  // датчик движения ночью
      if(subMenuNightLight[2].data == "On"){
    pirSensorNight.enabled();
    }
  else if(subMenuNightLight[2].data == "Off"){
pirSensorNight.disabled();
  }
  pirSensorNight.setTimeWork(rangeTimeNight[0], rangeTimeNight[1]);//время работы
  pirSensorNight.setTimeDelay(timeDelayPirNight); //времы задержки освещения
  if (pirSensorNight.timeControl(rtc)) {
    digitalWrite(ledNight, HIGH);
  }
  else {
    digitalWrite(ledNight, LOW);
  }

  // датчик движения днем
    if(subMenuDayLight[2].data == "On"){
    pirSensorDay.enabled();
    }
  else if(subMenuDayLight[2].data == "Off"){
pirSensorDay.disabled();
  }
  pirSensorDay.setTimeWork(rangeTimeDay[0], rangeTimeDay[1]);//время работы
  pirSensorDay.setTimeDelay(timeDelayPirDay); //времы задержки освещения
if (pirSensorDay.timeControl(rtc)) {
    if (!condition) { // проверка, не было ли условие выполнено ранее
      digitalWrite(ledDay, HIGH);
      condition = true; // установить флаг в true
    }
  } else {
    if (condition) { // проверка, было ли условие выполнено ранее
      digitalWrite(ledDay, LOW);
      condition = false; // сбросить флаг
    }
  }

 //будильник
  if(subMenuBuzzer[2].data == "On"){
    alarmClock.enabled();
    }
  else if(subMenuBuzzer[2].data == "Off"){
alarmClock.disabled();
  }
  alarmClock.setTimeDelay(timeDelayAlarm);
  alarmClock.setTimeAlarm(subMenuBuzzer[0].data);
  alarmClock.timeControl(rtc);

}