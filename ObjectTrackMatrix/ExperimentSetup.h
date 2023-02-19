#ifndef EXPERIMENTSETUP_H
#define EXPERIMENTSETUP_H

#include <QWidget>

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


private slots:
    void on_pushButton_generateRandomSequence_clicked();

private:
    Ui::ExperimentSetup *ui;

    int numberOfObjects = 12;
};

#endif // EXPERIMENTSETUP_H
