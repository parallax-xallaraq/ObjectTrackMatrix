#include "ExperimentSetup.h"
#include "ui_ExperimentSetup.h"

#include <QStringList>
#include <QRandomGenerator>
#include <QDebug>

// ====================================
// Created by: Thresa Kelly
// Email: ThresaKelly133@gmail.com
// Date: 3/22/2023
// ====================================

ExperimentSetup::ExperimentSetup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExperimentSetup)
{
    ui->setupUi(this);

    // initialize
    SetNumberOfObjects(12);
    on_pushButton_port_clicked();

    // hide errors
    ui->label_sequenceErr->setVisible(false);
    ui->label_portErr->setVisible(false);
}

ExperimentSetup::~ExperimentSetup()
{
    delete ui;
}

void ExperimentSetup::EnableInputs(bool lock)
{
    // enable or disable user inputs using lock
    ui->doubleSpinBox_timeBetweenTrials->setEnabled(lock);
    ui->spinBox_sampleRate->setEnabled(lock);
    ui->plainTextEdit_sequence->setEnabled(lock);
    ui->spinBox_nTrials->setEnabled(lock);
    ui->pushButton_generateRandomSequence->setEnabled(lock);
    ui->comboBox_port->setEnabled(lock);
    ui->pushButton_port->setEnabled(lock);
    ui->doubleSpinBox_timeout->setEnabled(lock);
}

bool ExperimentSetup::CheckRequiredInputs()
{    
    // hide error lables
    ui->label_sequenceErr->setVisible(false);
    ui->label_portErr->setVisible(false);
    bool valid = true;

    // show error for invalid input(s)
    if(!IsSequenceValid())
    {
        ui->label_sequenceErr->setVisible(true);
        valid = false;
    }
    if(!IsPortValid())
    {
        ui->label_portErr->setVisible(true);
        valid = false;
    }

    return(valid);
}

double ExperimentSetup::GetTimeBetweenTrials_s()
{
    return(ui->doubleSpinBox_timeBetweenTrials->value());
}

int ExperimentSetup::GetTimeBetweenTrials_ms()
{
    return( int( GetTimeBetweenTrials_s() * 1000. ) );
}

double ExperimentSetup::GetTimeout_s()
{
    return(ui->doubleSpinBox_timeout->value());
}

int ExperimentSetup::GetTimeout_ms()
{
    return( int( GetTimeout_s() * 1000. ) );
}

int ExperimentSetup::GetSampleRate_Hz()
{
    return(ui->spinBox_sampleRate->value());
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

QString ExperimentSetup::GetPortName()
{
    return(ui->comboBox_port->currentText());
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

bool ExperimentSetup::IsPortValid()
{
    // a port must be selected
    if( ui->comboBox_port->currentText() == QString("No ports available"))
    {
        return(false);
    }
    return(true);
}

void ExperimentSetup::on_pushButton_port_clicked()
{
    // clear out contents
    ui->comboBox_port->clear();

    // get available serial ports from computer
    QList<QSerialPortInfo> Allports = QSerialPortInfo::availablePorts();

    // no ports
    if( Allports.length() == 0 )
    {
        ui->comboBox_port->addItem(QString("No ports available"));
    }
    // has ports
    else
    {
        for(QSerialPortInfo port : Allports)
        {
            // add all port names to box
            ui->comboBox_port->addItem(port.portName());
        }
    }
}
