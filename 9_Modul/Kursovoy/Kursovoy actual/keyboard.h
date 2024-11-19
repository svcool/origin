#ifndef KEYBOARD_CONTROL
#define KEYBOARD_CONTROL
#include <LiquidCrystal_I2C.h>

bool error = false;

void processTimeInput(char& keypressed, int k);
void processSecondHourDigit(char& keypressed);
void processFirstHourDigit(char& keypressed);
void processFirstMinutDigit(char& keypressed);
void processSecondMinutDigit(char& keypressed, int& k);
void displayError(const char* errorMessage);
void updateCursorLocation(char& keypressed);
void processInput(char& keypressed);
void showLcd(int x, char& keypressed);
void processKeyInput(char& keypressed);
void processFirstSecondDigit(char& keypressed);
void processSecondSecondDigit(char& keypressed);
void processFullTimeInput(char& keypressed);
void processDateInput(char& keypressed);
void processMonthDigit(char& keypressed);
void processYearDigit(char& keypressed);
void processDayDigit(char& keypressed);

//задержка для отображения ошибки
void timeDelayError(unsigned long& previousMillis, unsigned long& currentMillis) {
  if (currentMillis - previousMillis >= 2000 && error) {
    previousMillis = currentMillis;
    lcd.noCursor();
    lcd.setCursor(0, 2);
    lcd.print("                ");
    lcd.cursor();
    lcd.setCursor(cursorLocation, stroka);
    error = false;
  }
}
// формат 00:00:00
void processFullTimeInput(char& keypressed) {
  if (cursorLocation < 6){
    processTimeInput(keypressed, 0);
}
 else if (cursorLocation == 6) {
    processFirstSecondDigit(keypressed);
  }
  else if (cursorLocation == 7) {
    processSecondSecondDigit(keypressed);
  }
  else {
    displayError("Error number");
  }

}

void processFirstSecondDigit(char& keypressed) {
  seconds[0] = keypressed;

  if (seconds[0] - '0' <= 5) { // Первая цифра может быть от 0 до 5
    controlLCD.inputBufferLCD(keypressed);
    lcd.print(keypressed);
    cursorLocation++;
    lcd.setCursor(cursorLocation, stroka);
  } else {
    displayError("Error number");
  }
}

void processSecondSecondDigit(char& keypressed) {
  seconds[1] = keypressed;
  Serial.println(cursorLocation);
  if (seconds[1] - '0' <= 9) { // Вторая цифра минут может быть от 0 до 9
    controlLCD.inputBufferLCD(keypressed);
    lcd.print(keypressed);
    Serial.println(cursorLocation);
    lcd.setCursor(cursorLocation, stroka);
    cursorLocation >= 7 ? cursorLocation = 0 : cursorLocation++; // Переходим к следующему полю
    lcd.setCursor(cursorLocation, stroka);
  }
  else {
    displayError("Error number");
  }
}


// Функция для обработки нажатий клавиш во время установки времени
void processTimeInput(char& keypressed, int k) {
  lcd.cursor();
  lcd.setCursor(cursorLocation, stroka);
  if (cursorLocation == 0 + k) {
    processFirstHourDigit(keypressed);
  } else if (cursorLocation == 1 + k) {
    processSecondHourDigit(keypressed);
  }
  else if (cursorLocation == 3 + k) {
    processFirstMinutDigit(keypressed);
  }
  else if (cursorLocation == 4 + k) {
    processSecondMinutDigit(keypressed, k);
  }
  else {
    displayError("Error number");
  }
}


void processFirstMinutDigit(char& keypressed) {
  minutes[0] = keypressed;

  if (minutes[0] - '0' <= 5) { // Первая цифра минут может быть от 0 до 5
    controlLCD.inputBufferLCD(keypressed);
    lcd.print(keypressed);
    cursorLocation++;
    lcd.setCursor(cursorLocation, stroka);
  } else {
    displayError("Error number");
  }
}

void processSecondMinutDigit(char& keypressed, int& k) {
  minutes[1] = keypressed;
  Serial.println(cursorLocation);
  if (minutes[1] - '0' <= 9) { // Вторая цифра минут может быть от 0 до 9
    controlLCD.inputBufferLCD(keypressed);
    lcd.print(keypressed);
    lcd.setCursor(cursorLocation, stroka);

    if (controlLCD.periodOfWork()) {
      if (cursorLocation == 4) {

        char dv[] = " - ";
        for (int i = 0; i < 3; i++) {
          cursorLocation++;
          controlLCD.inputBufferLCD(dv[i]);
        }
        cursorLocation ++;
        lcd.setCursor(cursorLocation, stroka);
      }
      if (cursorLocation >= 12)  cursorLocation = 0;
      lcd.setCursor(cursorLocation, stroka);
    }
    else if (controlLCD.timeM()) {

      //    lcd.print(keypressed);
      cursorLocation ++;
      char dv = ':';
      controlLCD.inputBufferLCD(dv);
      cursorLocation ++;
      lcd.setCursor(cursorLocation, stroka);
    }
    else if(controlLCD.timeOfWork()) {
      cursorLocation >= 4 ? cursorLocation = 0 : cursorLocation++; // Переходим к следующему полю
      lcd.setCursor(cursorLocation, stroka);
    }
  }
  else {
    displayError("Error number");
  }
}

// Функция для обработки первой цифры часов
void processFirstHourDigit(char& keypressed) {
  hours[0] = keypressed;

  if ((hours[0] - '0' < 2 && hours[1] - '0' <= 9) ||
      (hours[0] - '0' == 2 && hours[1] - '0' <= 4)) {

    controlLCD.inputBufferLCD(keypressed);
    lcd.print(keypressed);
    cursorLocation++;
    lcd.setCursor(cursorLocation, stroka);
  } else {
    displayError("Error number");
  }
}

// Функция для обработки второй цифры часов
void processSecondHourDigit(char& keypressed) {
  hours[1] = keypressed;

  if ((hours[1] - '0' <= 9 && hours[0] - '0' < 2) ||
      (hours[1] - '0' <= 4 && hours[0] - '0' == 2)) {
    controlLCD.inputBufferLCD(keypressed);
    lcd.print(keypressed);
    cursorLocation ++;
    char dv = ':';
    controlLCD.inputBufferLCD(dv);
    cursorLocation ++;
    lcd.setCursor(cursorLocation, stroka);
  } else {
    displayError("Error number");
  }
}

// Функция для отображения сообщения об ошибке
void displayError(const char* errorMessage) {
  error = true;
  lcd.noCursor();
  lcd.setCursor(0, 2);
  lcd.print(errorMessage);
  lcd.setCursor(cursorLocation, stroka);
  lcd.cursor();
}


void processDateInput(char& keypressed) {
  if (cursorLocation < 3) {
    processDayDigit(keypressed);
  } 
  else if (cursorLocation < 5) {
    processMonthDigit(keypressed);
  } else if (cursorLocation < 10) {
    processYearDigit(keypressed);
  } else {
    displayError("Error date");
  }
}

void processDayDigit(char& keypressed) {
  if (cursorLocation == 0) { // Первая цифра дня может быть от 0 до 3
    day[0] = keypressed;
    if(day[0] - '0' <= 3){
    controlLCD.inputBufferLCD(keypressed);
    lcd.print(keypressed);
    cursorLocation++;
    lcd.setCursor(cursorLocation, stroka);
    }
    else {
    displayError("Error day");
  }
  }
  else if (cursorLocation == 1){
    day[1] = keypressed;
    if((day[1] - '0' <= 9 && day[0] - '0' != 3) || 
    (day[1] - '0' <= 1 && day[0] - '0' == 3)){
    controlLCD.inputBufferLCD(keypressed);
    lcd.print(keypressed);
    cursorLocation ++;
    char dv = '.';
    controlLCD.inputBufferLCD(dv);
    cursorLocation ++;
    lcd.setCursor(cursorLocation, stroka);
    }
  
 else {
    displayError("Error day");
 }
  }
}

void processMonthDigit(char& keypressed) {
  if (cursorLocation == 3) {
  month[0] = keypressed;
  if (month[0] - '0' <= 1) { // Первая цифра месяца может быть от 0 до 1
    controlLCD.inputBufferLCD(keypressed);
    lcd.print(keypressed);
    cursorLocation++;
    lcd.setCursor(cursorLocation, stroka);
  }
  else {
    displayError("Error month");
  }
  }
    else if (cursorLocation == 4){
month[1] = keypressed;
    if((month[1] - '0' <= 9 && month[0] - '0' == 0)|| 
    (month[1] - '0' < 3 && month[0] - '0'== 1)){
      Serial.print("fffff");
    controlLCD.inputBufferLCD(keypressed);
    lcd.print(keypressed);
    cursorLocation ++;
    char dv = '.';
    controlLCD.inputBufferLCD(dv);
    cursorLocation ++;
    Serial.print(cursorLocation);
    lcd.setCursor(cursorLocation, stroka);
    }
    else {
    displayError("Error month");
  }
  }
}

void processYearDigit(char& keypressed) {
  if (cursorLocation == 6) {
    year[0] = keypressed;
    }else if (cursorLocation == 7){
    year[1] = keypressed;
    }else  if (cursorLocation == 8) {
    year[2] = keypressed;
    }else if (cursorLocation == 9){
    year[3] = keypressed;
    }
    controlLCD.inputBufferLCD(keypressed);
    lcd.print(keypressed); 
   cursorLocation >= 9 ? cursorLocation = 0 : cursorLocation++;
   lcd.setCursor(cursorLocation, stroka);
}

//ограничение и вывод полей на LCD
void showLcd(int x, char& keypressed) {
  controlLCD.inputBufferLCD(keypressed);
  lcd.print(keypressed);
  cursorLocation == x ? cursorLocation = 0 : cursorLocation++;
  lcd.setCursor(cursorLocation, stroka);
}

void processKeyInput(char& keypressed) {
  if (controlLCD.timeOfWork()) {
    processTimeInput(keypressed, 0);
  }
  else if (controlLCD.periodOfWork()) {

    if (cursorLocation <= 4) {
      processTimeInput(keypressed, 0);
    } else {
      processTimeInput(keypressed, 8);
    }

  } else if (controlLCD.durationNightM()) {
    showLcd(1, keypressed);
  } else if (controlLCD.durationM()) {
    showLcd(2, keypressed);
  } else if (controlLCD.timeM()) {
    processFullTimeInput(keypressed);
    //showLcd(7, keypressed);
  } else if (controlLCD.dateM()) {
    processDateInput(keypressed);
  } else {
    showLcd(19, keypressed);
  }
}


#endif //KEYBOARD_CONTROL