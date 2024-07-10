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
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *act_connect;
    QAction *act_addData;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *gb_filters;
    QFormLayout *formLayout;
    QLabel *lb_category;
    QComboBox *cb_category;
    QSpacerItem *verticalSpacer;
    QPushButton *pb_request;
    QLabel *lb_statusConnect;
    QPushButton *pb_clear;
    QTableView *tv_ableView;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(780, 548);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        act_connect = new QAction(MainWindow);
        act_connect->setObjectName("act_connect");
        act_addData = new QAction(MainWindow);
        act_addData->setObjectName("act_addData");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        gb_filters = new QGroupBox(centralwidget);
        gb_filters->setObjectName("gb_filters");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(gb_filters->sizePolicy().hasHeightForWidth());
        gb_filters->setSizePolicy(sizePolicy1);
        formLayout = new QFormLayout(gb_filters);
        formLayout->setObjectName("formLayout");
        lb_category = new QLabel(gb_filters);
        lb_category->setObjectName("lb_category");

        formLayout->setWidget(0, QFormLayout::LabelRole, lb_category);

        cb_category = new QComboBox(gb_filters);
        cb_category->addItem(QString());
        cb_category->addItem(QString());
        cb_category->addItem(QString());
        cb_category->setObjectName("cb_category");

        formLayout->setWidget(0, QFormLayout::FieldRole, cb_category);


        gridLayout->addWidget(gb_filters, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(verticalSpacer, 2, 1, 1, 1);

        pb_request = new QPushButton(centralwidget);
        pb_request->setObjectName("pb_request");
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pb_request->sizePolicy().hasHeightForWidth());
        pb_request->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pb_request, 4, 1, 1, 1);

        lb_statusConnect = new QLabel(centralwidget);
        lb_statusConnect->setObjectName("lb_statusConnect");
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lb_statusConnect->sizePolicy().hasHeightForWidth());
        lb_statusConnect->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(lb_statusConnect, 0, 0, 1, 1);

        pb_clear = new QPushButton(centralwidget);
        pb_clear->setObjectName("pb_clear");
        sizePolicy2.setHeightForWidth(pb_clear->sizePolicy().hasHeightForWidth());
        pb_clear->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pb_clear, 3, 1, 1, 1);

        tv_ableView = new QTableView(centralwidget);
        tv_ableView->setObjectName("tv_ableView");

        gridLayout->addWidget(tv_ableView, 1, 0, 2, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 780, 22));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(act_addData);
        menu->addSeparator();
        menu->addAction(act_connect);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        act_connect->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214\321\201\321\217", nullptr));
        act_addData->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\321\201\321\202\320\270 \320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
        gb_filters->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\270\320\273\321\214\321\202\321\200\321\213", nullptr));
        lb_category->setText(QCoreApplication::translate("MainWindow", "\320\226\320\260\320\275\321\200:", nullptr));
        cb_category->setItemText(0, QCoreApplication::translate("MainWindow", "\320\222\321\201\320\265", nullptr));
        cb_category->setItemText(1, QCoreApplication::translate("MainWindow", "\320\232\320\276\320\274\320\265\320\264\320\270\321\217", nullptr));
        cb_category->setItemText(2, QCoreApplication::translate("MainWindow", "\320\243\320\266\320\260\321\201\321\213", nullptr));

        pb_request->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\273\321\203\321\207\320\270\321\202\321\214", nullptr));
        lb_statusConnect->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\320\273\321\216\321\207\320\265\320\275\320\276", nullptr));
        pb_clear->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
