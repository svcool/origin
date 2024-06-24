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

    progressBar = new QProgressBar(this);
    ui->statusbar->addPermanentWidget(progressBar);
    progressBar->setMinimum(0);
    progressBar->setMaximum(10);


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


void MainWindow::on_pushButton_clicked()
{
QString newText = ui->cb_list->currentText();
 if(progressBar->value()!=10){
    progressBar->setStyleSheet(QString());
    ui->progressBar->setFormat(QString());
    progressBar->setValue(++val);
    newText += " летит....";
   ui->statusbar->showMessage(newText);
 }
 else{
     newText += " прилетел:(";
    ui->statusbar->showMessage(newText);

     progressBar->setValue(0);
     progressBar->setFormat("              Бабам!!!");
     progressBar->setStyleSheet("background: red; border: 1px solid black;");
     val = 0;
 }


}

