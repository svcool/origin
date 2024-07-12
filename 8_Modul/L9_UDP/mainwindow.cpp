#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    udpWorker = new UDPworker(this);
    udpWorker->InitSocket();

    ui->pb_stop->setEnabled(false);

    connect(udpWorker, &UDPworker::sig_sendTimeToGUI, this, &MainWindow::DisplayTime);//для таймере
    connect(udpWorker, &UDPworker::sig_sendTextToGUI, this, &MainWindow::DisplayText);//для текста

    timer = new QTimer(this);
    //для таймере
    connect(timer, &QTimer::timeout, this, [&]{

        QDateTime dateTime = QDateTime::currentDateTime();

        QByteArray dataToSend;
        QDataStream outStr(&dataToSend, QIODevice::WriteOnly);

        outStr << dateTime;

        udpWorker->SendDatagram(dataToSend, typeUDP::timeUDP);
        timer->start(TIMER_DELAY);

    });
    //для текста
    connect(ui->pb_sendData, &QPushButton::clicked, this, [&]{

        QString text = ui->le_lineEdit->text();
        QByteArray dataToSend;
        QDataStream outStr(&dataToSend, QIODevice::WriteOnly);

        outStr << text;

        udpWorker->SendDatagram(dataToSend, typeUDP::textUDP);

    });

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_start_clicked()
{
    ui->pb_start->setEnabled(false);
    ui->pb_stop->setEnabled(true);
    timer->start(TIMER_DELAY);
}


void MainWindow::DisplayTime(QDateTime data)
{
    counterPck++;
    if(counterPck % 20 == 0){
        ui->te_result->clear();
    }

    ui->te_result->append("Текущее время: " + data.toString() + ". "
                "Принято пакетов " + QString::number(counterPck));


}

void MainWindow::DisplayText(QString data, QNetworkDatagram &datagram)
{

    datagram.data().size();
    ui->te_result->append("Принято сообщение от адресата:"
                          + datagram.senderAddress().toString() + ":" + QString::number(datagram.senderPort())+
                          ", размер сообщения(байт) " + QString::number(datagram.data().size()));


}

void MainWindow::on_pb_stop_clicked()
{
    timer->stop();
    ui->pb_stop->setEnabled(false);
    ui->pb_start->setEnabled(true);
}

