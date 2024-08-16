#ifndef GLOBAL_H
#define GLOBAL_H

//Типы запросов
enum requestType : int {

    requestAirport = 0,
    requestArriving   = 1,
    requestDeparture = 2,
    requestStatisticsYear = 3,
    requestStatisticsDay = 4,
    NumberOfRequestTypes = 5
};

#define POSTGRE_DRIVER "QPSQL"
#define DB_NAME "MyDB"

#define HOSTNAME "981757-ca08998.tmweb.ru"
#define DBNAME "demo"
#define LOGIN "netology_usr_cpp"
#define PASSWORD "CppNeto3"
#define PORT "5432"


#endif // GLOBAL_H
