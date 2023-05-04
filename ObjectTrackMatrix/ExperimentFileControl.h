#ifndef EXPERIMENTFILECONTROL_H
#define EXPERIMENTFILECONTROL_H

#include <QFile>
#include <QDate>
#include <QList>

// ====================================
// Created by: Thresa Kelly
// Email: ThresaKelly133@gmail.com
// ====================================

class ExperimentFileControl
{
public:
    // constructors and destructor
    ExperimentFileControl();
    ExperimentFileControl(QString parentDirectorypath, QString experimentDirectoryName);
    ~ExperimentFileControl();

    // Stream Data file
    void StartStreamDataFile();
    void WriteStreamDataline();
    void EndStreamDataFile();
    // other files
    void WriteExperiemtnInfoFile(QString experimenterName, QString subjectName, QDate date, QString notes,
                                 int timeBetweenTrials_ms, int timeout_ms, int samplerate_Hz, int numberOfTrials, QList<int> trialSequence);
    void WriteTrialStatusFile();

    // setters
    void setParentDirectorypath(const QString &newParentDirectorypath);
    void setExperimentDirectoryName(const QString &newExperimentDirectory);

private:
    // file paths
    QString _parentDirectorypath;
    QString _experimentDirectoryName;

    // files
    QFile * _streamData;
    QFile * _experimentInfo;
    QFile * _trialStatus;

    // file control
    QFile * OpenFileInParentDirectory(QString fileName);
    void CloseFile(QFile * file);
    void DeleteFile(QFile * file);

    // file writing
    void WriteLine_TwoColCSV(QFile * file, const char * left, QString right);
    void WriteLine_TwoColCSV(QFile * file, const char * left, int right);
    void WriteLine_TwoColCSV(QFile * file, int left, int right);
};

#endif // EXPERIMENTFILECONTROL_H
