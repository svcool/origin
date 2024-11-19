/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "d:\Program Files\MyProject\origin\origin\8_Modul\Kursovoy\airport_manager\qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QRadioButton *rb_cos;
    QDoubleSpinBox *dsB_step;
    QPushButton *pb_updGraph;
    QPushButton *pb_clear;
    QLabel *lb_step;
    QLabel *lb_func;
    QDoubleSpinBox *dsB_maxRange;
    QRadioButton *rb_sinx_x;
    QDoubleSpinBox *dsB_minRange;
    QRadioButton *rb_mouse;
    QLabel *lb_range;
    QCustomPlot *customPlot;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(413, 506);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setSizeConstraint(QLayout::SetMinimumSize);
        rb_cos = new QRadioButton(centralwidget);
        rb_cos->setObjectName("rb_cos");

        gridLayout->addWidget(rb_cos, 6, 2, 1, 1);

        dsB_step = new QDoubleSpinBox(centralwidget);
        dsB_step->setObjectName("dsB_step");
        dsB_step->setDecimals(3);
        dsB_step->setMinimum(-100.000000000000000);
        dsB_step->setMaximum(100.000000000000000);
        dsB_step->setSingleStep(0.100000000000000);
        dsB_step->setValue(0.100000000000000);

        gridLayout->addWidget(dsB_step, 4, 1, 1, 2);

        pb_updGraph = new QPushButton(centralwidget);
        pb_updGraph->setObjectName("pb_updGraph");
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pb_updGraph->sizePolicy().hasHeightForWidth());
        pb_updGraph->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pb_updGraph, 6, 1, 3, 1);

        pb_clear = new QPushButton(centralwidget);
        pb_clear->setObjectName("pb_clear");
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(21);
        sizePolicy2.setHeightForWidth(pb_clear->sizePolicy().hasHeightForWidth());
        pb_clear->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pb_clear, 5, 1, 1, 1);

        lb_step = new QLabel(centralwidget);
        lb_step->setObjectName("lb_step");
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lb_step->sizePolicy().hasHeightForWidth());
        lb_step->setSizePolicy(sizePolicy3);
        lb_step->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout->addWidget(lb_step, 3, 1, 1, 2);

        lb_func = new QLabel(centralwidget);
        lb_func->setObjectName("lb_func");
        lb_func->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lb_func, 5, 2, 1, 1);

        dsB_maxRange = new QDoubleSpinBox(centralwidget);
        dsB_maxRange->setObjectName("dsB_maxRange");
        dsB_maxRange->setDecimals(3);
        dsB_maxRange->setMinimum(-100.000000000000000);
        dsB_maxRange->setMaximum(100.000000000000000);
        dsB_maxRange->setSingleStep(0.000000000000000);
        dsB_maxRange->setValue(30.000000000000000);

        gridLayout->addWidget(dsB_maxRange, 2, 2, 1, 1);

        rb_sinx_x = new QRadioButton(centralwidget);
        rb_sinx_x->setObjectName("rb_sinx_x");

        gridLayout->addWidget(rb_sinx_x, 7, 2, 1, 1);

        dsB_minRange = new QDoubleSpinBox(centralwidget);
        dsB_minRange->setObjectName("dsB_minRange");
        dsB_minRange->setDecimals(3);
        dsB_minRange->setMinimum(-100.000000000000000);
        dsB_minRange->setMaximum(100.000000000000000);
        dsB_minRange->setSingleStep(0.100000000000000);
        dsB_minRange->setValue(-30.000000000000000);

        gridLayout->addWidget(dsB_minRange, 2, 1, 1, 1);

        rb_mouse = new QRadioButton(centralwidget);
        rb_mouse->setObjectName("rb_mouse");

        gridLayout->addWidget(rb_mouse, 8, 2, 1, 1);

        lb_range = new QLabel(centralwidget);
        lb_range->setObjectName("lb_range");
        sizePolicy3.setHeightForWidth(lb_range->sizePolicy().hasHeightForWidth());
        lb_range->setSizePolicy(sizePolicy3);
        lb_range->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout->addWidget(lb_range, 1, 1, 1, 2);

        customPlot = new QCustomPlot(centralwidget);
        customPlot->setObjectName("customPlot");

        gridLayout->addWidget(customPlot, 0, 1, 1, 2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 413, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        rb_cos->setText(QCoreApplication::translate("MainWindow", "cos(x)", nullptr));
        pb_updGraph->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214", nullptr));
        pb_clear->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        lb_step->setText(QCoreApplication::translate("MainWindow", "\320\250\320\260\320\263", nullptr));
        lb_func->setText(QCoreApplication::translate("MainWindow", "\320\244\321\203\320\275\320\272\321\206\320\270\321\217", nullptr));
        rb_sinx_x->setText(QCoreApplication::translate("MainWindow", "sin(x)/x", nullptr));
        rb_mouse->setText(QCoreApplication::translate("MainWindow", "\320\234\321\213\321\210\321\214", nullptr));
        lb_range->setText(QCoreApplication::translate("MainWindow", "\320\224\320\270\320\260\320\277\320\260\320\267\320\276\320\275", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
