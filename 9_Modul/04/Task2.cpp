#include <fDigitsSegtPin.h> // Подключаем библиотеку fDigitsSegtPinж
// Инициализируем объект-4-х разрядный индикатор, передаём использованные
// для подключения контакты на:
fDigitsSegtPin display(6, 5, 9, 4, 8, 13, 3, 12, 11, 7, 2, 10);
const int reset = 0;
const int start = 1;
bool stop = true;

int lastButton_start = LOW; // предыдущее состояние кнопки
int curButton_start = LOW; // текущее состояние кнопки
int lastButton_reset = LOW; // предыдущее состояние кнопки
int curButton_reset = LOW; // текущее состояние кнопки


int debounce(int last, int button) {
  int current = digitalRead(button);
  if (last != current) {
    delay(5);
    current = digitalRead(button);
  }
  return current;
}

void setup()
{
  display.begin();
  pinMode(reset, INPUT_PULLUP); // Инициализация пина для кнопки сброса
  pinMode(start, INPUT_PULLUP); // Инициализация пина для кнопки старта/стопа
}


void loop()
{
   static unsigned long timer = millis(); //текущее время
   static float deciSeconds = 0; //время, отображаемое на индикаторе
   unsigned long currentMillis = millis();

curButton_reset = debounce(lastButton_reset, reset);

if(lastButton_reset == HIGH && curButton_reset ==LOW){
  if(stop){
    deciSeconds = 0;
  }

}
lastButton_reset = curButton_reset;



curButton_start = debounce(lastButton_start, start);

if(lastButton_start == HIGH && curButton_start ==LOW){
stop = !stop;
}
lastButton_start = curButton_start;

    if (currentMillis - timer >= 1000) //прошло 1000 мс
    {
      
      if(!stop){
      timer = currentMillis;
      deciSeconds += 1; // 1000 мс = 1 сек
      }
  }
display.print(deciSeconds); //периодический вызов функции в основном цикле

}