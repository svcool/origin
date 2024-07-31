#include "database.h"

DataBase::DataBase(QObject *parent)
    : QObject{parent}
{
    /*Выделяем память под объекты классов.
     *Объект QSqlDatabase является основным классом низкого уровня,
     *в котором настраивается подключение к БД.
    */
    dB = new QSqlDatabase;
    tableQueryMod = new QSqlQueryModel();// база подключается в методе setQuery


}

DataBase::~DataBase()
{
    if (dB->isOpen()) {
        dB->close();
        qDebug() << "Database closed in destructor";
    }
    delete dB;
    delete tableQueryMod;
}

/*!
 * \brief Метод добавляет БД к экземпляру класса QSqlDataBase
 * \param driver драйвер БД
 * \param nameDB имя БД (Если отсутствует Qt задает имя по умолчанию)
 */
void DataBase::AddDataBase(QString driver, QString nameDB)
{

    *dB = QSqlDatabase::addDatabase(driver, nameDB);

}

/*!
 * \brief Метод подключается к БД
 * \param для удобства передаем контейнер с данными необходимыми для подключения
 * \return возвращает тип ошибки
 */
void DataBase::ConnectToDataBase(QVector<QString> data)
{

    dB->setHostName(data[hostName]);
    dB->setDatabaseName(data[dbName]);
    dB->setUserName(data[login]);
    dB->setPassword(data[pass]);
    dB->setPort(data[port].toInt());

    bool status;
    status = dB->open( );
    emit sig_SendStatusConnection(status);

}
/*!
 * \brief Метод производит отключение от БД
 * \param Имя БД
 */
void DataBase::DisconnectFromDataBase(QString nameDb)
{
   // QSqlDatabase db = QSqlDatabase::database(nameDb);
    if (dB->isOpen()) {
       dB->close();
        qDebug() << "Database" << nameDb << "closed";
    } else {
        qDebug() << "Database" << nameDb << "is not open";
    }

    // Remove the database connection to clean up
    //QSqlDatabase::removeDatabase(nameDb);

}
/*!
 * \brief Метод формирует запрос к БД.
 * \param request - SQL запрос
 * \return
 */
void DataBase::RequestToDB(QString request, quint32 requestIndex)
{
    *query = QSqlQuery(*dB);
    QSqlError err;
    if(requestIndex== 0){
        if(query->exec(request) == false){
            err = query->lastError();
        }
    }
    else {

        if(tableQueryMod != nullptr){
            //очистка формы
            tableQueryMod->clear();
            tableQueryMod->setQuery(request, *dB); //выполняем запрос в конкретной базе

            if(tableQueryMod->lastError().isValid()){

                err = tableQueryMod->lastError();
            }
        }
    }
    emit sig_SendStatusRequest(err, request, requestIndex);

}

void DataBase::ReadAnswerFromDB(QString request, quint32 requestIndex){
    switch (requestIndex) {

    case requestAirport:{
        //airportList.clear();
        while (query->next()) {
            QString airportName = query->value("airportName").toString();
            QString airportCode = query->value("airport_code").toString();
            airportList.append(qMakePair(airportName, airportCode));
        }

        emit sig_SendDataFromDBQueryForComboBox(airportList, requestIndex);

        break;
    }

    case requestArriving:{
        tableQueryMod->setQuery(request[requestArriving], *dB);
            //наименование столбцов
        // tableQueryMod->setHeaderData(0, Qt::Horizontal, QObject::tr("Название фильма"));
        // tableQueryMod->setHeaderData(1, Qt::Horizontal, QObject::tr("Описание фильма"));

        emit sig_SendDataFromDBQueryMod(tableQueryMod, requestIndex);
        break;
    }

        // case requestDeparture:{

        //     tableQueryMod->setQuery(request[requestDeparture], *dB);
        //     // tableQueryMod->setHeaderData(0, Qt::Horizontal, QObject::tr("Название фильма"));
        //     // tableQueryMod->setHeaderData(1, Qt::Horizontal, QObject::tr("Описание фильма"));

        //     emit sig_SendDataFromDBQueryMod(tableQueryMod, numberRequest);
        //     break;
        // }

        // case requestStatisticsYear:{

        //     tableQueryMod->setQuery(request[requestStatisticsYear], *dB);
        //     tableQueryMod->setHeaderData(0, Qt::Horizontal, QObject::tr("Название фильма"));
        //     tableQueryMod->setHeaderData(1, Qt::Horizontal, QObject::tr("Описание фильма"));

        //     emit sig_SendDataFromDBQueryMod(tableQueryMod, numberRequest);
        //     break;
        // }

        // case requestStatisticsDay:{

        //     tableQueryMod->setQuery(request[requestStatisticsDay], *dB);
        //     tableQueryMod->setHeaderData(0, Qt::Horizontal, QObject::tr("Название фильма"));
        //     tableQueryMod->setHeaderData(1, Qt::Horizontal, QObject::tr("Описание фильма"));

        //     emit sig_SendDataFromDBQueryMod(tableQueryMod, numberRequest);
        //     break;
        // }

    default:
        break;
    }

}

void DataBase::ClearForm()
{
    if(tableQueryMod != nullptr){
      tableQueryMod->clear();
    }
}

/*!
 * @brief Метод возвращает последнюю ошибку БД
 */
QSqlError DataBase::GetLastError()
{
    return dB->lastError();
}
