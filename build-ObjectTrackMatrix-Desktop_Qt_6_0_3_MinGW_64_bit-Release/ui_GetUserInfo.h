/********************************************************************************
** Form generated from reading UI file 'GetUserInfo.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GETUSERINFO_H
#define UI_GETUSERINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GetUserInfo
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label_experimenterName;
    QLineEdit *lineEdit_experimenterName;
    QLabel *label_subjectName;
    QLineEdit *lineEdit_subjectName;
    QLabel *label_date;
    QDateEdit *dateEdit_todayDate;
    QLabel *label_notes;
    QTextEdit *textEdit_notes;
    QLabel *label_title;
    QLineEdit *lineEdit_title;

    void setupUi(QWidget *GetUserInfo)
    {
        if (GetUserInfo->objectName().isEmpty())
            GetUserInfo->setObjectName(QString::fromUtf8("GetUserInfo"));
        GetUserInfo->resize(400, 345);
        verticalLayout = new QVBoxLayout(GetUserInfo);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_experimenterName = new QLabel(GetUserInfo);
        label_experimenterName->setObjectName(QString::fromUtf8("label_experimenterName"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_experimenterName);

        lineEdit_experimenterName = new QLineEdit(GetUserInfo);
        lineEdit_experimenterName->setObjectName(QString::fromUtf8("lineEdit_experimenterName"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_experimenterName);

        label_subjectName = new QLabel(GetUserInfo);
        label_subjectName->setObjectName(QString::fromUtf8("label_subjectName"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_subjectName);

        lineEdit_subjectName = new QLineEdit(GetUserInfo);
        lineEdit_subjectName->setObjectName(QString::fromUtf8("lineEdit_subjectName"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_subjectName);

        label_date = new QLabel(GetUserInfo);
        label_date->setObjectName(QString::fromUtf8("label_date"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_date);

        dateEdit_todayDate = new QDateEdit(GetUserInfo);
        dateEdit_todayDate->setObjectName(QString::fromUtf8("dateEdit_todayDate"));

        formLayout->setWidget(3, QFormLayout::FieldRole, dateEdit_todayDate);

        label_notes = new QLabel(GetUserInfo);
        label_notes->setObjectName(QString::fromUtf8("label_notes"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_notes);

        textEdit_notes = new QTextEdit(GetUserInfo);
        textEdit_notes->setObjectName(QString::fromUtf8("textEdit_notes"));

        formLayout->setWidget(4, QFormLayout::FieldRole, textEdit_notes);

        label_title = new QLabel(GetUserInfo);
        label_title->setObjectName(QString::fromUtf8("label_title"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_title);

        lineEdit_title = new QLineEdit(GetUserInfo);
        lineEdit_title->setObjectName(QString::fromUtf8("lineEdit_title"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_title);


        verticalLayout->addLayout(formLayout);


        retranslateUi(GetUserInfo);

        QMetaObject::connectSlotsByName(GetUserInfo);
    } // setupUi

    void retranslateUi(QWidget *GetUserInfo)
    {
        GetUserInfo->setWindowTitle(QCoreApplication::translate("GetUserInfo", "Form", nullptr));
        label_experimenterName->setText(QCoreApplication::translate("GetUserInfo", "Experimenter name:", nullptr));
        label_subjectName->setText(QCoreApplication::translate("GetUserInfo", "Subject name:", nullptr));
        label_date->setText(QCoreApplication::translate("GetUserInfo", "Date: ", nullptr));
        label_notes->setText(QCoreApplication::translate("GetUserInfo", "Notes:", nullptr));
        label_title->setText(QCoreApplication::translate("GetUserInfo", "Experiment title:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GetUserInfo: public Ui_GetUserInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GETUSERINFO_H
