#ifndef EXPERIMENTSETUP_H
#define EXPERIMENTSETUP_H

#include <QWidget>
#include <QList>

// ====================================
// Created by: Thresa Kelly
// Email: ThresaKelly133@gmail.com
// Date: 2/18/2023
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
    double GetTrialDuration();
    double GetTimeBetweenTrials();
    int GetNumberOfTrials();
    QList<int> GetTrialSequence();

    // setters
    void SetNumberOfObjects(int n);

private slots:
    void on_pushButton_generateRandomSequence_clicked();

private:
    Ui::ExperimentSetup *ui;

    // variables
    int numberOfObjects;

    // input validation
    bool IsSequenceValid();
};

#endif // EXPERIMENTSETUP_H
