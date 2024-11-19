#ifndef WIFI_SETTINGS
#define WIFI_SETTINGS
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <RTClib.h>

class WifiSettings {
    const char* _ssid;
    const char* _password;
  public:
    WifiSettings(const char* ssid = "Wokwi-GUEST", const char* password = "");
    void connectWifi();
    void setSsid(const char* ssid);
    void setPass(const char* password);
};

class ServerTimeHttp {
    const String _httpAdress;
    HTTPClient http; // создаем объект для работы с HTTP
    String _payload;
  public:
    ServerTimeHttp(const String& httpAdress);
    void begin();
    String getCode();
    bool requestHttp();
    DateTime handleReceivedMessage();
};


#endif