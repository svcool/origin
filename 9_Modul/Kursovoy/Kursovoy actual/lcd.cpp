#include "lcd.h"

// Инициализация текущего символа
char letter = 'A' - 1;
// Инициализация карты клавиш
char keymap[Rows][Cols] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

// Инициализация пинов
byte rPins[Rows] = {19, 18, 17, 16};
byte cPins[Cols] = {4, 14, 13};

// Экземпляр Keypad
Keypad kpd = Keypad(makeKeymap(keymap), rPins, cPins, Rows, Cols);

// Подменю для Дневной свет
MenuItem subMenuDayLight[] = {
  {3, "07:00 - 23:22", "Period of time", nullptr},
  {3, "600", "Duration", nullptr},
  {3, "On", "Sensor(on/off)", nullptr}
};

// Подменю для Ночной свет
MenuItem subMenuNightLight[] = {
  {3, "23:00 - 07:00", "Period of time", nullptr},
  {3, "60", "Duration", nullptr},
  {3, "On", "Sensor(on/off)", nullptr}
};

// Подменю для Установка времени
MenuItem subMenuClock[] = {
  {2, "01.01.2024", "Date", nullptr},
  {2, "00:00:00", "Time", nullptr}
};

// Подменю для Будильник
MenuItem subMenuBuzzer[] = {
  {3, "16:39", "Time of work", nullptr},
  {3, "600", "Duration", nullptr},
  {3, "On", "On/Off", nullptr}
};

// Подменю для Сеть
MenuItem subMenuNetwork[] = {
  {2, "Wokwi-GUEST", "SSID", nullptr},
  {2, "", "Password", nullptr}
};

// Подменю для Настройки
MenuItem subMenuSettings[] = {
  {4, "", "Day light", subMenuDayLight},
  {4, "", "Night light", subMenuNightLight},
  {4, "", "Date and Time", subMenuClock},
  {4, "", "Alarm", subMenuBuzzer}
};

// Главное меню
MenuItem mainMenu[] = {
  {4, "", "Settings modul", subMenuSettings},
  {4, "", "Network", subMenuNetwork},
  {4, "", "Date and time", subMenuClock},
  {4, "", "Exit", nullptr}
};
//*******************************************************************************************************
// Конструктор
ConrolLCD::ConrolLCD(LiquidCrystal_I2C& lcd, int lcdColums, int lcdLines, int& cursorLocation, int& stroka, MenuItem* initMenu)
  : _lcd(lcd), _lcdColums(lcdColums), _lcdLines(lcdLines), _cursorLocation(cursorLocation), _stroka(stroka), currentMenu(initMenu) {
  // Инициализация полей
  _currentMenuItem = 0;
  _currentMenuLevel = 0;
  enterMenu = false;
  on = true;
  keyboard = true;
  jostik = true;
  startWindow = true;
  timeWork = false;
  periodWork = false;
  durationMenu = false;
  timeMenu = false;
  dateMenu = false;
  durationNightMenu = false;
  errorDuration = false;
  applyDataMenu = false;
  applyClockMenu = false;
  applyDateMenu = false;
  applyWifiMenu = false;
  hours = 0;
  minutes = 0;
}
//*******************************************************************************************************
// Определения методов класса
bool ConrolLCD::getStartWindow() {
  return startWindow;
}
//*******************************************************************************************************
void ConrolLCD::inputBufferLCD(char& key) {
  inputBuffer[_cursorLocation] = key;
}
//*******************************************************************************************************
String ConrolLCD::getInputBuffer() {
  return String(inputBuffer);
}
//*******************************************************************************************************
void ConrolLCD::moveLine(int &y) {
  if (y > 2048 + 200 && _stroka >= 0) {
    if (!enterMenu) {
      moveUp();
      _stroka = _currentMenuItem;
      changeCursor();
    } else {
      if (currentMenu[_currentMenuItem].text == "SSID" || currentMenu[_currentMenuItem].text == "Password") {
        letter++; // смена символа
        _lcd.print(letter);
        inputBufferLCD(letter); // запись в буфер введенных символов
        _lcd.setCursor(_cursorLocation, _stroka); // возврат курсора
      }
      if (currentMenu[_currentMenuItem].text == "Sensor(on/off)" || currentMenu[_currentMenuItem].text == "On/Off") {
        changeOnOff();
      }
    }
  }

  if (y < 2048 - 200 && _stroka <= _lcdLines - 1) {
    if (!enterMenu) {
      moveDown();
      _stroka = _currentMenuItem;
      changeCursor();
    } else {
      if (currentMenu[_currentMenuItem].text == "SSID" || currentMenu[_currentMenuItem].text == "Password") {
        letter--; // смена символа
        _lcd.print(letter);
        inputBufferLCD(letter); // запись в буфер введенных символов _lcd.setCursor(_cursorLocation, _stroka); // возврат курсора
      }
      if (currentMenu[_currentMenuItem].text == "Sensor(on/off)" || currentMenu[_currentMenuItem].text == "On/Off") {
         changeOnOff();
      }
    }
  }
  delay(100);
}
//*******************************************************************************************************
void ConrolLCD::changeOnOff() {
  on ? _lcd.setCursor(0, 1):_lcd.setCursor(0, 2);
  _lcd.print("  ");//стираем курсор
  on = !on;
  _lcd.setCursor(0, on ? 1 : 2);
  _lcd.print("->");
}
//*******************************************************************************************************
void ConrolLCD::moveCursor(int &x) {
  if (x < 2048 - 200) { // Движение вправо
    if (!enterMenu) {
      returnPreviosMenu();
    } else {
      if (currentMenu[_currentMenuItem].text == "Time of work") {
        reversLcdCursor(4, true);
      } else if (currentMenu[_currentMenuItem].text == "Duration") {
        if (currentMenu == subMenuNightLight) {
          reversLcdCursor(1, true);
        } else {
          reversLcdCursor(2, true);
        }
      } else if (currentMenu[_currentMenuItem].text == "Date") {
        reversLcdCursor(9, true);
      } else if (currentMenu[_currentMenuItem].text == "Time") {
        reversLcdCursor(8, true);
      } else if (currentMenu[_currentMenuItem].text == "Period of time") {
        reversLcdCursor(12, true);
      } else {
        reversLcdCursor(19, true);
      }
      _lcd.setCursor(_cursorLocation, _stroka);
    }
  } else if (x > 2048 + 200) { // Движение влево
    if (!enterMenu) {
      returnPreviosMenu();
    } else {
      if (currentMenu[_currentMenuItem].text == "Time of work") {
        reversLcdCursor(4, false);
      } else if (currentMenu[_currentMenuItem].text == "Duration") {
        if (currentMenu == subMenuNightLight) {
          reversLcdCursor(1, false);
        } else {
          reversLcdCursor(2, false);
        }
      } else if (currentMenu[_currentMenuItem].text == "Date") {
        reversLcdCursor(10, false);
      } else if (currentMenu[_currentMenuItem].text == "Time") {
        reversLcdCursor(8, false);
      } else if (currentMenu[_currentMenuItem].text == "Period of time") {
        reversLcdCursor(12, false);
      } else {
        reversLcdCursor(19, false);
      }
      _lcd.setCursor(_cursorLocation, _stroka);
    }
  }
  delay(100);
}
//*******************************************************************************************************
void ConrolLCD::reversLcdCursor(int x, bool right) {
  if (right) {
    _cursorLocation == x ? _cursorLocation = 0 : _cursorLocation++;
  } else {
    _cursorLocation == 0 ? _cursorLocation = x : _cursorLocation--;
  }
}
//*******************************************************************************************************
void ConrolLCD::changeCursor() {
  int num = 0;
  int count = currentMenu[0].count;
  _lcd.home();
  for (num; num < count; num++) {
    if (num != _stroka) {
      _lcd.setCursor(0, num);
      _lcd.print("  ");
    } else {
      _lcd.setCursor(0, num);
      _lcd.print("->");
    }
  }
}
//*******************************************************************************************************
void ConrolLCD::displayMenu() {
  startWindow = false;
  _currentMenuItem = 0; _stroka = 0;
  _lcd.home();
  _lcd.clear();
  _lcd.setCursor(0, 0);

  int count = currentMenu[0].count;
  for (int i = 0; i < count; i++) {
    _lcd.setCursor(0, i);
    _lcd.println("  " + currentMenu[i].text);
  }
  changeCursor();
}
//*******************************************************************************************************
void ConrolLCD::moveUp() {
  if (_currentMenuItem > 0) {
    _currentMenuItem--;
  } else {
    _currentMenuItem = currentMenu[0].count - 1;
  }
  delay(200);
}
//*******************************************************************************************************
void ConrolLCD::moveDown() {
  if (_currentMenuItem < currentMenu[0].count - 1) {
    _currentMenuItem++;
  } else {
    _currentMenuItem = 0;
  }
  delay(200);
}
//*******************************************************************************************************
bool ConrolLCD::timeOfWork() {
  return timeWork;
}
//*******************************************************************************************************
bool ConrolLCD::periodOfWork() {
  return periodWork;
}
//*******************************************************************************************************
bool ConrolLCD::durationM() {
  return durationMenu;
}
//*******************************************************************************************************
bool ConrolLCD::durationNightM() {
  return durationNightMenu;
}
//*******************************************************************************************************
bool ConrolLCD::timeM() {
  return timeMenu;
}
//*******************************************************************************************************
bool ConrolLCD::dateM() {
  return dateMenu;
}
//*******************************************************************************************************
void ConrolLCD::displayInitailMenu() {
  _lcd.cursor();
  _lcd.setCursor(0, 1);
  _lcd.print(currentMenu[_currentMenuItem].data);
  strcpy(inputBuffer, currentMenu[_currentMenuItem].data.c_str());
  _lcd.setCursor(0, 1);
  _lcd.cursor();
}
//*******************************************************************************************************
void ConrolLCD::selectMenuItem() {
  if (currentMenu[_currentMenuItem].subMenu != nullptr && !enterMenu) {
    this->_previosMenus[_currentMenuLevel] = currentMenu;
    _currentMenuLevel++;
    currentMenu = currentMenu[_currentMenuItem].subMenu;
    displayMenu();
  } else if (currentMenu[_currentMenuItem].text == "Exit") {
    returnPreviosMenu();
  } else {
    if (enterMenu) {
      _lcd.noCursor();
      action();
      if (!errorDuration) {
        enterMenu = false;
        _currentMenuItem = 0;
        keyboard = true;
        jostik = true;
        timeWork = false;
        periodWork = false;
        durationMenu = false;
        durationNightMenu = false;
        timeMenu = false;
        dateMenu = false;
        _lcd.noCursor();
        displayMenu();
      }
    } else {
      _lcd.clear();
      memset(inputBuffer, '\0', sizeof(inputBuffer));

      _lcd.setCursor(0, 0);
      _lcd.print(currentMenu[_currentMenuItem].text + ":");
      _stroka = 1;
      _cursorLocation = 0;
      _lcd.setCursor(_cursorLocation, _stroka);
      enterMenu = true;
      _lcd.cursor();

      if (currentMenu[_currentMenuItem].text == "Duration") {
        if (currentMenu == subMenuNightLight) {
          durationNightMenu = true;
          jostik = false;
          displayInitailMenu();
        } else {
          durationMenu = true;
          jostik = false;
          displayInitailMenu();
        }
      }

      if (currentMenu[_currentMenuItem].text == "Time") {
        timeMenu = true;
        jostik = false;
        displayInitailMenu();
      }

      if (currentMenu[_currentMenuItem].text == "Date") {
        dateMenu = true;
        jostik = false;
        displayInitailMenu();
      }

      if (currentMenu[_currentMenuItem].text == "Time of work") {
        timeWork = true;
        jostik = false;
        displayInitailMenu();
      }
      if (currentMenu[_currentMenuItem].text == "Period of time") {
        periodWork = true;
        jostik = false;
        displayInitailMenu();
      }

      if (currentMenu[_currentMenuItem].text == "Sensor(on/off)") {
        keyboard = false;
      }
      if (currentMenu[_currentMenuItem].text == "Data") {
        jostik = false;
      }

      if (currentMenu[_currentMenuItem].text == "Sensor(on/off)" || currentMenu[_currentMenuItem].text == "On/Off") {
        keyboard = false;
        _lcd.noCursor();
        onOff();//вывести on/off
        if (currentMenu[2].data == "Off") {
          _lcd.setCursor(0, 2);
          _lcd.print("->");
          on = false ;
        }
        else {
         on = true;
        _lcd.setCursor(0, 1);
        _lcd.print("->"); 
        }

      }
    }
  }
}
//*******************************************************************************************************
bool ConrolLCD::keyboardEnabled() {
  return keyboard;
}
//*******************************************************************************************************
bool ConrolLCD::jostikEnabled() {
  return jostik;
}
//*******************************************************************************************************
void ConrolLCD::returnPreviosMenu() {
  if (currentMenu != mainMenu) {
    _currentMenuLevel--;
    currentMenu = this->_previosMenus[_currentMenuLevel];
    enterMenu = false;
    displayMenu();
  } else {
    _lcd.clear();
    _lcd.setCursor(0, 0);
    _lcd.print("********************");
    _lcd.setCursor(0, 1);
    _lcd.print("Hello!");
    _lcd.setCursor(0, 3);
    _lcd.print("Press the joystick");
    startWindow = true;
  }
}
//*******************************************************************************************************
bool ConrolLCD::getenterMenu() {
  return enterMenu;
}
//*******************************************************************************************************
void ConrolLCD::setApplyDataMenu(bool apply) {
  applyDataMenu = apply;
}
//*******************************************************************************************************
bool ConrolLCD::getApplyDataMenu() {
  return applyDataMenu;
}
//*******************************************************************************************************
void ConrolLCD::setApplyDateMenu(bool apply) {
  applyDateMenu = apply;
}
//*******************************************************************************************************
bool ConrolLCD::getApplyDateMenu() {
  return applyDateMenu;
}
//*******************************************************************************************************
void ConrolLCD::setApplyClockMenu(bool apply) {
  applyClockMenu = apply;
}
//*******************************************************************************************************
bool ConrolLCD::getApplyClockMenu() {
  return applyClockMenu;
}
//*******************************************************************************************************
void ConrolLCD::setApplyWifiMenu(bool apply) {
  applyWifiMenu = apply;
}
//*******************************************************************************************************
bool ConrolLCD::getApplyWifiMenu() {
  return applyWifiMenu;
}
//*******************************************************************************************************
void ConrolLCD::applyData() {
  _lcd.noCursor();
  _lcd.clear();
  _lcd.setCursor(0, 0);
  _lcd.print(currentMenu[_currentMenuItem].text);
  _lcd.setCursor(0, 1);
  _lcd.print(inputBuffer);
  _lcd.setCursor(0, 2);
  _lcd.print("OK");
  applyDataMenu = true;
  delay(500);
}
//*******************************************************************************************************
void ConrolLCD::onOff() {
  _lcd.setCursor(2, 1);
  _lcd.print("On");
  _lcd.setCursor(2, 2);
  _lcd.print("Off");
}
//*******************************************************************************************************
void ConrolLCD::action() {
  if (currentMenu == subMenuNetwork) {
    switch (_currentMenuItem) {
      case mSSID: {
        currentMenu[_currentMenuItem].data = inputBuffer;
        applyWifiMenu = true;
        applyData();
        break;
      }
      case mPassword: {
        currentMenu[_currentMenuItem].data = inputBuffer;
        applyWifiMenu = true;
        applyData();
        break;
      }
      default: break;
    }
  }
  if (currentMenu == subMenuBuzzer) {
    switch (_currentMenuItem) {
      case mTime_of_work_b: {
        currentMenu[_currentMenuItem].data = inputBuffer;
        applyData();
        break;
      }
      case mDuration_b: {
        chekDuration(10, 600);
        if (!errorDuration) {
          currentMenu[_currentMenuItem].data = inputBuffer;
          applyData();
        }
        break;
      }
      case mOn_Off_b: {
        checkOnOff();
        currentMenu[_currentMenuItem].data = inputBuffer;
        applyData();
        break;
      }
      default: break;
    }
  }
  if (currentMenu == subMenuClock) {
    switch (_currentMenuItem) {
      case mData: {
        currentMenu[_currentMenuItem].data = inputBuffer;
        applyDateMenu = true;
        applyData();
        break;
      }
      case mTime: {
        currentMenu[_currentMenuItem].data = inputBuffer;
        applyClockMenu = true;
        applyData();
        break;
      }
      default: break;
    }
  }
  if (currentMenu == subMenuNightLight) {
    switch (_currentMenuItem) {
      case mPeriod_of_time: {
        currentMenu[_currentMenuItem].data = inputBuffer;
        applyData();
        break;
      }
      case mDuration: {
        chekDuration(10, 60);
        if (!errorDuration) {
          currentMenu[_currentMenuItem].data = inputBuffer;
          applyData();
        }
        break;
      }
      case mSensor_on_off: {
        checkOnOff();
        currentMenu[_currentMenuItem].data = inputBuffer;
        applyData();
        break;
      }
      case mOn_Off: {
        checkOnOff();
        currentMenu[_currentMenuItem].data = inputBuffer;
        applyData();
        break;
      }
      default: break;
    }
  }
  if (currentMenu == subMenuDayLight) {
    switch (_currentMenuItem) {
      case mPeriod_of_time: {
        currentMenu[_currentMenuItem].data = inputBuffer;
        applyData();
        break;
      }
      case mDuration: {
        chekDuration(10, 600);
        if (!errorDuration) {
          currentMenu[_currentMenuItem].data = inputBuffer;
          applyData();
        }
        break;
      }
      case mSensor_on_off: {
        checkOnOff();
        currentMenu[_currentMenuItem].data = inputBuffer;
        applyData();
        break;
      }
      case mOn_Off: {
        checkOnOff();
        currentMenu[_currentMenuItem].data = inputBuffer;
        applyData();
        break;
      }
      default: break;
    }
  }
}
//*******************************************************************************************************
void ConrolLCD::checkOnOff() {
      if (on) {
        strcpy(inputBuffer, "On");
      }
      else {
        strcpy(inputBuffer, "Off");
      }
    }

    void ConrolLCD::chekDuration(int start, int finish) {
      int duration = atoi(inputBuffer);
      if (duration >= start && duration <= finish) {
        errorDuration = false;
        _lcd.setCursor(0, 2);
        _lcd.println("                    ");
        _lcd.setCursor(0, 3);
        _lcd.println("                    ");
        _cursorLocation = 0;
        currentMenu[_currentMenuItem].data = duration;
      }
      else {

        errorDuration = true;
        _lcd.setCursor(0, 2);
        String Er = "from " + String(start) + " to " + String(finish);
        _lcd.print("Error. The range is");
        _lcd.setCursor(0, 3);
        _lcd.println(Er);
        _lcd.setCursor(0, _stroka);
        _cursorLocation = 0;
        _lcd.cursor();
      }
    }
//*******************************************************************************************************