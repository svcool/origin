#ifndef WATCH_H
#define WATCH_H

#include <QObject>
#include <QTimer>
#include <QElapsedTimer>
#include <QTime>


class Watch : public QObject
{
    Q_OBJECT
public:
    explicit Watch(QObject *parent = nullptr);

public slots:
    void start();
    void stop();
    void updateTime();
    QString circle();
    void reset();

signals:
    void sig_timeUpdated(const QString &text);

private:
    QTimer *timer; //таймер
    QTime *displaytime; // для формата hh:mm:ss:zzz
    QElapsedTimer time;//для расчет прошедшего времени
    qint64 m_timepause = 0; // пауза
    qint64 m_numbercircle = 0; //номер круга
    qint64 m_startcircle = 0; //начало следующего круга
    qint64 m_timecircle = 0; //расчетное время круга
};

#endif // WATCH_H
