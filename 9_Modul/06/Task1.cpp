#include "MPU6050.h"         // ���������� ��� ������ � MPU6050
#include <LiquidCrystal.h>    // ���������� ��� ������ � LCD-��������
#include <Wire.h>             // ���������� ��� ������ � I2C
#include <math.h>             // �������������� �������, � ��� ����� ��������

// ���� ����������� LCD-�������
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);
// ������ ����� ��� ����������� ������
const char* labels[3][2] = {
    {"X: ", "Y: "},
    {"Y: ", "Z: "},
    {"Z: ", "X: "}
};

MPU6050 mpu;                  // �������� ������� MPU6050
int16_t ax, ay, az;           // ���������� ��� �������� �������� �������������
float angles[3];              // ���� �� ���� X, Y, Z
float ax_avg = 0, ay_avg = 0, az_avg = 0;
int displayIndex = 0;         // ������ ������� ������ �������

void displayAngles(int index) {
    lcd.setCursor(0, 0);
    lcd.print(labels[index][0]);
    lcd.print(angles[index]);
    lcd.print((char)223); // ������ �������

    lcd.setCursor(0, 1);
    lcd.print(labels[index][1]);
    lcd.print(angles[(index + 1) % 3]);
    lcd.print((char)223);
}

// ���������� �� 10 ���������
void average(const int size){
  float ax_sum = 0, ay_sum = 0, az_sum = 0;
for (int i = 0; i < size; i++) {
        mpu.getAcceleration(&ax, &ay, &az); // ������ �������������
        ax_sum += ax;
        ay_sum += ay;
        az_sum += az;
        delay(100); // �������� 100 �� ����� �����������
    }
        // ������� ��������
    ax_avg = ax_sum / size;
    ay_avg = ay_sum / size;
    az_avg = az_sum / size;
}

void setup() {
    lcd.begin(16, 2);          // ������������� �������
    lcd.clear();               // ������� �������

    Wire.begin();              // ������������� I2C
    Serial.begin(9600);        // ������������� ����������������� ����������
    mpu.initialize();          // ������������� MPU6050

    // �������� ����������� � MPU6050
    if (mpu.testConnection()) {
        lcd.print("MPU6050 OK");
        Serial.println("MPU6050 OK");
    } else {
        lcd.print("MPU6050 FAIL");
        Serial.println("MPU6050 FAIL");
        while (1);  // ���������� ����������, ���� ������ �� ���������
    }
    delay(1000);
    lcd.clear();
}

void loop() {
    average(10);//�������� �������� ������������� �� 10 ���������

    // �������������� � ��������� � g
    float ax_g = (float)ax_avg / 32768 * 2;
    float ay_g = (float)ay_avg / 32768 * 2;
    float az_g = (float)az_avg / 32768 * 2;

    // ���������� ����� ������� (� ��������) �� ������ ���
    angles[0] = atan2(ay_g, az_g) * 180 / PI; // ���� �� ��� X
    angles[1] = atan2(ax_g, az_g) * 180 / PI; // ���� �� ��� Y
    angles[2] = atan2(ax_g, ay_g) * 180 / PI; // ���� �� ��� Z
    
    lcd.clear();// ������� �������
    displayAngles(displayIndex);// ����������� �� ������� ����������
    displayIndex = (displayIndex + 1) % 3; // ���������� ������� ������

    //������ � ���������������� ����
    Serial.print("Angle X: "); Serial.print(angles[0]); Serial.print('\t');
    Serial.print("Angle Y: "); Serial.print(angles[1]); Serial.print('\t');
    Serial.print("Angle Z: "); Serial.println(angles[2]);

    delay(500); // �������� ����� ��������� �����������
}
