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
#include <QtWidgets/QHBoxLayout>
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
    QGridLayout *gridLayout;
    QLabel *label_trialDuration;
    QDoubleSpinBox *doubleSpinBox_trialDuration;
    QLabel *label_secDuration;
    QLabel *label_timeBetweenTrials;
    QDoubleSpinBox *doubleSpinBox_timeBetweenTrials;
    QLabel *label_secBetweenTrials;
    QLabel *label_sequence;
    QPlainTextEdit *plainTextEdit_sequence;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_errSequence;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_generateRandomSequence;
    QLabel *label_nTrials;
    QSpinBox *spinBox_nTrials;

    void setupUi(QWidget *ExperimentSetup)
    {
        if (ExperimentSetup->objectName().isEmpty())
            ExperimentSetup->setObjectName(QString::fromUtf8("ExperimentSetup"));
        ExperimentSetup->resize(466, 204);
        gridLayout = new QGridLayout(ExperimentSetup);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_trialDuration = new QLabel(ExperimentSetup);
        label_trialDuration->setObjectName(QString::fromUtf8("label_trialDuration"));

        gridLayout->addWidget(label_trialDuration, 0, 0, 1, 1);

        doubleSpinBox_trialDuration = new QDoubleSpinBox(ExperimentSetup);
        doubleSpinBox_trialDuration->setObjectName(QString::fromUtf8("doubleSpinBox_trialDuration"));
        doubleSpinBox_trialDuration->setMinimum(1.000000000000000);

        gridLayout->addWidget(doubleSpinBox_trialDuration, 0, 1, 1, 1);

        label_secDuration = new QLabel(ExperimentSetup);
        label_secDuration->setObjectName(QString::fromUtf8("label_secDuration"));

        gridLayout->addWidget(label_secDuration, 0, 2, 1, 1);

        label_timeBetweenTrials = new QLabel(ExperimentSetup);
        label_timeBetweenTrials->setObjectName(QString::fromUtf8("label_timeBetweenTrials"));

        gridLayout->addWidget(label_timeBetweenTrials, 1, 0, 1, 1);

        doubleSpinBox_timeBetweenTrials = new QDoubleSpinBox(ExperimentSetup);
        doubleSpinBox_timeBetweenTrials->setObjectName(QString::fromUtf8("doubleSpinBox_timeBetweenTrials"));
        doubleSpinBox_timeBetweenTrials->setMinimum(1.000000000000000);

        gridLayout->addWidget(doubleSpinBox_timeBetweenTrials, 1, 1, 1, 1);

        label_secBetweenTrials = new QLabel(ExperimentSetup);
        label_secBetweenTrials->setObjectName(QString::fromUtf8("label_secBetweenTrials"));

        gridLayout->addWidget(label_secBetweenTrials, 1, 2, 1, 1);

        label_sequence = new QLabel(ExperimentSetup);
        label_sequence->setObjectName(QString::fromUtf8("label_sequence"));

        gridLayout->addWidget(label_sequence, 2, 0, 1, 1, Qt::AlignTop);

        plainTextEdit_sequence = new QPlainTextEdit(ExperimentSetup);
        plainTextEdit_sequence->setObjectName(QString::fromUtf8("plainTextEdit_sequence"));

        gridLayout->addWidget(plainTextEdit_sequence, 2, 1, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_errSequence = new QLabel(ExperimentSetup);
        label_errSequence->setObjectName(QString::fromUtf8("label_errSequence"));
        QFont font;
        font.setBold(true);
        label_errSequence->setFont(font);

        verticalLayout_2->addWidget(label_errSequence, 0, Qt::AlignTop);


        gridLayout->addLayout(verticalLayout_2, 2, 2, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_generateRandomSequence = new QPushButton(ExperimentSetup);
        pushButton_generateRandomSequence->setObjectName(QString::fromUtf8("pushButton_generateRandomSequence"));

        horizontalLayout_2->addWidget(pushButton_generateRandomSequence);

        label_nTrials = new QLabel(ExperimentSetup);
        label_nTrials->setObjectName(QString::fromUtf8("label_nTrials"));

        horizontalLayout_2->addWidget(label_nTrials);

        spinBox_nTrials = new QSpinBox(ExperimentSetup);
        spinBox_nTrials->setObjectName(QString::fromUtf8("spinBox_nTrials"));
        spinBox_nTrials->setMinimum(1);
        spinBox_nTrials->setValue(10);

        horizontalLayout_2->addWidget(spinBox_nTrials);


        gridLayout->addLayout(horizontalLayout_2, 3, 1, 1, 1);

        QWidget::setTabOrder(doubleSpinBox_trialDuration, doubleSpinBox_timeBetweenTrials);
        QWidget::setTabOrder(doubleSpinBox_timeBetweenTrials, plainTextEdit_sequence);
        QWidget::setTabOrder(plainTextEdit_sequence, spinBox_nTrials);
        QWidget::setTabOrder(spinBox_nTrials, pushButton_generateRandomSequence);

        retranslateUi(ExperimentSetup);

        QMetaObject::connectSlotsByName(ExperimentSetup);
    } // setupUi

    void retranslateUi(QWidget *ExperimentSetup)
    {
        ExperimentSetup->setWindowTitle(QCoreApplication::translate("ExperimentSetup", "Form", nullptr));
        label_trialDuration->setText(QCoreApplication::translate("ExperimentSetup", "Trial duration:", nullptr));
        label_secDuration->setText(QCoreApplication::translate("ExperimentSetup", "seconds", nullptr));
        label_timeBetweenTrials->setText(QCoreApplication::translate("ExperimentSetup", "Time between trials:", nullptr));
        label_secBetweenTrials->setText(QCoreApplication::translate("ExperimentSetup", "seconds", nullptr));
        label_sequence->setText(QCoreApplication::translate("ExperimentSetup", "Sequence:", nullptr));
        label_errSequence->setText(QCoreApplication::translate("ExperimentSetup", "[!!!]", nullptr));
        pushButton_generateRandomSequence->setText(QCoreApplication::translate("ExperimentSetup", "Generate Random", nullptr));
        label_nTrials->setText(QCoreApplication::translate("ExperimentSetup", "Number of trials:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExperimentSetup: public Ui_ExperimentSetup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPERIMENTSETUP_H
