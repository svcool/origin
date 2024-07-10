#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDataStream>
#include <QMessageBox>
#include <QtGlobal>
#include <QtConcurrent>
#include <QElapsedTimer>


//#include <algorithm>

///Подключаем все что нужно для графиков
#include <QLineSeries>
#include <QtCharts>
#include <QChartView>

#define FD 1000.0 //частота дискретизации

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //Метод считывает данные из исходного файла
    QVector<uint32_t> ReadFile(QString path, uint8_t numberChannel);
    //Метод преобразует данные физические величины, В?
    QVector<double> ProcessFile(QVector<uint32_t> dataFile);
    //Метод ищет Максимумы
    QVector<double> FindMax(QVector<double> resultData);
    //Метод ищет минимумы
    QVector<double> FindMin(QVector<double> resultData);
    //Метод отображает результаты
    void DisplayResult(QVector<double> mins, QVector<double> maxs);


public slots:
    void UpdateGraph();
    void on_pb_path_clicked();
    void on_pb_start_clicked();
signals:
    void sig_finish();


private slots:
    void on_cmB_numCh_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    QString pathToFile = "";
    uint8_t numberSelectChannel = 0xEA;

    QVector<double> resultDataTime;
    QElapsedTimer time;
    qint32 adjustedTime = 1000;

    QVector<uint32_t> readData;
    QVector<double> procesData;
    QVector<double> mins, maxs;

    QChart* chart;
    QChartView* chartView;
    QGridLayout *layout;
    QLineSeries* ptrGraph;

    QMainWindow *chartWindow; // Указатель на окно с графиком
};
#endif // MAINWINDOW_H
