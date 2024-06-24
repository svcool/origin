#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "connect.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Dialog *ui;
    Connect *connectWin;
};

#endif // DIALOG_H
