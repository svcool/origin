#ifndef SIGNALS_H
#define SIGNALS_H

#include <QObject>
#include <QDebug>

class Signals : public QObject
{
    Q_OBJECT

public:
    explicit Signals(QObject *parent = nullptr);
    ~Signals();
    void SendSignal();

public slots:




signals:
    void sig_SendSimpleSignal( );

    void sig_SendSignal(QString text);
    void sig_SendSignal(int num);

};



#endif // SIGNALS_H























//void SendSimpleSignal(void);
//void SendSignal(QString str);
//void SendSignal(int num);

//signals:

//void sig_simpleSignal( void );

//void sig_Signal(QString rcv);
//void sig_Signal(int num);


