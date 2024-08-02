#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtConcurrent>
#include <QTimer>
#include <memory>
#include "graphic.h"
#include "database.h"


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


    void updateConnectionStatus(const QString &statusText);
    void tryingToConnect();//попытка подключения после иницилизации данных

public slots:
    void ReceiveStatusRequestToDB(QSqlError err, QVector<QString> request, int numberRequest);
    void ScreenDataFromDBQueryMod(QSqlQueryModel* tableQueryMod, quint32 typeRequest);
    void ScreenDataFromDBQueryComboBox(QList<QPair<QString, QString>> airportList, int numberRequest);
    void ReceiveStatusConnectionToDB(bool status);
    void requestToDb(int numberRequest);
    void on_pb_graphic_clicked();
    void on_pb_get_clicked();

    void openGraphiclWindow();
signals:


    void sig_RequestToDbAirports(int numberRequest);
    void sig_RequestToDb(int numberRequest);
private:
    Ui::MainWindow *ui;
    std::unique_ptr<QMessageBox> msg;
    std::unique_ptr<Graphic> graphicWin;
    QVector<QString> dataForConnect; // Данные для подключения
    std::unique_ptr<DataBase> dataBase;
    QVector<QString> request; // Запросы
    QVector<QString> templrequest;//шаблонные запросы для редактирования
    QLabel* statusLabel;
    std::unique_ptr<QTimer> timer;
    int numberRequest = 0;
};
#endif // MAINWINDOW_H
