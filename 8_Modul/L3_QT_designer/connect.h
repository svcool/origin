#ifndef CONNECT_H
#define CONNECT_H

#include <QDialog>

namespace Ui {
class Connect;
}

class Connect : public QDialog
{
    Q_OBJECT

public:
    explicit Connect(QWidget *parent = nullptr);
    ~Connect();

private slots:
    void on_progressBar_valueChanged(int value);

private:
    Ui::Connect *ui;
};

#endif // CONNECT_H
