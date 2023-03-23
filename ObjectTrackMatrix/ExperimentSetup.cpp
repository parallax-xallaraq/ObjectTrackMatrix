#include "ExperimentSetup.h"
#include "ui_ExperimentSetup.h"

#include <QStringList>
#include <QRandomGenerator>
#include <QDebug>

#include "Commands.h"

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

    // initialize variables
    SetNumberOfObjects(12);

    // hide errors
    ui->label_sequenceErr->setVisible(false);

    // TESTING
    Commands cmd = Commands();
}

ExperimentSetup::~ExperimentSetup()
{
    delete ui;
}

void ExperimentSetup::EnableInputs(bool lock)
{
    // enable or disable user inputs using lock
    ui->doubleSpinBox_timeBetweenTrials->setEnabled(lock);
    ui->doubleSpinBox_sampleRate->setEnabled(lock);
    ui->plainTextEdit_sequence->setEnabled(lock);
    ui->spinBox_nTrials->setEnabled(lock);
    ui->pushButton_generateRandomSequence->setEnabled(lock);
}

bool ExperimentSetup::CheckRequiredInputs()
{
    if(IsSequenceValid())
    {
        ui->label_sequenceErr->setVisible(false);
        return(true);
    }
    else
    {
        ui->label_sequenceErr->setVisible(true);
        return(false);
    }
}

int ExperimentSetup::GetSampleRate()
{
    return(ui->doubleSpinBox_sampleRate->value());
}

double ExperimentSetup::GetTimeBetweenTrials()
{
    return(ui->doubleSpinBox_timeBetweenTrials->value());
}

int ExperimentSetup::GetNumberOfTrials()
{
    // verify valid sequence
    if(!IsSequenceValid()) throw "Sequence is Invalid";

    // return length of sequence
    QStringList sequenceList = ui->plainTextEdit_sequence->toPlainText().split(",");
    int len = sequenceList.length();
    return(len);
}

QList<int> ExperimentSetup::GetTrialSequence()
{
    // verify valid sequence
    if(!IsSequenceValid()) throw "Sequence is Invalid";

    // initialize list
    QList<int> seq;
    // iterate through each sequence item
    QStringList sequenceList = ui->plainTextEdit_sequence->toPlainText().split(",");
    for (int i=0; i < sequenceList.length(); i++ )
    {
        // convert item to int and append to sequence
        seq.append(sequenceList[i].toInt());
    }
    // return sequence list
    return(seq);
}

void ExperimentSetup::SetNumberOfObjects(int n)
{
    numberOfObjects = n;
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

bool ExperimentSetup::IsSequenceValid()
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
            return(false);
        }
    }
    // else, everything is good!
    return(true);
}

void ExperimentSetup::on_pushButton_port_clicked()
{

}
