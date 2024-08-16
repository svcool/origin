#include "graphicwin.h"
#include "ui_graphicwin.h"

GraphicWin::GraphicWin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GraphicWin)
{
    ui->setupUi(this);
    ui->tabWidget->setCurrentIndex(0);
    //Создаем объект нашего класса
    graphClassYear = new CpGraphic(ui->cp_widget_1);
    graphClassMonth = new CpGraphic(ui->cp_widget_2);

}

GraphicWin::~GraphicWin()
{
    delete ui;
    delete graphClassYear;
    delete graphClassMonth;
}

void GraphicWin::graphicBuild()
{
    //обновить графики
    // graphClassYear->UpdateGraph(ui->cp_widget_1);
    //   graphClassMonth->UpdateGraph(ui->cp_widget_2);
}
//очистка графиков
void GraphicWin::graphicClear()
{
    graphClassYear->ClearGraph(ui->cp_widget_1);
    graphClassMonth->ClearGraph(ui->cp_widget_2);
}

void GraphicWin::addMonthsComboBox(){
    ui->cb_comboBox->clear();
    ui->cb_comboBox->addItems(months);
    ui->cb_comboBox->setCurrentIndex(0);

}

void GraphicWin::setLabel(const QString &text){

    QString newtext = text.section(':', 0, 0).trimmed();


    ui->lb_airport->setText(newtext);
}

void GraphicWin::ScreenDataFromDBQueryGraphic(QList<QPair<QDateTime, int>> data, int numberRequest)
{


}

void GraphicWin::FetchDataRequest(QList<QPair<QDateTime, int>> data, int numberRequest){
    switch(numberRequest){
    case requestStatisticsYear:{
        dataBars = data;
        GraphicWin::ScreenDataGraphicBars(dataBars);
    }
    case requestStatisticsDay:{
        dataLine = data;
        GraphicWin::ScreenDataGraphicLine(dataLine, 0);
    }
    }


}

void GraphicWin::ScreenDataGraphicLine(QList<QPair<QDateTime, int>> data, int index){
    QList<QPair<int, int>> x_month_day;//для линейного графика
    QVector<int> y_flCounts; //для линейного графика


    for (int i = 0; i < data.size(); ++i) {

        if (index == data[i].first.date().month()-1) {
            x_month_day.append(qMakePair(data[i].first.date().month(), data[i].first.date().day()));
            y_flCounts.append(data[i].second);
        }
    }
    graphClassMonth->UpdateGraph(ui->cp_widget_2, x_month_day, y_flCounts);
    // graphClassMonth->UpdateGraph(ui->cp_widget_2);
}

void GraphicWin::ScreenDataGraphicBars(QList<QPair<QDateTime, int>> data){
    QVector<double> ticks;
    QVector<QString> labels;
    QVector<double> flCounts;


    for (int i = 0; i < data.size(); ++i) {
        qDebug() << "Data:" << data[i].first.toString("dd MMM yyyy");
        ticks.append(i + 1);
        labels.append(data[i].first.toString("MMM yyyy"));
        flCounts.append(data[i].second);
    }
    graphClassYear->UpdateGraphBars(ui->cp_widget_1,ticks, labels, flCounts);
    // graphClassYear->UpdateGraphBars(ui->cp_widget_1);
}

void GraphicWin::on_cb_comboBox_currentIndexChanged(int index)
{
    GraphicWin::ScreenDataGraphicLine(dataLine, index);

}

