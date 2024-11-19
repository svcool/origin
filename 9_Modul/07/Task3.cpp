#include <Servo.h> //подключение библиотеки
// Функция чтения данных с датчика
long readUltrasonicDistance(int triggerPin, int echoPin);
Servo myservo; // создание объекта
int val; // маштабируемое значение 
float cm;

const int triggerPin = 3; // Пин триггера ультразвукового датчика
const int echoPin = 2;    // Пин эхо ультразвукового датчика
const int servoPin = 9;   // Пин серво

// Функция чтения данных с датчика
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT); // сброс Trig
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH); // установка TRIG на 10 мкс
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT); // измерение длительности ECHO
  return pulseIn(echoPin, HIGH);
}

void setup() {
  myservo.attach(servoPin); // привязка линии управления к выводу 9
}
void loop() {

  cm = readUltrasonicDistance(triggerPin, echoPin) / 58;
  val = map(cm, 0, 400, 180, 0); // масштабирование значения обратно пропорционально
// Ограничиваем значение до допустимого диапазона
  val = constrain(val, 0, 180);

  myservo.write(val); // устанвока новой позиции сервопривода
  delay(15); // отладка
}