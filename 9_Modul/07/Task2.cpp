#include "menegmentStepEngine.h"
MenegmentStepEngine menegmentEngine; // ����������� �� ���������

void setup()
{

}

void loop()
{

  menegmentEngine.setStep(200);

  menegmentEngine.setSpeed(true, 3000);
  menegmentEngine.start();

  delay(1000); // �������� �������
  menegmentEngine.setSpeed(false, 1000);
  menegmentEngine.start();

  delay(1000); // �������� �������
}

