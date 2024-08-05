#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QSettings>
#include "ui_settings.h"
#include <QSettings>


namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = nullptr);
    ~Settings();

    void initSettings();
    void loadSettings();
    void saveSettings();

public slots:
    void on_bb_Box_accepted();
    void on_bb_Box_rejected();
    void on_def_Button_clicked();

signals:
    void sig_sendData(QVector<QString> data);

private:
    Ui::Settings *ui;
    QVector<QString> data;
    QSettings settings;
};

#endif // SETTINGS_H
