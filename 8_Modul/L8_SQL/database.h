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

    requestAllFilms = 0,
    requestComedy   = 1,
    requestHorrors  = 2,
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
    void ReadAnswerFromDB(QVector<QString> request, quint32 requestIndex);
    void ClearForm();

signals:

   void sig_SendDataFromDBQueryMod(QSqlQueryModel* tableQueryMod, quint32 typeR);
   void sig_SendDataFromDBTableMod(QSqlTableModel* tableTableMod);
   void sig_SendStatusConnection(bool);
   void sig_SendStatusRequest(QSqlError err, quint32 requestIndex);


private:

    QSqlDatabase* dB;
    QSqlQueryModel* tableQueryMod;
    QSqlTableModel* tableTableMod;
};

#endif // DATABASE_H
