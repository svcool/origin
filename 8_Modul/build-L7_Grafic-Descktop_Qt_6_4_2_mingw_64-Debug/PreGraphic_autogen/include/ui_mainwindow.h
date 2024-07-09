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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *gb_result;
    QFormLayout *formLayout;
    QCheckBox *chB_readSucces;
    QCheckBox *chB_procFileSucces;
    QCheckBox *chB_maxSucess;
    QCheckBox *chB_minSucess;
    QSpinBox *spinBox;
    QTextEdit *te_Result;
    QComboBox *cmB_numCh;
    QLabel *lb_numCh;
    QLineEdit *le_path;
    QPushButton *pb_clearResult;
    QPushButton *pb_start;
    QPushButton *pb_path;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(402, 484);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        gb_result = new QGroupBox(centralwidget);
        gb_result->setObjectName("gb_result");
        formLayout = new QFormLayout(gb_result);
        formLayout->setObjectName("formLayout");
        chB_readSucces = new QCheckBox(gb_result);
        chB_readSucces->setObjectName("chB_readSucces");
        chB_readSucces->setEnabled(false);
        chB_readSucces->setCheckable(true);

        formLayout->setWidget(0, QFormLayout::LabelRole, chB_readSucces);

        chB_procFileSucces = new QCheckBox(gb_result);
        chB_procFileSucces->setObjectName("chB_procFileSucces");
        chB_procFileSucces->setEnabled(false);
        chB_procFileSucces->setCheckable(true);

        formLayout->setWidget(1, QFormLayout::LabelRole, chB_procFileSucces);

        chB_maxSucess = new QCheckBox(gb_result);
        chB_maxSucess->setObjectName("chB_maxSucess");
        chB_maxSucess->setEnabled(false);
        chB_maxSucess->setCheckable(true);

        formLayout->setWidget(2, QFormLayout::LabelRole, chB_maxSucess);

        chB_minSucess = new QCheckBox(gb_result);
        chB_minSucess->setObjectName("chB_minSucess");
        chB_minSucess->setEnabled(false);

        formLayout->setWidget(3, QFormLayout::LabelRole, chB_minSucess);

        spinBox = new QSpinBox(gb_result);
        spinBox->setObjectName("spinBox");

        formLayout->setWidget(4, QFormLayout::SpanningRole, spinBox);


        gridLayout->addWidget(gb_result, 0, 0, 1, 2);

        te_Result = new QTextEdit(centralwidget);
        te_Result->setObjectName("te_Result");
        te_Result->setReadOnly(true);

        gridLayout->addWidget(te_Result, 1, 0, 1, 2);

        cmB_numCh = new QComboBox(centralwidget);
        cmB_numCh->addItem(QString());
        cmB_numCh->addItem(QString());
        cmB_numCh->addItem(QString());
        cmB_numCh->setObjectName("cmB_numCh");

        gridLayout->addWidget(cmB_numCh, 2, 1, 1, 1);

        lb_numCh = new QLabel(centralwidget);
        lb_numCh->setObjectName("lb_numCh");

        gridLayout->addWidget(lb_numCh, 2, 0, 1, 1);

        le_path = new QLineEdit(centralwidget);
        le_path->setObjectName("le_path");
        le_path->setReadOnly(true);

        gridLayout->addWidget(le_path, 3, 0, 1, 1);

        pb_clearResult = new QPushButton(centralwidget);
        pb_clearResult->setObjectName("pb_clearResult");

        gridLayout->addWidget(pb_clearResult, 4, 0, 1, 2);

        pb_start = new QPushButton(centralwidget);
        pb_start->setObjectName("pb_start");
        pb_start->setFlat(false);

        gridLayout->addWidget(pb_start, 5, 0, 1, 2);

        pb_path = new QPushButton(centralwidget);
        pb_path->setObjectName("pb_path");

        gridLayout->addWidget(pb_path, 3, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 402, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(pb_clearResult, &QPushButton::clicked, te_Result, qOverload<>(&QTextEdit::clear));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        gb_result->setTitle(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\321\213 \320\262\321\213\320\277\320\276\320\273\320\275\320\265\320\275\320\270\321\217", nullptr));
        chB_readSucces->setText(QCoreApplication::translate("MainWindow", "\320\241\321\207\320\270\321\202\321\213\320\262\320\260\320\275\320\270\320\265 \320\267\320\260\320\262\320\265\321\200\321\210\320\265\320\275\320\276", nullptr));
        chB_procFileSucces->setText(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273 \320\276\320\261\321\200\320\260\320\261\320\276\321\202\320\260\320\275", nullptr));
        chB_maxSucess->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\320\272\321\201\320\270\320\274\321\203\320\274\321\213 \320\275\320\260\320\271\320\264\320\265\320\275\321\213", nullptr));
        chB_minSucess->setText(QCoreApplication::translate("MainWindow", "\320\234\320\270\320\275\320\270\320\274\321\203\320\274\321\213 \320\275\320\260\320\271\320\264\320\265\320\275\321\213", nullptr));
        cmB_numCh->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        cmB_numCh->setItemText(1, QCoreApplication::translate("MainWindow", "2", nullptr));
        cmB_numCh->setItemText(2, QCoreApplication::translate("MainWindow", "3", nullptr));

        lb_numCh->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200 \320\272\320\260\320\275\320\260\320\273\320\260:", nullptr));
        pb_clearResult->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202", nullptr));
        pb_start->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\260\321\200\321\202", nullptr));
        pb_path->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \320\277\321\203\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
