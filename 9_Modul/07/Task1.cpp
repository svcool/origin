#include <Stepper.h> //подключение библиотеки
const int stepsPerRevolution = 200; //количество шагов на оборот
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11); //управление выводами 8 - 11
int stepCount = 0; //количество шагов, которое сделал двигатель

static int lastButton_stop = LOW; // предыдущее состояние кнопки
static int lastButton_left = LOW;
static int lastButton_right = LOW;
//текущее состояние кнопок
bool start_stop = false;
bool left = false;
bool right = true; //вращается по часовой стрелке по умолчанию

const int but_stop = 2; // кнопка старт/стоп
const int but_left = 3; // кнопка вращения влево
const int but_right = 4; // кнопка вращения вправо

int rotation = 1;

// Функция для получения состояния кнопки и обновления start_stop
bool handleButton(int buttonPin, int &lastState, bool &button) {
  int currentState = digitalRead(buttonPin);
  // устранение дребезга
  if (lastState != currentState) {
    delay(5);
    currentState = digitalRead(buttonPin);
  }
  if (lastState == HIGH && currentState == LOW) {
    button = !button; // Переключаем состояние
  }
  // Обновляем предыдущее состояние
  lastState = currentState;
  return button;
}


void setup() {
  pinMode(but_stop, INPUT_PULLUP); //контакт кнопки - вход
  pinMode(but_left, INPUT_PULLUP); //контакт кнопки - вход
  pinMode(but_right, INPUT_PULLUP); //контакт кнопки - вход
  Serial.begin(9600); // для отладки
}
void loop() {

  // обработка кнопок
  start_stop = handleButton(but_stop, lastButton_stop, start_stop);
  bool oldleft = left;
  bool oldright = right;
  left = handleButton(but_left, lastButton_left, left);
  right = handleButton(but_right, lastButton_right, right);

  //исключаем неопределенное состояние
  if (right != oldright && right) {
    right = true;
    left = false;
  }
  if (left != oldleft && left) {
    left = true;
    right = false;
  }
  Serial.print("Start_Stop: ");
  Serial.println(start_stop);
  Serial.print("But_Left: ");
  Serial.println(left);
  Serial.print("But_Right: ");
  Serial.println(right);


  if (start_stop) {
    int sensor = analogRead(A0); // чтение значения потенциометра
    int motorSpeed = map(sensor, 0, 1023, 0, 100); // масштабирование этого значения
    if (motorSpeed > 0) {
      myStepper.setSpeed(motorSpeed); //установка нового значения скорости
      //обработка кнопок вращения
      if (left) {
        rotation = -1; // Влево
      } else if (right) {
        rotation = 1; // Вправо
      }
        myStepper.step(rotation * (stepsPerRevolution / 100)); // сделать 1/100 полного оборота
    }
  }
}