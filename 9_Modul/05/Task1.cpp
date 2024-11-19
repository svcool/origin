#define D1 A0
#define D2 A1
#define D3 A2

#include <LiquidCrystal.h>
#include <math.h>

// �������������� ������-�����
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

const int arraySize = 3;
float arrDT[arraySize] {0};

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
}

// ������� ��� �������� ��������� ������� � ������� �������
float Getterm(int RawADC) {
  float celsius = 1 / (log(1 / (1023. / RawADC - 1)) / 3950 + 1.0 / 298.15) - 273.15;
  return celsius;
}

// ������� ��� ��������� ������������ �������� � �������
float averageValue(int DT) {
  float data = 0;
  for (int i = 0; i < 10; i++) {
    data += Getterm(analogRead(DT));
    delay(100); 
  }
  return data / 10;
}

// ������� ��� ���������� ������������� �������� � �������
float maxValue(float* arr) {
  float maxNumber = arr[0]; 
  for (int i = 1; i < arraySize; i++) {
    if (arr[i] > maxNumber) {
      maxNumber = arr[i];
    }
  }
  return maxNumber;
}

// ������� ��� ���������� ������������ �������� � �������
float minValue(float* arr) {
  float minNumber = arr[0];
  for (int i = 1; i < arraySize; i++) {
    if (arr[i] < minNumber) {
      minNumber = arr[i];
    }
  }
  return minNumber;
}

// ������� ��� ���������� �������� �������� � �������
float avgValue(float* arr) {
  float sum = 0;
  for (int i = 0; i < arraySize; i++) {
    sum += arr[i];
  }
  return sum / arraySize;
}

void loop() {
  // �������� ����������� �������� � ��������
  arrDT[0] = averageValue(D1);
  arrDT[1] = averageValue(D2);
  arrDT[2] = averageValue(D3);

  // ������� �������� �� LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("MAX");
  lcd.print(maxValue(arrDT));

  lcd.setCursor(8, 0); 
  lcd.print("MIN");
  lcd.print(minValue(arrDT));

  lcd.setCursor(0, 1);
  lcd.print("    AVG");
  lcd.print(avgValue(arrDT));

  delay(500); 
}
