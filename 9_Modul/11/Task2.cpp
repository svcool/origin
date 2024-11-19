//����������� ���������� ��� ����������
#include "PID_v1.h"
// ������ �������
const int PWMPin = 3;
const int inputPin = -1;
const int setPointPin = A1;
const int setPointIndicator = 6;
const int inputIndicator = 5;
//���������� ��� ��� ����������
double Setpoint, Input, Output;
//��������� ��� ����������
//double Kp = 17, Ki = 0.3, Kd = 2; // �������� ���������
//double Kp = 255, Ki = .0, Kd = 0; // ���������������� ���������

// �������� ������ ������� �� ����������������� ������������(��). 
// ����������, ���� ������ ���������� ��, ��������� �� ������ ������� ������ �� �������. 
// ��� � ������� �� �� �� ������ ��������� �������, �� �������� ���������� �������������, 
// ������� ���������. �� �� ������� ��������� ������� ���� ������ ������, ��� � ���� ����� ����� ��������. 
// �� ��������� ������ ������ �� ������� � �������, ��� ������ ��� ������.
double Kp = 100, Ki = .04, Kd = 0; // ������ ������������ �� ���������
//double Kp = 120, Ki = .01, Kd = 1; // ������ ������������ �� ���������
//������ ��� ����������
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, P_ON_E, DIRECT);

void setup()
{
  Serial.begin(115200);
  myPID.SetOutputLimits(-4, 255); //�������� ������
  //���������� ��� �������
  if (setPointIndicator >= 0) pinMode(setPointIndicator,
                                        OUTPUT);
  if (inputIndicator >= 0) pinMode(inputIndicator, OUTPUT);
  Setpoint = 0; //��������� �������� ������� - ����
  myPID.SetMode(AUTOMATIC); //��������� ����������
  if (inputPin > 0) //����� ��������� �������� �������
  {
    Input = analogRead(inputPin);
  } else {
    Input = simPlant(0.0, 1.0); //���������� ������ �������� �������
  }
  Serial.println("Setpoint Input Output Watts");
}

void loop()
{
  float heaterWatts = (int)Output * 20.0 / 255; //�������� ����������� ��� ������
  if (inputPin > 0 )
  {
    Input = analogRead(inputPin);
  } else
  {
    Input = simPlant(heaterWatts, Output > 0 ? 1.0 : 1 - Output);
    //������������� �������
  }
  if (myPID.Compute()) //��� ���������
  {
    analogWrite(PWMPin, (int)Output); //����� �� �����������
    Setpoint = analogRead(setPointPin) / 4; // ������ �������  ����������� (�� 0 �� 255)
    if (inputIndicator >= 0) analogWrite(inputIndicator, Input); // ���  �������
    if (setPointIndicator >= 0) analogWrite(setPointIndicator,
                                              Setpoint);
  }
  report(); //����� ���������� ������ � com ����
}

/*������� ������ ���������� ������ ���-����������*/
void report(void)
{
  static uint32_t last = 0;
  const int interval = 1000; //����� ��� � �������
  if (millis() - last > interval)
  {
    last += interval;
    Serial.print("SP:");
    Serial.print(Setpoint);
    Serial.print(" PV:");
    Serial.print(Input);
    Serial.print(" CV:");
    Serial.print(Output);
    Serial.print(' ');
    Serial.println();
  }
}

/*������� ������ �������
Q - �������� [��],
hfactor - ������������� ����������� ����������������*/
float simPlant(float Q,float hfactor)
{
//�������� ������������ ����� �������� 1x1x2 �� � ������������ � ��������� �����������
float h = 5 *hfactor ; // ��/�2K ����������� ���������
float Cps = 0.89; // ������������ ��/�����C
float area = 1e-4; // ������� ���������, �2
float mass = 1 ; // �����, ������
float Tamb = 25; // ����������� ���������� ����� �C
static float T = Tamb; // ������� ����������� �C
static uint32_t last = 0; // ����� ��� �������������
uint32_t interval = 100; // ������ ���������� ������, ��
if (millis() - last >= interval)
{
last += interval;
T = T + Q * interval / 1000 / mass / Cps - (T - Tamb) * area * h;
}
return T;
}