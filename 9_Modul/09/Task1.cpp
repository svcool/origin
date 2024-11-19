#include <SPI.h>
int speed[] = {1000, 500, 250, 125, 63}; // �������� � �������������
int k = 0; // ������
const int STCPPin = 4; // ���, ����������� �������� ��������

static int lastButton = LOW; // ���������� ��������� ������
bool button = false;//������� ��������� ������
const int but = 2; // ���� ����������� ������

// ��������� �����
void rotateLeft(uint16_t &bits) {
  uint16_t high_bit = bits & (1 << 15) ? 1 : 0;
  bits = (bits << 1) | high_bit;
}

// ������� ��� ��������� ��������� ������ � ���������� start_stop
bool handleButton(int buttonPin, int &lastState, bool &button) {
  int currentState = digitalRead(buttonPin);
  // ���������� ��������
  if (lastState != currentState) {
    delay(20);
    currentState = digitalRead(buttonPin);
  }
  if (lastState == HIGH && currentState == LOW) {
    button = !button; // ����������� ���������
  }
  // ��������� ���������� ���������
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
  static uint16_t nomad = 1; //������� ������ ���� ���������
  SPI.transfer(highByte(nomad)); // �������� �������� �����
  SPI.transfer(lowByte(nomad));  // �������� �������� �����
  digitalWrite(STCPPin, HIGH); //������������ ������ �� �������� �������
  digitalWrite(STCPPin, LOW);
  rotateLeft(nomad); //����� ���� �� ���� �����
  delay(speed[k]);
}

void setup()
{
  SPI.begin();
  pinMode(STCPPin, OUTPUT);
  digitalWrite(STCPPin, LOW);
  SPI.transfer(0); //����� ���� ������� � ����
  SPI.transfer(0); // ����� ���� ������� ������� ��������
  digitalWrite(STCPPin, HIGH); //������������ ������ �� �������� �������
  digitalWrite(STCPPin, LOW);

  pinMode(2, INPUT_PULLUP);  // ������������� �������� �� ����� ����������
  attachInterrupt(0, start, FALLING); //���������� �������� ���������� (����� 3 Arduino UNO)
}


void loop()
{
  updatespeed();
  blinkLED();
}