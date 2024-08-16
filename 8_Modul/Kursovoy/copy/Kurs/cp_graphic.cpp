#include "cp_graphic.h"

CpGraphic::CpGraphic(QCustomPlot* cPlot)
{
    /*
    Выделяем память под объекты графиков. В конструкторе необходимо
    передать оси, по которым будет строиться график.
   */

    ptrGraph = new QCPGraph(cPlot->xAxis, cPlot->yAxis);
    ptrGraphBars = new QCPBars(cPlot->xAxis, cPlot->yAxis);

    //В отличии от QtCharts QCustomPlot поддерживает встроенные функции масштабирования мышью.
    // cPlot->setInteraction(QCP::iRangeZoom, true);
    //  cPlot->setInteraction(QCP::iRangeDrag, true);
}

CpGraphic::~CpGraphic() {
   // delete ptrGraph;
  //  delete ptrGraphBars;
}


/*!
    @brief Метод очищает данные хранящиеся в памяти графиков
*/
void CpGraphic::ClearGraph(QCustomPlot* cPlot)
{
    //Очищаем данные
    ptrGraph->data().clear();
    cPlot->graph(0)->data()->clear();

    //Обновляем отображение графика
    cPlot->replot();

}

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
    auto maxY = *std::max_element(flCounts.begin(), flCounts.end());
    cPlot->yAxis->setRange(0, maxY + maxY/4);
    cPlot->yAxis->setLabel("Количество вылетов");

    CpGraphic::UpdateGraph(cPlot);
}

void CpGraphic::UpdateGraph(QCustomPlot *cPlot)
{
    //Масштабируем оси
    //cPlot->rescaleAxes();
    //Отрисовываем график
    cPlot->replot();
}


void CpGraphic::UpdateGraph(QCustomPlot *cPlot, QList<QPair<int, int>> month_day, QVector<int> flCount){

    QVector<double> day;
       QVector<double> flcount;
       double maxday = 0, maxflcount = 0;

       for (int i = 0; i < month_day.size(); ++i) {
           day.append(month_day[i].second);
           flcount.append(flCount[i]);

           if (month_day[i].second > maxday) {
               maxday = month_day[i].second;
           }

           if (flCount[i] > maxflcount) {
               maxflcount = flCount[i];
           }
       }

       ptrGraph->setData(day, flcount);
       cPlot->xAxis->setLabel("День месяца");
       cPlot->yAxis->setLabel("Количество вылетов");

       // Устанавливаем диапазон на оси Y с небольшим запасом сверху
       cPlot->yAxis->setRange(1, maxflcount + 3);

       // Настройка количества делений на оси Y
       int maxIntervals = 20;
       int tickCount = std::min(maxIntervals, static_cast<int>(maxflcount));

       // Используем QSharedPointer для настройки делений на оси Y
       QSharedPointer<QCPAxisTickerFixed> fixedTicker(new QCPAxisTickerFixed);
       fixedTicker->setTickStep(1.0); // Устанавливаем шаг равный 1 для целых чисел
       fixedTicker->setScaleStrategy(QCPAxisTickerFixed::ssMultiples); // Устанавливаем стратегию делений

       cPlot->yAxis->setTicker(fixedTicker);
       cPlot->yAxis->ticker()->setTickCount(tickCount);

       // Устанавливаем количество делений на оси X для дней месяца
       cPlot->xAxis->ticker()->setTickCount(31);
       cPlot->xAxis->setRange(1, maxday); // Диапазон от 1 до maxday

       // Добавляем графику заливку (опционально)
       cPlot->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20)));

    CpGraphic::UpdateGraph(cPlot);
}
