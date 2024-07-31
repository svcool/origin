#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //Исходное состояние виджетов
    ui->setupUi(this);
    ui->lb_statusConnect->setStyleSheet("color:red");
    ui->pb_request->setEnabled(false);


    /*
     * Выделим память под необходимые объекты. Все они наследники
     * QObject, поэтому воспользуемся иерархией.
    */


    request.resize(NumberOfRequestTypes);
    request[requestAllFilms] = "film";

    request[requestComedy] = "SELECT f.flight_no, f.scheduled_arrival, ad.airport_name->>'ru' as \"Якутск\" "
                             "FROM bookings.flights f "
                             "JOIN bookings.airports_data ad ON ad.airport_code = f.departure_airport "
                             "WHERE f.arrival_airport = 'YKS'";




    request[requestHorrors] = "SELECT title, description "
                       "FROM film f "
                       "JOIN film_category fc ON f.film_id = fc.film_id "
                       "JOIN category c ON c.category_id = fc.category_id "
                       "WHERE c.name = 'Horror';";



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
     connect(dataBase, &DataBase::sig_SendDataFromDBTableMod, this, &MainWindow::ScreenDataFromDBTableMod);
     connect(dataBase, &DataBase::sig_SendDataFromDBQueryMod, this, &MainWindow::ScreenDataFromDBQueryMod);

    /*
     *  Сигнал для подключения к БД
     */
    connect(dataBase, &DataBase::sig_SendStatusConnection, this, &MainWindow::ReceiveStatusConnectionToDB);

}

MainWindow::~MainWindow()
{
    //DataBase::DisconnectFromDataBase
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
        ui->pb_request->setEnabled(false);
    }

}

/*!
 * \brief Обработчик кнопки "Получить"
 */
void MainWindow::on_pb_request_clicked()
{
    ui->pb_request->setEnabled(false);
    ui->pb_clear->setEnabled(false);
     //передаем запрос из вектора по индексу комбо бокса
    requestIndex = ui->cb_category->currentIndex();
    auto req = [&]{dataBase->RequestToDB(request[requestIndex], requestIndex);};
    (void)QtConcurrent::run(req);
}

/*!
 * \brief Слот отображает значение в QTableWidget
 * \param widget
 * \param typeRequest
 */
void MainWindow::ScreenDataFromDBTableMod(QSqlTableModel* tableTableMod)
{
    ui->tv_ableView->setModel(tableTableMod);
    // скрываем все столбцы
    for(int i = 0; i < tableTableMod->columnCount(); ++i) {
        ui->tv_ableView->setColumnHidden(i, true);
    }
    // Отображает нужные столбцы
    ui->tv_ableView->setColumnHidden(tableTableMod->fieldIndex("title"), false);
    ui->tv_ableView->setColumnHidden(2, false);
    ui->tv_ableView->setColumnHidden(3, false);
    //автоподбор ширины
    ui->tv_ableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //автоподбор ширины по содержимому столбца
    ui->tv_ableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);
    //включаем кнопки
    ui->pb_request->setEnabled(true);
    ui->pb_clear->setEnabled(true);
    //ui->tv_ableView->show();

}


void MainWindow::ScreenDataFromDBQueryMod(QSqlQueryModel* tableQueryMod, quint32 typeRequest){
    switch (typeRequest){
    case requestHorrors:{
        ui->tv_ableView->setModel(tableQueryMod);
        ui->tv_ableView->horizontalHeader()->setVisible(true); // Показать горизонтальные заголовки
        ui->tv_ableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); //растягиваем колонке по форме
       // ui->tv_ableView->show();
         break;
    }
    case requestComedy:{
        ui->tv_ableView->setModel(tableQueryMod);
        ui->tv_ableView->horizontalHeader()->setVisible(true); // Показать горизонтальные заголовки
        ui->tv_ableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        //ui->tv_ableView->show();

        break;

    }
    default:
        break;
    }
    //включаем кнопки
     ui->pb_request->setEnabled(true);
     ui->pb_clear->setEnabled(true);

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
        ui->pb_request->setEnabled(true);
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

void MainWindow::ReceiveStatusRequestToDB(QSqlError err, quint32 requestIndex)
{

    if(err.type() != QSqlError::NoError){
        msg->setText(err.text());
        msg->exec();
        //включаем кнопки
        ui->pb_request->setEnabled(true);
        ui->pb_clear->setEnabled(true);
    }
    else{

        dataBase->ReadAnswerFromDB(request, requestIndex);

    }

}


void MainWindow::on_pb_clear_clicked()
{
    dataBase->ClearForm();

}

