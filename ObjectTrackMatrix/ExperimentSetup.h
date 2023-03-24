#ifndef EXPERIMENTSETUP_H
#define EXPERIMENTSETUP_H

#include <QWidget>
#include <QList>
#include <QSerialPortInfo>

// ====================================
// Created by: Thresa Kelly
// Email: ThresaKelly133@gmail.com
// Date: 3/22/2023
// ====================================

namespace Ui {
class ExperimentSetup;
}

class ExperimentSetup : public QWidget
{
    Q_OBJECT

public:
    explicit ExperimentSetup(QWidget *parent = nullptr);
    ~ExperimentSetup();

    // input validation
    void EnableInputs(bool lock);
    bool CheckRequiredInputs();

    // getters
    double      GetTimeBetweenTrials_s();
    int         GetTimeBetweenTrials_ms();
    double      GetTimeout_s();
    int         GetTimeout_ms();
    int         GetSampleRate_Hz();
    int         GetNumberOfTrials();
    QList<int>  GetTrialSequence();
    QString     GetPortName();

    // setters
    void SetNumberOfObjects(int n);

private slots:
    void on_pushButton_generateRandomSequence_clicked();
    void on_pushButton_port_clicked();

private:
    Ui::ExperimentSetup *ui;

    // variables
    int numberOfObjects;

    // input validation
    bool IsSequenceValid();
    bool IsPortValid();
};

#endif // EXPERIMENTSETUP_H
