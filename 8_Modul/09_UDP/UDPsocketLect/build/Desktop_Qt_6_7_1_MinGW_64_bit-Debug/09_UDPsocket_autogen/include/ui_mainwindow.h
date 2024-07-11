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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *lb_receiveData;
    QTextEdit *te_result;
    QTextEdit *textEdit;
    QLineEdit *lineEdit;
    QPushButton *pb_stop;
    QPushButton *pb_start;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(427, 430);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        lb_receiveData = new QLabel(centralwidget);
        lb_receiveData->setObjectName("lb_receiveData");
        lb_receiveData->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lb_receiveData);

        te_result = new QTextEdit(centralwidget);
        te_result->setObjectName("te_result");

        verticalLayout->addWidget(te_result);

        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");

        verticalLayout->addWidget(textEdit);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");

        verticalLayout->addWidget(lineEdit);

        pb_stop = new QPushButton(centralwidget);
        pb_stop->setObjectName("pb_stop");

        verticalLayout->addWidget(pb_stop);

        pb_start = new QPushButton(centralwidget);
        pb_start->setObjectName("pb_start");

        verticalLayout->addWidget(pb_start);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        lb_receiveData->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\320\275\321\217\321\202\321\213\320\265 \320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
        pb_stop->setText(QCoreApplication::translate("MainWindow", "\320\236\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\277\320\265\321\200\320\265\320\264\320\260\321\207\321\203", nullptr));
        pb_start->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\321\202\321\214 \320\277\320\265\321\200\320\265\320\264\320\260\321\207\321\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
