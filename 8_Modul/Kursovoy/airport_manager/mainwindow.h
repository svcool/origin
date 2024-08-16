#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtConcurrent>
#include <QSettings>
#include <QTimer>
#include "graphicwin.h"
#include "database.h"
#include "settings.h"
#include "request.h"
#include <QDateTime>
#include <QTimeZone>

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
    //void initializeSettings(); // Метод для инициализации настроек

    void initRequests();//иницилизация запросов
    void updateConnectionStatus(const QString &statusText);
    void tryingToConnect();//попытка подключения после иницилизации данных
    void processNextTask();
    void onTaskFinished();
    void disablesPushButtom(bool status);

public slots:
    void timeConnect(QVector<QString> receivData);
    void receiveStatusRequestToDB(QSqlError err, QVector<QString> request, int numberRequest);
    void screenDataFromDBQueryMod(QSqlQueryModel* tableQueryMod, int typeRequest);
    void screenDataFromDBQueryComboBox(QList<QPair<QString, QString>> airportList, int numberRequest);
    void receiveStatusConnectionToDB(bool status);
    void requestToDb(int numberRequest);
    void on_menu_settings_triggered();
    void on_pb_get_clicked();
    void openGraphiclWindow();

private slots:
    void on_dif_checkBox_clicked(bool checked);

private:
    Ui::MainWindow *ui;
    QMessageBox* msg;
    GraphicWin* graphicWin;
    QVector<QString> dataForConnect; // Данные для подключения
    DataBase* dataBase;
    QVector<QString> request; // Запросы
    QVector<QString> templrequest;//шаблонные запросы для редактирования
    QLabel* statusLabel;
    QTimer* timer;
    Settings* m_settings;//класс для настроек
    QQueue<int> taskQueue;  // Очередь запросов
    bool isProcessing = false;
    QFutureWatcher<void> futureWatcher;
    int offsetHours=0;
};
#endif // MAINWINDOW_H
