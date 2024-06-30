#include "signals.h"

Signals::Signals(QObject *parent)
    : QObject{parent}
{

}

Signals::~Signals()
{

}

void Signals::SendSignal()
{
   emit sig_SendSimpleSignal( );
   qDebug() << "Signal Emitted";
}






