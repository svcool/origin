#ifndef REQUEST_H
#define REQUEST_H
//Типы запросов
enum requestType : int {

    requestAirport = 0,
    requestArriving   = 1,
    requestDeparture = 2,
    requestStatisticsYear = 3,
    requestStatisticsDay = 4,
    NumberOfRequestTypes = 5
};

#endif // REQUEST_H
