#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFont>
#include "watch.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_start_toggled(bool checked);
    void UpdateTime(QString str);
    void on_pb_circle_clicked();

    void on_pb_clear_clicked();

private:
    Ui::MainWindow *ui;
    Watch *watch;
};
#endif // MAINWINDOW_H
