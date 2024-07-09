#include "database.h"

DataBase::DataBase(QObject *parent)
    : QObject{parent}
{
    /*Выделяем память под объекты классов.
     *Объект QSqlDatabase является основным классом низкого уровня,
     *в котором настраивается подключение к БД.
    */
<<<<<<< HEAD
    view = new QTableView;
    dataBase = new QSqlDatabase;
    //Объект QSqlQueryModel отвечает за формирование запросов к БД
    tableQueryMod = new QSqlQueryModel;
    //QSqlTableModel необходим для формирования отображения ответа и передачи его в форму.
    tableTableMod = new QSqlTableModel;
=======
    dataBase = new QSqlDatabase;
    //Объект QSqlQueryModel отвечает за формирование запросов к БД
    tableQuery = new QSqlQueryModel;
    //QSqlTableModel необходим для формирования отображения ответа и передачи его в форму.
    tableSql = new QSqlTableModel;
>>>>>>> 1

}

DataBase::~DataBase()
{
    delete dataBase;
<<<<<<< HEAD
    delete tableQueryMod;
    delete tableTableMod;
=======
    delete tableQuery;
    delete tableSql;
>>>>>>> 1
}

/*!
 * \brief Метод добавляет БД к экземпляру класса QSqlDataBase
 * \param driver драйвер БД
 * \param nameDB имя БД (Если отсутствует Qt задает имя по умолчанию)
 */
void DataBase::AddDataBase(QString driver, QString nameDB)
{

    *dataBase = QSqlDatabase::addDatabase(driver, nameDB);

}

/*!
 * \brief Метод подключается к БД
 * \param для удобства передаем контейнер с данными необходимыми для подключения
 * \return возвращает тип ошибки
 */
void DataBase::ConnectToDataBase(QVector<QString> data)
{

    dataBase->setHostName(data[hostName]);
    dataBase->setDatabaseName(data[dbName]);
    dataBase->setUserName(data[login]);
    dataBase->setPassword(data[pass]);
    dataBase->setPort(data[port].toInt());


    ///Тут должен быть код ДЗ


    bool status;
    status = dataBase->open( );
    emit sig_SendStatusConnection(status);

}
/*!
 * \brief Метод производит отключение от БД
 * \param Имя БД
 */
void DataBase::DisconnectFromDataBase(QString nameDb)
{

    *dataBase = QSqlDatabase::database(nameDb);
    dataBase->close();

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
        tableTableMod->setTable(request);
        tableTableMod->select();

<<<<<<< HEAD
        if(tableTableMod->lastError().isValid()){
            err = tableTableMod->lastError();

        }

        emit sig_SendStatusRequest(err, requestIndex);


    }
    //для QSqlTableModel
    else {
        tableQueryMod->setQuery(request);

        if(tableQueryMod->lastError().isValid()){
            err = tableQueryMod->lastError();
        }

        emit sig_SendStatusRequest(err, requestIndex);

    }

}
=======
    /*  Для фоомирования запроса будем использовать
     *  объект QSqlQuery.
     *  В конструктор передадим адрес объекта QSqlDatabase
    */
    *tableQuery = QSqlQueryModel(*dataBase);
    /*
       Выполнение запроса выполняется при помощи
       метода exec. В случае успешного запроса он вернет true.
       Если возникает какая либо ошибка, ее можно посмотреть
       при помощи метода lastError. Этот метод возвращает
       экземпляр класса QSqlError.
    */
    QSqlError err;
    if(simpleQuery->exec(request) == false){
        err = simpleQuery->lastError();
    }

    emit sig_SendStatusRequest(err);





    ///Тут должен быть код ДЗ
>>>>>>> 1

void DataBase::ReadAnswerFromDB(QVector<QString> request, quint32 requestIndex){
    switch (requestIndex) {
    //Для наших запросов вид таблицы не поменяетя. Поэтому бужет единый обработчик.
    case requestAllFilms:{

        tableTableMod->setTable(request[requestAllFilms]);
        tableTableMod->select();
        tableTableMod->setEditStrategy(QSqlTableModel::OnFieldChange); // Стратегия редактирования
        tableTableMod->setHeaderData(0, Qt::Horizontal, tr("Name"));
        tableTableMod->setHeaderData(1, Qt::Horizontal, tr("Salary"));
        view->setModel(tableTableMod);
        view->setWindowTitle("Комедии и Ужасы");
        break;
    }

    case requestComedy:{
        tableQueryMod->setQuery(request[requestComedy]);
        tableQueryMod->setHeaderData(0, Qt::Horizontal, QObject::tr("Название фильма"));
        tableQueryMod->setHeaderData(1, Qt::Horizontal, QObject::tr("Описание фильма"));
        view->setModel(tableQueryMod);
        break;
    }

    case requestHorrors:{

        tableQueryMod->setQuery(request[requestHorrors]);
        tableQueryMod->setHeaderData(0, Qt::Horizontal, QObject::tr("Название фильма"));
        tableQueryMod->setHeaderData(1, Qt::Horizontal, QObject::tr("Описание фильма"));
        view->setModel(tableQueryMod);
        break;
    }

    default:
        break;
    }

    emit sig_SendDataFromDB(view, requestIndex);
}

/*!
 * @brief Метод возвращает последнюю ошибку БД
 */
QSqlError DataBase::GetLastError()
{
    return dataBase->lastError();
}
