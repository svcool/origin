#include "database.h"

DataBase::DataBase(QObject *parent)
    : QObject{parent}
{
    /*Выделяем память под объекты классов.
     *Объект QSqlDatabase является основным классом низкого уровня,
     *в котором настраивается подключение к БД.
    */
    dB = new QSqlDatabase;
    query = new QSqlQuery();
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
    delete query;
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
    data[hostName] = HOSTNAME;
    data[dbName] = DBNAME;
    data[login] = LOGIN;
    data[pass] = PASSWORD;
    data[port] = PORT;
    dB->setHostName(data[hostName]);
    dB->setDatabaseName(data[dbName]);
    dB->setUserName(data[login]);
    dB->setPassword(data[pass]);
    dB->setPort(data[port].toInt());


    bool status;
    status = dB->open( );
    emit sig_SendStatusConnection(status);

}

void DataBase::RequestToDB(QString request, qint32 numberRequest)
{
    *query = QSqlQuery(*dB);
    QSqlError err;
    if(numberRequest == 0){
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
    emit sig_SendStatusRequest(err, request, numberRequest);

}

void DataBase::ReadAnswerFromDB(QString request, quint32 numberRequest){
    switch (numberRequest) {

    case requestAirport:{
        //airportList.clear();
        while (query->next()) {
            QString airportName = query->value("airportName").toString();
            QString airportCode = query->value("airport_code").toString();
            airportList.append(qMakePair(airportName, airportCode));
        }

        emit sig_SendDataFromDBQueryForComboBox(airportList, numberRequest);

        break;
    }

    case requestArriving:{
        tableQueryMod->setQuery(request[requestArriving], *dB);
            //наименование столбцов
        // tableQueryMod->setHeaderData(0, Qt::Horizontal, QObject::tr("Название фильма"));
        // tableQueryMod->setHeaderData(1, Qt::Horizontal, QObject::tr("Описание фильма"));

        emit sig_SendDataFromDBQueryMod(tableQueryMod, numberRequest);
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

/*!
 * \brief Метод производит отключение от БД
 * \param Имя БД
 */
void DataBase::DisconnectFromDataBase(QString nameDb)
{

    if (dB->isOpen()) {
        dB->close();
        qDebug() << "Database" << nameDb << "closed";
    } else {
        qDebug() << "Database" << nameDb << "is not open";
    }

}

/*!
 * @brief Метод возвращает последнюю ошибку БД
 */
QSqlError DataBase::GetLastError()
{
    return dB->lastError();
}
