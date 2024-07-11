#include "udpworker.h"

UDPworker::UDPworker(QObject *parent) : QObject(parent)
{

}

/*!
 * @brief Метод инициализирует UDP сервер
 */

void UDPworker::InitSocket()
{
    serviceUdpSocket = new QUdpSocket(this);
    serviceUdpSocketDZ = new QUdpSocket(this);
    /*
     * Соединяем присваиваем адрес и порт серверу и соединяем функцию
     * обраотчик принятых пакетов с сокетом
     */
    serviceUdpSocket->bind(QHostAddress::LocalHost, BIND_PORT);
    serviceUdpSocketDZ->bind(QHostAddress::LocalHost, BIND_PORT_DZ);
 //конект для time
    connect(serviceUdpSocket, &QUdpSocket::readyRead, this, [&]{
        this->readPendingDatagrams(serviceUdpSocket, typeUDP::timeUDP);
    });
//конект для Датаграм
    connect(serviceUdpSocketDZ, &QUdpSocket::readyRead, this, [&]{
        this->readPendingDatagrams(serviceUdpSocketDZ, typeUDP::textUDP);
    });
}

/*!
 * @brief Метод осуществляет обработку принятой датаграммы
 */
void UDPworker::ReadDatagram(QNetworkDatagram datagram, typeUDP type)
{

    QByteArray data;
    data = datagram.data();


    QDataStream inStr(&data, QIODevice::ReadOnly);

    switch (type){

    case timeUDP:{
    QDateTime dateTime;
    inStr >> dateTime;
    emit sig_sendTimeToGUI(dateTime);
    break;
    }

    case textUDP:{
        QString text;
        inStr >> text;
        emit sig_sendTextToGUI(text, datagram);
        break;
    }
    default: break;
    }
}
/*!
 * @brief Метод осуществляет опередачу датаграммы
 */
void UDPworker::SendDatagram(QByteArray data, typeUDP type )
{
    /*
     *  Отправляем данные на localhost и задефайненный порт
     */
    switch (type){
        case timeUDP:{
        serviceUdpSocket->writeDatagram(data, QHostAddress::LocalHost, BIND_PORT);
            break;
        }
        case textUDP:{
        serviceUdpSocketDZ->writeDatagram(data, QHostAddress::LocalHost, BIND_PORT_DZ);
            break;
        }
        default:
            break;

    }

}

/*!
 * @brief Метод осуществляет чтение датаграм из сокета
 */
void UDPworker::readPendingDatagrams(QUdpSocket* udpSocket, typeUDP type)
{
    /*
     *  Производим чтение принятых датаграмм
     */
    while(udpSocket->hasPendingDatagrams()){
            QNetworkDatagram datagram = udpSocket->receiveDatagram();
            ReadDatagram(datagram, type);
    }

}
