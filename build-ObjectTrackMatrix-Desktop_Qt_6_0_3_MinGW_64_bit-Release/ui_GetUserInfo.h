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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GetUserInfo
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_subjectName;
    QDateEdit *dateEdit_experimentDate;
    QLabel *label_experimenterName;
    QLabel *label_title;
    QLineEdit *lineEdit_experimenterName;
    QLabel *label_notes;
    QLineEdit *lineEdit_title;
    QLabel *label_date;
    QLabel *label_subjectName;
    QLabel *label_errTitle;
    QLabel *label_errName;
    QLabel *label_errSubject;
    QPlainTextEdit *plainTextEdit_notes;

    void setupUi(QWidget *GetUserInfo)
    {
        if (GetUserInfo->objectName().isEmpty())
            GetUserInfo->setObjectName(QString::fromUtf8("GetUserInfo"));
        GetUserInfo->resize(400, 345);
        verticalLayout = new QVBoxLayout(GetUserInfo);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit_subjectName = new QLineEdit(GetUserInfo);
        lineEdit_subjectName->setObjectName(QString::fromUtf8("lineEdit_subjectName"));

        gridLayout->addWidget(lineEdit_subjectName, 2, 1, 1, 1);

        dateEdit_experimentDate = new QDateEdit(GetUserInfo);
        dateEdit_experimentDate->setObjectName(QString::fromUtf8("dateEdit_experimentDate"));

        gridLayout->addWidget(dateEdit_experimentDate, 3, 1, 1, 1);

        label_experimenterName = new QLabel(GetUserInfo);
        label_experimenterName->setObjectName(QString::fromUtf8("label_experimenterName"));

        gridLayout->addWidget(label_experimenterName, 1, 0, 1, 1);

        label_title = new QLabel(GetUserInfo);
        label_title->setObjectName(QString::fromUtf8("label_title"));

        gridLayout->addWidget(label_title, 0, 0, 1, 1);

        lineEdit_experimenterName = new QLineEdit(GetUserInfo);
        lineEdit_experimenterName->setObjectName(QString::fromUtf8("lineEdit_experimenterName"));

        gridLayout->addWidget(lineEdit_experimenterName, 1, 1, 1, 1);

        label_notes = new QLabel(GetUserInfo);
        label_notes->setObjectName(QString::fromUtf8("label_notes"));

        gridLayout->addWidget(label_notes, 4, 0, 1, 1, Qt::AlignTop);

        lineEdit_title = new QLineEdit(GetUserInfo);
        lineEdit_title->setObjectName(QString::fromUtf8("lineEdit_title"));

        gridLayout->addWidget(lineEdit_title, 0, 1, 1, 1);

        label_date = new QLabel(GetUserInfo);
        label_date->setObjectName(QString::fromUtf8("label_date"));

        gridLayout->addWidget(label_date, 3, 0, 1, 1);

        label_subjectName = new QLabel(GetUserInfo);
        label_subjectName->setObjectName(QString::fromUtf8("label_subjectName"));

        gridLayout->addWidget(label_subjectName, 2, 0, 1, 1);

        label_errTitle = new QLabel(GetUserInfo);
        label_errTitle->setObjectName(QString::fromUtf8("label_errTitle"));
        QFont font;
        font.setBold(true);
        label_errTitle->setFont(font);

        gridLayout->addWidget(label_errTitle, 0, 2, 1, 1);

        label_errName = new QLabel(GetUserInfo);
        label_errName->setObjectName(QString::fromUtf8("label_errName"));
        label_errName->setFont(font);

        gridLayout->addWidget(label_errName, 1, 2, 1, 1);

        label_errSubject = new QLabel(GetUserInfo);
        label_errSubject->setObjectName(QString::fromUtf8("label_errSubject"));
        QFont font1;
        font1.setBold(true);
        font1.setKerning(true);
        label_errSubject->setFont(font1);

        gridLayout->addWidget(label_errSubject, 2, 2, 1, 1);

        plainTextEdit_notes = new QPlainTextEdit(GetUserInfo);
        plainTextEdit_notes->setObjectName(QString::fromUtf8("plainTextEdit_notes"));

        gridLayout->addWidget(plainTextEdit_notes, 4, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        QWidget::setTabOrder(lineEdit_title, lineEdit_experimenterName);
        QWidget::setTabOrder(lineEdit_experimenterName, lineEdit_subjectName);
        QWidget::setTabOrder(lineEdit_subjectName, dateEdit_experimentDate);
        QWidget::setTabOrder(dateEdit_experimentDate, plainTextEdit_notes);

        retranslateUi(GetUserInfo);

        QMetaObject::connectSlotsByName(GetUserInfo);
    } // setupUi

    void retranslateUi(QWidget *GetUserInfo)
    {
        GetUserInfo->setWindowTitle(QCoreApplication::translate("GetUserInfo", "Form", nullptr));
        label_experimenterName->setText(QCoreApplication::translate("GetUserInfo", "Experimenter name:", nullptr));
        label_title->setText(QCoreApplication::translate("GetUserInfo", "Experiment title:", nullptr));
        label_notes->setText(QCoreApplication::translate("GetUserInfo", "Notes:", nullptr));
        label_date->setText(QCoreApplication::translate("GetUserInfo", "Date: ", nullptr));
        label_subjectName->setText(QCoreApplication::translate("GetUserInfo", "Subject name:", nullptr));
        label_errTitle->setText(QCoreApplication::translate("GetUserInfo", "[!!!]", nullptr));
        label_errName->setText(QCoreApplication::translate("GetUserInfo", "[!!!]", nullptr));
        label_errSubject->setText(QCoreApplication::translate("GetUserInfo", "[!!!]", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GetUserInfo: public Ui_GetUserInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GETUSERINFO_H
