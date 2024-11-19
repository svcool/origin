int led[3] {11,12,13};
int number=0;
const int button = 0; //������ ���������� � �������� 0

int lastButton = LOW; //���������� ��������� ������
int curButton = LOW; //������� ��������� ������
int ledOn = HIGH; //������� ��������� ����������

/*������� ���������� ��������
last - ���������� ��������� ������*/
int debounce (int last)
{
int current = digitalRead(button);
if(last != current) //���� ��������� ����������
{
delay(5);
current = digitalRead(button);
}
return current;
}
void setup() {
for(int i=0; i<3; i++){
pinMode(led[i], OUTPUT); //������� ���������� - �����
digitalWrite(led[i], HIGH); //�� ������ ���. 0
}
pinMode(button, INPUT); //������� ������ - ����
digitalWrite(button, HIGH); //������������� �������� �� �����
}

void loop() {
curButton = debounce (lastButton);
if(lastButton == HIGH && curButton == LOW) //������� �������
{
ledOn = !ledOn;
if(number > 0 && number < 3){
digitalWrite(led[number], ledOn);
digitalWrite(led[number-1], !ledOn);
}
else {
digitalWrite(led[number], ledOn);
digitalWrite(led[number-1], !ledOn);
}
if (number < 3) number++;
else number = 0;
ledOn = !ledOn;
}
lastButton = curButton;
}
