#include <TimerOne.h>
const int led = 9; // ����� �� �����������
int ledState = LOW; //��������� ����������
volatile unsigned long blinkCount = 0; // ����������� volatile ��� ����� ����������
const unsigned long shortSignalInterval = 200000; // �������� ������
const unsigned long longSignalInterval = 600000;  // ������� ������

void start() {
  Timer1.setPeriod(shortSignalInterval);//��������� ��������
  timerSettings();
}


void blinkLED(void)
{
  static int i = 0; // ������ ��� ������ ��������� ��������� c������ SOS
  if (ledState == LOW)
  {
    ledState = HIGH;
    blinkCount = blinkCount + 1; //���������� �������
  } else
  {
    ledState = LOW;
  }
  digitalWrite(led, ledState);
  i++;
  // ������ ��� ������ ��������� ��������� c������ SOS
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

  if (blinkCount >= 9) {//SOS �������
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
  pinMode(2, INPUT_PULLUP);  // ������������� �������� �� ����� ����������
  Timer1.initialize(shortSignalInterval); // ���������� ��������� �������� �������
  attachInterrupt(0, start, FALLING); //���������� �������� ���������� (����� 3 Arduino UNO)
  Serial.begin(9600);
}

void loop(void)
{

}