#include <SD.h>
#include <Stepper.h> //подключение библиотеки
const int stepsPerRevolution = 200; //количество шагов на оборот
Stepper myStepper(stepsPerRevolution, 4, 5, 6, 7); //управление выводами 7-4
const int CSPin = 10;
File root;
void setup()
{
  Serial.begin(115200);
  Serial.print("Initializing SD card... ");
  if (!SD.begin(CSPin)) //Если ошибка инициализации, то блокирование работы
  {
    Serial.println("Card initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");
  myStepper.setSpeed(100);//скорость
  //Пример чтения из файла
  File textFile = SD.open("wokwi.txt");
  if (textFile)
  {
    Serial.println("wokwi.txt");
    while (textFile.available()) {
      String line = textFile.readStringUntil('\n');
      int steps, direction, pause;

      sscanf(line.c_str(), "%d %d %d", &steps, &direction, &pause);

      Serial.print("Steps: ");
      Serial.print(steps);
      Serial.print(", Direction: ");
      Serial.print(direction == 0 ? "->" : "<-");
      Serial.print(", Pause: ");
      Serial.println(pause);
      if(direction != 0){
        steps = -steps;
      }
      myStepper.step(steps);
      delay(pause);
    }
    textFile.close();
  } else {
    Serial.println("error opening wokwi.txt!");
  }
}
void loop()
{


}