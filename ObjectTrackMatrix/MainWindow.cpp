#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // setup pointers
    cmdCtrl = new Commands();
    port = new QSerialPort(this);

    // hide
    ui->groupBox_experimentDetails->setVisible(false);
    ui->groupBox_objectMatrix->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete cmdCtrl;
    cmdCtrl = nullptr;

    port->close();

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

void MainWindow::on_pushButton_startExperiment_clicked()
{
    // lock experiment details
    ui->groupBox_experimentDetails->setEnabled(false);

    // open serial port
    OpenPort();

    // write experiment setup settings to hardware
    InitExperiment();

    // TODO start reading data
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

void MainWindow::OpenPort()
{
    // set port name
    port->setPortName(ui->widget_experimentSetup->GetPortName());

    // open port for read and write
    port->close();
    port->open(QIODevice::ReadWrite);

    if(port->isOpen())
    {
        // setup port
        port->setBaudRate(QSerialPort::Baud115200);
        port->setDataBits(QSerialPort::Data8);
        port->setParity(QSerialPort::NoParity);
        port->setStopBits(QSerialPort::OneStop);
        port->setFlowControl(QSerialPort::NoFlowControl);
    }
    else
    {
        throw std::invalid_argument("can't open the port");
    }
}

void MainWindow::InitExperiment()
{    
    // NTRIALS
    QByteArray cmdNtrials = cmdCtrl->BuildCommand(
                    Commands::NTRIALS,
                    0,
                    ui->widget_experimentSetup->GetNumberOfTrials()
                );
    port->write(cmdNtrials);
    qDebug() << cmdNtrials;

//    // TRIAL
//    QList<int> trialSequence = ui->widget_experimentSetup->GetTrialSequence();
//    for (int i=0; i<trialSequence.length(); i++)
//    {
//        QByteArray cmdTrial = cmdCtrl->BuildCommand(
//                        Commands::TRIAL,
//                        i+1,
//                        trialSequence[i]
//                    );
//        port->write(cmdTrial);
//    }

//    // SEPARATION
//    QByteArray cmdSeparation = cmdCtrl->BuildCommand(
//                    Commands::SEPARATION,
//                    0,
//                    ui->widget_experimentSetup->GetTimeBetweenTrials_ms()
//                );
//    port->write(cmdSeparation);

//    // TIMEOUT
//    QByteArray cmdTimeout = cmdCtrl->BuildCommand(
//                    Commands::TIMEOUT,
//                    0,
//                    ui->widget_experimentSetup->GetTimeout_ms()
//                );
//    port->write(cmdTimeout);


//    // SAMPLE RATE
//    QByteArray cmdSampleRate = cmdCtrl->BuildCommand(
//                    Commands::SAMPLERATE,
//                    0,
//                    ui->widget_experimentSetup->GetSampleRate_Hz()
//                );
//    port->write(cmdSampleRate);

    qDebug() << "Experiment initialized.";
}
