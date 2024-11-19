#include "MPU6050.h"         // Библиотека для работы с MPU6050
#include <LiquidCrystal.h>    // Библиотека для работы с LCD-дисплеем
#include <Wire.h>             // Библиотека для работы с I2C

// Пины подключения LCD-дисплея
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

MPU6050 mpu1(0x68);           // MPU6050 (AD0 = LOW)
MPU6050 mpu2(0x69);           // MPU6050 (AD0 = HIGH)

int16_t ax1, ay1, az1;        // Данные первого MPU6050
int16_t ax2, ay2, az2;        // Данные второго MPU6050
int16_t data[3]; 
// Массив строк для отображения данных
const char* labels[3][2] = {
    {"dX: ", "dY: "},
    {"dY: ", "dZ: "},
    {"dZ: ", "dX: "}
};

int displayIndex = 0;         // Индекс текущей строки дисплея
//функция для вывода в режиме прокрутки
void displayAngles(int index) {
    lcd.setCursor(0, 0);
    lcd.print(labels[index][0]);
    lcd.print(data[index]);

    lcd.setCursor(0, 1);
    lcd.print(labels[index][1]);
    lcd.print(data[(index + 1) % 3]);
}

void setup() {
    lcd.begin(16, 2);          // Инициализация дисплея
    lcd.clear();               // Очистка дисплея

    Wire.begin();              // Инициализация I2C
    Serial.begin(9600);        // Инициализация последовательного соединения

    // Инициализация MPU6050
    mpu1.initialize();
    mpu2.initialize();

    // Проверка подключения к MPU6050
    if (mpu1.testConnection() && mpu2.testConnection()) {
        lcd.print("MPU6050 OK");
        Serial.println("MPU6050 OK");
    } else {
        lcd.print("MPU6050 FAIL");
        Serial.println("MPU6050 FAIL");
        while (1);  // Остановить выполнение, если датчики не подключены
    }
    delay(1000);                // Задержка 1 секунда
    lcd.clear();
}

void loop() {
    mpu1.getAcceleration(&ax1, &ay1, &az1);//данные с первого MPU6050
    mpu2.getAcceleration(&ax2, &ay2, &az2);//данные со второго MPU6050
    // Разница между показаниями
    data[0] = abs(ax1 - ax2);
    data[1] = abs(ay1 - ay2);
    data[2] = abs(az1 - az2);

    lcd.clear();// Очистка дисплея
    displayAngles(displayIndex);// Отображение на дисплее прокруткой
    displayIndex = (displayIndex + 1) % 3; // Обновление индекса строки

    // Для проверки можно также выводить данные в последовательный монитор
    Serial.print("dX: "); Serial.print(data[0]); Serial.print('\t');
    Serial.print("dY: "); Serial.print(data[1]); Serial.print('\t');
    Serial.print("dZ: "); Serial.println(data[2]);

    delay(1000); // Задержка перед следующим обновлением
}
