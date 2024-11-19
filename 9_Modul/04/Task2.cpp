#include <fDigitsSegtPin.h> // ���������� ���������� fDigitsSegtPin�
// �������������� ������-4-� ��������� ���������, ������� ��������������
// ��� ����������� �������� ��:
fDigitsSegtPin display(6, 5, 9, 4, 8, 13, 3, 12, 11, 7, 2, 10);
const int reset = 0;
const int start = 1;
bool stop = true;

int lastButton_start = LOW; // ���������� ��������� ������
int curButton_start = LOW; // ������� ��������� ������
int lastButton_reset = LOW; // ���������� ��������� ������
int curButton_reset = LOW; // ������� ��������� ������


int debounce(int last, int button) {
  int current = digitalRead(button);
  if (last != current) {
    delay(5);
    current = digitalRead(button);
  }
  return current;
}

void setup()
{
  display.begin();
  pinMode(reset, INPUT_PULLUP); // ������������� ���� ��� ������ ������
  pinMode(start, INPUT_PULLUP); // ������������� ���� ��� ������ ������/�����
}


void loop()
{
   static unsigned long timer = millis(); //������� �����
   static float deciSeconds = 0; //�����, ������������ �� ����������
   unsigned long currentMillis = millis();

curButton_reset = debounce(lastButton_reset, reset);

if(lastButton_reset == HIGH && curButton_reset ==LOW){
  if(stop){
    deciSeconds = 0;
  }

}
lastButton_reset = curButton_reset;



curButton_start = debounce(lastButton_start, start);

if(lastButton_start == HIGH && curButton_start ==LOW){
stop = !stop;
}
lastButton_start = curButton_start;

    if (currentMillis - timer >= 1000) //������ 1000 ��
    {
      
      if(!stop){
      timer = currentMillis;
      deciSeconds += 1; // 1000 �� = 1 ���
      }
  }
display.print(deciSeconds); //������������� ����� ������� � �������� �����

}