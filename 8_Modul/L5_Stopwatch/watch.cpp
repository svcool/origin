#include "watch.h"

Watch::Watch(QObject *parent)
    : QObject{parent}
{
    //иницилизация таймера
    displaytime = new QTime(0,0);
    timer = new QTimer(this);
    timer->setInterval(100);
    connect(timer, &QTimer::timeout, this, &Watch::updateTime);
}
//старт таймера
void Watch::start() {
    time.start();
    timer->start();
}

//остановка таймера
void Watch::stop() {
    m_timepause = time.elapsed();//сохраняем пройденое время
    m_startcircle = 0; //очистка времени слудующего круга
    timer->stop();
}

void Watch::reset(){
    m_numbercircle = 0;
    m_startcircle = 0;
    m_timepause = 0;
    time.restart();

}

//расчет времени круга с момента старта или остановки
QString Watch::circle() {
    ++m_numbercircle;// номер круга
    m_timecircle = time.elapsed() - m_startcircle; //время круга от начала отсчета
    m_startcircle = time.elapsed(); //сохраняем время для следующего круга
    QString text = "Круг " + QString::number(m_numbercircle) + ", время: ";
    text += (displaytime->addMSecs(m_timecircle)).toString("hh:mm:ss:zzz") + " сек.";
    return text;
}

void Watch::updateTime() {
    qint64 elapsed = time.elapsed() + m_timepause;//m_timepause добавление времени при остановке
    QString text = (displaytime->addMSecs(elapsed)).toString("hh:mm:ss:zzz");
    emit sig_timeUpdated(text);
}
