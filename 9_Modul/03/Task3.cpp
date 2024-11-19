#include "Keypad.h"

const int led[3] = {11, 12, 13};
bool ledStates[3] = {false, false, false};
unsigned long previousMillis = 0;
int interval = 0;

const byte Rows = 4;
const byte Cols = 4;

char keymap[Rows][Cols] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rPins[Rows] = {9, 8, 7, 6};
byte cPins[Cols] = {5, 4, 3, 2};

Keypad kpd = Keypad(makeKeymap(keymap), rPins, cPins, Rows, Cols);

void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(led[i], OUTPUT);
    digitalWrite(led[i], HIGH); // ¬ключаем все светодиоды при старте
  }
  Serial.begin(9600);
}

void loop() {
  char keypressed = kpd.getKey();

  if (keypressed != NO_KEY) {
    handleKeypress(keypressed);
  }

  if (interval > 0) {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      toggleLEDs();
    }
  }
}

void handleKeypress(char key) {
  switch (key) {
    case '0':
      setLEDs(true, true, true);
      break;
    case '1':
      setLEDs(true, false, false);
      break;
    case '2':
      setLEDs(false, true, false);
      break;
    case '3':
      setLEDs(false, false, true);
      break;
    case '4':
      setLEDs(true, true, false);
      break;
    case '5':
      setLEDs(false, true, true);
      break;
    case '6':
      setLEDs(true, false, true);
      break;
    case '7':
      setLEDs(false, false, false);
      break;
    case 'A':
      interval = 0;
      break;
    case 'B':
      interval = 1000;
      break;
    case 'C':
      interval = 500;
      break;
    case 'D':
      interval = 250;
      break;
    default:
      break;
  }
}

void setLEDs(bool led1, bool led2, bool led3) {
  digitalWrite(led[0], led1);
  digitalWrite(led[1], led2);
  digitalWrite(led[2], led3);

  ledStates[0] = led1;
  ledStates[1] = led2;
  ledStates[2] = led3;
}

void toggleLEDs() {
  for (int i = 0; i < 3; i++) {
    if (ledStates[i]) {
      digitalWrite(led[i], !digitalRead(led[i]));
    }
  }
}
