#ifndef LCD16x4
#define LCD16x4

#include <LiquidCrystal_I2C.h>
#include "Keypad.h"

extern char letter; // текущий символ

// Объявления перечислений
enum lightMenu : int {
  mPeriod_of_time = 0,
  mDuration,
  mSensor_on_off,
  mOn_Off
};

enum clockMenu : int {
  mData = 0,
  mTime
};

enum buzzerMenu : int {
  mTime_of_work_b = 0,
  mDuration_b,
  mOn_Off_b
};

enum networkMenu : int {
  mSSID = 0,
  mPassword
};

// Объявления констант
const byte Rows = 4;
const byte Cols = 3;

// Объявление карты клавиш
extern char keymap[Rows][Cols];

// Объявление пинов
extern byte rPins[Rows];
extern byte cPins[Cols];

// Экземпляр Keypad
extern Keypad kpd;

// Структура меню
struct MenuItem {
  int count;
  String data;
  String text;
  MenuItem* subMenu;
};

// Объявления подменю
extern MenuItem subMenuDayLight[];
extern MenuItem subMenuNightLight[];
extern MenuItem subMenuClock[];
extern MenuItem subMenuBuzzer[];
extern MenuItem subMenuNetwork[];
extern MenuItem subMenuSettings[];
extern MenuItem mainMenu[];

// Класс ConrolLCD
class ConrolLCD {
  LiquidCrystal_I2C& _lcd;
  int& _cursorLocation;
  int& _stroka;
  int _lcdColums;
  int _lcdLines;
  int _currentMenuItem;
  static const int _menuLevels = 5;
  int _currentMenuLevel;
  MenuItem* currentMenu;
  MenuItem* _previosMenus[_menuLevels];
  bool enterMenu;
  bool on;
  char inputBuffer[50];
  bool keyboard;
  bool jostik;
  bool startWindow;
  bool timeWork;
  bool periodWork;
  bool durationMenu;
  bool timeMenu;
  bool dateMenu;
  bool durationNightMenu;
  bool errorDuration;
  bool applyDataMenu;
  bool applyClockMenu;
  bool applyDateMenu;
  bool applyWifiMenu;
  int hours;
  int minutes;

public:
  ConrolLCD(LiquidCrystal_I2C& lcd, int lcdColums, int lcdLines, int& cursorLocation, int& stroka, MenuItem* initMenu = mainMenu);
  bool getStartWindow();
  void inputBufferLCD(char& key);
  String getInputBuffer();
  void moveLine(int &y);
  void changeOnOff();
  void moveCursor(int &x);
  void reversLcdCursor(int x, bool right);
  void changeCursor();
  void displayMenu();
  void moveUp();
  void moveDown();
  bool timeOfWork();
  bool periodOfWork();
  bool durationM();
  bool durationNightM();
  bool timeM();
  bool dateM();
  void displayInitailMenu();
  void selectMenuItem();
  bool keyboardEnabled();
  bool jostikEnabled();
  void returnPreviosMenu();
  bool getenterMenu();
  void setApplyDataMenu(bool apply);
  bool getApplyDataMenu();
  void setApplyDateMenu(bool apply);
  bool getApplyDateMenu();
  void setApplyClockMenu(bool apply);
  bool getApplyClockMenu();
   void setApplyWifiMenu(bool apply);
  bool getApplyWifiMenu();
  void applyData();
  void onOff();
  void action();
  void checkOnOff();
  void chekDuration(int start, int finish);
};

#endif // LCD16x4