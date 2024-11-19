#include <IRremote.h>
#include <LiquidCrystal.h>
#include <Servo.h>

const int PIN_RECEIVER = 2; // Вход для ИК приемника
LiquidCrystal lcd(12, 11, 10, 9, 8, 7); // LCD
Servo myservo; // Объект сервопривода

int number = 0; 
int digitCount = 0;

// вывода на индикатор
void lcdPrint(int value)
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("The angle:");
  lcd.setCursor(0, 1);
  lcd.print(value);
}

// добавления цифры
void addDigit(int digit) {
  if (digitCount < 3) {
    number = number * 10 + digit;
    digitCount++;
    lcdPrint(number);
  }
}

// очистки последней цифры
void clearLastDigit() {
  if (digitCount > 0) {
    number /= 10; // Удаляем последнюю цифру
    digitCount--;
    lcdPrint(number);
  }
}

// сброса числа
void resetNumber() {
  number = 0;
  digitCount = 0;
  lcdPrint(number);
}

void translateIR()
{
  switch (IrReceiver.decodedIRData.command) {
    case 168: // PLAY
      if (digitCount > 0) {
        int angle = number; // Получаем число для установки угла
        if (angle >= 0 && angle <= 180) {
          myservo.write(angle); // Установка новой позиции сервопривода
        }
        else {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Invalid angle!");
          delay(1000);
          resetNumber(); // Сброс
        }
      }
      break;
    case 104: // 0
      addDigit(0);
      break;
    case 176: // C
      resetNumber(); // Сброс числа
      break;
    case 48:  // 1
      addDigit(1);
      break;
    case 24:  // 2
      addDigit(2);
      break;
    case 122: // 3
      addDigit(3);
      break;
    case 16:  // 4
      addDigit(4);
      break;
    case 56:  // 5
      addDigit(5);
      break;
    case 90:  // 6
      addDigit(6);
      break;
    case 66:  // 7
      addDigit(7);
      break;
    case 74:  // 8
      addDigit(8);
      break;
    case 82:  // 9
      addDigit(9);
      break;
    case 194:  // BACK (или используйте другой код, если ваш пульт имеет другой код для BACK)
      clearLastDigit(); // Удаление последней цифры
      break;
  }
}

void setup()
{
  myservo.attach(3); // Привязка линии управления к выводу 3
  lcd.begin(16, 2);
  lcd.print("<Take a corner>");
  IrReceiver.begin(PIN_RECEIVER, ENABLE_LED_FEEDBACK);
  IrReceiver.enableIRIn(); // Запуск ИК приемника
}

void loop()
{
  if (IrReceiver.decode()) { // Проверка новых данных
    translateIR();
    IrReceiver.resume(); // Запуск приема новой команды
  }
}
