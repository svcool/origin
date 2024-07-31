#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //Исходное состояние виджетов
    ui->setupUi(this);
    ui->lb_statusConnect->setStyleSheet("color:red");


    request[requestAirport] = "SELECT airport_name->>'ru' as airportName, airport_code "
                              "FROM bookings.airports_data";

    request[requestArriving] = "SELECT f.flight_no, f.scheduled_arrival, ad.airport_name->>'ru' as \"Якутск\" "
                               "FROM bookings.flights f "
                               "JOIN bookings.airports_data ad ON ad.airport_code = f.departure_airport "
                               "WHERE f.arrival_airport = 'YKS'";

    request[requestDeparture] = "SELECT flight_no, scheduled_departure, ad.airport_name->>'ru' as \"Name\" "
                                "FROM bookings.flights f "
                                "JOIN bookings.airports_data ad on ad.airport_code = f.arrival_airport "
                                "WHERE f.departure_airport = 'YKS'";

    request[requestStatisticsYear] = "SELECT count(flight_no), date_trunc('month', scheduled_departure) as \"Month\" "
                                     "FROM bookings.flights f "
                                     "WHERE (scheduled_departure::date > date('2016-08-31') "
                                     "and scheduled_departure::date <= date('2017-08-31')) "
                                     "and (departure_airport = airportCode or arrival_airport = airportCode) "
                                     "GROUP BY \"Month\"";

    request[requestStatisticsDay] = "SELECT count(flight_no), date_trunc('day', scheduled_departure) as \"Day\" "
                                    "FROM bookings.flights f "
                                    "WHERE (scheduled_departure::date > date('2016-08-31') "
                                    "and scheduled_departure::date <= date('2017-08-31')) "
                                    "and (departure_airport = airportCode or arrival_airport = airportCode) "
                                    "GROUP BY \"Day\"";


    dataDb = new DbData(this);
    dataBase = new DataBase(this);
    msg = new QMessageBox(this);

    //Установим размер вектора данных для подключения к БД
    dataForConnect.resize(NUM_DATA_FOR_CONNECT_TO_DB);

    /*
     * Добавим БД используя стандартный драйвер PSQL и зададим имя.
    */
    dataBase->AddDataBase(POSTGRE_DRIVER, DB_NAME);

    /*
     * Устанавливаем данные для подключениея к БД.
     * Поскольку метод небольшой используем лямбда-функцию.
     */
    connect(dataDb, &DbData::sig_sendData, this, [&](QVector<QString> receivData){
        dataForConnect = receivData;
    });
    connect(dataBase, &DataBase::sig_SendStatusRequest, this, &MainWindow::ReceiveStatusRequestToDB);
    /*
     * Соединяем сигнал, который передает ответ от БД с методом, который отображает ответ в ПИ
     */
    connect(dataBase, &DataBase::sig_SendDataFromDBQueryMod, this, &MainWindow::ScreenDataFromDBQueryMod);
connect(dataBase, &DataBase::sig_SendDataFromDBQueryForComboBox, this, &MainWindow::ScreenDataFromDBQueryComboBox);
    /*
     *  Сигнал для подключения к БД
     */
    connect(dataBase, &DataBase::sig_SendStatusConnection, this, &MainWindow::ReceiveStatusConnectionToDB);

}

MainWindow::~MainWindow()
{

    delete ui;
}

/*!
 * @brief Слот отображает форму для ввода данных подключения к БД
 */
void MainWindow::on_act_addData_triggered()
{
    //Отобразим диалоговое окно. Какой метод нужно использовать?
    dataDb->show();
}

/*!
 * @brief Слот выполняет подключение к БД. И отображает ошибки.
 */

void MainWindow::on_act_connect_triggered()

{
    /*
     * Обработчик кнопки у нас должен подключаться и отключаться от БД.
     * Можно привязаться к надписи лейбла статуса. Если он равен
     * "Отключено" мы осуществляем подключение, если "Подключено" то
     * отключаемся
    */
    if(ui->lb_statusConnect->text() == "Отключено"){

       ui->lb_statusConnect->setText("Подключение");
       ui->lb_statusConnect->setStyleSheet("color : black");


       auto conn = [&]{dataBase->ConnectToDataBase(dataForConnect);};
       (void)QtConcurrent::run(conn);// void игнорируем возвращаемое значение QFuture, чтобы избежать предупреждения

    }
    else{
        dataBase->DisconnectFromDataBase(DB_NAME);
        ui->lb_statusConnect->setText("Отключено");
        ui->act_connect->setText("Подключиться");
        ui->lb_statusConnect->setStyleSheet("color:red");
    }

}

/*!
 * \brief Обработчик кнопки "Получить"
 */
void MainWindow::on_pb_request_clicked()
{

     //передаем запрос из вектора по индексу комбо бокса
    requestIndex =0;
    auto req = [&]{dataBase->RequestToDB(request[requestIndex], requestIndex);};
    (void)QtConcurrent::run(req);
}


void MainWindow::ScreenDataFromDBQueryMod(QSqlQueryModel* tableQueryMod, quint32 typeRequest){
    switch (typeRequest) {
    case requestAirport: {
        ui->tv_tableView->setModel(tableQueryMod);
        ui->tv_tableView->horizontalHeader()->setVisible(true);
        ui->tv_tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        break;
    }
    case requestArriving: {
        ui->tv_tableView->setModel(tableQueryMod);
        ui->tv_tableView->horizontalHeader()->setVisible(true);
        ui->tv_tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        break;
    }
    default:
        break;
    }

}
/*!
 * \brief Метод изменяет стотояние формы в зависимости от статуса подключения к БД
 * \param status
 */
void MainWindow::ReceiveStatusConnectionToDB(bool status)
{
    if(status){
        ui->act_connect->setText("Отключиться");
        ui->lb_statusConnect->setText("Подключено к БД");
        ui->lb_statusConnect->setStyleSheet("color:green");

    }
    else{
        dataBase->DisconnectFromDataBase(DB_NAME);
        msg->setIcon(QMessageBox::Critical);
        msg->setText(dataBase->GetLastError().text());
        ui->lb_statusConnect->setText("Отключено");
        ui->lb_statusConnect->setStyleSheet("color:red");
        msg->exec();
    }

}


void MainWindow::on_pb_clear_clicked()
{
    dataBase->ClearForm();

}

void MainWindow::ReceiveStatusRequestToDB(QSqlError err, QString request, qint32 requestIndex)
{

    if(err.type() != QSqlError::NoError){
        msg->setText(err.text());
        msg->exec();

    }

    else{

        dataBase->ReadAnswerFromDB(request, requestIndex);

    }

}

void MainWindow::ScreenDataFromDBQueryComboBox(QList<QPair<QString, QString>> airportList, qint32 numberRequest)
{
    if (airportList.isEmpty()) {
        qDebug() << "Airport list is empty. No items to add to comboBox.";
        return;
    }
    ui->cb_comboBox->clear(); // Очистка текущих элементов
    for (const auto &pair : airportList) {
        QString displayText = pair.first + " : " + pair.second;
        ui->cb_comboBox->addItem(displayText, pair.second);
    }

}


