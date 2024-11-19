#include "DHT6.h"
#define DHTTYPE DHT22 //тип датчика
//DHT6(count, pin1, pin2, pin3, pin4, pin5, pin6, typeDHT)
DHT6 dht(4, DHTTYPE, 2, 3, 4, 5); //объект DHT6
void setup()
{
  Serial.begin(9600);
  Serial.println("DHT22 test!");
  dht.begin(); //Инициализация
}
void loop()
{
  // опрос датчика раз в 2 секунды
  delay(2000);
  // чтение показаний
  float maxH = dht.getMaxHumidity();
  float minH = dht.getMinHumidity();
  float avgH = dht.getAvgHumidity();

  float maxT = dht.getMaxTemperature();
  float minT = dht.getMinTemperature();
  float avgT = dht.getAvgTemperature();
  // Если считано не число, то ошибка!
  if (isnan(maxH) || isnan(minH) || isnan(avgH) || isnan(maxT) || isnan(minT) || isnan(avgT))
  {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  //Влажность
  Serial.println("Humidity: ");
  Serial.print("MaxH = "); Serial.print(maxH); Serial.print("% ");
  Serial.print("MinH = "); Serial.print(minH); Serial.print("% ");
  Serial.print("AvgH = "); Serial.print(avgH); Serial.println("% ");

  //Температура
  Serial.println("Temperature: ");
  Serial.print("MaxT = "); Serial.print(maxT); Serial.print("°C ");
  Serial.print("MinT = "); Serial.print(minT); Serial.print("°C ");
  Serial.print("AvgT = "); Serial.print(avgT); Serial.println("°C ");

}