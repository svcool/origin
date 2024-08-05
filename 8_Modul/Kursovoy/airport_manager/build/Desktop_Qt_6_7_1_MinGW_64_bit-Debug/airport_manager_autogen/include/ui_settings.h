/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QLabel *lb_host;
    QLabel *lb_dbName;
    QSpinBox *spB_port;
    QLabel *lb_port;
    QLineEdit *le_dbName;
    QLineEdit *le_host;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLineEdit *le_pass;
    QLineEdit *le_login;
    QLabel *lb_pass;
    QLabel *lb_login;
    QPushButton *def_Button;
    QDialogButtonBox *bb_Box;

    void setupUi(QDialog *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName("Settings");
        Settings->resize(599, 254);
        Settings->setMinimumSize(QSize(0, 254));
        Settings->setMaximumSize(QSize(16777215, 254));
        gridLayout_2 = new QGridLayout(Settings);
        gridLayout_2->setObjectName("gridLayout_2");
        groupBox_2 = new QGroupBox(Settings);
        groupBox_2->setObjectName("groupBox_2");
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName("gridLayout_3");
        lb_host = new QLabel(groupBox_2);
        lb_host->setObjectName("lb_host");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(35);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lb_host->sizePolicy().hasHeightForWidth());
        lb_host->setSizePolicy(sizePolicy);
        lb_host->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(lb_host, 2, 0, 1, 1);

        lb_dbName = new QLabel(groupBox_2);
        lb_dbName->setObjectName("lb_dbName");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lb_dbName->sizePolicy().hasHeightForWidth());
        lb_dbName->setSizePolicy(sizePolicy1);
        lb_dbName->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(lb_dbName, 3, 0, 1, 1);

        spB_port = new QSpinBox(groupBox_2);
        spB_port->setObjectName("spB_port");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(spB_port->sizePolicy().hasHeightForWidth());
        spB_port->setSizePolicy(sizePolicy2);
        spB_port->setMaximum(65535);

        gridLayout_3->addWidget(spB_port, 5, 1, 1, 1);

        lb_port = new QLabel(groupBox_2);
        lb_port->setObjectName("lb_port");
        sizePolicy1.setHeightForWidth(lb_port->sizePolicy().hasHeightForWidth());
        lb_port->setSizePolicy(sizePolicy1);
        lb_port->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(lb_port, 5, 0, 1, 1);

        le_dbName = new QLineEdit(groupBox_2);
        le_dbName->setObjectName("le_dbName");
        sizePolicy2.setHeightForWidth(le_dbName->sizePolicy().hasHeightForWidth());
        le_dbName->setSizePolicy(sizePolicy2);

        gridLayout_3->addWidget(le_dbName, 3, 1, 1, 1);

        le_host = new QLineEdit(groupBox_2);
        le_host->setObjectName("le_host");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(le_host->sizePolicy().hasHeightForWidth());
        le_host->setSizePolicy(sizePolicy3);

        gridLayout_3->addWidget(le_host, 2, 1, 1, 1);


        gridLayout_2->addWidget(groupBox_2, 0, 0, 1, 2);

        groupBox = new QGroupBox(Settings);
        groupBox->setObjectName("groupBox");
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        le_pass = new QLineEdit(groupBox);
        le_pass->setObjectName("le_pass");
        sizePolicy2.setHeightForWidth(le_pass->sizePolicy().hasHeightForWidth());
        le_pass->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(le_pass, 0, 2, 1, 1);

        le_login = new QLineEdit(groupBox);
        le_login->setObjectName("le_login");
        sizePolicy2.setHeightForWidth(le_login->sizePolicy().hasHeightForWidth());
        le_login->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(le_login, 1, 2, 1, 1);

        lb_pass = new QLabel(groupBox);
        lb_pass->setObjectName("lb_pass");
        sizePolicy1.setHeightForWidth(lb_pass->sizePolicy().hasHeightForWidth());
        lb_pass->setSizePolicy(sizePolicy1);
        lb_pass->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lb_pass, 0, 1, 1, 1);

        lb_login = new QLabel(groupBox);
        lb_login->setObjectName("lb_login");
        sizePolicy1.setHeightForWidth(lb_login->sizePolicy().hasHeightForWidth());
        lb_login->setSizePolicy(sizePolicy1);
        lb_login->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lb_login, 1, 1, 1, 1);


        gridLayout_2->addWidget(groupBox, 1, 0, 1, 2);

        def_Button = new QPushButton(Settings);
        def_Button->setObjectName("def_Button");

        gridLayout_2->addWidget(def_Button, 2, 0, 1, 1);

        bb_Box = new QDialogButtonBox(Settings);
        bb_Box->setObjectName("bb_Box");
        bb_Box->setOrientation(Qt::Horizontal);
        bb_Box->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(bb_Box, 2, 1, 1, 1);


        retranslateUi(Settings);

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QDialog *Settings)
    {
        Settings->setWindowTitle(QCoreApplication::translate("Settings", "Dialog", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Settings", "\320\241\320\265\321\200\320\262\320\265\321\200 \320\221\320\224", nullptr));
        lb_host->setText(QCoreApplication::translate("Settings", "\320\245\320\276\321\201\321\202:", nullptr));
        lb_dbName->setText(QCoreApplication::translate("Settings", "\320\230\320\274\321\217 \320\261\320\260\320\267\321\213 \320\264\320\260\320\275\320\275\321\213\321\205:", nullptr));
        lb_port->setText(QCoreApplication::translate("Settings", "\320\237\320\276\321\200\321\202:", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Settings", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
        lb_pass->setText(QCoreApplication::translate("Settings", "\320\237\320\260\321\200\320\276\320\273\321\214:", nullptr));
        lb_login->setText(QCoreApplication::translate("Settings", "\320\233\320\276\320\263\320\270\320\275:", nullptr));
        def_Button->setText(QCoreApplication::translate("Settings", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\277\320\276 \321\203\320\274\320\276\320\273\321\207\320\260\320\275\320\270\321\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
