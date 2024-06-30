#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sig  = new Signals(this);
    ui->rb_simpleSig->setChecked(true);
    ui->le_str->setEnabled(false);
    ui->spB_num->setEnabled(false);


    connect(ui->rb_sendStr, &QRadioButton::clicked, this, [this]{
        ui->le_str->setEnabled(true);
        ui->spB_num->setEnabled(false);
    });
    connect(ui->rb_sendNum, &QRadioButton::clicked, this, [this]{
        ui->le_str->setEnabled(false);
        ui->spB_num->setEnabled(true);
    });
    connect(ui->rb_simpleSig, &QRadioButton::clicked, this, [this]{
        ui->le_str->setEnabled(false);
        ui->spB_num->setEnabled(false);
    });


    connect(ui->pb_sendSignal, &QPushButton::clicked, this, [this]{
        if(ui->rb_simpleSig->isChecked()){
            sig->SendSignal();
        }
        else if(ui->rb_sendStr->isChecked()){
            emit sig->sig_SendSignal(ui->le_str->text());
            //disconnect(sig, qOverload<QString>(&Signals::sig_SendSignal), this, qOverload<QString>(&MainWindow::ReceiveSignal));
        }
        else if(ui->rb_sendNum->isChecked()){
            emit sig->sig_SendSignal(ui->spB_num->value());
        }

    });

    connect(sig, &Signals::sig_SendSimpleSignal, this, [this]{

        qDebug() << "Signal receive";
        ui->tb_result->append("Принят простой сигнал!");

    });

    // enum ConnectionType {
    //     AutoConnection,  Если сигнал и слот находятся в одном потоке то DirectConnection, если в разных - QueuedConnection
    //     DirectConnection, управление переходит в слот сразу после вызова сигнала
    //     QueuedConnection, вызов слота ставится в очередь, слот вызывается при первой возможности
    //     BlockingQueuedConnection, блокирует текущий поток до завершения выполнения слота
    //     UniqueConnection =  0x80, битовая маска, соединение может быть установлено только один раз
    //     SingleShotConnection = 0x100, битовая маска, соединение может быть вызвано только один раз
    // };

    connect(sig, qOverload<QString>(&Signals::sig_SendSignal), this, qOverload<QString>(&MainWindow::ReceiveSignal));
    connect(sig, qOverload<int>(&Signals::sig_SendSignal), this, qOverload<int>(&MainWindow::ReceiveSignal));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ReceiveSignal(QString str)
{
    ui->tb_result->append(QString("Принят сигнал со строкой '%1'").arg(str));
}

void MainWindow::ReceiveSignal(int num)
{
    ui->tb_result->append(QString("Принят сигнал с числом '%1'").arg(num));
}

// void MainWindow::on_pb_sendSignal_clicked()
// {

// }
