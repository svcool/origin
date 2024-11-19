#include <SD.h>
#include <Stepper.h> //����������� ����������
const int stepsPerRevolution = 200; //���������� ����� �� ������
Stepper myStepper(stepsPerRevolution, 4, 5, 6, 7); //���������� �������� 7-4
const int CSPin = 10;
File root;
void setup()
{
  Serial.begin(115200);
  Serial.print("Initializing SD card... ");
  if (!SD.begin(CSPin)) //���� ������ �������������, �� ������������ ������
  {
    Serial.println("Card initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");
  myStepper.setSpeed(100);//��������
  //������ ������ �� �����
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