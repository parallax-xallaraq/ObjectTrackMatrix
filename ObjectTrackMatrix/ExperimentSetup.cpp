#include "ExperimentSetup.h"
#include "ui_ExperimentSetup.h"

#include <QStringList>
#include <QRandomGenerator>

// ====================================
// Created by: Thresa Kelly
// Email: ThresaKelly133@gmail.com
// Date: 2/18/2023
// ====================================

ExperimentSetup::ExperimentSetup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExperimentSetup)
{
    ui->setupUi(this);

    // hide errors
    ui->label_errSequence->setVisible(false);
}

ExperimentSetup::~ExperimentSetup()
{
    delete ui;
}

void ExperimentSetup::EnableInputs(bool lock)
{
    // enable or disable user inputs using lock
    ui->doubleSpinBox_timeBetweenTrials->setEnabled(lock);
    ui->doubleSpinBox_trialDuration->setEnabled(lock);
    ui->plainTextEdit_sequence->setEnabled(lock);
    ui->spinBox_nTrials->setEnabled(lock);
    ui->pushButton_generateRandomSequence->setEnabled(lock);
}

bool ExperimentSetup::CheckRequiredInputs()
{
    // sequence must be properly formatted:
    //  #, #, #, # --where each number is 1-12

    // split sequence text at each comma and check each item
    QStringList sequenceList = ui->plainTextEdit_sequence->toPlainText().split(",");
    for (int i=0; i < sequenceList.length(); i++ )
    {
        bool ok; // true when conversion to int is successful
        int val = sequenceList[i].toInt(&ok);

        // value must be int between 1-12. if not, show error
        if(!ok || (val < 1 || val > numberOfObjects) )
        {
            ui->label_errSequence->setVisible(true);
            return(false);
        }
    }
    // else, everything is good!
    ui->label_errSequence->setVisible(false);
    return(true);
}

void ExperimentSetup::on_pushButton_generateRandomSequence_clicked()
{
    // initialize sequence string
    QString seq = "";
    // generate n random integers between 1-numberOfObjects
    int nTrials = ui->spinBox_nTrials->value();
    for (int i=0; i<nTrials; i++)
    {
        int val =  QRandomGenerator::global()->bounded(1, numberOfObjects+1);
        seq = seq + QString::number(val);
        if(i!=nTrials-1)
        {
            seq = seq + ",";
        }
    }
    // write sequence to textbox
    ui->plainTextEdit_sequence->setPlainText(seq);
}
