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
    delete tableTableMod;
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
    //иницилизация QSqlTableModel, QSqlQueryModel
    tableTableMod = new QSqlTableModel(nullptr, *dB);//необходимо подключить базу через конструктор

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
    //для     QSqlQueryModel
    QSqlError err;

    if(requestIndex == 0){
        //выделяем память под QSqlTableModel

        DataBase::ClearForm();//очистка формы
        tableTableMod->setTable("film"); //выполняем запрос в конкретной базе
        tableTableMod->setEditStrategy(QSqlTableModel::OnManualSubmit);
        tableTableMod->select();


        if(tableTableMod->lastError().isValid()){

            err = tableTableMod->lastError();

        }

    }
    //для QSqlTableModel
    else {
        DataBase::ClearForm();//очистка формы
        tableQueryMod->setQuery(request, *dB); //выполняем запрос в конкретной базе

        if(tableQueryMod->lastError().isValid()){

            err = tableQueryMod->lastError();
        }

    }
    emit sig_SendStatusRequest(err, requestIndex);

}

void DataBase::ReadAnswerFromDB(QVector<QString> request, quint32 requestIndex){
    switch (requestIndex) {
    //Для наших запросов вид таблицы не поменяетя. Поэтому бужет единый обработчик.
    case requestAllFilms:{

        tableTableMod->setTable(request[requestAllFilms]);
        tableTableMod->setEditStrategy(QSqlTableModel::OnFieldChange);// Стратегия редактирования

        //наименование столбцов
        tableTableMod->setHeaderData(1, Qt::Horizontal, tr("Название фильма"));
        tableTableMod->setHeaderData(2, Qt::Horizontal, tr("Описание фильма"));
        tableTableMod->setHeaderData(3, Qt::Horizontal, tr("Год выпуска"));
        tableTableMod->select();
        emit sig_SendDataFromDBTableMod(tableTableMod);
        break;
    }

    case requestComedy:{
        tableQueryMod->setQuery(request[requestComedy], *dB);
         //наименование столбцов
        tableQueryMod->setHeaderData(0, Qt::Horizontal, QObject::tr("Название фильма"));
        tableQueryMod->setHeaderData(1, Qt::Horizontal, QObject::tr("Описание фильма"));

        emit sig_SendDataFromDBQueryMod(tableQueryMod, requestIndex);
        break;
    }

    case requestHorrors:{

        tableQueryMod->setQuery(request[requestHorrors], *dB);
        tableQueryMod->setHeaderData(0, Qt::Horizontal, QObject::tr("Название фильма"));
        tableQueryMod->setHeaderData(1, Qt::Horizontal, QObject::tr("Описание фильма"));

        emit sig_SendDataFromDBQueryMod(tableQueryMod, requestIndex);
        break;
    }

    default:
        break;
    }

}

void DataBase::ClearForm()
{
    if(tableQueryMod != nullptr){
      tableQueryMod->clear();
    }
    if(tableTableMod != nullptr){
    tableTableMod->clear();
         }
}

/*!
 * @brief Метод возвращает последнюю ошибку БД
 */
QSqlError DataBase::GetLastError()
{
    return dB->lastError();
}
