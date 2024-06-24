#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProgressBar>
//#include <QtGui>
//#include <QtCore>

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

    void on_cb_list_currentTextChanged(const QString &arg1);
    void updateStatusBar(const QString &text);
    void on_pushButton_toggled(bool checked);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QProgressBar *progressBar;
    uint32_t val = 0;
};
#endif // MAINWINDOW_H
