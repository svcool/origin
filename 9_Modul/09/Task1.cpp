#include <SPI.h>
int speed[] = {1000, 500, 250, 125, 63}; // Скорости в миллисекундах
int k = 0; // индекс
const int STCPPin = 4; // пин, управляющий выходной защёлкой

static int lastButton = LOW; // предыдущее состояние кнопки
bool button = false;//текущее состояние кнопок
const int but = 2; // порт подключения кнопки

// Кольцевой сдвиг
void rotateLeft(uint16_t &bits) {
  uint16_t high_bit = bits & (1 << 15) ? 1 : 0;
  bits = (bits << 1) | high_bit;
}

// Функция для получения состояния кнопки и обновления start_stop
bool handleButton(int buttonPin, int &lastState, bool &button) {
  int currentState = digitalRead(buttonPin);
  // устранение дребезга
  if (lastState != currentState) {
    delay(20);
    currentState = digitalRead(buttonPin);
  }
  if (lastState == HIGH && currentState == LOW) {
    button = !button; // Переключаем состояние
  }
  // Обновляем предыдущее состояние
  lastState = currentState;
  return button;
}

void start() {
  button = handleButton(but, lastButton, button);
}

void updatespeed() {
  if (button) {
    k++;
    if (k == 5) {
      k = 0;
    }
    button = false;
  }
}

void blinkLED(void)
{
  static uint16_t nomad = 1; //активен только один светодиод
  SPI.transfer(highByte(nomad)); // отправка старшего байта
  SPI.transfer(lowByte(nomad));  // отправка младшего байта
  digitalWrite(STCPPin, HIGH); //формирование фронта на выходную защелку
  digitalWrite(STCPPin, LOW);
  rotateLeft(nomad); //сдвиг бита на один разрд
  delay(speed[k]);
}

void setup()
{
  SPI.begin();
  pinMode(STCPPin, OUTPUT);
  digitalWrite(STCPPin, LOW);
  SPI.transfer(0); //сброс всех выходов в ноль
  SPI.transfer(0); // сброс всех выходов второго регистра
  digitalWrite(STCPPin, HIGH); //формирование фронта на выходную защелку
  digitalWrite(STCPPin, LOW);

  pinMode(2, INPUT_PULLUP);  // подтягивающий резистор на входе прерывания
  attachInterrupt(0, start, FALLING); //разрешение внешнего прерывания (вывод 3 Arduino UNO)
}


void loop()
{
  updatespeed();
  blinkLED();
}