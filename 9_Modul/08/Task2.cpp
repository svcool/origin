#include <Stepper.h> //����������� ����������
const int stepsPerRevolution = 200; //���������� ����� �� ������
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11); //���������� �������� 8 - 11

//������� ��������� ������
volatile bool start_stop = false;
volatile bool left_right = false;

const int but_stop_start = 3; // ������ �����/����
const int but_left_right = 2; // ������ ��������
volatile int rotation = 1;

void setup()
{
myStepper.setSpeed(100); //��������� ��������
pinMode(but_left_right , INPUT_PULLUP); // ������������� �������� �� ����� ����������
pinMode(but_stop_start, INPUT_PULLUP); // ������������� �������� �� ����� ����������
attachInterrupt(1, step_start_stop, FALLING); //���������� �������� ���������� (����� 2 Arduino UNO)
attachInterrupt(0, step_rotation, FALLING); //���������� �������� ���������� (����� 3 Arduino UNO)
}
void loop()
{
  if(start_stop){
  myStepper.step(rotation * (stepsPerRevolution / 100));
  }
}

//������� ��������� �������� ����������
void step_rotation()
{
  if(rotation == 1){
    rotation = -1;
  }
  else{
    rotation = 1;
  }
}

void step_start_stop()
{
start_stop = !start_stop;
}