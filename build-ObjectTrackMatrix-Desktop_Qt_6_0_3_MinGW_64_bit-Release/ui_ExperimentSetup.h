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
    QPlainTextEdit *plainTextEdit_sequence;
    QLabel *label_timeBetweenTrials;
    QLabel *label_nTrials;
    QDoubleSpinBox *doubleSpinBox_timeBetweenTrials;
    QLabel *label_secBetweenTrials;
    QLabel *label_trialDuration;
    QPushButton *pushButton_generateRandomSequence;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_errSequence;
    QLabel *label_secDuration;
    QLabel *label_sequence;
    QDoubleSpinBox *doubleSpinBox_trialDuration;
    QSpinBox *spinBox_nTrials;

    void setupUi(QWidget *ExperimentSetup)
    {
        if (ExperimentSetup->objectName().isEmpty())
            ExperimentSetup->setObjectName(QString::fromUtf8("ExperimentSetup"));
        ExperimentSetup->resize(400, 233);
        verticalLayout = new QVBoxLayout(ExperimentSetup);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        plainTextEdit_sequence = new QPlainTextEdit(ExperimentSetup);
        plainTextEdit_sequence->setObjectName(QString::fromUtf8("plainTextEdit_sequence"));

        gridLayout->addWidget(plainTextEdit_sequence, 2, 1, 1, 1);

        label_timeBetweenTrials = new QLabel(ExperimentSetup);
        label_timeBetweenTrials->setObjectName(QString::fromUtf8("label_timeBetweenTrials"));

        gridLayout->addWidget(label_timeBetweenTrials, 1, 0, 1, 1);

        label_nTrials = new QLabel(ExperimentSetup);
        label_nTrials->setObjectName(QString::fromUtf8("label_nTrials"));

        gridLayout->addWidget(label_nTrials, 3, 2, 1, 1);

        doubleSpinBox_timeBetweenTrials = new QDoubleSpinBox(ExperimentSetup);
        doubleSpinBox_timeBetweenTrials->setObjectName(QString::fromUtf8("doubleSpinBox_timeBetweenTrials"));
        doubleSpinBox_timeBetweenTrials->setMinimum(0.010000000000000);

        gridLayout->addWidget(doubleSpinBox_timeBetweenTrials, 1, 1, 1, 1);

        label_secBetweenTrials = new QLabel(ExperimentSetup);
        label_secBetweenTrials->setObjectName(QString::fromUtf8("label_secBetweenTrials"));

        gridLayout->addWidget(label_secBetweenTrials, 1, 2, 1, 1);

        label_trialDuration = new QLabel(ExperimentSetup);
        label_trialDuration->setObjectName(QString::fromUtf8("label_trialDuration"));

        gridLayout->addWidget(label_trialDuration, 0, 0, 1, 1);

        pushButton_generateRandomSequence = new QPushButton(ExperimentSetup);
        pushButton_generateRandomSequence->setObjectName(QString::fromUtf8("pushButton_generateRandomSequence"));

        gridLayout->addWidget(pushButton_generateRandomSequence, 3, 1, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_errSequence = new QLabel(ExperimentSetup);
        label_errSequence->setObjectName(QString::fromUtf8("label_errSequence"));
        QFont font;
        font.setBold(true);
        label_errSequence->setFont(font);

        verticalLayout_2->addWidget(label_errSequence, 0, Qt::AlignTop);


        gridLayout->addLayout(verticalLayout_2, 2, 2, 1, 1);

        label_secDuration = new QLabel(ExperimentSetup);
        label_secDuration->setObjectName(QString::fromUtf8("label_secDuration"));

        gridLayout->addWidget(label_secDuration, 0, 2, 1, 1);

        label_sequence = new QLabel(ExperimentSetup);
        label_sequence->setObjectName(QString::fromUtf8("label_sequence"));

        gridLayout->addWidget(label_sequence, 2, 0, 1, 1, Qt::AlignTop);

        doubleSpinBox_trialDuration = new QDoubleSpinBox(ExperimentSetup);
        doubleSpinBox_trialDuration->setObjectName(QString::fromUtf8("doubleSpinBox_trialDuration"));
        doubleSpinBox_trialDuration->setMinimum(0.010000000000000);

        gridLayout->addWidget(doubleSpinBox_trialDuration, 0, 1, 1, 1);

        spinBox_nTrials = new QSpinBox(ExperimentSetup);
        spinBox_nTrials->setObjectName(QString::fromUtf8("spinBox_nTrials"));
        spinBox_nTrials->setMinimum(1);

        gridLayout->addWidget(spinBox_nTrials, 3, 3, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(ExperimentSetup);

        QMetaObject::connectSlotsByName(ExperimentSetup);
    } // setupUi

    void retranslateUi(QWidget *ExperimentSetup)
    {
        ExperimentSetup->setWindowTitle(QCoreApplication::translate("ExperimentSetup", "Form", nullptr));
        label_timeBetweenTrials->setText(QCoreApplication::translate("ExperimentSetup", "Time between trials:", nullptr));
        label_nTrials->setText(QCoreApplication::translate("ExperimentSetup", "Number of trials:", nullptr));
        label_secBetweenTrials->setText(QCoreApplication::translate("ExperimentSetup", "seconds", nullptr));
        label_trialDuration->setText(QCoreApplication::translate("ExperimentSetup", "Trial duration:", nullptr));
        pushButton_generateRandomSequence->setText(QCoreApplication::translate("ExperimentSetup", "Generate Random", nullptr));
        label_errSequence->setText(QCoreApplication::translate("ExperimentSetup", "[!!!]", nullptr));
        label_secDuration->setText(QCoreApplication::translate("ExperimentSetup", "seconds", nullptr));
        label_sequence->setText(QCoreApplication::translate("ExperimentSetup", "Sequence:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExperimentSetup: public Ui_ExperimentSetup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPERIMENTSETUP_H
