#include "MainWindow.h"
#include "ui_MainWindow.h"

// ====================================
// Created by: Thresa Kelly
// Email: ThresaKelly133@gmail.com
// Date: 03/03/2023
// ====================================

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // create command control object
    cmdCtrl = new Commands();

    // hide
    ui->groupBox_experimentDetails->setVisible(false);
    ui->groupBox_objectMatrix->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete cmdCtrl;
    cmdCtrl = nullptr;

    delete ui;
}

void MainWindow::on_pushButton_newExperiment_clicked()
{
    // allow user input
    EnableExperimentInputs(true);
    // toggle visible groupboxes
    ui->groupBox_NewUser->setVisible(false);
    ui->groupBox_experimentDetails->setVisible(true);
}

void MainWindow::on_pushButton_experimentSubmit_clicked()
{
    // check that all required inputs are valid
    bool isUserGood = ui->widget_userInfo->CheckRequiredInputs();
    bool isSequenceGood = ui->widget_experimentSetup->CheckRequiredInputs();

    // if all inputs are valid...
    if(isUserGood && isSequenceGood)
    {
        // submit info
        EnableExperimentInputs(false);
        ui->groupBox_objectMatrix->setVisible(true);
    }
}

void MainWindow::on_pushButton_experimentEdit_clicked()
{
    // allow input
    EnableExperimentInputs(true);
}

void MainWindow::EnableExperimentInputs(bool en)
{
    // enable user input fields
    ui->widget_userInfo->EnableInputs(en);
    ui->widget_experimentSetup->EnableInputs(en);
    // toggle button visibility
    ui->pushButton_experimentSubmit->setVisible(en);
    ui->pushButton_experimentEdit->setVisible(!en);
    // un-enable the experiment window
    ui->groupBox_objectMatrix->setEnabled(!en);
}

void MainWindow::InitExperiment()
{
    // NTRIALS
    QList<bool> cmdNtrials = cmdCtrl->BuildCommand(
                    Commands::NTRIALS,
                    0,
                    ui->widget_experimentSetup->GetNumberOfTrials()
                );
    // TODO write here

    // TRIAL
    QList<int> trialSequence = ui->widget_experimentSetup->GetTrialSequence();
    for (int i=0; i<trialSequence.length(); i++)
    {
        QList<bool> cmdTrial = cmdCtrl->BuildCommand(
                        Commands::TRIAL,
                        i,
                        trialSequence[i]
                    );
        // TODO write here
    }

    // SEPARATION
    QList<bool> cmdSeparation = cmdCtrl->BuildCommand(
                    Commands::SEPARATION,
                    0,
                    ui->widget_experimentSetup->GetTimeBetweenTrials_ms()
                );
    // TODO write here

    // TIMEOUT
    QList<bool> cmdTimeout = cmdCtrl->BuildCommand(
                    Commands::TIMEOUT,
                    0,
                    ui->widget_experimentSetup->GetTimeout_ms()
                );
    // TODO write here


    // SAMPLE RATE
    QList<bool> cmdSampleRate = cmdCtrl->BuildCommand(
                    Commands::SAMPLERATE,
                    0,
                    ui->widget_experimentSetup->GetSampleRate_Hz()
                );
    // TODO write here
}

void MainWindow::on_pushButton_startExperiment_clicked()
{
    // lock experiment details
    ui->groupBox_experimentDetails->setEnabled(false);

    // write experiment setup settings to hardware
    InitExperiment();

    // TODO start reading data
}
