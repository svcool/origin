#include "connect.h"
#include "ui_connect.h"

Connect::Connect(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Connect)
{
    ui->setupUi(this);

}

Connect::~Connect()
{
    delete ui;
}

void Connect::on_progressBar_valueChanged(int value)
{

}

