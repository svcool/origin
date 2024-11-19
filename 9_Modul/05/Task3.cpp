#define Y_PIN A0
#define X_PIN A1
#define SEL_PIN 3
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);
const int ledPin = 13;
const int inputPin = 2;
int pirState = LOW;
int val = 0;

int lastButton = LOW;
int curButton = LOW;
int lastX = 512;
bool status = false;

int timeoff = 0; // Изначально 2 секунды
unsigned long previousMillis = 0;

void moveCursor(int x, int &timeoff) {
  if (x < 512 - 100 && timeoff < 10) {
    timeoff++;
  } else if (x > 512 + 100 && timeoff > 0) { // Минимальное время 2 секунды
    timeoff--;
  }
  delay(200); // Задержка для устранения дребезга
}

int debounce(int last) {
  int current = digitalRead(SEL_PIN);
  if (last != current) {
    delay(5);
    current = digitalRead(SEL_PIN);
  }
  return current;
}

bool countingTime(unsigned long duration) {
  unsigned long currentMillis = millis();
  // Проверяем, прошло ли заданное время
  if (currentMillis - previousMillis >= duration) {
    return true;
  }
  return false;
}

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(inputPin, INPUT);
  Serial.begin(9600);
  pinMode(Y_PIN, INPUT);
  pinMode(X_PIN, INPUT);
  pinMode(SEL_PIN, INPUT_PULLUP);

  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Time: ");
  lcd.print(timeoff);
  lcd.print(" sec");
}

void loop() {
  curButton = debounce(lastButton);
  if (lastButton == HIGH && curButton == LOW) {
    timeoff = 0; // Сброс до 2 секунд, минимального значения
    lcd.clear();
    lcd.print("Time: ");
    lcd.print(timeoff);
    lcd.print(" sec");
  }
  lastButton = curButton;

  int x = analogRead(X_PIN);

  if (x != lastX) {
    moveCursor(x, timeoff);
    lastX = x;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Time: ");
    lcd.print(timeoff);
    lcd.print(" sec");
  }

  val = digitalRead(inputPin);
  if (timeoff != 0) {
    if (status == false) {
      if (val == HIGH) {
        digitalWrite(ledPin, HIGH);
        Serial.println("Motion detected!");
        previousMillis = millis();  // Начало отсчета времени
        status = true;
      }
    } else {
      // Передаем время работы светодиода в миллисекундах
      if (countingTime(timeoff * 1000)) {
        digitalWrite(ledPin, LOW);
        Serial.println("Motion ended!");
        Serial.println(timeoff);
        status = false;
      }
    }
  }
}
