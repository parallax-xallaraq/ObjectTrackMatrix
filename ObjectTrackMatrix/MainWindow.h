#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>

#include "Commands.h"

// ====================================
// Created by: Thresa Kelly
// Email: ThresaKelly133@gmail.com
// Date: 3/29/2023
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

    Commands * cmdCtrl;
    QSerialPort * port;

    void EnableExperimentInputs(bool en);
    void OpenPort();
    void InitExperiment();
};
#endif // MAINWINDOW_H
