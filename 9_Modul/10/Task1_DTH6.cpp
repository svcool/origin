#include "DHT6.h"

DHT6::DHT6(int numDht,
           uint8_t type,
           uint8_t Pin1,
           uint8_t Pin2 = NONE,
           uint8_t Pin3 = NONE,
           uint8_t Pin4 = NONE,
           uint8_t Pin5 = NONE,
           uint8_t Pin6 = NONE
          ): numDht(numDht), type(type) {

  sensors = new DHT[numDht](Pin1, type); //иницилизация массива объектов DHT, обязателен конструктор
  tempArr = new float[numDht];
  humArr = new float[numDht];

  if (numDht > 1) {
    if (Pin2 != NONE) sensors[1] = DHT(Pin2, type);
    if (Pin3 != NONE) sensors[2] = DHT(Pin3, type);
    if (Pin4 != NONE) sensors[3] = DHT(Pin4, type);
    if (Pin5 != NONE) sensors[4] = DHT(Pin5, type);
    if (Pin6 != NONE) sensors[5] = DHT(Pin6, type);
  }
};

void DHT6::begin() {
  for (int i = 0; i < numDht; ++i) {
    sensors[i].begin();
  }
  Serial.begin(9600);
}

void DHT6::Temperature(bool S, bool force) {
  for (int i = 0; i < numDht; i++) {
    tempArr[i] = sensors[i].readTemperature(S, force);
  }
}

void  DHT6::Humidity(bool force) {
  for (int i = 0; i < numDht; i++) {
    humArr[i] = sensors[i].readHumidity(force);
  }
}

//Температура
float DHT6::getMaxTemperature(bool S, bool force) {
  float maxTemp = tempArr[0];
  DHT6::Temperature(S, force);
  for (int i = 1; i < numDht; i++) {
    if (tempArr[i] > maxTemp) {
      maxTemp = tempArr[i];
    }
  }
  return maxTemp;
}

float DHT6::getMinTemperature(bool S, bool force) {
  float minTemp = tempArr[0];
  DHT6::Temperature(S, force);
  for (int i = 1; i < numDht; i++) {
    if (tempArr[i] < minTemp) {
      minTemp = tempArr[i];
    }
  }
  return minTemp;
}

float DHT6::getAvgTemperature(bool S, bool force) {
  float avg = 0;
  DHT6::Temperature(S, force);
  for (int i = 0; i < numDht; i++) {
    avg += tempArr[i];
  }
  return avg / numDht;
}


//Влажность
float DHT6::getMaxHumidity(bool force) {
  float maxHum = humArr[0];
  DHT6::Humidity(force);
  for (int i = 0; i < numDht; i++) {
    if (humArr[i] > maxHum) {
      maxHum = humArr[i];
    }
  }
  return maxHum;
}

float DHT6::getMinHumidity(bool force) {
  float minHum = humArr[0];
  DHT6::Humidity(force);
  for (int i = 0; i < numDht; i++) {
    if (humArr[i] < minHum) {
      minHum = humArr[i];
    }
  }
  return minHum;
}

float DHT6::getAvgHumidity(bool force) {
  float avg = 0;
  DHT6::Humidity(force);
  for (int i = 0; i < numDht; i++) {
    avg += humArr[i];
  }
  return avg / numDht;
}
