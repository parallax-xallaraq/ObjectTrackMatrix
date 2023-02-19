#ifndef GETUSERINFO_H
#define GETUSERINFO_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QDate>

// ====================================
// Created by: Thresa Kelly
// Email: ThresaKelly133@gmail.com
// Date: 2/18/2023
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
    QDate GetExperimentDate();

private:
    Ui::GetUserInfo *ui;
    // input validation
    bool CheckOneLineEdit(QLineEdit * txt, QLabel * lbl);
};

#endif // GETUSERINFO_H
