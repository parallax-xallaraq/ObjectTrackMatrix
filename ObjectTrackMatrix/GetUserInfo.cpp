#include "GetUserInfo.h"
#include "ui_GetUserInfo.h"

#include <QDate>

// ====================================
// Created by: Thresa Kelly
// Email: ThresaKelly133@gmail.com
// Date: 2/18/2023
// ====================================

GetUserInfo::GetUserInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GetUserInfo)
{
    ui->setupUi(this);

    // set date to current date
    ui->dateEdit_experimentDate->setDate(QDate::currentDate());

    // hide errors
    ui->label_errTitle->setVisible(false);
    ui->label_errName->setVisible(false);
    ui->label_errSubject->setVisible(false);
    ui->label_errSaveFile->setVisible(false);
}

GetUserInfo::~GetUserInfo()
{
    delete ui;
}

void GetUserInfo::EnableInputs(bool lock)
{
    // enable or disable user inputs using lock
    ui->lineEdit_title->setEnabled(lock);
    ui->lineEdit_experimenterName->setEnabled(lock);
    ui->lineEdit_subjectName->setEnabled(lock);
    ui->dateEdit_experimentDate->setEnabled(lock);
    ui->plainTextEdit_notes->setEnabled(lock);
    ui->lineEdit_saveFile->setEnabled(lock);
}

bool GetUserInfo::CheckRequiredInputs()
{
    // check that each required inputs are good
    bool isTitleGood   = CheckOneLineEdit(ui->lineEdit_title, ui->label_errTitle);
    bool isNameGood    = CheckOneLineEdit(ui->lineEdit_experimenterName, ui->label_errName);
    bool isSubjectGood = CheckOneLineEdit(ui->lineEdit_subjectName, ui->label_errSubject);
    bool isFileGood    = CheckOneLineEdit(ui->lineEdit_saveFile, ui->label_errSaveFile);
    // returns true when all lines are good
    return((isTitleGood && isNameGood) && (isSubjectGood && isFileGood));
}

QString GetUserInfo::GetExperimentTitle()
{
    return(ui->lineEdit_title->text());
}

QString GetUserInfo::GetExperimenterName()
{
    return(ui->lineEdit_experimenterName->text());
}

QString GetUserInfo::GetSubjectName()
{
    return(ui->lineEdit_subjectName->text());
}

QString GetUserInfo::GetNotes()
{
    return(ui->plainTextEdit_notes->toPlainText());
}

QString GetUserInfo::GetFilePath()
{
    return(ui->lineEdit_saveFile->text());
}

QDate GetUserInfo::GetExperimentDate()
{
    return(ui->dateEdit_experimentDate->date());
}

bool GetUserInfo::CheckOneLineEdit(QLineEdit *txt, QLabel *lbl)
{
    // if the QLineEdit has no text, then show warning lable
    if(txt->text().isEmpty())
    {
        lbl->setVisible(true);
        return(false);
    }
    // else hide warning label
    lbl->setVisible(false);
    return(true);
}
