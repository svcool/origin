#define Y_PIN A0
#define X_PIN A1
#define SEL_PIN 5

#include <LiquidCrystal.h>

// �������������� ������-�����, ������� �������������� ��� ����������� �������� �� Arduino � �������: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);
bool stroka = false; // ���������� ��� ������������ ������
int lastButton = LOW; // ���������� ��������� ������
int curButton = LOW;  // ������� ��������� ������
int cursorLocation = 0; // ������� ������� �� ������
char letter = 'A'- 1; // ������� ������
int lastX = 512; // ���������� �������� �� ��� X
int lastY = 512; // ���������� �������� �� ��� Y

void moveCursor(int x, int &cursorLocation) {
 if (x < 512 - 100 && cursorLocation < 15) { // �������� ������
    cursorLocation++;
  } 
  else if (x > 512 + 100 && cursorLocation > 0) { // �������� �����
    cursorLocation--;
  }
  if (x < 512 - 100 && cursorLocation == 15) { // ���� ������ �� ����
    cursorLocation = 0; // ������� � ������
  } 
  else if (x > 512 + 100 && cursorLocation == 0) { // ���� ����� �� ����
    cursorLocation = 15; // ������� � �����
  }
    delay(100);
}

void moveLine(int y, char &letter) {
  if (y > 512 + 100 && letter < 'Z') {
    letter++;
  } else if (y < 512 - 100 && letter > 'A') {
    letter--;
  }
  delay(100);
}

/* ������� ���������� �������� (last - ���������� ��������� ������) */
int debounce(int last) {
  int current = digitalRead(SEL_PIN);
  if (last != current) {  // ���� ��������� ����������
    delay(5);
    current = digitalRead(SEL_PIN);
  }
  return current;
}

void setup() {
  pinMode(Y_PIN, INPUT);
  pinMode(X_PIN, INPUT);
  pinMode(SEL_PIN, INPUT_PULLUP);  // ������������� �������� �� ����� ��� 1

  // ������������� ������ (���������� �������� � �����) ������
  lcd.begin(16, 2);
  // ������� �����
  lcd.clear();

  // �������� ������
  lcd.cursor();
  
  // ������������� ��������� ������� � ������
  lcd.setCursor(cursorLocation, stroka);
  //lcd.print(letter);
}

void loop() {
  curButton = debounce(lastButton);
  if (lastButton == HIGH && curButton == LOW) {  // ������� �������
    stroka = !stroka; // ����������� ������ ��� ������� ������
    lcd.setCursor(cursorLocation, stroka);
    letter = 'A' - 1;
  }
  lastButton = curButton;

  int x = analogRead(X_PIN);  // ��������� �������� ��� X
  int y = analogRead(Y_PIN);  // ��������� �������� ��� Y

  if (x != lastX) { // ���� �������� ��� X ����������
    delay(200);
    moveCursor(x, cursorLocation);
    lcd.setCursor(cursorLocation, stroka);
  }
  if (y != lastY) { // ���� �������� ��� Y ����������
    moveLine(y, letter);
    delay(200);
   
    lcd.print(letter);
    lcd.setCursor(cursorLocation, stroka);//������� �������
  }
//��� ������� �� �����������, ������ ��� ���������� ��������
  //lastX = x; // ��������� ���������� �������� X
  //lastY = y; // ��������� ���������� �������� Y
}
