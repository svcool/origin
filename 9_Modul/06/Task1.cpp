#include "MPU6050.h"         // Библиотека для работы с MPU6050
#include <LiquidCrystal.h>    // Библиотека для работы с LCD-дисплеем
#include <Wire.h>             // Библиотека для работы с I2C
#include <math.h>             // Математические функции, в том числе арксинус

// Пины подключения LCD-дисплея
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);
// Массив строк для отображения данных
const char* labels[3][2] = {
    {"X: ", "Y: "},
    {"Y: ", "Z: "},
    {"Z: ", "X: "}
};

MPU6050 mpu;                  // Создание объекта MPU6050
int16_t ax, ay, az;           // Переменные для хранения значений акселерометра
float angles[3];              // Углы по осям X, Y, Z
float ax_avg = 0, ay_avg = 0, az_avg = 0;
int displayIndex = 0;         // Индекс текущей строки дисплея

void displayAngles(int index) {
    lcd.setCursor(0, 0);
    lcd.print(labels[index][0]);
    lcd.print(angles[index]);
    lcd.print((char)223); // Символ градуса

    lcd.setCursor(0, 1);
    lcd.print(labels[index][1]);
    lcd.print(angles[(index + 1) % 3]);
    lcd.print((char)223);
}

// Усреднение по 10 измерений
void average(const int size){
  float ax_sum = 0, ay_sum = 0, az_sum = 0;
for (int i = 0; i < size; i++) {
        mpu.getAcceleration(&ax, &ay, &az); // Данные акселерометра
        ax_sum += ax;
        ay_sum += ay;
        az_sum += az;
        delay(100); // Ожидание 100 мс между измерениями
    }
        // среднее значение
    ax_avg = ax_sum / size;
    ay_avg = ay_sum / size;
    az_avg = az_sum / size;
}

void setup() {
    lcd.begin(16, 2);          // Инициализация дисплея
    lcd.clear();               // Очистка дисплея

    Wire.begin();              // Инициализация I2C
    Serial.begin(9600);        // Инициализация последовательного соединения
    mpu.initialize();          // Инициализация MPU6050

    // Проверка подключения к MPU6050
    if (mpu.testConnection()) {
        lcd.print("MPU6050 OK");
        Serial.println("MPU6050 OK");
    } else {
        lcd.print("MPU6050 FAIL");
        Serial.println("MPU6050 FAIL");
        while (1);  // Остановить выполнение, если датчик не подключен
    }
    delay(1000);
    lcd.clear();
}

void loop() {
    average(10);//усреднее значений акселерометра за 10 измерений

    // Преобразование в ускорение в g
    float ax_g = (float)ax_avg / 32768 * 2;
    float ay_g = (float)ay_avg / 32768 * 2;
    float az_g = (float)az_avg / 32768 * 2;

    // Вычисление углов наклона (в градусах) по каждой оси
    angles[0] = atan2(ay_g, az_g) * 180 / PI; // Угол по оси X
    angles[1] = atan2(ax_g, az_g) * 180 / PI; // Угол по оси Y
    angles[2] = atan2(ax_g, ay_g) * 180 / PI; // Угол по оси Z
    
    lcd.clear();// Очистка дисплея
    displayAngles(displayIndex);// Отображение на дисплее прокруткой
    displayIndex = (displayIndex + 1) % 3; // Обновление индекса строки

    //данные в последовательный порт
    Serial.print("Angle X: "); Serial.print(angles[0]); Serial.print('\t');
    Serial.print("Angle Y: "); Serial.print(angles[1]); Serial.print('\t');
    Serial.print("Angle Z: "); Serial.println(angles[2]);

    delay(500); // Задержка перед следующим обновлением
}
