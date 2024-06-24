/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *spinBox;
    QLineEdit *lineEdit_2;
    QSplitter *splitter_3;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QSplitter *splitter;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QLabel *label_5;
    QLineEdit *lineEdit_4;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(761, 384);
        Dialog->setMaximumSize(QSize(761, 384));
        verticalLayout = new QVBoxLayout(Dialog);
        verticalLayout->setObjectName("verticalLayout");
        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName("groupBox");
        groupBox->setMinimumSize(QSize(0, 181));
        groupBox->setMaximumSize(QSize(16777215, 181));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(groupBox);
        label->setObjectName("label");

        gridLayout->addWidget(label, 3, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        spinBox = new QSpinBox(groupBox);
        spinBox->setObjectName("spinBox");
        spinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout->addWidget(spinBox, 4, 0, 1, 1);

        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName("lineEdit_2");

        gridLayout->addWidget(lineEdit_2, 2, 0, 1, 1);

        splitter_3 = new QSplitter(groupBox);
        splitter_3->setObjectName("splitter_3");
        splitter_3->setOrientation(Qt::Vertical);
        label_3 = new QLabel(splitter_3);
        label_3->setObjectName("label_3");
        splitter_3->addWidget(label_3);
        lineEdit = new QLineEdit(splitter_3);
        lineEdit->setObjectName("lineEdit");
        splitter_3->addWidget(lineEdit);

        gridLayout->addWidget(splitter_3, 0, 0, 1, 1);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(Dialog);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setMinimumSize(QSize(0, 129));
        groupBox_2->setMaximumSize(QSize(16777215, 129));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName("gridLayout_2");
        splitter = new QSplitter(groupBox_2);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Vertical);
        label_4 = new QLabel(splitter);
        label_4->setObjectName("label_4");
        splitter->addWidget(label_4);
        lineEdit_3 = new QLineEdit(splitter);
        lineEdit_3->setObjectName("lineEdit_3");
        splitter->addWidget(lineEdit_3);

        gridLayout_2->addWidget(splitter, 0, 0, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName("label_5");

        gridLayout_2->addWidget(label_5, 1, 0, 1, 1);

        lineEdit_4 = new QLineEdit(groupBox_2);
        lineEdit_4->setObjectName("lineEdit_4");

        gridLayout_2->addWidget(lineEdit_4, 2, 0, 1, 1);


        verticalLayout->addWidget(groupBox_2);

        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setMinimumSize(QSize(0, 24));
        buttonBox->setMaximumSize(QSize(16777215, 24));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(Dialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Dialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Dialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Dialog", "\320\241\320\265\321\200\320\262\320\265\321\200 \320\221\320\224", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "\320\237\320\276\321\200\321\202:", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "\320\230\320\274\321\217  \321\205\320\276\321\201\321\202\320\260:", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog", "\320\230\320\274\321\217 \320\221\320\224:", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Dialog", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
        label_4->setText(QCoreApplication::translate("Dialog", "\320\233\320\276\320\263\320\270\320\275:", nullptr));
        label_5->setText(QCoreApplication::translate("Dialog", "\320\237\320\260\321\200\320\276\320\273\321\214:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
