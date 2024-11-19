#include <Stepper.h> //подключение библиотеки
const int stepsPerRevolution = 200; //количество шагов на оборот
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11); //управление выводами 8 - 11

//текущее состояние кнопок
volatile bool start_stop = false;
volatile bool left_right = false;

const int but_stop_start = 3; // кнопка старт/стоп
const int but_left_right = 2; // кнопка вращения
volatile int rotation = 1;

void setup()
{
myStepper.setSpeed(100); //установка скорости
pinMode(but_left_right , INPUT_PULLUP); // подтягивающий резистор на входе прерывания
pinMode(but_stop_start, INPUT_PULLUP); // подтягивающий резистор на входе прерывания
attachInterrupt(1, step_start_stop, FALLING); //разрешение внешнего прерывания (вывод 2 Arduino UNO)
attachInterrupt(0, step_rotation, FALLING); //разрешение внешнего прерывания (вывод 3 Arduino UNO)
}
void loop()
{
  if(start_stop){
  myStepper.step(rotation * (stepsPerRevolution / 100));
  }
}

//Функция обработки внешнего прерывания
void step_rotation()
{
  if(rotation == 1){
    rotation = -1;
  }
  else{
    rotation = 1;
  }
}

void step_start_stop()
{
start_stop = !start_stop;
}