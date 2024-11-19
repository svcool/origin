#include "MPU6050.h"         // ���������� ��� ������ � MPU6050
#include <LiquidCrystal.h>    // ���������� ��� ������ � LCD-��������
#include <Wire.h>             // ���������� ��� ������ � I2C

// ���� ����������� LCD-�������
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

MPU6050 mpu1(0x68);           // MPU6050 (AD0 = LOW)
MPU6050 mpu2(0x69);           // MPU6050 (AD0 = HIGH)

int16_t ax1, ay1, az1;        // ������ ������� MPU6050
int16_t ax2, ay2, az2;        // ������ ������� MPU6050
int16_t data[3]; 
// ������ ����� ��� ����������� ������
const char* labels[3][2] = {
    {"dX: ", "dY: "},
    {"dY: ", "dZ: "},
    {"dZ: ", "dX: "}
};

int displayIndex = 0;         // ������ ������� ������ �������
//������� ��� ������ � ������ ���������
void displayAngles(int index) {
    lcd.setCursor(0, 0);
    lcd.print(labels[index][0]);
    lcd.print(data[index]);

    lcd.setCursor(0, 1);
    lcd.print(labels[index][1]);
    lcd.print(data[(index + 1) % 3]);
}

void setup() {
    lcd.begin(16, 2);          // ������������� �������
    lcd.clear();               // ������� �������

    Wire.begin();              // ������������� I2C
    Serial.begin(9600);        // ������������� ����������������� ����������

    // ������������� MPU6050
    mpu1.initialize();
    mpu2.initialize();

    // �������� ����������� � MPU6050
    if (mpu1.testConnection() && mpu2.testConnection()) {
        lcd.print("MPU6050 OK");
        Serial.println("MPU6050 OK");
    } else {
        lcd.print("MPU6050 FAIL");
        Serial.println("MPU6050 FAIL");
        while (1);  // ���������� ����������, ���� ������� �� ����������
    }
    delay(1000);                // �������� 1 �������
    lcd.clear();
}

void loop() {
    mpu1.getAcceleration(&ax1, &ay1, &az1);//������ � ������� MPU6050
    mpu2.getAcceleration(&ax2, &ay2, &az2);//������ �� ������� MPU6050
    // ������� ����� �����������
    data[0] = abs(ax1 - ax2);
    data[1] = abs(ay1 - ay2);
    data[2] = abs(az1 - az2);

    lcd.clear();// ������� �������
    displayAngles(displayIndex);// ����������� �� ������� ����������
    displayIndex = (displayIndex + 1) % 3; // ���������� ������� ������

    // ��� �������� ����� ����� �������� ������ � ���������������� �������
    Serial.print("dX: "); Serial.print(data[0]); Serial.print('\t');
    Serial.print("dY: "); Serial.print(data[1]); Serial.print('\t');
    Serial.print("dZ: "); Serial.println(data[2]);

    delay(1000); // �������� ����� ��������� �����������
}
