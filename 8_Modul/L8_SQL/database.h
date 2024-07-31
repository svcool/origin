#ifndef DATABASE_H
#define DATABASE_H

#include <QTableWidget>
#include <QObject>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QSqlTableModel>
#include <QSqlQuery>



#define POSTGRE_DRIVER "QPSQL"
#define DB_NAME "MyDB"

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

//Типы запросов
enum requestType{

    requestAirport = 0,
    requestArriving   = 1,
    requestDeparture = 2,
    requestStatisticsYear = 3,
    requestStatisticsDay = 4,
    NumberOfRequestTypes

};



class DataBase : public QObject
{
    Q_OBJECT

public:
    explicit DataBase(QObject *parent = nullptr);
    ~DataBase();

    void AddDataBase(QString driver, QString nameDB = "");
    void DisconnectFromDataBase(QString nameDb = "");
    void RequestToDB(QString request, quint32 requestIndex);
    QSqlError GetLastError(void);
    void ConnectToDataBase(QVector<QString> dataForConnect);
    void ReadAnswerFromDB(QString request, quint32 requestIndex);
    void ClearForm();

signals:

   void sig_SendStatusConnection(bool);
   void sig_sendData(QVector<QString> data); //сигнал для подключения БД
   void sig_SendDataFromDBQueryMod(QSqlQueryModel* tableQueryMod, qint32 numberRequest);
   void sig_SendStatusRequest(QSqlError err, QString request, qint32 requestIndex);
   void sig_SendDataFromDBQueryForComboBox(QList<QPair<QString, QString>> airportList, qint32 numberRequest);



private:

    QSqlDatabase* dB;
    QSqlQueryModel* tableQueryMod;
    QSqlQuery* query;
    QString airportName;
    QString airportCode;
    QList<QPair<QString, QString>> airportList;
};

#endif // DATABASE_H
