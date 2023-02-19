#include "ExperimentSetup.h"
#include "ui_ExperimentSetup.h"

ExperimentSetup::ExperimentSetup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExperimentSetup)
{
    ui->setupUi(this);
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
