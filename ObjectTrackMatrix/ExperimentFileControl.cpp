#include "ExperimentFileControl.h"

#include <QDir>
#include <QDebug>
#include <QTextStream>

ExperimentFileControl::ExperimentFileControl()
{
    // initialize member variables
    _parentDirectorypath     = "";
    _experimentDirectoryName = "";
    _currentTime_ms    = 0;
    _samplingPeriod_ms = 0;
    _streamData     = nullptr;
    _experimentInfo = nullptr;
    _trialStatus    = nullptr;
}

ExperimentFileControl::ExperimentFileControl(QString parentDirectorypath, QString experimentDirectoryName)
{
    // set strings
    setParentDirectorypath(parentDirectorypath);
    setExperimentDirectoryName(experimentDirectoryName);
    // set times
    _currentTime_ms    = 0;
    _samplingPeriod_ms = 0;
    // set files to null
    _streamData     = nullptr;
    _experimentInfo = nullptr;
    _trialStatus    = nullptr;
}

ExperimentFileControl::~ExperimentFileControl()
{
    DeleteFileObject(_streamData);
    DeleteFileObject(_experimentInfo);
    DeleteFileObject(_trialStatus);
}

void ExperimentFileControl::StartStreamDataFile(int sampleRate_Hz)
{
    // remove existing file
    DeleteFileObject(_streamData);

    // create new file
    _streamData = OpenFileInParentDirectory("Experiment_Data_Stream.csv");

    // init times
    _currentTime_ms = 0;
    _samplingPeriod_ms = (1.0 / sampleRate_Hz) * 1000.0 ;

    // write column names
    WriteLine_ThreeColCSV(_streamData, "Time (ms)", "Trial", "Object");
}

void ExperimentFileControl::WriteStreamDataline(int trialNumber, int objectId)
{
    // write info
    WriteLine_ThreeColCSV(_streamData, _currentTime_ms, trialNumber, objectId);

    // increment timestamp
    _currentTime_ms += _samplingPeriod_ms;
}

void ExperimentFileControl::EndStreamDataFile()
{
    // close file
    CloseFile(_streamData);
}

void ExperimentFileControl::WriteExperiemtnInfoFile(QString experimentTitle, QString experimenterName, QString subjectName, QDate date, QString notes, int timeBetweenTrials_ms, int timeout_ms, int samplerate_Hz, int numberOfTrials, QList<int> trialSequence)
{
    // remove existing file
    DeleteFileObject(_experimentInfo);

    // create new file
    _experimentInfo = OpenFileInParentDirectory("Experiment_Information.csv");

    // write away!
    WriteLine_TwoColCSV(_experimentInfo,    "Experimenter Title",       experimentTitle );
    WriteLine_TwoColCSV(_experimentInfo,    "Experimenter Name",        experimenterName );
    WriteLine_TwoColCSV(_experimentInfo,    "Subject Name",             subjectName );
    WriteLine_TwoColCSV(_experimentInfo,    "Date",                     date.toString("dddd MMMM dd yyyy") );
    WriteLine_TwoColCSV(_experimentInfo,    "Notes",                    notes );
    WriteLine_TwoColCSV(_experimentInfo,    "Time between trials (ms)", timeBetweenTrials_ms );
    WriteLine_TwoColCSV(_experimentInfo,    "Trial Timeout (ms)",       timeout_ms );
    WriteLine_TwoColCSV(_experimentInfo,    "Sample rate (Hz)",         samplerate_Hz );
    WriteLine_TwoColCSV(_experimentInfo,    "Number of trials",         numberOfTrials );
    WriteLine_TwoColCSV(_experimentInfo,    "Trial number:",            "Object:" );
    for(int i=0; i<numberOfTrials; i++){
        WriteLine_TwoColCSV(_experimentInfo, i+1,                       trialSequence[i] );
    }

    // close file
    CloseFile(_experimentInfo);
}

void ExperimentFileControl::WriteTrialStatusFile(QList<int> trialSequence)
{
    // read stream data file
    QList<QStringList> streamData = ReadCSV("Experiment_Data_Stream.csv");

    // init as false
    QList<bool> trialStatus;
    for(int i=0; i<trialSequence.length(); i++){
        trialStatus.append(false);
    }

    // iterate through each row in file
    int currentTrial  = 0;
    for(int i=1; i<streamData.length(); i++){
        // get values
        int trialInRow  = streamData[i][StreamData::TRIAL].toInt();
        int objectInRow = streamData[i][StreamData::OBJECT].toInt();
        // new trial
        if(trialInRow != currentTrial){
            currentTrial = trialInRow;
        }
        // correct object moved
        if(objectInRow == trialSequence[currentTrial-1]){
            trialStatus[currentTrial-1] = true;
        }
    }

    // create new file
    DeleteFileObject(_trialStatus);
    _trialStatus = OpenFileInParentDirectory("Trial_Status.csv");

    // write away!
    WriteLine_ThreeColCSV(_trialStatus, "Trial number", "Object", "Status");
    for(int i=0; i<trialSequence.length(); i++){
        WriteLine_ThreeColCSV(_trialStatus, i+1, trialSequence[i], trialStatus[i] );
    }

    // close file
    CloseFile(_trialStatus);
}

QList<QStringList> ExperimentFileControl::ReadCSV(QString fileName)
{
    // Open csv-file
    QFile * file = OpenFileInParentDirectory(fileName);
    // read data from file
    QTextStream stream(file);
    QList<QStringList> data;
    while (stream.atEnd() == false){
        data << stream.readLine().split(",");
    }
    // finish
    DeleteFileObject(file);
    return data;
}


QFile *ExperimentFileControl::OpenFileInParentDirectory(QString fileName)
{
    // build filename
    QString finishedFileName = "";

    if(!_parentDirectorypath.isEmpty()){
        // add directory path
        finishedFileName.append(_parentDirectorypath);
    }

    if(!_experimentDirectoryName.isEmpty()){
        // add experiment directory to path
        finishedFileName.append('/');
        finishedFileName.append(_experimentDirectoryName);
    }

    // create directory if it doesnt exist
    QDir dir(finishedFileName);
    if (!dir.exists())
        dir.mkpath(".");

    // add backslash if path given
    if(!finishedFileName.isEmpty()){
        finishedFileName.append('/');
    }

    // add file name
    finishedFileName.append(fileName);

    // create and open file
    QFile * file = new QFile(finishedFileName);
    file->open(QIODeviceBase::ReadWrite);

    return(file);
}

void ExperimentFileControl::CloseFile(QFile *file)
{
    if(file != nullptr){
        if(file->isOpen()){
            file->close();
        }
    }
}

void ExperimentFileControl::DeleteFileObject(QFile *file)
{
    if(file != nullptr){
        CloseFile(file);
        delete file;
        file = nullptr;
    }
}

void ExperimentFileControl::WriteLine_TwoColCSV(QFile *file, const char *left, QString right)
{
    file->write(left);
    file->write(",");
    file->write(right.toUtf8());
    file->write("\n");
}

void ExperimentFileControl::WriteLine_TwoColCSV(QFile *file, const char *left, int right)
{
    file->write(left);
    file->write(",");
    file->write(QString::number(right).toUtf8());
    file->write("\n");
}

void ExperimentFileControl::WriteLine_TwoColCSV(QFile *file, int left, int right)
{
    file->write(QString::number(left).toUtf8());
    file->write(",");
    file->write(QString::number(right).toUtf8());
    file->write("\n");
}

void ExperimentFileControl::WriteLine_ThreeColCSV(QFile *file, const char *left, const char *center, const char *right)
{
    file->write(left);
    file->write(",");
    file->write(center);
    file->write(",");
    file->write(right);
    file->write("\n");
}

void ExperimentFileControl::WriteLine_ThreeColCSV(QFile *file, int left, int center, int right)
{
    file->write(QString::number(left).toUtf8());
    file->write(",");
    file->write(QString::number(center).toUtf8());
    file->write(",");
    file->write(QString::number(right).toUtf8());
    file->write("\n");
}

void ExperimentFileControl::setParentDirectorypath(const QString &newParentDirectorypath)
{
    _parentDirectorypath = newParentDirectorypath;
}

void ExperimentFileControl::setExperimentDirectoryName(const QString &newExperimentDirectoryName)
{
    _experimentDirectoryName = newExperimentDirectoryName;
}
