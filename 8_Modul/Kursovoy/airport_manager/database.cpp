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

   // QSqlDatabase::removeDatabase(DB_NAME);
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

    *dB = QSqlDatabase::addDatabase(driver, nameDB.isEmpty() ? DB_NAME : nameDB);

}

/*!
 * \brief Метод подключается к БД
 * \param для удобства передаем контейнер с данными необходимыми для подключения
 * \return возвращает тип ошибки
 */
void DataBase::ConnectToDataBase(QVector<QString> data)
{
    if (data.size() != NUM_DATA_FOR_CONNECT_TO_DB) {
        qWarning() << "Invalid data for database connection";
        emit sig_SendStatusConnection(false);
        return;
    }

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


    bool status = dB->open();
    emit sig_SendStatusConnection(status);

}

void DataBase::RequestToDB(QVector<QString> request, int numberRequest) {
    qDebug() << "RequestToDB Received numberRequest:" << numberRequest;
    *query = QSqlQuery(*dB);
    QSqlError err;

    if(numberRequest == requestAirport || numberRequest == requestStatisticsYear || numberRequest == requestStatisticsDay){
        if(!query->exec(request[numberRequest])){
            err = query->lastError();
        }
    }
    else if(numberRequest == requestArriving || numberRequest == requestDeparture ) {

    if(tableQueryMod != nullptr){
        //очистка формы
        tableQueryMod->clear();
        tableQueryMod->setQuery(request[numberRequest], *dB); //выполняем запрос в конкретной базе

        if(tableQueryMod->lastError().isValid()){

            err = tableQueryMod->lastError();
        }
    }


    }
    emit sig_SendStatusRequest(err, request, numberRequest);

}

void DataBase::ReadAnswerFromDB(QVector<QString> request, int numberRequest){
    switch (numberRequest) {

    case requestAirport:{
        airportList.clear();
        while (query->next()) {
            QString airportName = query->value("airportName").toString();
            QString airportCode = query->value("airport_code").toString();
            airportList.append(qMakePair(airportName, airportCode));
        }

       emit sig_SendDataFromDBQueryForComboBox(airportList, numberRequest);

        break;
    }

    case requestArriving:{
        tableQueryMod->setQuery(request[requestDeparture], *dB);
        tableQueryMod->setHeaderData(0, Qt::Horizontal, QObject::tr("Номер рейса"));
        tableQueryMod->setHeaderData(1, Qt::Horizontal, QObject::tr("Время прилета"));
        tableQueryMod->setHeaderData(2, Qt::Horizontal, QObject::tr("Аэропорт назначения"));
        tableQueryMod->setQuery(request[numberRequest], *dB);

        emit sig_SendDataFromDBQueryMod(tableQueryMod, numberRequest);
        break;

    }

    case requestDeparture:{
        tableQueryMod->setQuery(request[requestDeparture], *dB);
        tableQueryMod->setHeaderData(0, Qt::Horizontal, QObject::tr("Номер рейса"));
        tableQueryMod->setHeaderData(1, Qt::Horizontal, QObject::tr("Время вылета"));
        tableQueryMod->setHeaderData(2, Qt::Horizontal, QObject::tr("Аэропорт назначения"));
        tableQueryMod->setQuery(request[numberRequest], *dB);

        emit sig_SendDataFromDBQueryMod(tableQueryMod, numberRequest);
        break;

    }


    case requestStatisticsYear:{
        //QList<QPair<QDateTime, int>> statYear;
        statYear.clear();
        while (query->next()) {
            QDateTime sYear = query->value("Month").toDateTime(); //из столбца "Month"
            int flightCountYear = query->value("count").toInt(); //из столбца "count"
            qDebug() << "Yar data:" << sYear << ":" << flightCountYear;
            statYear.append(qMakePair(sYear, flightCountYear));
        }

        emit sig_SendDataFromDBQueryForGraphic(statYear, numberRequest);
        break;
    }

    case requestStatisticsDay: {
       // QList<QPair<QDateTime, int>> statDay;
        statDay.clear();
        while (query->next()) {
            QDateTime sDay = query->value("Day").toDateTime(); //из столбца "Month"
            int flightCountDay = query->value("count").toInt(); //из столбца "count"
            qDebug() << "Yar data:" << sDay << ":" << flightCountDay;
            statDay.append(qMakePair(sDay, flightCountDay));
        }

        emit sig_SendDataFromDBQueryForGraphic(statDay, numberRequest);
        break;
    }

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
