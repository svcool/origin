#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <unistd.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , msg(std::make_unique<QMessageBox>(this))
    , graphicWin(std::make_unique<GraphicWin>(this))
    , dataBase(std::make_unique<DataBase>(this))
    , timer(std::make_unique<QTimer>(this))
{

    ui->setupUi(this);
    // Инициализация запросов к базе данных
    request.resize(NumberOfRequestTypes);


    request[requestAirport] = "SELECT airport_name->>'ru' as airportName, airport_code "
                              "FROM bookings.airports_data";

    request[requestArriving] = "SELECT f.flight_no, f.scheduled_arrival, ad.airport_name->>'ru' as \"Name\" "
                               "FROM bookings.flights f "
                               "JOIN bookings.airports_data ad ON ad.airport_code = f.departure_airport "
                               "WHERE f.arrival_airport = 'airportCode'";

    request[requestDeparture] = "SELECT flight_no, scheduled_departure, ad.airport_name->>'ru' as \"Name\" "
                                "FROM bookings.flights f "
                                "JOIN bookings.airports_data ad on ad.airport_code = f.arrival_airport "
                                "WHERE f.departure_airport = 'airportCode'";

    request[requestStatisticsYear] = "SELECT count(flight_no), date_trunc('month', scheduled_departure) as \"Month\" "
                                     "FROM bookings.flights f "
                                     "WHERE (scheduled_departure::date > date('2016-08-31') "
                                     "AND scheduled_departure::date <= date('2017-08-31')) "
                                     "AND (departure_airport = 'airportCode' or arrival_airport = 'airportCode') "
                                     "GROUP BY \"Month\"";

    request[requestStatisticsDay] = "SELECT count(flight_no), date_trunc('day', scheduled_departure) as \"Day\" "
                                    "FROM bookings.flights f "
                                    "WHERE (scheduled_departure::date > date('2016-08-31') "
                                    "AND scheduled_departure::date <= date('2017-08-31')) "
                                    "AND (departure_airport = 'airportCode' or arrival_airport = 'airportCode') "
                                    "GROUP BY \"Day\"";

    templrequest=request; //шаблонные запросы для редактирования
    connect(this,&MainWindow::sig_RequestToDbAirports, this, &MainWindow::requestToDb);
    connect(this,&MainWindow::sig_RequestToDb, this, &MainWindow::requestToDb);
    // Инициализация объектов

    // Инициализация метки состояния подключения
    statusLabel = new QLabel(this);
    statusBar()->addWidget(statusLabel);
    updateConnectionStatus(tr("Отключено  "));

    // Добавление базы данных и её настройка
    dataBase->AddDataBase(POSTGRE_DRIVER, DB_NAME);

    // Получение данных для подключения
    connect(dataBase.get(), &DataBase::sig_SendStatusConnection, this, &MainWindow::ReceiveStatusConnectionToDB);
    connect(dataBase.get(), &DataBase::sig_SendStatusRequest, this, &MainWindow::ReceiveStatusRequestToDB);


    // Таймер для автоматического подключения к базе данных
    //connect(timer, &QTimer::timeout, this, &MainWindow::tryingToConnect);

    dataForConnect.resize(NUM_DATA_FOR_CONNECT_TO_DB);

//Соединяем сигнал, который передает ответ от БД с методом, который отображает ответ в ПИ

    connect(dataBase.get(), &DataBase::sig_SendDataFromDBQueryMod, this, &MainWindow::ScreenDataFromDBQueryMod);
    connect(dataBase.get(), &DataBase::sig_SendDataFromDBQueryForComboBox, this, &MainWindow::ScreenDataFromDBQueryComboBox);
    connect(dataBase.get(), &DataBase::sig_SendDataFromDBQueryForGraphic, graphicWin.get(), &GraphicWin::FetchDataRequest);
//вызов окна с графиком
 connect(ui->pb_graphic, &QPushButton::clicked, this, &MainWindow::openGraphiclWindow);


    tryingToConnect();
}

MainWindow::~MainWindow() {
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






void MainWindow::openGraphiclWindow() {

    graphicWin->addMonthsComboBox();//обработка окна во вкладке месяц
    //запрос данных из БД

    request=templrequest;//копируем шаблон
    QString targetWord = "airportCode";
    QString newWord = ui->cb_comboBox->currentData().toString();
    ui->cb_comboBox->currentData();
    graphicWin->setWindowModality(Qt::ApplicationModal);

    qDebug() << "Received aitcod_openGraphiclWindow:" << newWord;
         //замена airportCode на код аэропорта
        request[requestStatisticsYear].replace(targetWord,newWord);
       // graphicWin->exec();
        QVector<QString> req1 = request;
        int rSY = requestStatisticsYear;
        qDebug() << "graphic Received numberRequest:" << request[requestStatisticsYear];
//        (void)QtConcurrent::run([this, req1, rSY]() {
//            dataBase->RequestToDB(req1, rSY);
//        });
        emit sig_RequestToDb(requestStatisticsYear);
        request[requestStatisticsDay].replace(targetWord,newWord);
        QVector<QString> req2 = request;
        int rSD = requestStatisticsDay;
        qDebug() << "graphic Received numberRequest:" << request[requestStatisticsDay];
//        (void)QtConcurrent::run([this, req2, rSD]() {
//            dataBase->RequestToDB(req2, rSD);
//        });
        sleep(2);
       emit sig_RequestToDb(requestStatisticsDay);

//         auto conrace1 = [this, req1, rSY]() {
//             dataBase->RequestToDB(req1, rSY);
//         };
//         auto conrace2 = [this, req2, rSD]() {
//             dataBase->RequestToDB(req2, rSD);
//         };

//         QtConcurrent::run(conrace1).then(conrace2);

        graphicWin->exec();



}

void MainWindow::ReceiveStatusConnectionToDB(bool status) {

    if (status) {
        updateConnectionStatus(tr("Подключено к БД  "));
        ui->statusbar->setStyleSheet("color:green");

        emit sig_RequestToDbAirports(requestAirport);

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





void MainWindow::ScreenDataFromDBQueryMod(QSqlQueryModel* tableQueryMod, int typeRequest) {
    switch (typeRequest) {
    case requestAirport:
    case requestArriving: {
        ui->tv_tableView->setModel(tableQueryMod);
        ui->tv_tableView->horizontalHeader()->setVisible(true);
        ui->tv_tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        break;
    }
    case requestDeparture: {
        ui->tv_tableView->setModel(tableQueryMod);
        ui->tv_tableView->horizontalHeader()->setVisible(true);
        ui->tv_tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        break;
    }
    default:
        break;
    }
}

void MainWindow::ScreenDataFromDBQueryComboBox(QList<QPair<QString, QString>> airportList, int numberRequest)
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

void MainWindow::requestToDb(int numberRequest)
{
    qDebug() << "Received numberRequest:" << numberRequest;
   // int numberReq=numberRequest;
    QVector<QString> req = request;
    // auto req = [&]{dataBase->RequestToDB(request, numberReq);}; // неправильно передает numberRequest
    // (void)QtConcurrent::run(req);
    (void)QtConcurrent::run([this, req, numberRequest]() {
        dataBase->RequestToDB(req, numberRequest);
    });
}


void MainWindow::on_pb_get_clicked()
{
    request[requestArriving]=templrequest[requestArriving];//копируем шаблон
    request[requestDeparture]=templrequest[requestDeparture];//копируем шаблон

    QString targetWord = "airportCode";
    QString newWord = ui->cb_comboBox->currentData().toString();

    QString startDate = ui->dtby_dateEdit->date().toString("yyyy-MM-dd");
    QString endDate = ui->dtfrom_dateEdit->date().toString("yyyy-MM-dd");
    qDebug() << "Received numberRequest:" << startDate;
    qDebug() << "Received numberRequest:" << endDate;

    //прилет
    if(ui->rb_arrival->isChecked()){
        //замена airportCode на код аэропорта
        request[requestArriving].replace(targetWord,newWord);
        request[requestArriving] += " AND f.scheduled_arrival BETWEEN '" + endDate + "' AND '" + startDate + "'";
         qDebug() << "Received numberRequest:" << request[requestArriving];
        emit sig_RequestToDb(requestArriving);
    }

    //вылет
    if(ui->rb_Departure->isChecked()){
        //замена airportCode на код аэропорта
        request[requestDeparture].replace(targetWord,newWord);
        request[requestDeparture] += " AND f.scheduled_arrival BETWEEN '" + endDate + "' AND '" + startDate + "'";
        qDebug() << "Received numberRequest:" << request[requestDeparture];
        emit sig_RequestToDb(requestDeparture);

    }

}

void MainWindow::ReceiveStatusRequestToDB(QSqlQuery query, QSqlError err, QVector<QString> request, int requestIndex)
{

    if(err.type() != QSqlError::NoError){
        msg->setText(err.text());
        msg->exec();

    }
    else{

        dataBase->ReadAnswerFromDB(query, request, requestIndex);

    }

}
