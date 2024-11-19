#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <LiquidCrystal.h> // Подключаем стандартную библиотеку LiquidCrystal
// Инициализируем объект-экран, передаём использованные
// для подключения контакты на Arduino в порядке:
// RS, E, D4, D5, D6, D7
LiquidCrystal lcd(14, 27, 26, 25, 33, 32);

// Вводим имя и пароль точки доступа
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
const long interval = 30000; // 30 секунд

static int lastButton = LOW; // предыдущее состояние кнопки
bool button = false;//текущее состояние кнопок
const int but = 23; // порт подключения кнопки

// Функция для получения состояния кнопки
bool handleButton(int buttonPin, int &lastState, bool &button) {
  int currentState = digitalRead(buttonPin);
  // устранение дребезга
  if (lastState != currentState) {
    delay(20);
    currentState = digitalRead(buttonPin);
  }
  if (lastState == HIGH && currentState == LOW) {
    button = !button; // Переключаем состояние
  }
  // Обновляем предыдущее состояние
  lastState = currentState;
  return button;
}


void setup()
{
  // устанавливаем размер (количество столбцов и строк) экрана
  lcd.begin(16, 2);
  lcd.clear();// ощищаем экран
  lcd.print("Weather");// выводим сообщение в первой строчке
  pinMode(but, INPUT_PULLUP);  // кнопка
  Serial.begin(115200);
  // делаем небольшую задержку на открытие монитора порта
  delay(1000);
  // подключаемся к Wi-Fi сети
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Соединяемся с Wi-Fi..");
  }
  Serial.println("Соединение с Wi-Fi установлено");
}

void loop() {
  unsigned long currentMillis = millis();

  // Проверка, прошло ли 30 секунд
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
  // выполняем проверку подключения к беспроводной сети
  if ((WiFi.status() == WL_CONNECTED))
  {
    // создаем объект для работы с HTTP
    HTTPClient http;
    // подключаемся к веб-странице OpenWeatherMap с указанными параметрами
    http.begin(endpoint + key);
    httpCode = http.GET(); // Делаем запрос
    // проверяем успешность запроса
    if (httpCode > 0)
    {
      // выводим ответ сервера
      String payload = http.getString();
      Serial.println(httpCode);
      //обработка полученных данных
      handleReceivedMessage(payload);
    }
    else {
      Serial.println("Ошибка HTTP-запроса");
    }
    http.end(); // освобождаем ресурсы микроконтроллера
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
  StaticJsonDocument<1500> doc; //Memory pool. Размер с запасом
  //разбор полученного сообщения как форматированного текста JSON
  DeserializationError error = deserializeJson(doc, message);
  // Если разбор прошел успешно
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