#ifndef GETUSERINFO_H
#define GETUSERINFO_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QDate>

// ====================================
// Created by: Thresa Kelly
// Email: ThresaKelly133@gmail.com
// ====================================

namespace Ui {
class GetUserInfo;
}

class GetUserInfo : public QWidget
{
    Q_OBJECT

public:
    explicit GetUserInfo(QWidget *parent = nullptr);
    ~GetUserInfo();
    // input validation
    void EnableInputs(bool lock);
    bool CheckRequiredInputs();
    // getters
    QString GetExperimentTitle();
    QString GetExperimenterName();
    QString GetSubjectName();
    QString GetNotes();
    QString GetFilePath();
    QDate   GetExperimentDate();

private slots:
    void on_pushButton_saveFile_clicked();

private:
    Ui::GetUserInfo *ui;
    // input validation
    bool CheckOneLineEdit(QLineEdit * txt, QLabel * lbl);
    void BrowseFile();
};

#endif // GETUSERINFO_H
