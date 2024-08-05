#ifndef GRAPHICWIN_H
#define GRAPHICWIN_H

#include <QDialog>
#include "request.h"
#include "cp_graphic.h"

//При использовании динамической библиотеки необходимо подключить заголовочный файл,
//но не добавлять его в проект.
//Типы запросов

namespace Ui {
class GraphicWin;
}

class GraphicWin : public QDialog
{
    Q_OBJECT

public:
    explicit GraphicWin(QWidget *parent = nullptr);
    ~GraphicWin();
    void graphicBuild();
    void graphicClear();
    void addMonthsComboBox();
    void ScreenDataFromDBQueryGraphic(QList<QPair<QDateTime, int>> statistic, int numberRequest);


    void ScreenDataGraphicLine(QList<QPair<QDateTime, int> > data, int index);
    void ScreenDataGraphicBars(QList<QPair<QDateTime, int> > data);
    void FetchDataRequest(QList<QPair<QDateTime, int> > data, int numberRequest);
    void setLabel(const QString &text);
private slots:


    void on_cb_comboBox_currentIndexChanged(int index);

private:
    Ui::GraphicWin *ui;
    QStringList months = {"Январь", "Февраль", "Март", "Апрель", "Май", "Июнь",
                          "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"};
    QCPGraph* graphic;
    CpGraphic* graphClassYear;
    CpGraphic* graphClassMonth;
    QList<QPair<QDateTime, int>> dataBars, dataLine;
    int numberMonth=0;
};

#endif // GRAPHICWIN_H
