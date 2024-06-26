#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProgressBar>


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
    void on_pb_button_toggled(bool checked);

private:
    Ui::MainWindow *ui;
    QProgressBar *progressBar;
    uint32_t val = 0;
};
#endif // MAINWINDOW_H
