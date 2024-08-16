#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QTableWidget>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QSqlQuery>
#include <QDateTime>
#include "request.h"

#define POSTGRE_DRIVER "QPSQL"
#define DB_NAME "MyDB"

#define HOSTNAME "981757-ca08998.tmweb.ru"
#define DBNAME "demo"
#define LOGIN "netology_usr_cpp"
#define PASSWORD "CppNeto3"
#define PORT "5432"

//Количество полей данных необходимых для подключения к БД
#define NUM_DATA_FOR_CONNECT_TO_DB 5

//Перечисление полей данных
enum fieldsForConnect{
    hostName = 0,
    dbName = 1,
    login = 2,
    pass = 3,
    port = 4
};

// //Типы запросов
// enum requestType : int {

//     requestAirport = 0,
//     requestArriving   = 1,
//     requestDeparture = 2,
//     requestStatisticsYear = 3,
//     requestStatisticsDay = 4,
//     NumberOfRequestTypes = 5
// };



class DataBase : public QObject
{
    Q_OBJECT

public:
    explicit DataBase(QObject *parent = nullptr);
    ~DataBase();
public slots:
   // void DataForConnection(); //данные для подключения БД
    void AddDataBase(QString driver, QString nameDB = "");
    void DisconnectFromDataBase(QString nameDb = "");
    void RequestToDB(QVector<QString> request, int numberRequest);
    QSqlError GetLastError(void);
    void ConnectToDataBase(QVector<QString> dataForConnect);
    void ReadAnswerFromDB(QVector<QString> request, int numberRequest);

signals:
    void sig_sendData(QVector<QString> data); //сигнал для подключения БД
    void sig_SendDataFromDBQueryMod(QSqlQueryModel* tableQueryMod, int numberRequest);
    void sig_SendStatusConnection(bool);
    void sig_SendStatusRequest(QSqlError err, QVector<QString> request, int numberRequest);
    void sig_SendDataFromDBQueryForComboBox(QList<QPair<QString, QString>> airportList, int numberRequest);
    void sig_SendDataFromDBQueryForGraphic(QList<QPair<QDateTime, int>> statistic, int numberRequest);
private:

    QSqlDatabase* dB;
    QSqlQueryModel* tableQueryMod;
    QSqlQuery* query;
   // QString airportName;
   // QString airportCode;
    QList<QPair<QString, QString>> airportList;
   // QDateTime sYear, sDay;
    //int flightCountYear, flightCountDay;
   QList<QPair<QDateTime, int>> statYear;
   QList<QPair<QDateTime, int>> statDay;
    //int numberRequest = 0;
};

#endif // DATABASE_H
