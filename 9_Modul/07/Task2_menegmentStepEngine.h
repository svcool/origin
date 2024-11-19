#ifndef MENEGEMENTSTEPENGINE_H
#define MENEGEMENTSTEPENGINE_H

class MenegmentStepEngine {
    const int _dirPin;
    const int _stepPin;
    int _stepsPerRevolution = 0;
    bool _rotation = 0;
    int _speed_time = 0;

  public:
    MenegmentStepEngine(const int dirPin = 2, const int stepPin = 3);

    void setSpeed(bool rotation, int speed_time);

    void setStep(int stepsPerRevolution);

    void start();

};

#endif // MENEGEMENTSTEPENGINE_H