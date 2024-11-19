const int pot = A0;
const int windowSize = 10;
int adcValues[windowSize] = {0};  // ������ ���� ��� ������� ����������� ��������
int index = 0;                    // ������� ������ � �������
long sum = 0;                     // ����� �������� � ����
bool checkindex = false;
float avgValue = 0;

float calculateFilteredAngle(int adcValue) {

    if(sum != 0) sum -= adcValues[index];  // �������� ������� �������� �� �����

    adcValues[index] = adcValue;    // ������ ������ �������� � ������ � ���������� ��� � �����
    sum += adcValue;
    index = (index + 1) % windowSize;   // ����������������� ������� � ����� ��� ���������� ������� ����
    if(index == 0 && sum != 0) checkindex = true; //�������� ������������� �������

    if (checkindex) {
        avgValue = static_cast<float>(sum) / windowSize; // ��������� ������� ��������, ���� ������ ��������
    } else {
        avgValue = adcValue; // ����� �� ���������� ���������� ������
    }
   
    return ((avgValue - 512.0) / 512.0) * 135.0; // �������������� �������� �������� � ����
}

void setup() {
    Serial.begin(9600);            // �������� ���������������� ����
    analogReference(DEFAULT);      // ������� ���������� 5�
}

void loop() {
    
    int adcValue = analogRead(pot);  

    float filteredAngle = calculateFilteredAngle(adcValue);

    // ����� �������� ���� � ��������
    Serial.print("�������� ��� �������: ");
    Serial.print(adcValue);
    Serial.print(" ������ AVG: ");
    Serial.println(filteredAngle);

    delay(100); // ��������
}
