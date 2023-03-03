#include "MainWindow.h"
#include "ui_MainWindow.h"

// ====================================
// Created by: Thresa Kelly
// Email: ThresaKelly133@gmail.com
// Date: 2/18/2023
// ====================================

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // hide
    ui->groupBox_experimentDetails->setVisible(false);
    ui->groupBox_objectMatrix->setVisible(false);
}

MainWindow::~MainWindow()
{
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

void MainWindow::on_pushButton_startExperiment_clicked()
{
    // lock experiment details
    ui->groupBox_experimentDetails->setEnabled(false);
}
