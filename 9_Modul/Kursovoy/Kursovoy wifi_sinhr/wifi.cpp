#include "wifi.h"

WifiSettings::WifiSettings(const char* ssid, const char* password):
  _ssid(ssid), _password(password) {}

void WifiSettings::connectWifi() {
  WiFi.disconnect();
  Serial.println(_ssid);
  Serial.println(_password);
  WiFi.begin(_ssid, _password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Соединяемся с Wi-Fi..");
  }
  Serial.println("Соединение с Wi-Fi установлено");
}

void WifiSettings::setSsid(const char* ssid) {
  _ssid = ssid;
}
void WifiSettings::setPass(const char* password) {
  _password = password;
}


ServerTimeHttp::ServerTimeHttp(const String& httpAdress): _httpAdress(httpAdress) {}

void ServerTimeHttp::begin(){
  http.begin(_httpAdress);
}
//получение загруженных даннх с http
String ServerTimeHttp::getCode() { 
  return _payload;
}

bool ServerTimeHttp::requestHttp() {
  int httpCode = http.GET(); // Делаем запрос
  bool request;
  // Проверяем успешность запроса
  if (httpCode > 0) {
    // Выводим ответ сервера
    _payload = http.getString();
    Serial.print("HTTP Code: ");
    Serial.println(httpCode);
    Serial.print("Payload: ");
    Serial.println(_payload);
    request = true;
  } else {
    Serial.print("Ошибка HTTP-запроса. Код ошибки: ");
    Serial.println(httpCode);
    request = false;
  }

  // Освобождаем ресурсы микроконтроллера
  http.end();

  return request;
}

DateTime ServerTimeHttp::handleReceivedMessage() {
  DateTime dt;
  StaticJsonDocument<1500> doc; //Memory pool. Размер с запасом
  //разбор полученного сообщения как форматированного текста JSON
  DeserializationError error = deserializeJson(doc, _payload);
  // Если разбор прошел успешно
  if (error)
  {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.c_str());
    return dt;
  }
  String datetime = doc["datetime"];// Получаем данные из JSON
  int year, month, day, hour, minute, second;
  sscanf(datetime.c_str(), "%4d-%02d-%02dT%02d:%02d:%02d", &year, &month, &day, &hour, &minute, &second);
  // Установка времени на RTC
  dt = DateTime(year, month, day, hour, minute, second);
  return dt;
}