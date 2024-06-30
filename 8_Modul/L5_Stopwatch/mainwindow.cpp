#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //иницилизация экземпляра класса watch
    watch = new Watch(this);
    //иницилизация textbrowser
    ui->setupUi(this);
    //иницилизация Label
    QFont font("Timer", 70);
    ui->lb_time->setFont(font);
    ui->lb_time->setText("00:00:00:000");
    //иницилизация textbrowser
    ui->tb_time->setFontPointSize(20);
    ui->tb_time->setText("Пройденые круги:");

    //иницилизация кнопок
    ui->pb_circle->setEnabled(false);
    ui->pb_start->setCheckable(true);
    ui->pb_start->setText("Старт");

    //connect-slot
    connect(watch, &Watch::sig_timeUpdated,this, &MainWindow::UpdateTime);

}

MainWindow::~MainWindow()
{
    delete ui;
}

//кнопка старт стоп
void MainWindow::on_pb_start_toggled(bool checked)
{
    if(checked){
        watch->start();
        ui->pb_start->setText("Стоп");
        ui->pb_circle->setEnabled(true);
    }
    else{
        watch->stop();
         ui->pb_start->setText("Старт");
         ui->pb_circle->setEnabled(false);

    }

}
//обновление времени в label
void MainWindow::UpdateTime(QString str)
{
    ui->lb_time->setText(str);
}

//кнопка круг
void MainWindow::on_pb_circle_clicked()
{
    ui->tb_time->append(watch->circle());
}

//кнопка очистки
void MainWindow::on_pb_clear_clicked()
{
    ui->lb_time->setText("00:00:00:000");
    ui->tb_time->setText("Пройденые круги:");
    watch->reset();
}

