#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <LiquidCrystal.h> // ���������� ����������� ���������� LiquidCrystal
// �������������� ������-�����, ������� ��������������
// ��� ����������� �������� �� Arduino � �������:
// RS, E, D4, D5, D6, D7
LiquidCrystal lcd(14, 27, 26, 25, 33, 32);

// ������ ��� � ������ ����� �������
const char* ssid = "Wokwi-GUEST";
const char* password = "";
const String endpoint = "http://api.openweathermap.org/data/2.5/weather?q=Moscow,ru,pt&APPID=";
const String key = "cdecb72a7903eb3bb1964c39615f1764";
int httpCode;

const char* name;
float temp;
float feels_like;
int humidity;
int displayIndex = 0;

unsigned long previousMillis = 0;
const long interval = 30000; // 30 ������

static int lastButton = LOW; // ���������� ��������� ������
bool button = false;//������� ��������� ������
const int but = 23; // ���� ����������� ������

// ������� ��� ��������� ��������� ������
bool handleButton(int buttonPin, int &lastState, bool &button) {
  int currentState = digitalRead(buttonPin);
  // ���������� ��������
  if (lastState != currentState) {
    delay(20);
    currentState = digitalRead(buttonPin);
  }
  if (lastState == HIGH && currentState == LOW) {
    button = !button; // ����������� ���������
  }
  // ��������� ���������� ���������
  lastState = currentState;
  return button;
}


void setup()
{
  // ������������� ������ (���������� �������� � �����) ������
  lcd.begin(16, 2);
  lcd.clear();// ������� �����
  lcd.print("Weather");// ������� ��������� � ������ �������
  pinMode(but, INPUT_PULLUP);  // ������
  Serial.begin(115200);
  // ������ ��������� �������� �� �������� �������� �����
  delay(1000);
  // ������������ � Wi-Fi ����
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("����������� � Wi-Fi..");
  }
  Serial.println("���������� � Wi-Fi �����������");
}

void loop() {
  unsigned long currentMillis = millis();

  // ��������, ������ �� 30 ������
  if (currentMillis - previousMillis >= interval || previousMillis == 0) {
    previousMillis = currentMillis;
    getWeatherData();
  }


  if (httpCode > 0) {
    button = handleButton(but, lastButton, button);
    if (button) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(name);
      displayData(displayIndex);
      displayIndex = (displayIndex + 1) % 3;
    }
    button = false;
  }
}

void getWeatherData() {
  // ��������� �������� ����������� � ������������ ����
  if ((WiFi.status() == WL_CONNECTED))
  {
    // ������� ������ ��� ������ � HTTP
    HTTPClient http;
    // ������������ � ���-�������� OpenWeatherMap � ���������� �����������
    http.begin(endpoint + key);
    httpCode = http.GET(); // ������ ������
    // ��������� ���������� �������
    if (httpCode > 0)
    {
      // ������� ����� �������
      String payload = http.getString();
      Serial.println(httpCode);
      //��������� ���������� ������
      handleReceivedMessage(payload);
    }
    else {
      Serial.println("������ HTTP-�������");
    }
    http.end(); // ����������� ������� ����������������
  }
}

void displayData(int index) {
  lcd.setCursor(0, 1);
  switch (index) {
    case 0:
      lcd.print("Temp: ");
      lcd.print(temp);
      break;
    case 1:
      lcd.print("Feels: ");
      lcd.print(feels_like);
      break;
    case 2:
      lcd.print("Humidity: ");
      lcd.print(humidity);
      break;
  }

}


void handleReceivedMessage(String message)
{
  StaticJsonDocument<1500> doc; //Memory pool. ������ � �������
  //������ ����������� ��������� ��� ���������������� ������ JSON
  DeserializationError error = deserializeJson(doc, message);
  // ���� ������ ������ �������
  if (error)
  {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.c_str());
    return;
  }
  Serial.println();
  Serial.println("----- DATA FROM OPENWEATHER ----");
  name = doc["name"];
  Serial.print("City: ");
  Serial.println(name);
  int timezone = doc["timezone"];
  Serial.print("Timezone: ");
  Serial.println(timezone);
  humidity = doc["main"]["humidity"];
  Serial.print("Humidity: ");
  Serial.println(humidity);
  temp = doc["main"]["temp"];
  Serial.print("temp: ");
  Serial.println(temp);
  feels_like = doc["main"]["feels_like"];
  Serial.print("feels_like: ");
  Serial.println(feels_like);
  Serial.println("------------------------------");
}