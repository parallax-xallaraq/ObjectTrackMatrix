#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // hide
    ui->groupBox_experimentDetails->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_newExperiment_clicked()
{
    // toggle visible groupboxes
    ui->groupBox_NewUser->setVisible(false);
    ui->groupBox_experimentDetails->setVisible(true);
}

void MainWindow::on_pushButton_experimentSubmit_clicked()
{
    // check that all required inputs are valid
    bool isUserGood = ui->widget_userInfo->CheckRequiredInputs();

    // if all inputs are valid, disable fields
    if(isUserGood)
    {
        ui->widget_userInfo->EnableInputs(false);
        ui->widget_experimentSetup->EnableInputs(false);
    }

}
