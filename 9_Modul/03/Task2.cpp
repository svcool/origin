
#define VERT_PIN A0
#define HORZ_PIN A1
#define SEL_PIN  2

int size_led = 6;
int led[6][2] {
  {3, 125},
  {5, 125},
  {6, 125},
  {9, 125},
  {10, 125},
  {11, 125}
};
int brightness = 125; 

int number=0; // номер светодиода в массиве
int lastButton = LOW; //предыдущее состояние кнопки
int curButton = LOW; //Текущее состояние кнопки


/*Функция подавления дребезга
last - предыдущее состояние кнопки*/
int debounce (int last)
{
int current = digitalRead(SEL_PIN);
if(last != current) //если состояние изменилось
{
delay(5);
current = digitalRead(SEL_PIN);
}
return current;
}


void ledOffset(int x, int &number){
if (x < 512 - 100 && number < size_led-1) { //вправо
number++;
delay(100);
}
if(x > 512 + 100 && number > 0){ //влево
  number--;
  delay(100);
}

}

void ledBrightness(int y, int &number){
if (y > 512 + 100 && led[number][1] < 250) {
    led[number][1]  += 10;
    if (led[number][1]  > 250) led[number][1]  = 250;
    delay(100);
  } else if (y < 512 - 100 && led[number][1]  > 0) {
    led[number][1]  -= 10;
    if (led[number][1]  < 0) led[number][1]  = 0;
    delay(100);
  }


}

void setup() {

 for(int i=0; i<6; i++){
pinMode(led[i][0], OUTPUT); //контакт светодиода - выход
digitalWrite(led[i][0], brightness); //на выходе лог. 0
}

pinMode(VERT_PIN, INPUT);
pinMode(HORZ_PIN, INPUT);
pinMode(SEL_PIN, INPUT_PULLUP);//INPUT_PULLUP подтягивающий резистор на входе лог 1
Serial.begin(9600); // Инициализация последовательного порта для вывода данных

}

void loop() {

curButton = debounce (lastButton);
if(lastButton == HIGH && curButton == LOW) //условие нажатия
{
  number = 0;
}
lastButton = curButton;

int x = analogRead(HORZ_PIN); // считываем значение оси Х
int y = analogRead(VERT_PIN); // считываем значение оси Y

ledOffset(x, number);
ledBrightness(y, number);

  analogWrite(led[number][0], led[number][1]); // включаем светодиоды с разной яркостью

}
