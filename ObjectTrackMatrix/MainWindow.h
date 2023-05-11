#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>

#include "ExperimentFileControl.h"
#include "SerialControl.h"

// ====================================
// Created by: Thresa Kelly
// Email: ThresaKelly133@gmail.com
// ====================================

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_newExperiment_clicked();
    void on_pushButton_experimentSubmit_clicked();
    void on_pushButton_experimentEdit_clicked();
    void on_pushButton_startExperiment_clicked();

private:
    Ui::MainWindow *ui;

    // class objects
    SerialControl * _port;
    ExperimentFileControl * _fileControl;

    // experiment setup
    void BeginNewExperiment();
    void SubmitExperimentInfo();
    void EditExperimentInfo();
    void EnableExperimentInputs(bool en);

    // run experiment
    void StartExperiment();
    void OpenPort();
    bool TestConnection();
    bool InitExperiment();
    bool RunExperiment();

    // testing
    QList<double> PingTimeDelay(int n);
};
#endif // MAINWINDOW_H
