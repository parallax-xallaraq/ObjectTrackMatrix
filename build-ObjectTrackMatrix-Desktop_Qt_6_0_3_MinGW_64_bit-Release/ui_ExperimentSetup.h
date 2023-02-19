/********************************************************************************
** Form generated from reading UI file 'ExperimentSetup.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPERIMENTSETUP_H
#define UI_EXPERIMENTSETUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExperimentSetup
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QDoubleSpinBox *doubleSpinBox_2;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_5;
    QLabel *label_3;
    QSpinBox *spinBox;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label;
    QPlainTextEdit *plainTextEdit;
    QLabel *label_7;
    QPushButton *pushButton;

    void setupUi(QWidget *ExperimentSetup)
    {
        if (ExperimentSetup->objectName().isEmpty())
            ExperimentSetup->setObjectName(QString::fromUtf8("ExperimentSetup"));
        ExperimentSetup->resize(400, 226);
        verticalLayout = new QVBoxLayout(ExperimentSetup);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));

        gridLayout->addLayout(verticalLayout_2, 2, 2, 1, 1);

        doubleSpinBox_2 = new QDoubleSpinBox(ExperimentSetup);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));

        gridLayout->addWidget(doubleSpinBox_2, 1, 1, 1, 1);

        doubleSpinBox = new QDoubleSpinBox(ExperimentSetup);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));

        gridLayout->addWidget(doubleSpinBox, 0, 1, 1, 1);

        label_5 = new QLabel(ExperimentSetup);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 0, 2, 1, 1);

        label_3 = new QLabel(ExperimentSetup);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        spinBox = new QSpinBox(ExperimentSetup);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        gridLayout->addWidget(spinBox, 4, 1, 1, 1);

        label_4 = new QLabel(ExperimentSetup);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        label_6 = new QLabel(ExperimentSetup);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 1, 2, 1, 1);

        label = new QLabel(ExperimentSetup);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1, Qt::AlignTop);

        plainTextEdit = new QPlainTextEdit(ExperimentSetup);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));

        gridLayout->addWidget(plainTextEdit, 2, 1, 1, 1);

        label_7 = new QLabel(ExperimentSetup);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 4, 0, 1, 1);

        pushButton = new QPushButton(ExperimentSetup);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 3, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(ExperimentSetup);

        QMetaObject::connectSlotsByName(ExperimentSetup);
    } // setupUi

    void retranslateUi(QWidget *ExperimentSetup)
    {
        ExperimentSetup->setWindowTitle(QCoreApplication::translate("ExperimentSetup", "Form", nullptr));
        label_5->setText(QCoreApplication::translate("ExperimentSetup", "seconds", nullptr));
        label_3->setText(QCoreApplication::translate("ExperimentSetup", "Trial duration:", nullptr));
        label_4->setText(QCoreApplication::translate("ExperimentSetup", "Time between trials:", nullptr));
        label_6->setText(QCoreApplication::translate("ExperimentSetup", "seconds", nullptr));
        label->setText(QCoreApplication::translate("ExperimentSetup", "Sequence:", nullptr));
        label_7->setText(QCoreApplication::translate("ExperimentSetup", "Number of trials:", nullptr));
        pushButton->setText(QCoreApplication::translate("ExperimentSetup", "Generate Random", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExperimentSetup: public Ui_ExperimentSetup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPERIMENTSETUP_H
