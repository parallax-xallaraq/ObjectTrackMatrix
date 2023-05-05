#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // setup pointers
    _port    = new SerialControl();
    _fileControl = new ExperimentFileControl();

    // hide
    ui->groupBox_experimentDetails->setVisible(false);
    ui->groupBox_objectMatrix->setVisible(false);
}

MainWindow::~MainWindow()
{
    _port->ClosePort();
    delete _port;
    _port = nullptr;

    delete _fileControl;
    _fileControl = nullptr;

    delete ui;
}

void MainWindow::on_pushButton_newExperiment_clicked()
{
    BeginNewExperiment();
}

void MainWindow::on_pushButton_experimentSubmit_clicked()
{
    SubmitExperimentInfo();
}

void MainWindow::on_pushButton_experimentEdit_clicked()
{
    EditExperimentInfo();
}

void MainWindow::on_pushButton_startExperiment_clicked()
{
    StartExperiment();
}

void MainWindow::BeginNewExperiment()
{
    // allow user input
    EnableExperimentInputs(true);
    // toggle visible groupboxes
    ui->groupBox_NewUser->setVisible(false);
    ui->groupBox_experimentDetails->setVisible(true);
}

void MainWindow::SubmitExperimentInfo()
{
    // check that all required inputs are valid
    bool isUserGood     = ui->widget_userInfo->CheckRequiredInputs();
    bool isSequenceGood = ui->widget_experimentSetup->CheckRequiredInputs();

    // if all inputs are valid...
    if(isUserGood && isSequenceGood){
        // submit info
        EnableExperimentInputs(false);
        ui->groupBox_objectMatrix->setVisible(true);
    }
}

void MainWindow::EditExperimentInfo()
{
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

void MainWindow::StartExperiment()
{
    // lock experiment details
    ui->groupBox_experimentDetails->setEnabled(false);

    // set file directory path
    _fileControl->setParentDirectorypath(ui->widget_userInfo->GetFilePath());
    _fileControl->setExperimentDirectoryName(ui->widget_userInfo->GetExperimentTitle());

    // write Experiment Info file
    _fileControl->WriteExperiemtnInfoFile(
                ui->widget_userInfo->GetExperimentTitle(),
                ui->widget_userInfo->GetExperimenterName(),
                ui->widget_userInfo->GetSubjectName(),
                ui->widget_userInfo->GetExperimentDate(),
                ui->widget_userInfo->GetNotes(),
                ui->widget_experimentSetup->GetTimeBetweenTrials_ms(),
                ui->widget_experimentSetup->GetTimeout_ms(),
                ui->widget_experimentSetup->GetSampleRate_Hz(),
                ui->widget_experimentSetup->GetNumberOfTrials(),
                ui->widget_experimentSetup->GetTrialSequence()
             );

    // open serial port
    OpenPort();

    // test that device is connected
    if(!TestConnection()){
        throw std::invalid_argument("Connection failed.");
    }

    // write experiment setup settings to hardware
    bool successInit = InitExperiment();
    if(!successInit){
        throw std::invalid_argument("Initialization failed.");
    }

    // start reading data
    bool successRun = RunExperiment();
    if(!successRun){
        throw std::invalid_argument("Streaming failed.");
    }

    // analyze trials and write to file
    _fileControl->WriteTrialStatusFile(ui->widget_experimentSetup->GetTrialSequence());
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
    qDebug() << "Initializing...";

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

    // TRIAL
    QList<int> trialSequence = ui->widget_experimentSetup->GetTrialSequence();
    for (int i=0; i<trialSequence.length(); i++)
    {
        written =_port->WriteAndReadPacket_CheckMatch(
                        Commands::TRIAL,
                        trialSequence[i],
                        i+1
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

    qDebug() << "Experiment initialized.";

    // return true when all commands were written and read back, false otherwise
    return(success);
}

bool MainWindow::RunExperiment()
{
    // open experiment stream file
    _fileControl->StartStreamDataFile(ui->widget_experimentSetup->GetSampleRate_Hz());

    qDebug() << "Streaming...";

    // STREAM ON
    bool success =_port->WriteAndReadPacket_CheckMatch(
            Commands::STREAM,
            0,
            1
        );
    if(!success){
        _fileControl->EndStreamDataFile();
        return(false);
    }

    bool readAgain  = true;
    bool calledSTOP = false;

    // read data
    while(readAgain){
        // read
        QList<uint> pkt = _port->ReadPacket();
        int command  = pkt[Commands::CMD];
        int objectID = pkt[Commands::ID];
        int trial    = pkt[Commands::DATA];

        // stop experiment
        if( trial >= ui->widget_experimentSetup->GetNumberOfTrials() ){
            if(!calledSTOP){
                // STREAM OFF
                _port->WritePacket(
                   Commands::STREAM,
                   0,
                   0
                );
                calledSTOP = true;
            }
        }

        // update condition -- stop when STREAM:0:0 is read
        if( command == Commands::STREAM && objectID == 0 && trial == 0 ){
            readAgain = false;
        }
        else{
            // write to file
            _fileControl->WriteStreamDataline(trial,objectID);
        }
    }

    qDebug() << "Streaming finished.";

    // close file
    _fileControl->EndStreamDataFile();
    return(success);
}
