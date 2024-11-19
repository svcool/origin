#include <Servo.h> //����������� ����������
// ������� ������ ������ � �������
long readUltrasonicDistance(int triggerPin, int echoPin);
Servo myservo; // �������� �������
int val; // ������������� �������� 
float cm;

const int triggerPin = 3; // ��� �������� ��������������� �������
const int echoPin = 2;    // ��� ��� ��������������� �������
const int servoPin = 9;   // ��� �����

// ������� ������ ������ � �������
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT); // ����� Trig
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH); // ��������� TRIG �� 10 ���
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT); // ��������� ������������ ECHO
  return pulseIn(echoPin, HIGH);
}

void setup() {
  myservo.attach(servoPin); // �������� ����� ���������� � ������ 9
}
void loop() {

  cm = readUltrasonicDistance(triggerPin, echoPin) / 58;
  val = map(cm, 0, 400, 180, 0); // ��������������� �������� ������� ���������������
// ������������ �������� �� ����������� ���������
  val = constrain(val, 0, 180);

  myservo.write(val); // ��������� ����� ������� ������������
  delay(15); // �������
}