#define Y_PIN A0
#define X_PIN A1
#define SEL_PIN 5

#include <LiquidCrystal.h>

// Инициализируем объект-экран, передаём использованные для подключения контакты на Arduino в порядке: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);
bool stroka = false; // переменная для переключения строки
int lastButton = LOW; // предыдущее состояние кнопки
int curButton = LOW;  // текущее состояние кнопки
int cursorLocation = 0; // позиция курсора на экране
char letter = 'A'- 1; // текущий символ
int lastX = 512; // предыдущее значение по оси X
int lastY = 512; // предыдущее значение по оси Y

void moveCursor(int x, int &cursorLocation) {
 if (x < 512 - 100 && cursorLocation < 15) { // Движение вправо
    cursorLocation++;
  } 
  else if (x > 512 + 100 && cursorLocation > 0) { // Движение влево
    cursorLocation--;
  }
  if (x < 512 - 100 && cursorLocation == 15) { // Если вправо на краю
    cursorLocation = 0; // Перейти в начало
  } 
  else if (x > 512 + 100 && cursorLocation == 0) { // Если влево на краю
    cursorLocation = 15; // Перейти в конец
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

/* Функция подавления дребезга (last - предыдущее состояние кнопки) */
int debounce(int last) {
  int current = digitalRead(SEL_PIN);
  if (last != current) {  // если состояние изменилось
    delay(5);
    current = digitalRead(SEL_PIN);
  }
  return current;
}

void setup() {
  pinMode(Y_PIN, INPUT);
  pinMode(X_PIN, INPUT);
  pinMode(SEL_PIN, INPUT_PULLUP);  // подтягивающий резистор на входе лог 1

  // Устанавливаем размер (количество столбцов и строк) экрана
  lcd.begin(16, 2);
  // Очищаем экран
  lcd.clear();

  // Включаем курсор
  lcd.cursor();
  
  // Устанавливаем начальную позицию и символ
  lcd.setCursor(cursorLocation, stroka);
  //lcd.print(letter);
}

void loop() {
  curButton = debounce(lastButton);
  if (lastButton == HIGH && curButton == LOW) {  // условие нажатия
    stroka = !stroka; // переключаем строку при нажатии кнопки
    lcd.setCursor(cursorLocation, stroka);
    letter = 'A' - 1;
  }
  lastButton = curButton;

  int x = analogRead(X_PIN);  // считываем значение оси X
  int y = analogRead(Y_PIN);  // считываем значение оси Y

  if (x != lastX) { // если значение оси X изменилось
    delay(200);
    moveCursor(x, cursorLocation);
    lcd.setCursor(cursorLocation, stroka);
  }
  if (y != lastY) { // если значение оси Y изменилось
    moveLine(y, letter);
    delay(200);
   
    lcd.print(letter);
    lcd.setCursor(cursorLocation, stroka);//возврат курсора
  }
//при нажатии не переключает, только при отпускании джостика
  //lastX = x; // обновляем предыдущее значение X
  //lastY = y; // обновляем предыдущее значение Y
}
