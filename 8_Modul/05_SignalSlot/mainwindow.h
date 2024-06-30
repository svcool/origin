#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "signals.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


public slots:
    void ReceiveSignal(QString str);
    void ReceiveSignal(int num);

private slots:




private:
    Ui::MainWindow *ui;
    Signals *sig;
    Signals *sig2;
};


#endif // MAINWINDOW_H
