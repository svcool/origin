#include <TimerOne.h>
const int led = 9; // вывод со светодиодом
int ledState = LOW; //состо€ние светодиода
volatile unsigned long blinkCount = 0; // используйте volatile дл€ общих переменных
const unsigned long shortSignalInterval = 200000; // короткий сигнал
const unsigned long longSignalInterval = 600000;  // длинный сигнал

void start() {
  Timer1.setPeriod(shortSignalInterval);//начальное значение
  timerSettings();
}


void blinkLED(void)
{
  static int i = 0; // каждые три вызова провер€ет положение cигнала SOS
  if (ledState == LOW)
  {
    ledState = HIGH;
    blinkCount = blinkCount + 1; //количество миганий
  } else
  {
    ledState = LOW;
  }
  digitalWrite(led, ledState);
  i++;
  // каждые три вызова провер€ет положение cигнала SOS
  if (i == 2) {
    i = 0;
    start();
  }

}

void timerSettings(void)
{
  static unsigned long currentInterval = shortSignalInterval;
  if (blinkCount < 3 || blinkCount >= 6 && blinkCount < 9) {
    currentInterval = shortSignalInterval;
  }
  if (blinkCount >= 3 && blinkCount < 6) {
    currentInterval = longSignalInterval;
  }

  if (blinkCount >= 9) {//SOS передан
    Timer1.stop();
    blinkCount = 0;
  }
  else {
    Timer1.setPeriod(currentInterval);
    Timer1.attachInterrupt(blinkLED);

  }
}

void setup(void)
{
  pinMode(led, OUTPUT);
  pinMode(2, INPUT_PULLUP);  // подт€гивающий резистор на входе прерывани€
  Timer1.initialize(shortSignalInterval); // ”становите начальный интервал таймера
  attachInterrupt(0, start, FALLING); //разрешение внешнего прерывани€ (вывод 3 Arduino UNO)
  Serial.begin(9600);
}

void loop(void)
{

}