#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <QDialog>

namespace Ui {
class Graphic;
}

class Graphic : public QDialog
{
    Q_OBJECT

public:
    explicit Graphic(QWidget *parent = nullptr);
    ~Graphic();

private:
    Ui::Graphic *ui;
};

#endif // GRAPHIC_H
