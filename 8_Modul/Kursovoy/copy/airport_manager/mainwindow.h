#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtConcurrent>
#include <QSettings>
#include <QTimer>
#include "graphic.h"
#include "database.h"
#include "settings.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void initializeSettings(); // Метод для инициализации настроек

    void ReceiveStatusRequestToDB(QSqlError err, qint32 numberRequest);

    void tryingToConnect();//попытка подключения после иницилизации данных

public slots:
    void ScreenDataFromDBQueryMod(QSqlQueryModel* tableQueryMod, quint32 typeRequest);
    void ScreenDataFromDBQueryComboBox(QList<QPair<QString, QString>> airportList, qint32 numberRequest);
    void ReceiveStatusConnectionToDB(bool status);
    void updateConnectionStatus(const QString &statusText);
    void requestToDb(qint32 numberRequest);
private slots:
    void on_menu_settings_triggered();
    void on_pb_graphic_clicked();
signals:
    void sig_RequestToDbAirports(qint32 numberRequest);
private:
    Ui::MainWindow *ui;
    QSettings settings;; //
    QMessageBox* msg;
    Graphic* graphicWin;
    Settings* m_settings;
    QVector<QString> dataForConnect; //данные для подключения
    DataBase* dataBase;
    QVector<QString> request;//запросы
    QLabel* statusLabel;
    QTimer *timer;
};
#endif // MAINWINDOW_H
