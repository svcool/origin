#include <Stepper.h> //����������� ����������
const int stepsPerRevolution = 200; //���������� ����� �� ������
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11); //���������� �������� 8 - 11
int stepCount = 0; //���������� �����, ������� ������ ���������

static int lastButton_stop = LOW; // ���������� ��������� ������
static int lastButton_left = LOW;
static int lastButton_right = LOW;
//������� ��������� ������
bool start_stop = false;
bool left = false;
bool right = true; //��������� �� ������� ������� �� ���������

const int but_stop = 2; // ������ �����/����
const int but_left = 3; // ������ �������� �����
const int but_right = 4; // ������ �������� ������

int rotation = 1;

// ������� ��� ��������� ��������� ������ � ���������� start_stop
bool handleButton(int buttonPin, int &lastState, bool &button) {
  int currentState = digitalRead(buttonPin);
  // ���������� ��������
  if (lastState != currentState) {
    delay(5);
    currentState = digitalRead(buttonPin);
  }
  if (lastState == HIGH && currentState == LOW) {
    button = !button; // ����������� ���������
  }
  // ��������� ���������� ���������
  lastState = currentState;
  return button;
}


void setup() {
  pinMode(but_stop, INPUT_PULLUP); //������� ������ - ����
  pinMode(but_left, INPUT_PULLUP); //������� ������ - ����
  pinMode(but_right, INPUT_PULLUP); //������� ������ - ����
  Serial.begin(9600); // ��� �������
}
void loop() {

  // ��������� ������
  start_stop = handleButton(but_stop, lastButton_stop, start_stop);
  bool oldleft = left;
  bool oldright = right;
  left = handleButton(but_left, lastButton_left, left);
  right = handleButton(but_right, lastButton_right, right);

  //��������� �������������� ���������
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
    int sensor = analogRead(A0); // ������ �������� �������������
    int motorSpeed = map(sensor, 0, 1023, 0, 100); // ��������������� ����� ��������
    if (motorSpeed > 0) {
      myStepper.setSpeed(motorSpeed); //��������� ������ �������� ��������
      //��������� ������ ��������
      if (left) {
        rotation = -1; // �����
      } else if (right) {
        rotation = 1; // ������
      }
        myStepper.step(rotation * (stepsPerRevolution / 100)); // ������� 1/100 ������� �������
    }
  }
}