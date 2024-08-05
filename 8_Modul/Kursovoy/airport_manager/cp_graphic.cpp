#include "cp_graphic.h"

CpGraphic::CpGraphic(QCustomPlot* cPlot)
{
    /*
    Выделяем память под объекты графиков. В конструкторе необходимо
    передать оси, по которым будет строиться график.
   */

   // ptrGraph = new QCPGraph(cPlot->xAxis, cPlot->yAxis);
    ptrGraphBars = new QCPBars(cPlot->xAxis, cPlot->yAxis);

    //В отличии от QtCharts QCustomPlot поддерживает встроенные функции масштабирования.
    cPlot->setInteraction(QCP::iRangeZoom, true);
    cPlot->setInteraction(QCP::iRangeDrag, true);
}

/*!
    @brief Метод добавляет данные на график
*/
void CpGraphic::AddDataToGrahp(QVector<double> x, QVector<double> y)
{
    //Добавляем данные на серию
    ptrGraph->addData(x,y);
}

void CpGraphic::AddDataToGrahpBars(QVector<double> ticks, QVector<QString> labels, QVector<double> flCounts)
{


}

/*!
    @brief Метод очищает данные хранящиеся в памяти графиков
*/
void CpGraphic::ClearGraph(QCustomPlot* cPlot)
{
    //Очищаем данные
    ptrGraph->data().clear();

    for(int i = 0; i< cPlot->graphCount(); i++){
        cPlot->graph(i)->data()->clear();
    }
    //Обновляем отображение графика
    cPlot->replot();

}

/*!
    @brief Слот обновляет отрисовку графика
*/

void CpGraphic::UpdateGraphBars(QCustomPlot *cPlot, QVector<double> ticks, QVector<QString> labels, QVector<double> flCounts){

    ptrGraphBars->setWidth(0.6);
    ptrGraphBars->setData(ticks, flCounts);
    ptrGraphBars->setPen(QPen(Qt::blue));
    ptrGraphBars->setBrush(QBrush(Qt::blue));


    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    cPlot->xAxis->setTicker(textTicker);
    cPlot->xAxis->setRange(0, 8);
    cPlot->xAxis->setTickLabelRotation(60);
    cPlot->xAxis->setSubTicks(false);
    cPlot->xAxis->setTickLength(0, 4);
    cPlot->xAxis->grid()->setVisible(true);
    cPlot->xAxis->setRange(0, ticks.size() + 1);

    cPlot->yAxis->setRange(0, *std::max_element(flCounts.begin(), flCounts.end()) + 10);
    cPlot->yAxis->setLabel("Flight Count");
    //Масштабируем оси
    //cPlot->rescaleAxes();
    //Отрисовываем график
    cPlot->replot();
}

void CpGraphic::UpdateGraph(QCustomPlot *cPlot)
{


    //Масштабируем оси
    cPlot->rescaleAxes();
    //Отрисовываем график
    cPlot->replot();

}

void CpGraphic::UpdateGraphBars(QCustomPlot *cPlot)
{


cPlot->replot();
}

void CpGraphic::UpdateGraph(QCustomPlot *cPlot, QList<QPair<int, int>> month_day, QVector<int> flCount){
    QVector<double> x ,y;
    int selectedMonth = 10;
    for (int i = 0; i < month_day.size(); ++i) {
            x.append(month_day[i].second);
            y.append(flCount[i]);
           // qDebug() << "x:" << month_day[i].second;
         //  qDebug() << "y:" << flCount[i];
    }

  cPlot->addGraph();
  cPlot->graph(0)->setData(x,y);

    cPlot->setInteraction(QCP::iRangeZoom, true);
    cPlot->setInteraction(QCP::iRangeDrag, true);
    cPlot->xAxis->setLabel("День месяца");
    cPlot->yAxis->setLabel("Количество вылетов");

    // Вычисляем максимальное значение на оси Y
    //double maxY = *std::max_element(y.begin(), y.end());
    //double yOffset = 10; // Смещение для оси Y
    //cPlot->yAxis->setRange(0, maxY + yOffset);
    cPlot->yAxis->ticker()->setTickCount(5);
    cPlot->xAxis->ticker()->setTickCount(31);
    cPlot->xAxis->setRange(1, 31); // Диапазон от 1 до 31 дня

  //  cPlot->yAxis->setRange(0, *std::max_element(y.begin(),y.end() + 10);





    //Масштабируем оси
    cPlot->rescaleAxes();
    //Отрисовываем график
    cPlot->replot();
}
