#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->cb_list->addItem("Тополь-М");
    ui->cb_list->addItem("Сармат");
    ui->cb_list->addItem("Булава 30");
    ui->cb_list->addItem("РС-24 Ярс");

    connect(ui->cb_list, SIGNAL(currentTextChanged(QString)), this, SLOT(updateStatusBar(QString)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

// Определение слота для обновления строки состояния
void MainWindow::updateStatusBar(const QString &text) {
    ui->statusbar->showMessage(text);
}
void MainWindow::on_cb_list_currentTextChanged(const QString &arg1)
{
  //  ui->statusbar->showMessage(QString("sdfsd '%1'").arg(arg1),3000);
}


void MainWindow::on_pushButton_toggled(bool checked)
{
  //  ui->cb_list->currentData();
    //ui->statusbar->showMessage(,3000);
}

