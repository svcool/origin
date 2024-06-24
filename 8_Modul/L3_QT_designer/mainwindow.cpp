#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dialogWin = new Dialog(this);
    dialogWin->setWindowTitle("Подключение к БД");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->statusbar->showMessage("Подключение...",3000);
    dialogWin->show();
}

