/********************************************************************************
** Form generated from reading UI file 'graphic.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHIC_H
#define UI_GRAPHIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Graphic
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *lb_airport;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QWidget *gr_yearwidget;
    QWidget *tab_2;
    QGridLayout *gridLayout_3;
    QLabel *lb_month;
    QComboBox *comboBox;
    QWidget *gr_monwidget;
    QPushButton *pb_close;

    void setupUi(QDialog *Graphic)
    {
        if (Graphic->objectName().isEmpty())
            Graphic->setObjectName("Graphic");
        Graphic->resize(834, 591);
        gridLayout = new QGridLayout(Graphic);
        gridLayout->setObjectName("gridLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(Graphic);
        label->setObjectName("label");
        label->setMaximumSize(QSize(100, 16777215));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);

        horizontalLayout_2->addWidget(label);

        lb_airport = new QLabel(Graphic);
        lb_airport->setObjectName("lb_airport");
        lb_airport->setFont(font);

        horizontalLayout_2->addWidget(lb_airport);


        verticalLayout->addLayout(horizontalLayout_2);

        tabWidget = new QTabWidget(Graphic);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setTabShape(QTabWidget::Triangular);
        tab = new QWidget();
        tab->setObjectName("tab");
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setObjectName("gridLayout_2");
        gr_yearwidget = new QWidget(tab);
        gr_yearwidget->setObjectName("gr_yearwidget");

        gridLayout_2->addWidget(gr_yearwidget, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        gridLayout_3 = new QGridLayout(tab_2);
        gridLayout_3->setObjectName("gridLayout_3");
        lb_month = new QLabel(tab_2);
        lb_month->setObjectName("lb_month");
        lb_month->setMaximumSize(QSize(50, 16777215));

        gridLayout_3->addWidget(lb_month, 0, 0, 1, 1);

        comboBox = new QComboBox(tab_2);
        comboBox->setObjectName("comboBox");

        gridLayout_3->addWidget(comboBox, 0, 1, 1, 1);

        gr_monwidget = new QWidget(tab_2);
        gr_monwidget->setObjectName("gr_monwidget");

        gridLayout_3->addWidget(gr_monwidget, 1, 0, 1, 2);

        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        pb_close = new QPushButton(Graphic);
        pb_close->setObjectName("pb_close");

        verticalLayout->addWidget(pb_close);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(Graphic);
        QObject::connect(pb_close, &QPushButton::clicked, Graphic, qOverload<>(&QDialog::close));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Graphic);
    } // setupUi

    void retranslateUi(QDialog *Graphic)
    {
        Graphic->setWindowTitle(QCoreApplication::translate("Graphic", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Graphic", "\320\220\321\215\321\200\320\276\320\277\320\276\321\200\321\202:", nullptr));
        lb_airport->setText(QCoreApplication::translate("Graphic", "\320\250\320\265\321\200\320\265\320\274\320\265\321\202\321\214\320\265\320\262\320\276", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Graphic", "                       \320\227\320\260 \320\263\320\276\320\264                          ", nullptr));
        lb_month->setText(QCoreApplication::translate("Graphic", "\320\234\320\265\321\201\321\217\321\206:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Graphic", "                    \320\227\320\260 \320\274\320\265\321\201\321\217\321\206                  ", nullptr));
        pb_close->setText(QCoreApplication::translate("Graphic", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Graphic: public Ui_Graphic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHIC_H
