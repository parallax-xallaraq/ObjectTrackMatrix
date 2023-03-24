/********************************************************************************
** Form generated from reading UI file 'ExperimentSetup.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPERIMENTSETUP_H
#define UI_EXPERIMENTSETUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
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
    QLabel *label_sampleRate;
    QLabel *label_port;
    QLabel *label_secBetweenTrials;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_sequenceErr;
    QDoubleSpinBox *doubleSpinBox_timeBetweenTrials;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_generateRandomSequence;
    QLabel *label_nTrials;
    QSpinBox *spinBox_nTrials;
    QLabel *label_timeBetweenTrials;
    QPushButton *pushButton_port;
    QLabel *label_portErr;
    QPlainTextEdit *plainTextEdit_sequence;
    QLabel *label_HzSampleRate;
    QComboBox *comboBox_port;
    QLabel *label_sequence;
    QDoubleSpinBox *doubleSpinBox_sampleRate;
    QLabel *label_timeout;
    QDoubleSpinBox *doubleSpinBox_timeout;
    QLabel *label_secTimeout;

    void setupUi(QWidget *ExperimentSetup)
    {
        if (ExperimentSetup->objectName().isEmpty())
            ExperimentSetup->setObjectName("ExperimentSetup");
        ExperimentSetup->resize(599, 253);
        gridLayout = new QGridLayout(ExperimentSetup);
        gridLayout->setObjectName("gridLayout");
        label_sampleRate = new QLabel(ExperimentSetup);
        label_sampleRate->setObjectName("label_sampleRate");

        gridLayout->addWidget(label_sampleRate, 8, 0, 1, 1);

        label_port = new QLabel(ExperimentSetup);
        label_port->setObjectName("label_port");

        gridLayout->addWidget(label_port, 1, 0, 1, 1);

        label_secBetweenTrials = new QLabel(ExperimentSetup);
        label_secBetweenTrials->setObjectName("label_secBetweenTrials");

        gridLayout->addWidget(label_secBetweenTrials, 6, 2, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_sequenceErr = new QLabel(ExperimentSetup);
        label_sequenceErr->setObjectName("label_sequenceErr");
        QFont font;
        font.setBold(true);
        label_sequenceErr->setFont(font);

        verticalLayout_2->addWidget(label_sequenceErr, 0, Qt::AlignTop);


        gridLayout->addLayout(verticalLayout_2, 9, 2, 1, 1);

        doubleSpinBox_timeBetweenTrials = new QDoubleSpinBox(ExperimentSetup);
        doubleSpinBox_timeBetweenTrials->setObjectName("doubleSpinBox_timeBetweenTrials");
        doubleSpinBox_timeBetweenTrials->setDecimals(3);
        doubleSpinBox_timeBetweenTrials->setMinimum(1.000000000000000);

        gridLayout->addWidget(doubleSpinBox_timeBetweenTrials, 6, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        pushButton_generateRandomSequence = new QPushButton(ExperimentSetup);
        pushButton_generateRandomSequence->setObjectName("pushButton_generateRandomSequence");

        horizontalLayout_2->addWidget(pushButton_generateRandomSequence);

        label_nTrials = new QLabel(ExperimentSetup);
        label_nTrials->setObjectName("label_nTrials");

        horizontalLayout_2->addWidget(label_nTrials);

        spinBox_nTrials = new QSpinBox(ExperimentSetup);
        spinBox_nTrials->setObjectName("spinBox_nTrials");
        spinBox_nTrials->setMinimum(1);
        spinBox_nTrials->setValue(10);

        horizontalLayout_2->addWidget(spinBox_nTrials);


        gridLayout->addLayout(horizontalLayout_2, 11, 1, 1, 1);

        label_timeBetweenTrials = new QLabel(ExperimentSetup);
        label_timeBetweenTrials->setObjectName("label_timeBetweenTrials");

        gridLayout->addWidget(label_timeBetweenTrials, 6, 0, 1, 1);

        pushButton_port = new QPushButton(ExperimentSetup);
        pushButton_port->setObjectName("pushButton_port");

        gridLayout->addWidget(pushButton_port, 1, 2, 1, 1);

        label_portErr = new QLabel(ExperimentSetup);
        label_portErr->setObjectName("label_portErr");
        label_portErr->setFont(font);

        gridLayout->addWidget(label_portErr, 1, 3, 1, 1);

        plainTextEdit_sequence = new QPlainTextEdit(ExperimentSetup);
        plainTextEdit_sequence->setObjectName("plainTextEdit_sequence");

        gridLayout->addWidget(plainTextEdit_sequence, 9, 1, 1, 1);

        label_HzSampleRate = new QLabel(ExperimentSetup);
        label_HzSampleRate->setObjectName("label_HzSampleRate");

        gridLayout->addWidget(label_HzSampleRate, 8, 2, 1, 1);

        comboBox_port = new QComboBox(ExperimentSetup);
        comboBox_port->setObjectName("comboBox_port");

        gridLayout->addWidget(comboBox_port, 1, 1, 1, 1);

        label_sequence = new QLabel(ExperimentSetup);
        label_sequence->setObjectName("label_sequence");

        gridLayout->addWidget(label_sequence, 9, 0, 1, 1, Qt::AlignTop);

        doubleSpinBox_sampleRate = new QDoubleSpinBox(ExperimentSetup);
        doubleSpinBox_sampleRate->setObjectName("doubleSpinBox_sampleRate");
        doubleSpinBox_sampleRate->setDecimals(3);
        doubleSpinBox_sampleRate->setMaximum(1000.000000000000000);
        doubleSpinBox_sampleRate->setValue(1.000000000000000);

        gridLayout->addWidget(doubleSpinBox_sampleRate, 8, 1, 1, 1);

        label_timeout = new QLabel(ExperimentSetup);
        label_timeout->setObjectName("label_timeout");

        gridLayout->addWidget(label_timeout, 7, 0, 1, 1);

        doubleSpinBox_timeout = new QDoubleSpinBox(ExperimentSetup);
        doubleSpinBox_timeout->setObjectName("doubleSpinBox_timeout");
        doubleSpinBox_timeout->setDecimals(3);
        doubleSpinBox_timeout->setMinimum(1.000000000000000);

        gridLayout->addWidget(doubleSpinBox_timeout, 7, 1, 1, 1);

        label_secTimeout = new QLabel(ExperimentSetup);
        label_secTimeout->setObjectName("label_secTimeout");

        gridLayout->addWidget(label_secTimeout, 7, 2, 1, 1);

        QWidget::setTabOrder(doubleSpinBox_timeBetweenTrials, plainTextEdit_sequence);
        QWidget::setTabOrder(plainTextEdit_sequence, spinBox_nTrials);
        QWidget::setTabOrder(spinBox_nTrials, pushButton_generateRandomSequence);

        retranslateUi(ExperimentSetup);

        QMetaObject::connectSlotsByName(ExperimentSetup);
    } // setupUi

    void retranslateUi(QWidget *ExperimentSetup)
    {
        ExperimentSetup->setWindowTitle(QCoreApplication::translate("ExperimentSetup", "Form", nullptr));
        label_sampleRate->setText(QCoreApplication::translate("ExperimentSetup", "Sample rate:", nullptr));
        label_port->setText(QCoreApplication::translate("ExperimentSetup", "Port:", nullptr));
        label_secBetweenTrials->setText(QCoreApplication::translate("ExperimentSetup", "seconds", nullptr));
        label_sequenceErr->setText(QCoreApplication::translate("ExperimentSetup", "[!!!]", nullptr));
        pushButton_generateRandomSequence->setText(QCoreApplication::translate("ExperimentSetup", "Generate Random", nullptr));
        label_nTrials->setText(QCoreApplication::translate("ExperimentSetup", "Number of trials:", nullptr));
        label_timeBetweenTrials->setText(QCoreApplication::translate("ExperimentSetup", "Time between trials:", nullptr));
        pushButton_port->setText(QCoreApplication::translate("ExperimentSetup", "Reload Ports", nullptr));
        label_portErr->setText(QCoreApplication::translate("ExperimentSetup", "[!!!]", nullptr));
        label_HzSampleRate->setText(QCoreApplication::translate("ExperimentSetup", "Hz", nullptr));
        label_sequence->setText(QCoreApplication::translate("ExperimentSetup", "Sequence:", nullptr));
        label_timeout->setText(QCoreApplication::translate("ExperimentSetup", "Trial timeout:", nullptr));
        label_secTimeout->setText(QCoreApplication::translate("ExperimentSetup", "seconds", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExperimentSetup: public Ui_ExperimentSetup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPERIMENTSETUP_H
