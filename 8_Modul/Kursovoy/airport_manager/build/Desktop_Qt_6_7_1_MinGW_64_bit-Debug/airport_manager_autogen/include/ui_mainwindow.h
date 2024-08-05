/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *menu_exit;
    QAction *menu_settings;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QTableView *tv_tableView;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QRadioButton *rb_arrival;
    QComboBox *cb_comboBox;
    QLabel *label_2;
    QLabel *label;
    QDateEdit *dtfrom_dateEdit;
    QSpacerItem *verticalSpacer;
    QLabel *label_3;
    QDateEdit *dtby_dateEdit;
    QLabel *label_4;
    QRadioButton *rb_Departure;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QPushButton *pb_exit;
    QPushButton *pb_help;
    QPushButton *pb_graphic;
    QPushButton *pb_get;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(640, 552);
        menu_exit = new QAction(MainWindow);
        menu_exit->setObjectName("menu_exit");
        menu_settings = new QAction(MainWindow);
        menu_settings->setObjectName("menu_settings");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        tv_tableView = new QTableView(centralwidget);
        tv_tableView->setObjectName("tv_tableView");

        horizontalLayout->addWidget(tv_tableView);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setMinimumSize(QSize(221, 0));
        groupBox->setMaximumSize(QSize(221, 16777215));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName("gridLayout_3");
        rb_arrival = new QRadioButton(groupBox);
        rb_arrival->setObjectName("rb_arrival");
        rb_arrival->setChecked(true);

        gridLayout_3->addWidget(rb_arrival, 3, 0, 1, 2);

        cb_comboBox = new QComboBox(groupBox);
        cb_comboBox->setObjectName("cb_comboBox");

        gridLayout_3->addWidget(cb_comboBox, 1, 0, 1, 2);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");

        gridLayout_3->addWidget(label_2, 5, 0, 1, 2);

        label = new QLabel(groupBox);
        label->setObjectName("label");

        gridLayout_3->addWidget(label, 0, 0, 1, 2);

        dtfrom_dateEdit = new QDateEdit(groupBox);
        dtfrom_dateEdit->setObjectName("dtfrom_dateEdit");
        dtfrom_dateEdit->setDateTime(QDateTime(QDate(2016, 8, 15), QTime(10, 55, 0)));
        dtfrom_dateEdit->setMaximumDateTime(QDateTime(QDate(2017, 9, 13), QTime(0, 0, 0)));
        dtfrom_dateEdit->setMinimumDateTime(QDateTime(QDate(2016, 8, 15), QTime(10, 55, 0)));
        dtfrom_dateEdit->setMaximumDate(QDate(2017, 9, 13));
        dtfrom_dateEdit->setMinimumDate(QDate(2016, 8, 15));
        dtfrom_dateEdit->setMaximumTime(QTime(0, 0, 0));
        dtfrom_dateEdit->setMinimumTime(QTime(10, 55, 0));
        dtfrom_dateEdit->setCalendarPopup(true);
        dtfrom_dateEdit->setCurrentSectionIndex(0);
        dtfrom_dateEdit->setDate(QDate(2016, 8, 15));

        gridLayout_3->addWidget(dtfrom_dateEdit, 6, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 8, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setMinimumSize(QSize(0, 16));
        label_3->setMaximumSize(QSize(16, 16777215));

        gridLayout_3->addWidget(label_3, 6, 0, 1, 1);

        dtby_dateEdit = new QDateEdit(groupBox);
        dtby_dateEdit->setObjectName("dtby_dateEdit");
        dtby_dateEdit->setDateTime(QDateTime(QDate(2017, 9, 14), QTime(0, 0, 0)));
        dtby_dateEdit->setMaximumDateTime(QDateTime(QDate(2017, 9, 14), QTime(0, 0, 0)));
        dtby_dateEdit->setMinimumDateTime(QDateTime(QDate(2016, 9, 15), QTime(2, 0, 0)));
        dtby_dateEdit->setMaximumDate(QDate(2017, 9, 14));
        dtby_dateEdit->setMinimumDate(QDate(2016, 9, 15));
        dtby_dateEdit->setMaximumTime(QTime(0, 0, 0));
        dtby_dateEdit->setCalendarPopup(true);
        dtby_dateEdit->setDate(QDate(2017, 9, 14));

        gridLayout_3->addWidget(dtby_dateEdit, 7, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setMinimumSize(QSize(0, 16));
        label_4->setMaximumSize(QSize(17, 16777215));

        gridLayout_3->addWidget(label_4, 7, 0, 1, 1);

        rb_Departure = new QRadioButton(groupBox);
        rb_Departure->setObjectName("rb_Departure");

        gridLayout_3->addWidget(rb_Departure, 4, 0, 1, 1);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setMinimumSize(QSize(221, 101));
        groupBox_2->setMaximumSize(QSize(221, 101));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName("gridLayout_2");
        pb_exit = new QPushButton(groupBox_2);
        pb_exit->setObjectName("pb_exit");

        gridLayout_2->addWidget(pb_exit, 2, 1, 1, 1);

        pb_help = new QPushButton(groupBox_2);
        pb_help->setObjectName("pb_help");

        gridLayout_2->addWidget(pb_help, 2, 0, 1, 1);

        pb_graphic = new QPushButton(groupBox_2);
        pb_graphic->setObjectName("pb_graphic");

        gridLayout_2->addWidget(pb_graphic, 1, 0, 1, 2);

        pb_get = new QPushButton(groupBox_2);
        pb_get->setObjectName("pb_get");

        gridLayout_2->addWidget(pb_get, 0, 0, 1, 2);


        verticalLayout->addWidget(groupBox_2);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 640, 22));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName("menu_2");
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName("menu_3");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menu->addAction(menu_settings);
        menu->addAction(menu_exit);

        retranslateUi(MainWindow);
        QObject::connect(pb_exit, &QPushButton::clicked, MainWindow, qOverload<>(&QMainWindow::close));
        QObject::connect(menu_exit, &QAction::triggered, MainWindow, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\230\320\275\321\201\320\277\320\265\320\272\321\202\320\276\321\200 \320\260\321\215\321\200\320\276\320\277\320\276\321\200\321\202\320\276\320\262", nullptr));
        menu_exit->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        menu_settings->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        groupBox->setTitle(QString());
        rb_arrival->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\320\273\320\265\321\202", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\276\321\200 \320\264\320\260\321\202\321\213:", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\276\321\200 \320\260\321\215\321\200\320\276\320\277\320\276\321\200\321\202\320\260:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "c:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\277\320\276:", nullptr));
        rb_Departure->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\273\320\265\321\202", nullptr));
        groupBox_2->setTitle(QString());
        pb_exit->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        pb_help->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\274\320\276\321\211\321\214", nullptr));
        pb_graphic->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\266\320\265\320\275\320\275\320\276\321\201\321\202\321\214 \320\260\321\215\321\200\320\276\320\277\320\276\321\200\321\202\320\276\320\262", nullptr));
        pb_get->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\273\321\203\321\207\320\270\321\202\321\214 \321\200\320\260\321\201\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \321\200\320\265\320\271\321\201\320\276\320\262", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\320\236\320\272\320\275\320\276", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\274\320\276\321\211\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
