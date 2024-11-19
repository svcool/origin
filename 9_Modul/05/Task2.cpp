#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

float dist;
const int led[3] {6, 5, 4};
unsigned long previousMillis = 0;
bool isBlinking = false;
float prevDist = 0;

long readUltrasonicDistance(int triggerPin, int echoPin);
void setupLEDs();
void displayDistance(float distance);
void updateLEDs(float distance);
void setLEDs(bool led1, bool led2, bool led3);

void setup()
{
  setupLEDs();
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();
}

void loop()
{
  long duration = readUltrasonicDistance(3, 2);
  dist = ((duration * 0.0343) / 2) / 100;
  
  displayDistance(dist);
  updateLEDs(dist);
  prevDist = dist;
}

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

void setupLEDs()
{
  for (int i = 0; i < 3; i++) {
    pinMode(led[i], OUTPUT);
    digitalWrite(led[i], HIGH);
  }
}

void displayDistance(float distance)
{
  Serial.print("Значение cm: ");
  Serial.print(distance);
  
  lcd.setCursor(0, 1);
  lcd.print("distance = ");
  lcd.print(distance, 1);
  lcd.print("m");
}

void updateLEDs(float distance)
{
  unsigned long currentMillis = millis();
  
  if (distance <= 1.0) {
    if (currentMillis - previousMillis >= 100) {
      previousMillis = currentMillis;
      isBlinking = !isBlinking;
      setLEDs(false, isBlinking, isBlinking); // красный мигает
    }
  } 
  else if (distance <= 2.0) {
    if (currentMillis - previousMillis >= 500) {
      previousMillis = currentMillis;
      isBlinking = !isBlinking;
      setLEDs(false, false, isBlinking); // желтый мигает
    }
  }
  else if (distance <= 4.0 && distance != prevDist) {
    for (int i = 0; i < 3; i++) {
      digitalWrite(led[i], LOW); // белый
    }
  }
}

void setLEDs(bool led1, bool led2, bool led3)
{
  digitalWrite(led[0], led1);
  digitalWrite(led[1], led2);
  digitalWrite(led[2], led3);
}
