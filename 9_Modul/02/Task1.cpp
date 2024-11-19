int led[3] {11,12,13};
int number=0;
const int button = 0; //кнопка подключена к контакту 0

int lastButton = LOW; //предыдущее состояние кнопки
int curButton = LOW; //Текущее состояние кнопки
int ledOn = HIGH; //Текущее состояние светодиода

/*Функция подавления дребезга
last - предыдущее состояние кнопки*/
int debounce (int last)
{
int current = digitalRead(button);
if(last != current) //если состояние изменилось
{
delay(5);
current = digitalRead(button);
}
return current;
}
void setup() {
for(int i=0; i<3; i++){
pinMode(led[i], OUTPUT); //контакт светодиода - выход
digitalWrite(led[i], HIGH); //на выходе лог. 0
}
pinMode(button, INPUT); //контакт кнопки - вход
digitalWrite(button, HIGH); //подтягивающий резистор на входе
}

void loop() {
curButton = debounce (lastButton);
if(lastButton == HIGH && curButton == LOW) //условие нажатия
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
