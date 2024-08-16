#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initRequests(); //иницилизация запросов

    // Инициализация объектов
    QSettings settings("Company", "App");
    msg = new QMessageBox(this);
    graphicWin = new GraphicWin(this);
    dataBase = new DataBase(this);
    timer = new  QTimer(this);
    connect(&futureWatcher, &QFutureWatcher<void>::finished, this, &MainWindow::processNextTask);
    m_settings = new Settings(this);
    ui->dtby_dateEdit->setDisabled(true);

    // Инициализация метки состояния подключения
    statusLabel = new QLabel(this);
    statusBar()->addWidget(statusLabel);
    updateConnectionStatus(tr("Отключено  "));

    // Добавление базы данных и её настройка
    dataBase->addDataToBase(POSTGRE_DRIVER, DB_NAME);

    // Получение данных для подключения
    connect(dataBase, &DataBase::sig_SendStatusConnection, this, &MainWindow::receiveStatusConnectionToDB);
    connect(dataBase, &DataBase::sig_SendStatusRequest, this, &MainWindow::receiveStatusRequestToDB);

    // Таймер для автоматического подключения к базе данных
    connect(timer, &QTimer::timeout, this, &MainWindow::tryingToConnect, Qt::DirectConnection);

    dataForConnect.resize(NUM_DATA_FOR_CONNECT_TO_DB);

    connect(m_settings, &Settings::sig_sendData, this, &MainWindow::timeConnect, Qt::DirectConnection);
    connect(dataBase, &DataBase::sig_SendDataFromDBQueryMod, this, &MainWindow::screenDataFromDBQueryMod);
    connect(dataBase, &DataBase::sig_SendDataFromDBQueryForComboBox, this, &MainWindow::screenDataFromDBQueryComboBox);
    connect(dataBase, &DataBase::sig_SendDataFromDBQueryForGraphic, graphicWin, &GraphicWin::fetchDataRequest);
    //вызов окна с графиком
    connect(ui->pb_graphic, &QPushButton::clicked, this, &MainWindow::openGraphiclWindow);

    //отключаем кнопки
    disablesPushButtom(false);

    m_settings->initSettings();
}

void MainWindow::initRequests() {
    request.resize(NumberOfRequestTypes);

    request[requestAirport] = "SELECT airport_name->>'ru' as airportName, airport_code "
                              "FROM bookings.airports_data";

    request[requestArriving] = "SELECT f.flight_no, f.scheduled_arrival AT TIME ZONE 'Europe/Moscow' AS scheduled_arrival_local, ad.airport_name->>'ru' as \"Name\" "
                               "FROM bookings.flights f "
                               "JOIN bookings.airports_data ad ON ad.airport_code = f.departure_airport "
                               "WHERE f.arrival_airport = 'airportCode'";

    request[requestDeparture] = "SELECT flight_no, scheduled_departure AT TIME ZONE 'Europe/Moscow' AS scheduled_arrival_local, ad.airport_name->>'ru' as \"Name\" "
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

    templrequest = request;
}


MainWindow::~MainWindow() {
    m_settings->saveSettings();
    delete ui;
}


void MainWindow::timeConnect(QVector<QString> receivData){
    timer->stop();
    dataBase->disconnectFromDataBase(DB_NAME);
    updateConnectionStatus(tr("Отключено  "));
    ui->statusbar->setStyleSheet("color:red");
    dataForConnect = receivData;
    receivData.clear();
    timer->start(5000);
}


void MainWindow::updateConnectionStatus(const QString &statusText) {
    statusLabel->setText(statusText);
}

void MainWindow::tryingToConnect() {
    timer->stop();
    updateConnectionStatus(tr("Подключение...     "));
    ui->statusbar->setStyleSheet("color:green");
    auto conn = [&]{ dataBase->connectToDataBase(dataForConnect); };
    (void)QtConcurrent::run(conn);
}


void MainWindow::openGraphiclWindow() {

    graphicWin->addMonthsComboBox();//обработка окна во вкладке месяц
    graphicWin->setLabel(ui->cb_comboBox->currentText());
    //запрос данных из БД
    request=templrequest;//копируем шаблон
    QString targetWord = "airportCode";
    QString newWord = ui->cb_comboBox->currentData().toString();
    ui->cb_comboBox->currentData();
    graphicWin->setWindowModality(Qt::ApplicationModal);
        //замена airportCode на код аэропорта
    request[requestStatisticsYear].replace(targetWord,newWord);
    requestToDb(requestStatisticsYear);

    request[requestStatisticsDay].replace(targetWord,newWord);

    requestToDb(requestStatisticsDay);

    graphicWin->exec();
}

void MainWindow::receiveStatusConnectionToDB(bool status) {

    if (status) {
        updateConnectionStatus(tr("Подключено к БД  "));
        ui->statusbar->setStyleSheet("color:green");
        requestToDb(requestAirport);

    } else {
        dataBase->disconnectFromDataBase(DB_NAME);
        msg->setIcon(QMessageBox::Critical);
        msg->setText(dataBase->getLastError().text());
        updateConnectionStatus(tr("Отключено  "));
        ui->statusbar->setStyleSheet("color:red");
        msg->exec();
        timer->start(5000);
    }
}

void MainWindow::screenDataFromDBQueryMod(QSqlQueryModel* tableQueryMod, int typeRequest) {
    switch (typeRequest) {
    case requestAirport:
    case requestArriving: {
        ui->tv_tableView->setModel(tableQueryMod);
        ui->tv_tableView->horizontalHeader()->setVisible(true);
        ui->tv_tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        disablesPushButtom(true);
        break;
    }
    case requestDeparture: {
        ui->tv_tableView->setModel(tableQueryMod);
        ui->tv_tableView->horizontalHeader()->setVisible(true);
        ui->tv_tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        disablesPushButtom(true);
        break;
    }
    default:
        break;
    }
}

void MainWindow::screenDataFromDBQueryComboBox(QList<QPair<QString, QString>> airportList, int numberRequest)
{
    if (airportList.isEmpty()) {
        qDebug() << "Airport list is empty. No items to add to comboBox.";
        return;
    }
    ui->cb_comboBox->clear();
    for (const auto &pair : airportList) {
        QString displayText = pair.first + " : " + pair.second;
        ui->cb_comboBox->addItem(displayText, pair.second);
        disablesPushButtom(true);
    }

}


void MainWindow::on_pb_get_clicked()
{
    disablesPushButtom(false);
    request[requestArriving]=templrequest[requestArriving];
    request[requestDeparture]=templrequest[requestDeparture];

    QString targetWord = "airportCode";
    QString newWord = ui->cb_comboBox->currentData().toString();

    QString startDate = ui->dtby_dateEdit->date().toString("yyyy-MM-dd");
    QString endDate = ui->dtfrom_dateEdit->date().toString("yyyy-MM-dd");
    //если выбран диапазон испльзуем только первую дату
    if(ui->dif_checkBox->isChecked() == false){
        startDate = endDate;
    }

    //прилет
    if(ui->rb_arrival->isChecked()){
        request[requestArriving].replace(targetWord,newWord);

        request[requestArriving] += " AND f.scheduled_arrival AT TIME ZONE 'Europe/Moscow' BETWEEN '" + endDate + " 00:00:00' AND '" + startDate + " 23:59:59'";
        requestToDb(requestArriving);
    }

    //вылет
    if(ui->rb_Departure->isChecked()){
        request[requestDeparture].replace(targetWord,newWord);

        request[requestDeparture] += " AND f.scheduled_arrival AT TIME ZONE 'Europe/Moscow' BETWEEN '" + endDate + " 00:00:00' AND '" + startDate + " 23:59:59'";
        requestToDb(requestDeparture);

    }

}

void MainWindow::receiveStatusRequestToDB(QSqlError err, QVector<QString> request, int requestIndex)
{

    if(err.type() != QSqlError::NoError){
        msg->setText(err.text());
        msg->exec();

    }
    else{

        dataBase->readAnswerFromDB(request, requestIndex);

    }

}


void MainWindow::requestToDb(int numberRequest) {
    // Добавляем запрос в очередь
    taskQueue.enqueue(numberRequest);

    // Если ничего не обрабатывается, запускаем обработку очереди
    if (!isProcessing) {
        isProcessing = true;
        processNextTask();
    }

}


void MainWindow::processNextTask() {
    if (taskQueue.isEmpty()) {
        isProcessing = false;
        return;
    }

    // Извлекаем следующий запрос из очереди
    int numberRequest = taskQueue.dequeue();

    QVector<QString> req = request;

    // Выполняем запрос в отдельном потоке
    QFuture<void> future = QtConcurrent::run([this, req, numberRequest]() {
        dataBase->requestToDB(req, numberRequest);
    });

    futureWatcher.setFuture(future);

    // Обработчик завершения задачи
    connect(&futureWatcher, &QFutureWatcher<void>::finished, this, &MainWindow::processNextTask);
}

void MainWindow::disablesPushButtom(bool status){
    ui->pb_get->setEnabled(status);
    ui->pb_graphic->setEnabled(status);

}

void MainWindow::on_menu_settings_triggered() {
    m_settings->show();
}

void MainWindow::on_dif_checkBox_clicked(bool checked)
{
    if(checked){
        ui->dtby_dateEdit->setDisabled(false);
    }
    else{
        ui->dtby_dateEdit->setDisabled(true);
    }


}


