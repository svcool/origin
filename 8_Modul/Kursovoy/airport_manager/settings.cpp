#include "settings.h"
#include "database.h"
#include <QDebug>


Settings::Settings(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Settings)
{

    ui->setupUi(this);
    data.resize(NUM_DATA_FOR_CONNECT_TO_DB);
    settings = new QSettings("company","app");
    data[hostName] = HOSTNAME;
    data[dbName] = DBNAME;
    data[login] = LOGIN;
    data[pass] = PASSWORD;
    data[port] = PORT;
    qDebug() << "data size:" << data.size();
    for (int i = 0; i < data.size(); ++i) {
        qDebug() << "data[" << i << "]:" << data[i];
    }
    // ui->le_host->setText(data[hostName]);
    // ui->le_dbName->setText(data[dbName]);
    // ui->le_login->setText(data[login]);
    // ui->le_pass->setText(data[pass]);
    // ui->spB_port->setValue(QString(data[port]).toInt());

    // Подключение слотов к сигналам
    connect(ui->bb_Box, &QDialogButtonBox::accepted, this, &Settings::on_bb_Box_accepted);
    connect(ui->def_Button, &QPushButton::clicked, this, &Settings::on_def_Button_clicked);
}

Settings::~Settings()
{
    delete ui;
}

void Settings::initSettings()
{
    //проверка наличия ключа data
    if(!settings->contains("data")){
        data[hostName] = HOSTNAME;
        data[dbName] = DBNAME;
        data[login] = LOGIN;
        data[pass] = PASSWORD;
        data[port] = PORT;
        saveSettings();
    }
    else if (data.isEmpty()){
        //если настройки изменены, т.е. есть ключ загружаем
        loadSettings();
    }

    qDebug() << "settings pointer:" << settings;
    qDebug() << "data size:" << data.size();
    for (int i = 0; i < data.size(); ++i) {
        qDebug() << "data[" << i << "]:" << data[i];
    }

    if (!data.isEmpty()) {
        emit sig_sendData(data);
    } else {
        qDebug() << "Data vector is empty, not sending signal.";
    }
}

void Settings::loadSettings() {
    data = settings->value("data").value<QVector<QString>>();
}

void Settings::saveSettings() {
    settings->setValue("data",QVariant::fromValue(data));
}


void Settings::on_bb_Box_accepted()
{
    //Добавляем данные в контейнер
    data[hostName] = ui->le_host->text();
    data[dbName] = ui->le_dbName->text();
    data[login] = ui->le_login->text();
    data[pass] = ui->le_pass->text();
    data[port] = ui->spB_port->text();
    qDebug() << "settings pointer:" << settings;
    qDebug() << "data size:" << data.size();
    for (int i = 0; i < data.size(); ++i) {
        qDebug() << "data[" << i << "]:" << data[i];
    }
    Settings::saveSettings();
    Settings::initSettings();
}

// установка данных по умолчанию
void Settings::on_def_Button_clicked()
{
    ui->le_host->setText(HOSTNAME);
    ui->le_dbName->setText(DBNAME);
    ui->le_login->setText(LOGIN);
    ui->le_pass->setText(PASSWORD);
    ui->spB_port->setValue(QString(PORT).toInt());
}

