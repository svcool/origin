#include <IRremote.h>
#include <LiquidCrystal.h>
#include <Servo.h>

const int PIN_RECEIVER = 2; // ���� ��� �� ���������
LiquidCrystal lcd(12, 11, 10, 9, 8, 7); // LCD
Servo myservo; // ������ ������������

int number = 0; 
int digitCount = 0;

// ������ �� ���������
void lcdPrint(int value)
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("The angle:");
  lcd.setCursor(0, 1);
  lcd.print(value);
}

// ���������� �����
void addDigit(int digit) {
  if (digitCount < 3) {
    number = number * 10 + digit;
    digitCount++;
    lcdPrint(number);
  }
}

// ������� ��������� �����
void clearLastDigit() {
  if (digitCount > 0) {
    number /= 10; // ������� ��������� �����
    digitCount--;
    lcdPrint(number);
  }
}

// ������ �����
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
        int angle = number; // �������� ����� ��� ��������� ����
        if (angle >= 0 && angle <= 180) {
          myservo.write(angle); // ��������� ����� ������� ������������
        }
        else {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Invalid angle!");
          delay(1000);
          resetNumber(); // �����
        }
      }
      break;
    case 104: // 0
      addDigit(0);
      break;
    case 176: // C
      resetNumber(); // ����� �����
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
    case 194:  // BACK (��� ����������� ������ ���, ���� ��� ����� ����� ������ ��� ��� BACK)
      clearLastDigit(); // �������� ��������� �����
      break;
  }
}

void setup()
{
  myservo.attach(3); // �������� ����� ���������� � ������ 3
  lcd.begin(16, 2);
  lcd.print("<Take a corner>");
  IrReceiver.begin(PIN_RECEIVER, ENABLE_LED_FEEDBACK);
  IrReceiver.enableIRIn(); // ������ �� ���������
}

void loop()
{
  if (IrReceiver.decode()) { // �������� ����� ������
    translateIR();
    IrReceiver.resume(); // ������ ������ ����� �������
  }
}
