int buttonLedState[6][5] = { 
    {0, 9, 0, 0, 250},
    {1, 9, 0, 0, 250},
    {2, 10, 0, 0, 250},
    {3, 10, 0, 0, 250},
    {4, 11, 0, 0, 250},
    {5, 11, 0, 0, 250}
};

const int button = 0;
const int led = 1;
const int currentB = 2;
const int lastB = 3;
const int ledBright = 4; // значение ШИМ на выводе соответствующего диода
const int step = 50;

/*Функция подавления дребезга
last - предыдущее состояние кнопки*/
int debounce(int last, int button) {
    int current = digitalRead(button);
    if (last != current) { // если состояние изменилось
        delay(5);
        current = digitalRead(button);
    }
    return current;
}

void uplight(int led, int& ledBright) {
    if (ledBright == 0) return;
        ledBright -= step;
    analogWrite(led, ledBright);
    delay(10);
}

void downlight(int led, int& ledBright) {
    if (ledBright == 250) return;
        ledBright += step;
    analogWrite(led, ledBright);
    delay(10);
}

void setup() {
    for (int i = 0; i < 6; i++) {
        pinMode(buttonLedState[i][led], OUTPUT); // контакт светодиода - выход
        digitalWrite(buttonLedState[i][led], HIGH); // на выходе лог. 1
    }

    for (int i = 0; i < 6; i++) {
        pinMode(buttonLedState[i][button], INPUT); // контакт кнопки - вход
        digitalWrite(buttonLedState[i][button], 250); // подтягивающий резистор на входе
    }
}

void loop() {
    for (int i = 0; i < 6; i++) {
        buttonLedState[i][currentB] = debounce(buttonLedState[i][lastB], buttonLedState[i][button]);

        if (buttonLedState[i][lastB] == HIGH && buttonLedState[i][currentB] == LOW) {
            if (i%2==0) {
                downlight(buttonLedState[i][led], buttonLedState[i][ledBright]);
            } else {
                uplight(buttonLedState[i][led], buttonLedState[i-1][ledBright]);
                
            }
        }

        buttonLedState[i][lastB] = buttonLedState[i][currentB];
    }
}