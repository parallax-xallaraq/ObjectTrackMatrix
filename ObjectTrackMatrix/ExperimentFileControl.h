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

    enum StreamData {
        TIME,
        TRIAL,
        OBJECT
    };

    // constructors and destructor
    ExperimentFileControl();
    ExperimentFileControl(QString parentDirectorypath, QString experimentDirectoryName);
    ~ExperimentFileControl();

    // WRITE
    // Stream Data file
    void StartStreamDataFile(int sampleRate_Hz);
    void WriteStreamDataline(int trialNumber, int objectId);
    void EndStreamDataFile();
    // other files
    void WriteExperiemtnInfoFile(QString experimentTitle, QString experimenterName, QString subjectName, QDate date, QString notes, int timeBetweenTrials_ms, int timeout_ms, int samplerate_Hz, int numberOfTrials, QList<int> trialSequence);
    void WriteTrialStatusFile(QList<int> trialSequence);

    // READ
    QList<QStringList> ReadCSV(QFile * file);

    // setters (call these first!)
    void setParentDirectorypath(const QString &newParentDirectorypath);
    void setExperimentDirectoryName(const QString &newExperimentDirectory);

private:
    // file paths
    QString _parentDirectorypath;
    QString _experimentDirectoryName;

    // time tracking
    int _currentTime_ms;
    int _samplingPeriod_ms;

    // files
    QFile * _streamData;
    QFile * _experimentInfo;
    QFile * _trialStatus;

    // file control
    QFile * OpenFileInParentDirectory(QString fileName);
    void    CloseFile(QFile * file);
    void    DeleteFileObject(QFile * file);

    // file writing
    void WriteLine_TwoColCSV(   QFile * file, const char * left,       QString right );
    void WriteLine_TwoColCSV(   QFile * file, const char * left,       int     right );
    void WriteLine_TwoColCSV(   QFile * file,       int    left,       int     right );
    void WriteLine_ThreeColCSV( QFile * file, const char * left, const char *  center, const char * right );
    void WriteLine_ThreeColCSV( QFile * file,       int    left,       int     center,       int    right );
};

#endif // EXPERIMENTFILECONTROL_H
