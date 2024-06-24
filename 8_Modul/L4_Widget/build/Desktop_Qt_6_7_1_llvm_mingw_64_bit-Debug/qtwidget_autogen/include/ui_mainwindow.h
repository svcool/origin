/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *rb_on;
    QRadioButton *rb_off;
    QLabel *label;
    QComboBox *cb_list;
    QPushButton *pb_button;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(522, 268);
        MainWindow->setMaximumSize(QSize(16777215, 268));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName("verticalLayout");
        rb_on = new QRadioButton(groupBox);
        rb_on->setObjectName("rb_on");

        verticalLayout->addWidget(rb_on);

        rb_off = new QRadioButton(groupBox);
        rb_off->setObjectName("rb_off");

        verticalLayout->addWidget(rb_off);


        verticalLayout_2->addWidget(groupBox);

        label = new QLabel(centralwidget);
        label->setObjectName("label");

        verticalLayout_2->addWidget(label);

        cb_list = new QComboBox(centralwidget);
        cb_list->setObjectName("cb_list");

        verticalLayout_2->addWidget(cb_list);

        pb_button = new QPushButton(centralwidget);
        pb_button->setObjectName("pb_button");
        pb_button->setCheckable(false);

        verticalLayout_2->addWidget(pb_button);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 522, 26));
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
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\274\320\260\320\275\320\264\320\260", nullptr));
        rb_on->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\320\267\321\200\320\265\321\210\320\270\321\202\321\214 \320\267\320\260\320\277\321\203\321\201\320\272", nullptr));
        rb_off->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\321\200\320\265\321\202\320\270\321\202\321\214 \320\267\320\260\320\277\321\203\321\201\320\272", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\276\321\200 \321\202\320\270\320\277\320\260 \321\200\320\260\320\272\320\265\321\202:", nullptr));
        pb_button->setText(QCoreApplication::translate("MainWindow", "\320\237\321\203\321\201\320\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
