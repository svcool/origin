#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {

    ui->setupUi(this);
    // Инициализация запросов к базе данных
    request.resize(NumberOfRequestTypes);
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

    connect(this,&MainWindow::sig_RequestToDbAirports, this, &MainWindow::requestToDb);
    connect(this,&MainWindow::sig_RequestToDb, this, &MainWindow::requestToDb);
    // Инициализация объектов
    graphicWin = new Graphic(this);
    dataBase = new DataBase(this);
    msg = new QMessageBox(this);
    timer = new QTimer(this);
    // Инициализация метки состояния подключения
    statusLabel = new QLabel(this);
    statusBar()->addWidget(statusLabel);
    updateConnectionStatus(tr("Отключено  "));

    // Добавление базы данных и её настройка
    dataBase->AddDataBase(POSTGRE_DRIVER, DB_NAME);

    // Получение данных для подключения
   connect(dataBase, &DataBase::sig_SendStatusConnection, this, &MainWindow::ReceiveStatusConnectionToDB);
    connect(dataBase, &DataBase::sig_SendStatusRequest, this, &MainWindow::ReceiveStatusRequestToDB);

    // Таймер для автоматического подключения к базе данных
    connect(timer, &QTimer::timeout, this, &MainWindow::tryingToConnect);

    dataForConnect.resize(NUM_DATA_FOR_CONNECT_TO_DB);

//Соединяем сигнал, который передает ответ от БД с методом, который отображает ответ в ПИ

    connect(dataBase, &DataBase::sig_SendDataFromDBQueryMod, this, &MainWindow::ScreenDataFromDBQueryMod);
    connect(dataBase, &DataBase::sig_SendDataFromDBQueryForComboBox, this, &MainWindow::ScreenDataFromDBQueryComboBox);

    tryingToConnect();
}

MainWindow::~MainWindow() {

    //delete dataBase;
    delete ui;
}

void MainWindow::updateConnectionStatus(const QString &statusText) {
    statusLabel->setText(statusText);
}

void MainWindow::tryingToConnect() {
    //timer->stop();
    updateConnectionStatus(tr("Подключение...     "));
    ui->statusbar->setStyleSheet("color:green");
    auto conn = [&]{ dataBase->ConnectToDataBase(dataForConnect); };
    (void)QtConcurrent::run(conn);
}

void MainWindow::on_pb_graphic_clicked() {
    graphicWin->show();
}

void MainWindow::ReceiveStatusConnectionToDB(bool status) {

    if (status) {
        updateConnectionStatus(tr("Подключено к БД  "));
        ui->statusbar->setStyleSheet("color:green");

        //emit sig_RequestToDbAirports(requestAirport);

    } else {
        dataBase->DisconnectFromDataBase(DB_NAME);
        msg->setIcon(QMessageBox::Critical);
        msg->setText(dataBase->GetLastError().text());
        updateConnectionStatus(tr("Отключено  "));
        ui->statusbar->setStyleSheet("color:red");
        msg->exec();
        //timer->start(5000);
    }
}





void MainWindow::ScreenDataFromDBQueryMod(QSqlQueryModel* tableQueryMod, quint32 typeRequest) {
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

void MainWindow::requestToDb(qint32 numberRequest)
{
    auto req = [&]{dataBase->RequestToDB(request[numberRequest], numberRequest);};
    (void)QtConcurrent::run(req);
}


void MainWindow::on_pb_get_clicked()
{
    //вылет
    if(ui->rb_arrival->isChecked()){
        emit sig_RequestToDb(requestArriving);
    }

    //прилет
    if(ui->rb_Departure->isChecked()){
        emit sig_RequestToDb(requestArriving);

    }

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
