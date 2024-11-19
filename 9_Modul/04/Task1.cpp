#define SEG_COUNT 7 // ���������� ������������ ���������
const int firstSeg = 2; // ������� ����� ������ ��� ����������� ����������
int number = 0;
int lastButton = LOW; // ���������� ��������� ������
int curButton = LOW; // ������� ��������� ������
const int but = 9; // ������ ���������� � �������� 9

byte numberSegments[16] = {
  0b11000000, // 0
  0b11111001, // 1
  0b10100100, // 2
  0b10110000, // 3
  0b10011001, // 4
  0b10010010, // 5
  0b10000010, // 6
  0b11111000, // 7
  0b10000000, // 8
  0b10010000, // 9
  0b10001000, // A
  0b10000011, // B
  0b11000110, // C
  0b10100001, // D
  0b10000110, // E
  0b10001110  // F
};

int debounce(int last, int button) {
  int current = digitalRead(button);
  if (last != current) {
    delay(5);
    current = digitalRead(button);
  }
  return current;
}

void setup() {
  for (int i = 0; i < SEG_COUNT; ++i) {
    pinMode(i + firstSeg, OUTPUT);
  }
  pinMode(but, INPUT);
  digitalWrite(but, HIGH); // �������� � �������
}

void loop()
{

// ��� ������� �������� ����������: ������ �� �� ���� �������.
curButton = debounce(lastButton, but);

if(lastButton == HIGH && curButton ==LOW){
  number++;
    if (number > 15) { // ����� ����� 15 (F)
      number = 0;
    }
}

// ����� ��� �������� �����
  int mask = numberSegments[number];
  
  // ���������� ���������� ����������
  for (int i = 0; i < SEG_COUNT; i++) {
    boolean enableSegment = bitRead(mask, i);
    digitalWrite(i + firstSeg, enableSegment);
  }

lastButton = curButton;
}