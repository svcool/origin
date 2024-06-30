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
    ui->rb_off->setText("Запретить запуск");
     ui->rb_on->setText("Разрешить запуск");
   // ui->pb_button->toggle();
    ui->pb_button->setCheckable(true);
    ui->pb_button->setText("ПУСК");
    ui->label->setText("Выбор типа ракеты:");
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



void MainWindow::on_pb_button_toggled(bool checked)
{
    if (checked) {
        if(ui->rb_off->isChecked()) {
            ui->statusbar->showMessage("Запуск запрещен!!!");
            return;
        }

        QString newText = ui->cb_list->currentText();

        if(ui->rb_on->isChecked()){

            if(progressBar->value()!=10 ){
                 progressBar->setStyleSheet(QString()); //вернуть цвет бара
                progressBar->setFormat(QString());//вернуть формат
                progressBar->setValue(++val);
                newText += " летит....";
                ui->statusbar->showMessage(newText);
            }
            else{
                newText += " прилетел:(";
                ui->statusbar->showMessage(newText);
                // установка формата цвета прогресс бара
                progressBar->setValue(0);
                progressBar->setFormat("Бабам!!!");
                progressBar->setStyleSheet("QProgressBar{border: 1px solid transparent;text-align: center;"
                                           "color:rgba(255,255,250,255);"
                                           "background-color: red;"
                                           "}"
                                           );
                val = 0;
            }

        }
        else {
            ui->statusbar->showMessage("Не выбрана команда!");

        }

    } else {
        // Код для состояния "выключено"
    }
}




