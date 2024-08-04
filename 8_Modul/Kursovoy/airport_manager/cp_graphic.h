#ifndef CP_GRAPHIC_H
#define CP_GRAPHIC_H

#include <QObject>
#include "qcustomplot.h"

#define FIRST_GRAPH 0

class CpGraphic : public QObject
{
    Q_OBJECT

public:
    CpGraphic(QCustomPlot* cPlot);
    void AddDataToGrahp(QVector<double> x, QVector<double> y);
    void AddDataToGrahpBars(QVector<double> ticks, QVector<QString> labels, QVector<double> flCounts);
    void ClearGraph(QCustomPlot* cPlot);
    void UpdateGraph(QCustomPlot* cPlot, QList<QPair<int, int>> month_day, QVector<int> flCount);
    void UpdateGraphBars(QCustomPlot *cPlot, QVector<double> ticks, QVector<QString> labels, QVector<double> flCounts);
    void UpdateGraph(QCustomPlot* cPlot);
    void UpdateGraphBars(QCustomPlot *cPlot);
private:

    //Определияем указатель QCPGraph, который отвечает именно за наполнение графика.
    QCPGraph* ptrGraph;
    QCPBars* ptrGraphBars;
};

#endif // CP_GRAPHIC_H
