#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // setup pointers
    _port    = new SerialControl();

    // hide
    ui->groupBox_experimentDetails->setVisible(false);
    ui->groupBox_objectMatrix->setVisible(false);
}

MainWindow::~MainWindow()
{
    _port->ClosePort();
    delete _port;
    _port = nullptr;

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

    // test that device is connected
    if(!TestConnection()){
        throw std::invalid_argument("Connection failed.");
    }

    // write experiment setup settings to hardware
    bool success = InitExperiment();
    if(!success){
        throw std::invalid_argument("Initialization failed.");
    }
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
    _port->OpenPort(ui->widget_experimentSetup->GetPortName());
}

bool MainWindow::TestConnection()
{
    // true if lists match, false otherwise
    return(_port->WriteAndReadPacket_CheckMatch(Commands::PING,0,0));
}

bool MainWindow::InitExperiment()
{
    // status flags
    bool success = true;
    bool written = false;

    // NTRIALS
    written =_port->WriteAndReadPacket_CheckMatch(
                    Commands::NTRIALS,
                    0,
                    ui->widget_experimentSetup->GetNumberOfTrials()
                );
    success = success && written;
/*
    // TRIAL
    QList<int> trialSequence = ui->widget_experimentSetup->GetTrialSequence();
    for (int i=0; i<trialSequence.length(); i++)
    {
        written =_port->WriteAndReadPacket_CheckMatch(
                        Commands::TRIAL,
                        i+1,
                        trialSequence[i]
                    );
        success = success && written;
    }

    // SEPARATION
    written =_port->WriteAndReadPacket_CheckMatch(
                    Commands::SEPARATION,
                    0,
                    ui->widget_experimentSetup->GetTimeBetweenTrials_ms()
                );
    success = success && written;

    // TIMEOUT
    written =_port->WriteAndReadPacket_CheckMatch(
                    Commands::TIMEOUT,
                    0,
                    ui->widget_experimentSetup->GetTimeout_ms()
                );
    success = success && written;

    // SAMPLE RATE
    written =_port->WriteAndReadPacket_CheckMatch(
                    Commands::SAMPLERATE,
                    0,
                    ui->widget_experimentSetup->GetSampleRate_Hz()
                );
    success = success && written;
*/
    qDebug() << "Experiment initialized.";

    // return true when all commands were written and read back, false otherwise
    return(success);
}
