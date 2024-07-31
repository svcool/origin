/********************************************************************************
** Form generated from reading UI file 'dbdata.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DBDATA_H
#define UI_DBDATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_DbData
{
public:
    QGridLayout *gridLayout;
    QLabel *lb_host;
    QLineEdit *le_host;
    QLabel *lb_dbName;
    QLineEdit *le_dbName;
    QLabel *lb_login;
    QLineEdit *le_login;
    QLabel *lb_pass;
    QLineEdit *le_pass;
    QLabel *lb_port;
    QSpinBox *spB_port;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DbData)
    {
        if (DbData->objectName().isEmpty())
            DbData->setObjectName("DbData");
        DbData->resize(400, 200);
        gridLayout = new QGridLayout(DbData);
        gridLayout->setObjectName("gridLayout");
        lb_host = new QLabel(DbData);
        lb_host->setObjectName("lb_host");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(35);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lb_host->sizePolicy().hasHeightForWidth());
        lb_host->setSizePolicy(sizePolicy);
        lb_host->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lb_host, 0, 0, 1, 1);

        le_host = new QLineEdit(DbData);
        le_host->setObjectName("le_host");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(le_host->sizePolicy().hasHeightForWidth());
        le_host->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(le_host, 0, 1, 1, 1);

        lb_dbName = new QLabel(DbData);
        lb_dbName->setObjectName("lb_dbName");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lb_dbName->sizePolicy().hasHeightForWidth());
        lb_dbName->setSizePolicy(sizePolicy2);
        lb_dbName->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lb_dbName, 1, 0, 1, 1);

        le_dbName = new QLineEdit(DbData);
        le_dbName->setObjectName("le_dbName");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(le_dbName->sizePolicy().hasHeightForWidth());
        le_dbName->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(le_dbName, 1, 1, 1, 1);

        lb_login = new QLabel(DbData);
        lb_login->setObjectName("lb_login");
        sizePolicy2.setHeightForWidth(lb_login->sizePolicy().hasHeightForWidth());
        lb_login->setSizePolicy(sizePolicy2);
        lb_login->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lb_login, 2, 0, 1, 1);

        le_login = new QLineEdit(DbData);
        le_login->setObjectName("le_login");
        sizePolicy3.setHeightForWidth(le_login->sizePolicy().hasHeightForWidth());
        le_login->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(le_login, 2, 1, 1, 1);

        lb_pass = new QLabel(DbData);
        lb_pass->setObjectName("lb_pass");
        sizePolicy2.setHeightForWidth(lb_pass->sizePolicy().hasHeightForWidth());
        lb_pass->setSizePolicy(sizePolicy2);
        lb_pass->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lb_pass, 3, 0, 1, 1);

        le_pass = new QLineEdit(DbData);
        le_pass->setObjectName("le_pass");
        sizePolicy3.setHeightForWidth(le_pass->sizePolicy().hasHeightForWidth());
        le_pass->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(le_pass, 3, 1, 1, 1);

        lb_port = new QLabel(DbData);
        lb_port->setObjectName("lb_port");
        sizePolicy2.setHeightForWidth(lb_port->sizePolicy().hasHeightForWidth());
        lb_port->setSizePolicy(sizePolicy2);
        lb_port->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lb_port, 4, 0, 1, 1);

        spB_port = new QSpinBox(DbData);
        spB_port->setObjectName("spB_port");
        sizePolicy3.setHeightForWidth(spB_port->sizePolicy().hasHeightForWidth());
        spB_port->setSizePolicy(sizePolicy3);
        spB_port->setMaximum(65535);

        gridLayout->addWidget(spB_port, 4, 1, 1, 1);

        buttonBox = new QDialogButtonBox(DbData);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 5, 0, 1, 2);


        retranslateUi(DbData);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, DbData, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, DbData, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(DbData);
    } // setupUi

    void retranslateUi(QDialog *DbData)
    {
        DbData->setWindowTitle(QCoreApplication::translate("DbData", "Dialog", nullptr));
        lb_host->setText(QCoreApplication::translate("DbData", "\320\245\320\276\321\201\321\202:", nullptr));
        lb_dbName->setText(QCoreApplication::translate("DbData", "\320\230\320\274\321\217 \320\261\320\260\320\267\321\213 \320\264\320\260\320\275\320\275\321\213\321\205:", nullptr));
        lb_login->setText(QCoreApplication::translate("DbData", "\320\233\320\276\320\263\320\270\320\275:", nullptr));
        lb_pass->setText(QCoreApplication::translate("DbData", "\320\237\320\260\321\200\320\276\320\273\321\214:", nullptr));
        lb_port->setText(QCoreApplication::translate("DbData", "\320\237\320\276\321\200\321\202:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DbData: public Ui_DbData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DBDATA_H
