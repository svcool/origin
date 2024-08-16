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
    void clearGraph(QCustomPlot* cPlot);
    void updateGraph(QCustomPlot* cPlot, QList<QPair<int, int>> month_day, QVector<int> flCount);
    void updateGraphBars(QCustomPlot *cPlot, QVector<double> ticks, QVector<QString> labels, QVector<double> flCounts);
    void updateGraph(QCustomPlot* cPlot);
private:

    QCPGraph* ptrGraph;
    QCPBars* ptrGraphBars;
};

#endif // CP_GRAPHIC_H
