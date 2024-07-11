#ifndef UDPWORKER_H
#define UDPWORKER_H

#include <QUdpSocket>
#include <QNetworkDatagram>
#include <QDateTime>


#define BIND_PORT 12345
#define BIND_PORT_DZ 14321

enum typeUDP{
    timeUDP=0,
    textUDP=1
};


class UDPworker : public QObject
{
    Q_OBJECT
public:
    explicit UDPworker(QObject *parent = nullptr);
    void InitSocket();
    void ReadDatagram( QNetworkDatagram datagram, typeUDP type);
    void SendDatagram(QByteArray data, typeUDP type);


private slots:
    void readPendingDatagrams(QUdpSocket* udpSocket, typeUDP type);

private:
    QUdpSocket* serviceUdpSocket;
    QUdpSocket* serviceUdpSocketDZ;

signals:
    void sig_sendTimeToGUI(QDateTime data);
    void sig_sendTextToGUI(QString text, QNetworkDatagram &datagram);

};

#endif // UDPWORKER_H
