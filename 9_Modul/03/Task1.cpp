const int pot = A0;
const int windowSize = 10;
int adcValues[windowSize] = {0};  // Размер окна для фильтра скользящего среднего
int index = 0;                    // Текущий индекс в массиве
long sum = 0;                     // Сумма значений в окне
bool checkindex = false;
float avgValue = 0;

float calculateFilteredAngle(int adcValue) {

    if(sum != 0) sum -= adcValues[index];  // Удаление старого значения из суммы

    adcValues[index] = adcValue;    // Запись нового значения в массив и добавление его к сумме
    sum += adcValue;
    index = (index + 1) % windowSize;   // Инкрементирование индекса и сброс при достижении размера окна
    if(index == 0 && sum != 0) checkindex = true; //проверка заполняемости массива

    if (checkindex) {
        avgValue = static_cast<float>(sum) / windowSize; // Вычисляем среднее значение, если массив заполнен
    } else {
        avgValue = adcValue; // Делим на количество полученных данных
    }
   
    return ((avgValue - 512.0) / 512.0) * 135.0; // Преобразование среднего значения в угол
}

void setup() {
    Serial.begin(9600);            // Включаем последовательный порт
    analogReference(DEFAULT);      // Опорное напряжение 5В
}

void loop() {
    
    int adcValue = analogRead(pot);  

    float filteredAngle = calculateFilteredAngle(adcValue);

    // Вывод значения угла в градусах
    Serial.print("Значение без фильтра: ");
    Serial.print(adcValue);
    Serial.print(" Фильтр AVG: ");
    Serial.println(filteredAngle);

    delay(100); // Задержка
}
