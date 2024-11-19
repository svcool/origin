#ifndef DHT6_H
#define DHT6_H
#define NONE 999

#include <DHT.h>

class DHT6 {
    DHT* sensors; //массив объектов DHT
    uint8_t type; //тип сенсора
    int  numDht; //количеств датчиков
    uint8_t  Pin1;
    uint8_t  Pin2;
    uint8_t  Pin3;
    uint8_t  Pin4;
    uint8_t  Pin5;
    uint8_t  Pin6;
    float *tempArr;
    float *humArr;
    void Temperature(bool S = false, bool force = false);
    void Humidity(bool force = false);

  public:
    DHT6(int numDht,
         uint8_t type,
         uint8_t Pin1,
         uint8_t Pin2 = NONE,
         uint8_t Pin3 = NONE,
         uint8_t Pin4 = NONE,
         uint8_t Pin5 = NONE,
         uint8_t Pin6 = NONE
        );

    void begin();
    /*!
        @brief  Read temperature
        @param  S
                Scale. Boolean value:
     					- true = Fahrenheit
     					- false = Celcius
        @param  force
                true if in force mode
     	@return Temperature value in selected scale
    */
    float getMaxTemperature(bool S = false, bool force = false);
    float getMinTemperature(bool S = false, bool force = false);
    float getAvgTemperature(bool S = false, bool force = false);

    float getMaxHumidity(bool force = false);
    float getMinHumidity(bool force = false);
    float getAvgHumidity(bool force = false);

    ~DHT6() {
      delete[] sensors; // Освобождаем память
      delete[] tempArr;
      delete[] humArr;
    }

};

#endif // DHT6_H